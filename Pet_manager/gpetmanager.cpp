#include "gpetmanager.h"
#include "ui_gpetmanager.h"
#include "graphiques.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QHeaderView>
#include <QScrollBar>
#include <QMessageBox>
#include <QInputDialog>
#include <QDialog>
#include <QDialogButtonBox>
#include <QDateEdit>
#include <QDateTime>
#include <QSpinBox>
#include <QMenu>
#include <QAction>
#include <QTimer>
#include <QLocale>
#include <QFileDialog>
#include <QFile>
#include <QStyledItemDelegate>
#include <QGraphicsDropShadowEffect>
#include <QEvent>
#include <algorithm>
#include <functional>
#include <cmath>

// Raccourcit un texte trop long pour un petit emplacement
static QString raccourcir(const QString &texte, int max)
{
    return texte.length() <= max ? texte : texte.left(max - 1) + "…";
}

static const int PAGE_STOCK = 3;
static const int PAGE_REAPPRO = 8;

// =====================================================================
//                         CONSTRUCTEUR
// =====================================================================

GPetManager::GPetManager(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::GPetManager)
{
    ui->setupUi(this);

    timerToast = new QTimer(this);
    timerToast->setSingleShot(true);
    connect(timerToast, &QTimer::timeout, this, [this]() { if (toast) toast->hide(); });

    configurerNavigation();
    configurerTableau();
    configurerFormulaire();
    configurerReappro();
    configurerGraphiques();
    chargerDonneesExemple();
    viderFormulaire();
    rafraichir();

    // CRUD
    connect(ui->btnEnregistrerStock, &QPushButton::clicked, this, &GPetManager::enregistrerProduit);
    connect(ui->btnModifierStock,    &QPushButton::clicked, this, &GPetManager::modifierProduit);
    connect(ui->btnSupprimerStock,   &QPushButton::clicked, this, &GPetManager::supprimerProduit);
    connect(ui->btnAnnulerStock,     &QPushButton::clicked, this, &GPetManager::annulerEdition);

    // Recherche (par nom) et tri (aucun / par date d'expiration)
    connect(ui->txtRechercheStock, &QLineEdit::textChanged, this, &GPetManager::afficherTableau);
    connect(ui->cmbTriStock, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &GPetManager::afficherTableau);

    // Double-clic sur une ligne = charger le produit dans le formulaire
    connect(ui->tableStock, &QTableWidget::cellDoubleClicked, this, [this](int ligne, int) {
        QTableWidgetItem *it = ui->tableStock->item(ligne, 0);
        if (it) chargerDansFormulaire(it->data(Qt::UserRole).toInt());
    });

    // Métiers
    connect(ui->cmbPeriodeStock, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &GPetManager::mettreAJourGraphiqueConso);
    connect(ui->btnNotif,         &QPushButton::clicked, this, &GPetManager::afficherNotifications);
    connect(ui->btnVoirToutStock,      &QPushButton::clicked, this, [this]() { changerPage(PAGE_REAPPRO); });
    connect(ui->btnOuvrirReappro, &QPushButton::clicked, this, [this]() { changerPage(PAGE_REAPPRO); });
    connect(ui->btnExcelStock,         &QPushButton::clicked, this, &GPetManager::exporterExcel);
    // Clic sur une carte alternative = ouvrir la substitution avec ce produit présélectionné
    for (QFrame *carte : {ui->frameAlt1Stock, ui->frameAlt2Stock}) {
        carte->installEventFilter(this);
        for (QLabel *lbl : carte->findChildren<QLabel*>())
            lbl->setAttribute(Qt::WA_TransparentForMouseEvents);
    }

    // Page Réapprovisionnement intelligent
    connect(ui->btnRetourStock,        &QPushButton::clicked, this, [this]() { changerPage(PAGE_STOCK); });
    connect(ui->btnCommanderSelectionStock, &QPushButton::clicked, this, &GPetManager::commanderSelection);
    connect(ui->btnToutSelectionnerStock,   &QPushButton::clicked, this, &GPetManager::toutSelectionner);
    connect(ui->btnExcelSuggestionsStock,   &QPushButton::clicked, this, &GPetManager::exporterExcel);
    connect(ui->btnExcelCommandesStock,     &QPushButton::clicked, this, &GPetManager::exporterCommandesExcel);
    connect(ui->spinDelaiStock,      QOverload<int>::of(&QSpinBox::valueChanged), this, &GPetManager::rafraichir);
    connect(ui->spinCouvertureStock, QOverload<int>::of(&QSpinBox::valueChanged), this, &GPetManager::rafraichir);

    // Contrôle automatique au démarrage
    QTimer::singleShot(800, this, [this]() {
        const int n = indicesAReapprovisionner().size();
        if (n > 0)
            afficherToast("info_teal", "Contrôle automatique du stock",
                          QString("%1 produit(s) nécessitent un réapprovisionnement.").arg(n),
                          "#E53935", "Voir les suggestions", [this]() { changerPage(PAGE_REAPPRO); });
    });
}

GPetManager::~GPetManager()
{
    delete ui;
}

bool GPetManager::eventFilter(QObject *objet, QEvent *evenement)
{
    if (evenement->type() == QEvent::MouseButtonPress) {
        int k = -1;
        if (objet == ui->frameAlt1Stock) k = 0;
        else if (objet == ui->frameAlt2Stock) k = 1;
        if (k >= 0 && k < indexAlternatives.size()) {
            const int alternative = indexAlternatives[k];
            QTimer::singleShot(0, this, [this, alternative]() {
                ouvrirSubstitution(indexRefAlternatives, 1, alternative);
            });
            return true;
        }
    }
    return QMainWindow::eventFilter(objet, evenement);
}

// =====================================================================
//                         CONFIGURATION
// =====================================================================

void GPetManager::configurerNavigation()
{
    // Ordre = ordre des pages du QStackedWidget
    boutonsNav = {ui->btnAccueil, ui->btnAnimaux, ui->btnRendezVous, ui->btnStock,
                  ui->btnCommandes, ui->btnFournisseurs, ui->btnEmployes, ui->btnParametres};

    for (int i = 0; i < boutonsNav.size(); ++i)
        connect(boutonsNav[i], &QPushButton::clicked, this, [this, i]() { changerPage(i); });

    // Pastille rouge sur la cloche
    badgeNotif = new QLabel(ui->btnNotif);
    badgeNotif->setGeometry(22, 2, 18, 18);
    badgeNotif->setAlignment(Qt::AlignCenter);
    badgeNotif->setAttribute(Qt::WA_TransparentForMouseEvents);
    badgeNotif->setStyleSheet("background:#E53935; color:white; border-radius:9px;"
                              "font-size:10px; font-weight:bold;");

    changerPage(PAGE_STOCK);
}

void GPetManager::changerPage(int index)
{
    const QStringList titres = {"Accueil", "Animaux", "Rendez-vous", "Gestion de stock",
                                "Commandes", "Fournisseurs", "Employés", "Paramètres",
                                "Réapprovisionnement intelligent"};
    const QStringList icones = {"home", "paw", "calendar", "box", "cart", "truck", "users", "gear", "clipboard"};

    ui->SWModules->setCurrentIndex(index);
    ui->lblIconeTitre->setPixmap(icone(icones[index] + "_teal").pixmap(64, 64));
    ui->lblTitre->setText(titres[index]);
    // La page Réapprovisionnement fait partie du module Stock
    boutonsNav[index == PAGE_REAPPRO ? PAGE_STOCK : index]->setChecked(true);
}

void GPetManager::configurerTableau()
{
    QTableWidget *t = ui->tableStock;
    t->setColumnCount(8);
    t->setHorizontalHeaderLabels({"", "Produit", "Catégorie", "Quantité",
                                  "Seuil min.", "Date d'expiration", "Statut", "Actions"});
    t->verticalHeader()->setVisible(false);
    t->verticalHeader()->setDefaultSectionSize(42);
    t->horizontalHeader()->setFixedHeight(38);
    t->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    t->horizontalHeader()->setStretchLastSection(false);
    t->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    t->setWordWrap(false);
    t->setSelectionBehavior(QAbstractItemView::SelectRows);
    t->setEditTriggers(QAbstractItemView::NoEditTriggers);
    t->setFocusPolicy(Qt::NoFocus);
    t->setToolTip("Double-cliquez sur une ligne pour afficher le produit dans le formulaire");

    // La colonne "Produit" prend toute la place libre, les autres ont une largeur fixe
    const QList<int> largeurs = {40, 0, 125, 80, 85, 125, 120, 115};
    for (int c = 0; c < largeurs.size(); ++c) {
        if (c == 1) {
            t->horizontalHeader()->setSectionResizeMode(c, QHeaderView::Stretch);
        } else {
            t->horizontalHeader()->setSectionResizeMode(c, QHeaderView::Fixed);
            t->setColumnWidth(c, largeurs[c]);
        }
    }
}

void GPetManager::configurerFormulaire()
{
    ui->cmbTriStock->addItems({"Aucun tri",
                          "Date d'expiration : la plus proche d'abord",
                          "Date d'expiration : la plus lointaine d'abord"});
    ui->cmbPeriodeStock->addItems({"7 derniers jours", "30 derniers jours"});
    ui->cmbCategorieStock->addItems({"Sélectionner une catégorie", "Alimentation", "Médicament", "Équipement"});
    ui->cmbEspeceStock->addItems({"Choisir…", "Chien", "Chat", "Toutes"});
    ui->cmbUsageStock->addItems({"Choisir…", "Nutrition", "Soin", "Vaccination", "Hygiène",
                            "Diagnostic", "Promenade", "Transport"});
    ui->cmbEspeceStock->setToolTip("Espèce à laquelle le produit est destiné");
    ui->cmbUsageStock->setToolTip("Rôle du produit : sert à trouver des alternatives compatibles");

    // Listes déroulantes : délégué standard pour que le texte des options
    // s'affiche correctement avec la feuille de style
    for (QComboBox *combo : findChildren<QComboBox*>())
        combo->setItemDelegate(new QStyledItemDelegate(combo));

    ui->txtRechercheStock->setClearButtonEnabled(true);
    ui->txtRechercheStock->addAction(icone("search_grey"), QLineEdit::LeadingPosition);
    ui->lblAvatar->setPixmap(icone("user_teal").pixmap(26, 26));

    ui->spinQuantiteStock->setRange(0, 100000);
    ui->spinSeuilStock->setRange(0, 100000);

    ui->dateExpirationStock->setCalendarPopup(true);
    ui->dateExpirationStock->setDisplayFormat("dd/MM/yyyy");
    ui->dateExpirationStock->setDate(QDate::currentDate());

    ui->spinPrixStock->setDecimals(3);
    ui->spinPrixStock->setRange(0, 1000000);
    ui->spinPrixStock->setSuffix(" TND");
}

void GPetManager::configurerReappro()
{
    ui->spinDelaiStock->setRange(1, 60);
    ui->spinDelaiStock->setValue(3);
    ui->spinDelaiStock->setSuffix(" jours");
    ui->spinCouvertureStock->setRange(1, 90);
    ui->spinCouvertureStock->setValue(14);
    ui->spinCouvertureStock->setSuffix(" jours");

    // Tableau des suggestions
    QTableWidget *s = ui->tableSuggestionsStock;
    s->setColumnCount(10);
    s->setHorizontalHeaderLabels({"", "Produit", "Stock", "Seuil", "Conso./jour", "Rupture prévue",
                                  "Priorité", "Qté conseillée", "Fournisseur", "Montant (TND)"});
    const QList<int> largeursS = {40, 0, 70, 70, 95, 140, 125, 120, 120, 120};

    // Tableau des commandes
    QTableWidget *c = ui->tableCommandesStock;
    c->setColumnCount(9);
    c->setHorizontalHeaderLabels({"N°", "Produit", "Quantité", "Fournisseur", "Commandée le",
                                  "Livraison prévue", "Montant (TND)", "Statut", "Actions"});
    const QList<int> largeursC = {75, 0, 85, 125, 115, 130, 120, 120, 240};

    auto preparer = [](QTableWidget *t, const QList<int> &largeurs) {
        t->verticalHeader()->setVisible(false);
        t->verticalHeader()->setDefaultSectionSize(42);
        t->horizontalHeader()->setFixedHeight(38);
        t->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft | Qt::AlignVCenter);
        t->horizontalHeader()->setStretchLastSection(false);
        t->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        t->setWordWrap(false);
        t->setSelectionMode(QAbstractItemView::NoSelection);
        t->setEditTriggers(QAbstractItemView::NoEditTriggers);
        t->setFocusPolicy(Qt::NoFocus);
        for (int col = 0; col < largeurs.size(); ++col) {
            if (largeurs[col] == 0) {
                t->horizontalHeader()->setSectionResizeMode(col, QHeaderView::Stretch);
            } else {
                t->horizontalHeader()->setSectionResizeMode(col, QHeaderView::Fixed);
                t->setColumnWidth(col, largeurs[col]);
            }
        }
    };
    preparer(s, largeursS);
    preparer(c, largeursC);

    // Historique des substitutions (page Stock)
    QTableWidget *h = ui->tableSubstitutionsStock;
    h->setColumnCount(6);
    h->setHorizontalHeaderLabels({"Date", "Produit demandé", "Remplacé par", "Quantité",
                                  "Compatibilité", "Motif"});
    preparer(h, {150, 0, 0, 90, 120, 170});
}

void GPetManager::configurerGraphiques()
{
    // Chaque graphique remplit sa zone et suit la taille de la fenêtre
    auto placer = [](QWidget *graphique, QWidget *zone) {
        QVBoxLayout *l = new QVBoxLayout(zone);
        l->setContentsMargins(0, 0, 0, 0);
        l->addWidget(graphique);
    };
    graphConso      = new GraphiqueCourbes(ui->widgetGraphiqueStock);
    graphCategories = new GraphiqueCamembert(ui->widgetCamembertStock);
    placer(graphConso, ui->widgetGraphiqueStock);
    placer(graphCategories, ui->widgetCamembertStock);

    ui->scrollStock->viewport()->setAutoFillBackground(false);
    ui->scrollReappro->viewport()->setAutoFillBackground(false);
}

void GPetManager::chargerDonneesExemple()
{
    const QDate auj = QDate::currentDate();
    produits = {
        {"Croquettes premium chien",    "Alimentation", "Chien",  "Nutrition",   12, 5,  auj.addMonths(11), "Royal Vet", 85.0,  {}, {}},
        {"Antibiotique (Amoxicilline)", "Médicament",   "Toutes", "Soin",         3, 5,  auj.addMonths(11), "PharmaVet", 24.5,  {}, {}},
        {"Vaccin CHPP",                 "Médicament",   "Chien",  "Vaccination",  0, 2,  auj.addDays(120),  "PharmaVet", 45.0,  {}, {}},
        {"Laisse réglable",             "Équipement",   "Chien",  "Promenade",   18, 10, auj.addYears(2),   "Animalis",  18.0,  {}, {}},
        {"Thermomètre vétérinaire",     "Équipement",   "Toutes", "Diagnostic",   4, 5,  auj.addYears(2),   "MedEquip",  32.0,  {}, {}},
        {"Cage de transport",           "Équipement",   "Toutes", "Transport",    6, 2,  auj.addYears(2),   "Animalis",  120.0, {}, {}},
        {"Désinfectant 500ml",          "Médicament",   "Toutes", "Hygiène",      1, 3,  auj.addDays(-18),  "PharmaVet", 15.0,  {}, {}},
        {"Aliment humide chat",         "Alimentation", "Chat",   "Nutrition",   20, 8,  auj.addDays(20),   "Royal Vet", 6.5,   {}, {}},
        {"Désinfectant 250ml",          "Médicament",   "Toutes", "Hygiène",     13, 4,  auj.addMonths(8),  "PharmaVet", 9.0,   {}, {}},
        {"Aliment sec chat",            "Alimentation", "Chat",   "Nutrition",   13, 5,  auj.addMonths(9),  "Royal Vet", 42.0,  {}, {}},
        {"Antibiotique (Doxycycline)",  "Médicament",   "Toutes", "Soin",         9, 3,  auj.addMonths(10), "PharmaVet", 28.0,  {}, {}},
        {"Vaccin CHPPi-L",              "Médicament",   "Chien",  "Vaccination",  6, 2,  auj.addMonths(6),  "PharmaVet", 52.0,  {}, {}},
        {"Croquettes standard chien",   "Alimentation", "Chien",  "Nutrition",   25, 8,  auj.addMonths(12), "Animalis",  60.0,  {}, {}}
    };

    // Historique de consommation des 30 derniers jours (données d'exemple) :
    // une base par produit + une variation qui change chaque jour
    const QList<int> bases = {3, 1, 1, 1, 0, 0, 1, 2, 1, 1, 1, 0, 2};
    for (int i = 0; i < produits.size(); ++i)
        for (int d = 0; d < 30; ++d) {
            if (bases[i] == 0) continue;
            const quint32 h = (quint32(d + 1) * 2654435761u) ^ (quint32(i + 1) * 40503u);
            const int variation = int((h >> 7) % 3) - 1;                    // -1, 0 ou +1
            const int v = bases[i] + variation;
            if (v > 0) produits[i].consommation[auj.addDays(-d)] = v;
        }
}

// =====================================================================
//              MÉTIER : RÉAPPROVISIONNEMENT INTELLIGENT
// =====================================================================

GPetManager::Etat GPetManager::etatProduit(const Produit &p) const
{
    if (p.dateExpiration < QDate::currentDate()) return Expire;
    if (p.quantite == 0)                         return Rupture;
    if (p.quantite <= p.seuil)                   return StockBas;
    return OK;
}

QString GPetManager::libelleEtat(Etat e) const
{
    switch (e) {
    case Expire:   return "Expiré";
    case Rupture:  return "Rupture";
    case StockBas: return "Stock bas";
    default:       return "OK";
    }
}

QString GPetManager::libellePriorite(int priorite) const
{
    switch (priorite) {
    case Critique:   return "Critique";
    case Urgente:    return "Urgent";
    case Preventive: return "Préventif";
    default:         return "Aucune";
    }
}

QString GPetManager::couleurPriorite(int priorite) const
{
    switch (priorite) {
    case Critique:   return "#E53935";
    case Urgente:    return "#F5A623";
    case Preventive: return "#1E88E5";
    default:         return "#2E8B57";
    }
}

/*
 * Analyse prédictive d'un produit :
 *  1) demande moyenne par jour sur les 30 derniers jours
 *     (consommation + quantités remplacées par une alternative)
 *  2) nombre de jours avant que le stock soit inutilisable
 *     (épuisé OU expiré : on retient la date la plus proche)
 *  3) priorité :
 *     - Critique   : expiré, épuisé, ou rupture avant la prochaine livraison possible
 *     - Urgente    : quantité <= seuil minimal
 *     - Préventive : rupture prévue moins de 7 jours après le délai de livraison
 *  4) quantité conseillée = consommation pendant (délai + couverture) + seuil de sécurité
 *                           - stock encore utilisable
 */
Analyse GPetManager::analyserProduit(int index) const
{
    const Produit &p = produits[index];
    const QDate auj = QDate::currentDate();
    const int delai = ui->spinDelaiStock->value();
    const int couverture = ui->spinCouvertureStock->value();
    Analyse a;

    int total = 0;
    for (int d = 0; d < 30; ++d)
        total += p.consommation.value(auj.addDays(-d), 0)
               + p.demandeNonSatisfaite.value(auj.addDays(-d), 0);   // demande réelle
    a.consoMoyenne = total / 30.0;

    const bool expire = p.dateExpiration < auj;
    const int stockUtilisable = expire ? 0 : p.quantite;

    double jours = -1;
    if (stockUtilisable == 0)      jours = 0;
    else if (a.consoMoyenne > 0)   jours = stockUtilisable / a.consoMoyenne;
    if (!expire) {
        const double joursAvantExpiration = auj.daysTo(p.dateExpiration);
        if (jours < 0 || joursAvantExpiration < jours) jours = joursAvantExpiration;
    }
    a.joursRestants = jours;
    if (jours >= 0) a.dateRupture = auj.addDays(int(std::floor(jours)));

    if (expire || stockUtilisable == 0 || (jours >= 0 && jours <= delai))
        a.priorite = Critique;
    else if (p.quantite <= p.seuil)
        a.priorite = Urgente;
    else if (jours >= 0 && jours <= delai + 7)
        a.priorite = Preventive;

    const double besoin = a.consoMoyenne * (delai + couverture) + p.seuil;
    a.qteConseillee = std::max(int(std::ceil(besoin)) - stockUtilisable, std::max(1, p.seuil));
    a.commandeEnCours = commandeEnAttente(p.nom);
    return a;
}

QString GPetManager::textePrevision(const Analyse &a) const
{
    if (a.joursRestants < 0) return "Non prévisible";
    if (a.joursRestants < 1) return "Aujourd'hui";
    return a.dateRupture.toString("dd/MM/yyyy") + QString("  (J-%1)").arg(int(std::floor(a.joursRestants)));
}

// Produits à réapprovisionner, du plus urgent au moins urgent
QVector<int> GPetManager::indicesAReapprovisionner(bool inclureCommandes) const
{
    QVector<int> liste;
    QVector<Analyse> analyses(produits.size());
    for (int i = 0; i < produits.size(); ++i) {
        analyses[i] = analyserProduit(i);
        if (analyses[i].priorite != Aucune && (inclureCommandes || !analyses[i].commandeEnCours))
            liste.append(i);
    }
    std::sort(liste.begin(), liste.end(), [&](int a, int b) {
        if (analyses[a].priorite != analyses[b].priorite)
            return analyses[a].priorite > analyses[b].priorite;
        double ja = analyses[a].joursRestants < 0 ? 1e9 : analyses[a].joursRestants;
        double jb = analyses[b].joursRestants < 0 ? 1e9 : analyses[b].joursRestants;
        return ja < jb;
    });
    return liste;
}

QSet<QString> GPetManager::nomsEnAlerte() const
{
    QSet<QString> noms;
    for (int idx : indicesAReapprovisionner())
        noms.insert(produits[idx].nom);
    return noms;
}

bool GPetManager::commandeEnAttente(const QString &nomProduit) const
{
    for (const Commande &c : commandes)
        if (c.statut == "En attente" && c.produit == nomProduit)
            return true;
    return false;
}

int GPetManager::indiceProduit(const QString &nom) const
{
    for (int i = 0; i < produits.size(); ++i)
        if (produits[i].nom == nom) return i;
    return -1;
}

// Alerte automatique : appelée après chaque mouvement de stock.
// Elle compare les alertes avant/après et prévient immédiatement l'utilisateur.
void GPetManager::signalerNouvellesAlertes(const QSet<QString> &avant)
{
    QVector<int> nouveaux;
    for (int idx : indicesAReapprovisionner())
        if (!avant.contains(produits[idx].nom))
            nouveaux.append(idx);
    if (nouveaux.isEmpty()) return;

    if (nouveaux.size() == 1) {
        const int idx = nouveaux.first();
        const Produit &p = produits[idx];
        const Analyse a = analyserProduit(idx);
        QString message = QString("Stock : %1 (seuil %2)").arg(p.quantite).arg(p.seuil);
        if (a.joursRestants >= 0)
            message += a.joursRestants < 1 ? " · rupture aujourd'hui"
                                           : QString(" · rupture prévue dans %1 jour(s)")
                                                 .arg(int(std::floor(a.joursRestants)));
        const QString nom = p.nom;
        const int quantite = a.qteConseillee;
        afficherToast(a.priorite == Critique ? "warning_red" : "warning_orange",
                      libellePriorite(a.priorite) + " : " + raccourcir(p.nom, 28), message,
                      couleurPriorite(a.priorite), QString("Commander %1").arg(quantite),
                      [this, nom, quantite]() {
                          const int i = indiceProduit(nom);
                          if (i >= 0 && creerCommande(i, quantite)) rafraichir();
                      });
    } else {
        afficherToast("warning_red", "Nouvelles alertes de stock",
                      QString("%1 produits ont besoin d'être réapprovisionnés.").arg(nouveaux.size()),
                      "#E53935", "Voir les suggestions", [this]() { changerPage(PAGE_REAPPRO); });
    }
}

bool GPetManager::creerCommande(int indexProduit, int quantite, bool silencieux)
{
    if (indexProduit < 0 || indexProduit >= produits.size() || quantite <= 0) return false;
    const Produit &p = produits[indexProduit];

    if (commandeEnAttente(p.nom)) {
        if (!silencieux)
            QMessageBox::information(this, "Commande déjà en cours",
                "Une commande est déjà en attente pour « " + p.nom + " ».");
        return false;
    }

    Commande c;
    c.numero = prochainNumero++;
    c.produit = p.nom;
    c.quantite = quantite;
    c.fournisseur = p.fournisseur;
    c.dateCommande = QDate::currentDate();
    c.dateLivraison = QDate::currentDate().addDays(ui->spinDelaiStock->value());
    c.montant = quantite * p.prix;
    c.statut = "En attente";
    commandes.append(c);

    if (!silencieux)
        afficherToast("check_green", QString("Commande n°%1 créée").arg(c.numero),
                      QString("%1 × %2 — livraison prévue le %3")
                          .arg(c.quantite).arg(raccourcir(c.produit, 26))
                          .arg(c.dateLivraison.toString("dd/MM/yyyy")),
                      "#2E8B57", "Voir les commandes", [this]() { changerPage(PAGE_REAPPRO); });
    return true;
}

void GPetManager::commanderSelection()
{
    QTableWidget *t = ui->tableSuggestionsStock;
    int nb = 0;
    double total = 0;
    for (int l = 0; l < t->rowCount(); ++l) {
        QTableWidgetItem *chk = t->item(l, 0);
        if (!chk || chk->checkState() != Qt::Checked) continue;
        const int idx = chk->data(Qt::UserRole).toInt();
        QSpinBox *spin = qobject_cast<QSpinBox*>(t->cellWidget(l, 7));
        const int q = spin ? spin->value() : analyserProduit(idx).qteConseillee;
        if (creerCommande(idx, q, true)) {
            nb++;
            total += q * produits[idx].prix;
        }
    }
    if (nb == 0) {
        QMessageBox::information(this, "Commander",
            "Cochez au moins un produit dans les suggestions.");
        return;
    }
    rafraichir();
    afficherToast("check_green", QString("%1 commande(s) créée(s)").arg(nb),
                  "Montant total : " + QString::number(total, 'f', 3) + " TND", "#2E8B57");
}

void GPetManager::toutSelectionner()
{
    QTableWidget *t = ui->tableSuggestionsStock;
    bool toutCoche = true;
    for (int l = 0; l < t->rowCount(); ++l) {
        QTableWidgetItem *chk = t->item(l, 0);
        if (chk && chk->flags().testFlag(Qt::ItemIsEnabled) && chk->checkState() != Qt::Checked)
            toutCoche = false;
    }
    for (int l = 0; l < t->rowCount(); ++l) {
        QTableWidgetItem *chk = t->item(l, 0);
        if (chk && chk->flags().testFlag(Qt::ItemIsEnabled))
            chk->setCheckState(toutCoche ? Qt::Unchecked : Qt::Checked);
    }
}

// Réception : le stock est mis à jour automatiquement
void GPetManager::receptionnerCommande(int indexCommande)
{
    if (indexCommande < 0 || indexCommande >= commandes.size()) return;
    Commande &c = commandes[indexCommande];
    const int idx = indiceProduit(c.produit);
    if (idx < 0) {
        QMessageBox::warning(this, "Produit introuvable",
            "Le produit « " + c.produit + " » n'existe plus dans le stock.");
        return;
    }

    QDialog dlg(this);
    dlg.setWindowTitle(QString("Réception de la commande n°%1").arg(c.numero));
    dlg.setMinimumWidth(380);
    QVBoxLayout *lay = new QVBoxLayout(&dlg);
    QLabel *info = new QLabel(QString("Produit : <b>%1</b><br>Quantité reçue : <b>%2</b><br>Fournisseur : %3")
                                  .arg(c.produit.toHtmlEscaped()).arg(c.quantite)
                                  .arg(c.fournisseur.toHtmlEscaped()));
    QLabel *lblDate = new QLabel("Date d'expiration du nouveau lot :");
    QDateEdit *date = new QDateEdit(QDate::currentDate().addYears(1));
    date->setCalendarPopup(true);
    date->setDisplayFormat("dd/MM/yyyy");
    date->setMinimumDate(QDate::currentDate().addDays(1));
    QDialogButtonBox *boutons = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    boutons->button(QDialogButtonBox::Ok)->setText("Confirmer la réception");
    boutons->button(QDialogButtonBox::Cancel)->setText("Annuler");
    connect(boutons, &QDialogButtonBox::accepted, &dlg, &QDialog::accept);
    connect(boutons, &QDialogButtonBox::rejected, &dlg, &QDialog::reject);
    lay->addWidget(info);
    lay->addSpacing(8);
    lay->addWidget(lblDate);
    lay->addWidget(date);
    lay->addSpacing(8);
    lay->addWidget(boutons);
    if (dlg.exec() != QDialog::Accepted) return;

    Produit &p = produits[idx];
    const bool expire = p.dateExpiration < QDate::currentDate();
    QString remarque;
    if (expire || p.quantite == 0) {
        if (expire && p.quantite > 0)
            remarque = QString(" (%1 unité(s) expirée(s) retirée(s))").arg(p.quantite);
        p.quantite = c.quantite;
        p.dateExpiration = date->date();
    } else {
        p.quantite += c.quantite;
        // On garde la date la plus proche : c'est le lot à utiliser en premier
        if (date->date() < p.dateExpiration) p.dateExpiration = date->date();
    }
    c.statut = "Reçue";
    c.dateLivraison = QDate::currentDate();

    const QString nom = p.nom;
    const int nouveauStock = p.quantite;
    rafraichir();
    afficherToast("check_green", "Commande réceptionnée",
                  QString("%1 : stock mis à jour → %2%3").arg(raccourcir(nom, 24)).arg(nouveauStock).arg(remarque),
                  "#2E8B57");
}

void GPetManager::annulerCommande(int indexCommande)
{
    if (indexCommande < 0 || indexCommande >= commandes.size()) return;
    Commande &c = commandes[indexCommande];
    if (QMessageBox::question(this, "Annuler la commande",
            QString("Annuler la commande n°%1 (%2 × %3) ?").arg(c.numero).arg(c.quantite).arg(c.produit))
        != QMessageBox::Yes)
        return;
    c.statut = "Annulée";
    rafraichir();   // le produit redevient une suggestion s'il est toujours en alerte
}

// =====================================================================
//                         NOTIFICATION "TOAST"
// =====================================================================

void GPetManager::afficherToast(const QString &nomIcone, const QString &titre, const QString &message,
                                const QString &couleur, const QString &texteBouton,
                                std::function<void()> action)
{
    if (toast) toast->deleteLater();

    QFrame *cadre = new QFrame(ui->centralwidget);
    cadre->setObjectName("toast");
    cadre->setStyleSheet(QString("#toast { background:white; border:1px solid #E0E8E8;"
                                 "border-left:6px solid %1; border-radius:10px; }").arg(couleur));
    QGraphicsDropShadowEffect *ombre = new QGraphicsDropShadowEffect(cadre);
    ombre->setBlurRadius(24);
    ombre->setOffset(0, 4);
    ombre->setColor(QColor(0, 0, 0, 60));
    cadre->setGraphicsEffect(ombre);

    QHBoxLayout *lay = new QHBoxLayout(cadre);
    lay->setContentsMargins(14, 12, 10, 12);
    lay->setSpacing(12);

    QLabel *lblIcone = new QLabel;
    lblIcone->setPixmap(GPetManager::icone(nomIcone).pixmap(28, 28));
    lblIcone->setFixedSize(28, 28);
    QLabel *lblTexte = new QLabel(QString("<b style='color:#17363A; font-size:13px'>%1</b><br>"
                                          "<span style='color:#5F7373; font-size:12px'>%2</span>")
                                      .arg(titre.toHtmlEscaped(), message.toHtmlEscaped()));
    lblTexte->setWordWrap(true);
    lay->addWidget(lblIcone);
    lay->addWidget(lblTexte, 1);

    if (!texteBouton.isEmpty() && action) {
        QPushButton *btn = new QPushButton(texteBouton);
        btn->setCursor(Qt::PointingHandCursor);
        btn->setStyleSheet(QString("QPushButton{background:%1;color:white;border:none;border-radius:6px;"
                                   "padding:7px 12px;font-weight:bold;}"
                                   "QPushButton:hover{background:#17363A;}").arg(couleur));
        connect(btn, &QPushButton::clicked, this, [this, action]() {
            if (toast) toast->hide();
            QTimer::singleShot(0, this, action);
        });
        lay->addWidget(btn);
    }

    QPushButton *fermer = new QPushButton("×");
    fermer->setFixedSize(26, 26);
    fermer->setCursor(Qt::PointingHandCursor);
    fermer->setStyleSheet("QPushButton{border:none;background:transparent;color:#6B8080;font-size:14px;}"
                          "QPushButton:hover{color:#17363A;}");
    connect(fermer, &QPushButton::clicked, cadre, &QWidget::hide);
    lay->addWidget(fermer, 0, Qt::AlignTop);

    cadre->setFixedWidth(470);
    cadre->adjustSize();
    cadre->move(ui->centralwidget->width() - cadre->width() - 28,
                ui->centralwidget->height() - cadre->height() - 28);
    cadre->show();
    cadre->raise();

    toast = cadre;
    timerToast->start(texteBouton.isEmpty() ? 5000 : 9000);
}

// =====================================================================
//                         AFFICHAGE
// =====================================================================

void GPetManager::rafraichir()
{
    afficherTableau();
    mettreAJourCartes();
    mettreAJourAlertes();
    mettreAJourAlternatives();
    mettreAJourGraphiqueConso();
    mettreAJourStatistiques();
    afficherSuggestions();
    afficherCommandes();
    afficherSubstitutions();
}

void GPetManager::ajusterHauteurTableau(QTableWidget *t, int lignes)
{
    const int visibles = std::max(1, std::min(lignes, 10));
    t->setFixedHeight(38 + visibles * 42 + 4);   // 38 = hauteur de l'en-tête
}

// Icône dessinée stockée dans les ressources (dossier icones/)
QIcon GPetManager::icone(const QString &nom)
{
    return QIcon(":/icones/" + nom + ".png");
}

QIcon GPetManager::iconeCategorie(const QString &categorie) const
{
    if (categorie == "Alimentation") return icone("bowl_green");
    if (categorie == "Médicament")   return icone("pill_red");
    return icone("tag_blue");
}

QWidget* GPetManager::creerBadge(const QString &texte, const QString &fond, const QString &couleur)
{
    QWidget *w = new QWidget;
    QHBoxLayout *lay = new QHBoxLayout(w);
    lay->setContentsMargins(4, 0, 4, 0);

    QLabel *lbl = new QLabel(texte);
    lbl->setAlignment(Qt::AlignCenter);
    lbl->setFixedHeight(24);
    lbl->setStyleSheet(QString("background-color:%1; color:%2; border-radius:12px;"
                               "padding:0 10px; font-size:11px; font-weight:bold;")
                           .arg(fond, couleur));
    lay->addWidget(lbl);
    lay->addStretch();
    return w;
}

QWidget* GPetManager::creerActions(int index)
{
    QWidget *w = new QWidget;
    QHBoxLayout *lay = new QHBoxLayout(w);
    lay->setContentsMargins(0, 0, 0, 0);
    lay->setSpacing(4);

    QPushButton *btnSortie = new QPushButton;
    QPushButton *btnEdit   = new QPushButton;
    QPushButton *btnSuppr  = new QPushButton;
    btnSortie->setIcon(icone("sortie_teal"));
    btnEdit->setIcon(icone("pencil_orange"));
    btnSuppr->setIcon(icone("trash_red"));
    btnSortie->setToolTip("Sortie de stock (utilisation)");
    btnEdit->setToolTip("Modifier");
    btnSuppr->setToolTip("Supprimer");

    for (QPushButton *b : {btnSortie, btnEdit, btnSuppr}) {
        b->setFixedSize(30, 30);
        b->setIconSize(QSize(18, 18));
        b->setCursor(Qt::PointingHandCursor);
        b->setStyleSheet("QPushButton{border:none;background:transparent;}"
                         "QPushButton:hover{background:#E6F2F1;border-radius:6px;}");
        lay->addWidget(b);
    }
    lay->addStretch();

    connect(btnEdit, &QPushButton::clicked, this, [this, index]() {
        chargerDansFormulaire(index);
    });

    // Ces actions reconstruisent le tableau : on les lance juste après le clic
    connect(btnSortie, &QPushButton::clicked, this, [this, index]() {
        QTimer::singleShot(0, this, [this, index]() { sortieDeStock(index); });
    });

    connect(btnSuppr, &QPushButton::clicked, this, [this, index]() {
        QTimer::singleShot(0, this, [this, index]() {
            if (QMessageBox::question(this, "Supprimer",
                    "Voulez-vous vraiment supprimer « " + produits[index].nom + " » ?")
                != QMessageBox::Yes)
                return;
            produits.removeAt(index);
            if (indexEnEdition == index)     viderFormulaire();
            else if (indexEnEdition > index) indexEnEdition--;
            rafraichir();
        });
    });
    return w;
}

void GPetManager::afficherTableau()
{
    // 1) Recherche uniquement par nom
    const QString filtre = ui->txtRechercheStock->text().trimmed();
    QVector<int> ordre;
    for (int i = 0; i < produits.size(); ++i)
        if (filtre.isEmpty() || produits[i].nom.contains(filtre, Qt::CaseInsensitive))
            ordre.append(i);

    // 2) Tri : 0 = aucun (ordre d'ajout), 1 = date la plus proche, 2 = date la plus lointaine
    const int tri = ui->cmbTriStock->currentIndex();
    if (tri != 0) {
        std::stable_sort(ordre.begin(), ordre.end(), [&](int a, int b) {
            return tri == 1 ? produits[a].dateExpiration < produits[b].dateExpiration
                            : produits[a].dateExpiration > produits[b].dateExpiration;
        });
    }

    // 3) Remplissage
    QTableWidget *t = ui->tableStock;
    t->setRowCount(0);
    t->setRowCount(ordre.size());

    for (int l = 0; l < ordre.size(); ++l) {
        const int idx = ordre[l];
        const Produit &p = produits[idx];
        const Analyse a = analyserProduit(idx);

        QTableWidgetItem *chk = new QTableWidgetItem();
        chk->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
        chk->setCheckState(Qt::Unchecked);
        chk->setData(Qt::UserRole, idx);
        t->setItem(l, 0, chk);

        QTableWidgetItem *itNom = new QTableWidgetItem(iconeCategorie(p.categorie), p.nom);
        itNom->setToolTip(p.nom + "\nEspèce : " + p.espece + " · Usage : " + p.usage
                          + "\nFournisseur : " + p.fournisseur
                          + "\nPrix : " + QString::number(p.prix, 'f', 3) + " TND"
                          + "\nConsommation moyenne : " + QString::number(a.consoMoyenne, 'f', 1) + " / jour"
                          + "\nRupture prévue : " + textePrevision(a));
        t->setItem(l, 1, itNom);

        QString fond, couleur;
        if (p.categorie == "Alimentation")    { fond = "#DFF3E6"; couleur = "#2E7D32"; }
        else if (p.categorie == "Médicament") { fond = "#FDE3E3"; couleur = "#C62828"; }
        else                                  { fond = "#E3EEFB"; couleur = "#1565C0"; }
        t->setCellWidget(l, 2, creerBadge(p.categorie, fond, couleur));

        t->setItem(l, 3, new QTableWidgetItem(QString::number(p.quantite)));
        t->setItem(l, 4, new QTableWidgetItem(QString::number(p.seuil)));
        t->setItem(l, 5, new QTableWidgetItem(p.dateExpiration.toString("dd/MM/yyyy")));

        const Etat e = etatProduit(p);
        const QString fondEtat = (e == OK) ? "#2E8B57" : (e == StockBas ? "#F5A623" : "#E53935");
        t->setCellWidget(l, 6, creerBadge(libelleEtat(e), fondEtat, "white"));

        t->setCellWidget(l, 7, creerActions(idx));
    }
    ajusterHauteurTableau(t, ordre.size());

    if (ordre.isEmpty())
        ui->lblAffichageStock->setText("Aucun produit ne correspond à « " + filtre + " »");
    else
        ui->lblAffichageStock->setText(QString("Affichage de %1 sur %2 produits")
                                      .arg(ordre.size()).arg(produits.size()));
}

void GPetManager::mettreAJourCartes()
{
    double valeur = 0;
    for (const Produit &p : produits)
        valeur += p.quantite * p.prix;

    ui->lblValeurTotalStock->setText(QString::number(produits.size()));
    ui->lblValeurReappro->setText(QString::number(indicesAReapprovisionner().size()));
    ui->lblValeurStock->setText(QLocale(QLocale::French).toString(valeur, 'f', 0) + " TND");
}

void GPetManager::mettreAJourAlertes()
{
    const QVector<int> liste = indicesAReapprovisionner();

    ui->lblAlerteBadgeStock->setText(QString::number(liste.size()));
    badgeNotif->setText(QString::number(liste.size()));
    badgeNotif->setVisible(!liste.isEmpty());

    const QList<QLabel*> noms = {ui->lblAlerte1Stock, ui->lblAlerte2Stock, ui->lblAlerte3Stock};
    const QList<QLabel*> infos = {ui->lblQte1Stock, ui->lblQte2Stock, ui->lblQte3Stock};

    for (int i = 0; i < 3; ++i) {
        if (i < liste.size()) {
            const Produit &p = produits[liste[i]];
            const Analyse a = analyserProduit(liste[i]);
            noms[i]->setText(QString("<span style='color:%1'>●</span> %2")
                                 .arg(couleurPriorite(a.priorite), raccourcir(p.nom, 34).toHtmlEscaped()));
            noms[i]->setToolTip(p.nom + "\n" + libellePriorite(a.priorite)
                                + "\nStock : " + QString::number(p.quantite)
                                + " (seuil " + QString::number(p.seuil) + ")"
                                + "\nRupture prévue : " + textePrevision(a)
                                + "\nQuantité conseillée : " + QString::number(a.qteConseillee));
            // Prévision affichée à droite : jours avant rupture
            if (a.joursRestants >= 0 && a.joursRestants < 1) infos[i]->setText("Rupture");
            else if (a.joursRestants >= 1) infos[i]->setText(QString("J-%1").arg(int(std::floor(a.joursRestants))));
            else infos[i]->setText("Qté : " + QString::number(p.quantite));
            noms[i]->show();
            infos[i]->show();
        } else if (i == 0) {
            noms[0]->setText("<span style='color:#2E8B57; font-weight:bold'>Tout est sous contrôle</span>");
            noms[0]->setToolTip(QString());
            noms[0]->show();
            infos[0]->hide();
        } else {
            noms[i]->hide();
            infos[i]->hide();
        }
    }
}

// Panneau "Alternatives suggérées" : pour le produit en cours d'édition, sinon pour
// le premier produit en alerte qui possède au moins une alternative compatible
void GPetManager::mettreAJourAlternatives()
{
    int ref = indexEnEdition;
    QVector<Alternative> alternatives;
    if (ref >= 0) {
        alternatives = chercherAlternatives(ref, 1);
    } else {
        const QVector<int> alertes = indicesAReapprovisionner(true);
        for (int idx : alertes) {
            alternatives = chercherAlternatives(idx, 1);
            if (!alternatives.isEmpty()) { ref = idx; break; }
        }
        if (ref < 0 && !alertes.isEmpty()) ref = alertes.first();
    }

    indexRefAlternatives = ref;
    indexAlternatives.clear();
    for (const Alternative &a : alternatives) indexAlternatives.append(a.index);

    ui->lblAltPourStock->setText(ref >= 0 ? "Pour : " + raccourcir(produits[ref].nom, 30)
                                     : "Aucun produit en alerte");

    const QList<QFrame*> cadres  = {ui->frameAlt1Stock, ui->frameAlt2Stock};
    const QList<QLabel*> icones  = {ui->lblAltIcone1Stock, ui->lblAltIcone2Stock};
    const QList<QLabel*> nomsAlt = {ui->lblAltNom1Stock, ui->lblAltNom2Stock};
    const QList<QLabel*> scores  = {ui->lblAltCat1Stock, ui->lblAltCat2Stock};
    const QList<QLabel*> infos   = {ui->lblAltQte1Stock, ui->lblAltQte2Stock};

    for (int k = 0; k < 2; ++k) {
        if (k < alternatives.size()) {
            const Produit &p = produits[alternatives[k].index];
            const int sc = alternatives[k].score;
            const QString couleur = sc >= 75 ? "#2E8B57" : (sc >= 50 ? "#E08A00" : "#6B8080");
            icones[k]->setPixmap(iconeCategorie(p.categorie).pixmap(28, 28));
            nomsAlt[k]->setText(raccourcir(p.nom, 24));
            scores[k]->setText(QString("<span style='color:%1; font-weight:bold'>Compatibilité : %2 %</span>")
                                   .arg(couleur).arg(sc));
            infos[k]->setText("Stock : " + QString::number(p.quantite) + " · " + p.espece);
            cadres[k]->setToolTip(alternatives[k].raisons.join("\n"));
            cadres[k]->show();
        } else {
            cadres[k]->hide();
        }
    }
    ui->lblAucuneAltStock->setVisible(ref >= 0 && alternatives.isEmpty());
}

void GPetManager::mettreAJourGraphiqueConso()
{
    const int nbJours = (ui->cmbPeriodeStock->currentIndex() == 0) ? 7 : 30;
    const QDate debut = QDate::currentDate().addDays(-(nbJours - 1));

    QStringList etiquettes;
    for (int d = 0; d < nbJours; ++d)
        etiquettes << debut.addDays(d).toString("dd/MM");

    // Les 3 produits les plus consommés sur la période
    QVector<QPair<int, int>> totaux;   // (total, indice produit)
    for (int i = 0; i < produits.size(); ++i) {
        int total = 0;
        for (int d = 0; d < nbJours; ++d)
            total += produits[i].consommation.value(debut.addDays(d), 0);
        if (total > 0) totaux.append(qMakePair(total, i));
    }
    std::sort(totaux.begin(), totaux.end(), std::greater<QPair<int, int>>());

    QStringList noms;
    QList<QList<double>> valeurs;
    for (int k = 0; k < std::min(3, int(totaux.size())); ++k) {
        const Produit &p = produits[totaux[k].second];
        noms << p.nom;
        QList<double> serie;
        for (int d = 0; d < nbJours; ++d)
            serie << p.consommation.value(debut.addDays(d), 0);
        valeurs << serie;
    }
    graphConso->setDonnees(etiquettes, noms, valeurs,
                           {QColor("#1F7A6E"), QColor("#F5A623"), QColor("#8E44AD")});
}

void GPetManager::mettreAJourStatistiques()
{
    // Répartition des quantités par catégorie
    const QStringList categories = {"Alimentation", "Médicament", "Équipement"};
    const QList<QColor> couleursCat = {QColor("#43A047"), QColor("#E53935"), QColor("#1E88E5")};

    QList<double> quantites;
    for (const QString &c : categories) {
        double q = 0;
        for (const Produit &p : produits)
            if (p.categorie == c) q += p.quantite;
        quantites << q;
    }
    graphCategories->setDonnees(categories, quantites, couleursCat);
}

// ---------------- Page Réapprovisionnement ----------------

void GPetManager::afficherSuggestions()
{
    const QVector<int> liste = indicesAReapprovisionner(true);
    QTableWidget *t = ui->tableSuggestionsStock;
    t->setRowCount(0);
    t->setRowCount(liste.size());

    int nbCritique = 0, nbUrgent = 0, nbPreventif = 0, nbCommandes = 0;
    double totalConseille = 0;

    for (int l = 0; l < liste.size(); ++l) {
        const int idx = liste[l];
        const Produit &p = produits[idx];
        const Analyse a = analyserProduit(idx);

        if (a.commandeEnCours) nbCommandes++;
        else if (a.priorite == Critique) nbCritique++;
        else if (a.priorite == Urgente) nbUrgent++;
        else nbPreventif++;

        QTableWidgetItem *chk = new QTableWidgetItem();
        chk->setData(Qt::UserRole, idx);
        if (a.commandeEnCours) {
            chk->setFlags(Qt::NoItemFlags);
            chk->setToolTip("Une commande est déjà en cours pour ce produit");
        } else {
            chk->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
            chk->setCheckState(Qt::Unchecked);
        }
        t->setItem(l, 0, chk);

        t->setItem(l, 1, new QTableWidgetItem(iconeCategorie(p.categorie), p.nom));
        t->setItem(l, 2, new QTableWidgetItem(QString::number(p.quantite)));
        t->setItem(l, 3, new QTableWidgetItem(QString::number(p.seuil)));
        t->setItem(l, 4, new QTableWidgetItem(QString::number(a.consoMoyenne, 'f', 1)));
        t->setItem(l, 5, new QTableWidgetItem(textePrevision(a)));

        if (a.commandeEnCours)
            t->setCellWidget(l, 6, creerBadge("Commandé", "#5C7C8A", "white"));
        else
            t->setCellWidget(l, 6, creerBadge(libellePriorite(a.priorite), couleurPriorite(a.priorite), "white"));

        QTableWidgetItem *itMontant = new QTableWidgetItem(QString::number(a.qteConseillee * p.prix, 'f', 3));
        t->setItem(l, 9, itMontant);

        if (a.commandeEnCours) {
            t->setItem(l, 7, new QTableWidgetItem("—"));
        } else {
            // Quantité conseillée, modifiable par l'utilisateur
            QSpinBox *spin = new QSpinBox;
            spin->setRange(1, 100000);
            spin->setValue(a.qteConseillee);
            spin->setToolTip("Quantité conseillée par le système (modifiable)");
            const double prix = p.prix;
            connect(spin, QOverload<int>::of(&QSpinBox::valueChanged), this, [itMontant, prix](int v) {
                itMontant->setText(QString::number(v * prix, 'f', 3));
            });
            t->setCellWidget(l, 7, spin);
            totalConseille += a.qteConseillee * p.prix;
        }
        t->setItem(l, 8, new QTableWidgetItem(p.fournisseur));
    }

    ajusterHauteurTableau(t, liste.size());
    t->setVisible(!liste.isEmpty());
    ui->lblAucuneSuggestionStock->setVisible(liste.isEmpty());
    ui->btnCommanderSelectionStock->setEnabled(liste.size() > nbCommandes);
    ui->btnToutSelectionnerStock->setEnabled(liste.size() > nbCommandes);

    ui->lblCompteursStock->setText(
        QString("<span style='color:#E53935'>●</span> Critique : <b>%1</b> &nbsp;&nbsp;&nbsp; "
                "<span style='color:#F5A623'>●</span> Urgent : <b>%2</b> &nbsp;&nbsp;&nbsp; "
                "<span style='color:#1E88E5'>●</span> Préventif : <b>%3</b> &nbsp;&nbsp;&nbsp; "
                "<span style='color:#5C7C8A'>●</span> Déjà commandés : <b>%4</b> &nbsp;&nbsp;&nbsp; "
                "Budget conseillé : <b>%5 TND</b>")
            .arg(nbCritique).arg(nbUrgent).arg(nbPreventif).arg(nbCommandes)
            .arg(QString::number(totalConseille, 'f', 3)));
}

void GPetManager::afficherCommandes()
{
    QTableWidget *t = ui->tableCommandesStock;
    t->setRowCount(0);

    // Les commandes les plus récentes en premier
    QVector<int> ordre;
    for (int i = commandes.size() - 1; i >= 0; --i) ordre.append(i);
    t->setRowCount(ordre.size());

    for (int l = 0; l < ordre.size(); ++l) {
        const int i = ordre[l];
        const Commande &c = commandes[i];

        t->setItem(l, 0, new QTableWidgetItem(QString::number(c.numero)));
        t->setItem(l, 1, new QTableWidgetItem(c.produit));
        t->setItem(l, 2, new QTableWidgetItem(QString::number(c.quantite)));
        t->setItem(l, 3, new QTableWidgetItem(c.fournisseur));
        t->setItem(l, 4, new QTableWidgetItem(c.dateCommande.toString("dd/MM/yyyy")));
        t->setItem(l, 5, new QTableWidgetItem(c.dateLivraison.toString("dd/MM/yyyy")));
        t->setItem(l, 6, new QTableWidgetItem(QString::number(c.montant, 'f', 3)));

        QString fond = "#F5A623", texte = "En attente";
        if (c.statut == "Reçue")   { fond = "#2E8B57"; texte = "Reçue"; }
        if (c.statut == "Annulée") { fond = "#9AA9A9"; texte = "Annulée"; }
        t->setCellWidget(l, 7, creerBadge(texte, fond, "white"));

        if (c.statut == "En attente") {
            QWidget *w = new QWidget;
            QHBoxLayout *lay = new QHBoxLayout(w);
            lay->setContentsMargins(4, 0, 4, 0);
            lay->setSpacing(6);
            QPushButton *btnRecevoir = new QPushButton(" Réceptionner");
            QPushButton *btnAnnulerCmd = new QPushButton(" Annuler");
            btnRecevoir->setIcon(icone("download_white"));
            btnAnnulerCmd->setIcon(icone("croix_red"));
            btnRecevoir->setIconSize(QSize(14, 14));
            btnAnnulerCmd->setIconSize(QSize(11, 11));
            btnRecevoir->setStyleSheet("QPushButton{background:#2A8C86;color:white;border:none;border-radius:6px;"
                                       "padding:5px 10px;font-size:11px;font-weight:bold;}"
                                       "QPushButton:hover{background:#237872;}");
            btnAnnulerCmd->setStyleSheet("QPushButton{background:white;color:#D32F2F;border:1px solid #E57373;"
                                         "border-radius:6px;padding:4px 10px;font-size:11px;}"
                                         "QPushButton:hover{background:#FDECEC;}");
            for (QPushButton *b : {btnRecevoir, btnAnnulerCmd}) {
                b->setCursor(Qt::PointingHandCursor);
                lay->addWidget(b);
            }
            lay->addStretch();
            connect(btnRecevoir, &QPushButton::clicked, this, [this, i]() {
                QTimer::singleShot(0, this, [this, i]() { receptionnerCommande(i); });
            });
            connect(btnAnnulerCmd, &QPushButton::clicked, this, [this, i]() {
                QTimer::singleShot(0, this, [this, i]() { annulerCommande(i); });
            });
            t->setCellWidget(l, 8, w);
        } else {
            t->setItem(l, 8, new QTableWidgetItem("—"));
        }
    }

    ajusterHauteurTableau(t, ordre.size());
    t->setVisible(!ordre.isEmpty());
    ui->lblAucuneCommandeStock->setVisible(ordre.isEmpty());
}

// =====================================================================
//                         FORMULAIRE / CRUD
// =====================================================================

bool GPetManager::lireFormulaire(Produit &p, bool nouveau)
{
    const QString nom = ui->txtNomStock->text().trimmed();
    if (nom.isEmpty()) {
        QMessageBox::warning(this, "Champ obligatoire", "Veuillez saisir le nom du produit.");
        ui->txtNomStock->setFocus();
        return false;
    }
    for (int i = 0; i < produits.size(); ++i)
        if ((nouveau || i != indexEnEdition) && produits[i].nom.compare(nom, Qt::CaseInsensitive) == 0) {
            QMessageBox::warning(this, "Doublon", "Un produit portant ce nom existe déjà.");
            ui->txtNomStock->setFocus();
            return false;
        }
    if (ui->cmbCategorieStock->currentIndex() == 0) {
        QMessageBox::warning(this, "Champ obligatoire", "Veuillez choisir une catégorie.");
        ui->cmbCategorieStock->setFocus();
        return false;
    }
    if (ui->cmbEspeceStock->currentIndex() == 0) {
        QMessageBox::warning(this, "Champ obligatoire", "Veuillez choisir l'espèce.");
        ui->cmbEspeceStock->setFocus();
        return false;
    }
    if (ui->cmbUsageStock->currentIndex() == 0) {
        QMessageBox::warning(this, "Champ obligatoire", "Veuillez choisir l'usage du produit.");
        ui->cmbUsageStock->setFocus();
        return false;
    }
    if (nouveau && ui->dateExpirationStock->date() <= QDate::currentDate()) {
        QMessageBox::warning(this, "Date invalide", "La date d'expiration doit être dans le futur.");
        ui->dateExpirationStock->setFocus();
        return false;
    }
    if (ui->txtFournisseurStock->text().trimmed().isEmpty()) {
        QMessageBox::warning(this, "Champ obligatoire", "Veuillez saisir le fournisseur.");
        ui->txtFournisseurStock->setFocus();
        return false;
    }
    if (ui->spinPrixStock->value() <= 0) {
        QMessageBox::warning(this, "Prix invalide", "Le prix unitaire doit être supérieur à 0.");
        ui->spinPrixStock->setFocus();
        return false;
    }

    p.nom            = nom;
    p.categorie      = ui->cmbCategorieStock->currentText();
    p.espece         = ui->cmbEspeceStock->currentText();
    p.usage          = ui->cmbUsageStock->currentText();
    p.quantite       = ui->spinQuantiteStock->value();
    p.seuil          = ui->spinSeuilStock->value();
    p.dateExpiration = ui->dateExpirationStock->date();
    p.fournisseur    = ui->txtFournisseurStock->text().trimmed();
    p.prix           = ui->spinPrixStock->value();
    return true;
}

void GPetManager::chargerDansFormulaire(int index)
{
    if (index < 0 || index >= produits.size()) return;
    const Produit &p = produits[index];

    ui->txtNomStock->setText(p.nom);
    ui->cmbCategorieStock->setCurrentText(p.categorie);
    ui->cmbEspeceStock->setCurrentText(p.espece);
    ui->cmbUsageStock->setCurrentText(p.usage);
    ui->spinQuantiteStock->setValue(p.quantite);
    ui->spinSeuilStock->setValue(p.seuil);
    ui->dateExpirationStock->setDate(p.dateExpiration);
    ui->txtFournisseurStock->setText(p.fournisseur);
    ui->spinPrixStock->setValue(p.prix);

    indexEnEdition = index;
    mettreAJourModeFormulaire();
    ui->scrollStock->verticalScrollBar()->setValue(0);
    ui->txtNomStock->setFocus();
    mettreAJourAlternatives();
}

// Mode "Ajout" : seul Enregistrer est actif.
// Mode "Modification" : Modifier et Annuler sont actifs, Enregistrer est grisé.
void GPetManager::mettreAJourModeFormulaire()
{
    const bool edition = (indexEnEdition >= 0);
    ui->btnEnregistrerStock->setEnabled(!edition);
    ui->btnModifierStock->setEnabled(edition);
    ui->btnAnnulerStock->setEnabled(edition);

    if (edition)
        ui->lblFormTitreStock->setText("Modifier : " + raccourcir(produits[indexEnEdition].nom, 22));
    else
        ui->lblFormTitreStock->setText("Ajouter un produit");
}

void GPetManager::annulerEdition()
{
    viderFormulaire();
    ui->tableStock->clearSelection();
    mettreAJourAlternatives();
}

void GPetManager::viderFormulaire()
{
    ui->txtNomStock->clear();
    ui->cmbCategorieStock->setCurrentIndex(0);
    ui->cmbEspeceStock->setCurrentIndex(0);
    ui->cmbUsageStock->setCurrentIndex(0);
    ui->spinQuantiteStock->setValue(0);
    ui->spinSeuilStock->setValue(0);
    ui->dateExpirationStock->setDate(QDate::currentDate());
    ui->txtFournisseurStock->clear();
    ui->spinPrixStock->setValue(0);
    indexEnEdition = -1;
    mettreAJourModeFormulaire();
}

void GPetManager::enregistrerProduit()
{
    Produit p;
    if (!lireFormulaire(p, true)) return;
    const QSet<QString> avant = nomsEnAlerte();
    produits.append(p);
    viderFormulaire();
    rafraichir();
    afficherToast("check_green", "Produit ajouté", "« " + p.nom + " » a été ajouté au stock.", "#2E8B57");
    signalerNouvellesAlertes(avant);
}

void GPetManager::modifierProduit()
{
    if (indexEnEdition < 0) return;
    Produit p;
    if (!lireFormulaire(p, false)) return;

    const QSet<QString> avant = nomsEnAlerte();

    // On garde l'historique ; une baisse de quantité compte comme une consommation
    const Produit &ancien = produits[indexEnEdition];
    p.consommation = ancien.consommation;
    p.demandeNonSatisfaite = ancien.demandeNonSatisfaite;
    if (p.quantite < ancien.quantite)
        p.consommation[QDate::currentDate()] += ancien.quantite - p.quantite;

    // Si le produit est renommé, ses commandes suivent
    for (Commande &c : commandes)
        if (c.produit == ancien.nom) c.produit = p.nom;

    produits[indexEnEdition] = p;
    viderFormulaire();
    rafraichir();
    afficherToast("check_green", "Produit modifié", "Les modifications ont été enregistrées.", "#2E8B57");
    signalerNouvellesAlertes(avant);
}

void GPetManager::supprimerProduit()
{
    // Produits cochés, sinon le produit chargé dans le formulaire
    QVector<int> aSupprimer;
    for (int l = 0; l < ui->tableStock->rowCount(); ++l) {
        QTableWidgetItem *chk = ui->tableStock->item(l, 0);
        if (chk && chk->checkState() == Qt::Checked)
            aSupprimer.append(chk->data(Qt::UserRole).toInt());
    }
    if (aSupprimer.isEmpty() && indexEnEdition >= 0)
        aSupprimer.append(indexEnEdition);

    if (aSupprimer.isEmpty()) {
        QMessageBox::information(this, "Supprimer",
            "Cochez un ou plusieurs produits, ou choisissez-en un avec le bouton Modifier (crayon).");
        return;
    }
    if (QMessageBox::question(this, "Supprimer",
            QString("Voulez-vous vraiment supprimer %1 produit(s) ?").arg(aSupprimer.size()))
        != QMessageBox::Yes)
        return;

    std::sort(aSupprimer.begin(), aSupprimer.end(), std::greater<int>());
    for (int idx : aSupprimer)
        produits.removeAt(idx);

    viderFormulaire();
    rafraichir();
}

// Sortie de stock (utilisation d'un produit).
// Si le produit est expiré, épuisé ou insuffisant, la substitution est proposée
// automatiquement au lieu de bloquer l'utilisateur.
void GPetManager::sortieDeStock(int index)
{
    if (index < 0 || index >= produits.size()) return;
    Produit &p = produits[index];

    if (etatProduit(p) == Expire || p.quantite == 0) {
        ouvrirSubstitution(index, 1);
        return;
    }

    bool ok = false;
    const int q = QInputDialog::getInt(this, "Sortie de stock",
        QString("Quantité nécessaire pour « %1 » (en stock : %2) :").arg(p.nom).arg(p.quantite),
        1, 1, 100000, 1, &ok);
    if (!ok) return;

    if (q > p.quantite) {           // stock insuffisant -> substitution
        ouvrirSubstitution(index, q);
        return;
    }

    const QSet<QString> avant = nomsEnAlerte();
    p.quantite -= q;
    p.consommation[QDate::currentDate()] += q;
    rafraichir();
    signalerNouvellesAlertes(avant);
}

// =====================================================================
//          MÉTIER : SUGGESTION ET SUBSTITUTION DE PRODUITS ALTERNATIFS
// =====================================================================

/*
 * Recherche des alternatives d'un produit.
 * Conditions obligatoires : même usage, espèce compatible, produit non expiré et en stock.
 * Score de compatibilité (sur 100) :
 *   espèce identique 30 (ou "Toutes" 20) + même catégorie 20 + stock suffisant 20
 *   + prix proche jusqu'à 15 + expiration lointaine jusqu'à 15
 */
QVector<Alternative> GPetManager::chercherAlternatives(int indexProduit, int besoin) const
{
    QVector<Alternative> resultat;
    if (indexProduit < 0 || indexProduit >= produits.size()) return resultat;
    const Produit &ref = produits[indexProduit];
    const QDate auj = QDate::currentDate();
    besoin = std::max(1, besoin);

    for (int i = 0; i < produits.size(); ++i) {
        if (i == indexProduit) continue;
        const Produit &p = produits[i];
        if (p.usage != ref.usage) continue;
        if (p.dateExpiration < auj || p.quantite == 0) continue;
        const bool memeEspece = (p.espece == ref.espece);
        const bool toutes = (p.espece == "Toutes" || ref.espece == "Toutes");
        if (!memeEspece && !toutes) continue;

        Alternative a;
        a.index = i;
        double score = 0;
        a.raisons << "Même usage (" + p.usage + ")";

        if (memeEspece) { score += 30; a.raisons << "Même espèce (" + p.espece + ")"; }
        else            { score += 20; a.raisons << "Convient à toutes les espèces"; }

        if (p.categorie == ref.categorie) { score += 20; a.raisons << "Même catégorie"; }

        if (p.quantite >= besoin) { score += 20; a.raisons << "Stock suffisant"; }
        else { score += 20.0 * p.quantite / besoin; a.raisons << QString("Stock partiel (%1)").arg(p.quantite); }

        if (ref.prix > 0) {
            const double ecart = std::abs(p.prix - ref.prix) / ref.prix;
            score += 15 * std::max(0.0, 1.0 - ecart);
            if (ecart <= 0.2)          a.raisons << "Prix proche";
            else if (p.prix < ref.prix) a.raisons << "Moins cher";
            else                        a.raisons << "Plus cher";
        }

        const qint64 jours = auj.daysTo(p.dateExpiration);
        if (jours >= 90)      { score += 15; a.raisons << "Expiration lointaine"; }
        else if (jours >= 30) { score += 8;  a.raisons << QString("Expire dans %1 j").arg(jours); }
        else                  { a.raisons << QString("Expire bientôt (%1 j)").arg(jours); }

        a.score = qRound(score);
        resultat.append(a);
    }
    std::sort(resultat.begin(), resultat.end(), [](const Alternative &x, const Alternative &y) {
        return x.score > y.score;
    });
    return resultat;
}

/*
 * Fenêtre de substitution : le système explique le problème, propose les alternatives
 * classées par score et l'utilisateur valide (ou refuse) la décision finale.
 */
void GPetManager::ouvrirSubstitution(int indexProduit, int quantiteDemandee, int alternativePreselectionnee)
{
    if (indexProduit < 0 || indexProduit >= produits.size()) return;
    const Produit ref = produits[indexProduit];
    const bool expire = ref.dateExpiration < QDate::currentDate();
    const int stockReel = expire ? 0 : ref.quantite;
    // Remplacement volontaire : le produit est disponible mais l'utilisateur choisit
    // une alternative depuis le panneau (par exemple pour préserver un stock bas)
    const bool volontaire = (stockReel > 0 && quantiteDemandee <= stockReel && alternativePreselectionnee >= 0);
    const int utilisable = volontaire ? 0 : stockReel;
    QString motif;
    if (expire)                       motif = "Produit expiré";
    else if (ref.quantite == 0)       motif = "Rupture de stock";
    else if (volontaire)              motif = (etatProduit(ref) == StockBas) ? "Stock bas préservé"
                                                                             : "Remplacement volontaire";
    else                              motif = "Stock insuffisant";

    QDialog dlg(this);
    dlg.setWindowTitle("Substitution de produit");
    dlg.setMinimumSize(980, 600);
    dlg.setStyleSheet(ui->centralwidget->styleSheet()
                      + "QDialog { background-color:#F4F8F8; } QLabel { color:#1E3A3A; }");

    QVBoxLayout *lay = new QVBoxLayout(&dlg);
    lay->setContentsMargins(22, 18, 22, 18);
    lay->setSpacing(12);

    QLabel *titre = new QLabel("Substitution de produit");
    titre->setStyleSheet("font-size:20px; font-weight:bold; color:#17363A;");
    lay->addWidget(titre);

    QLabel *probleme = new QLabel(QString("<b>%1</b> — %2. Le système propose des produits compatibles ; "
                                          "la décision finale vous appartient.")
                                      .arg(ref.nom.toHtmlEscaped(), motif.toLower()));
    probleme->setWordWrap(true);
    probleme->setStyleSheet("background:#FDECEC; border:1px solid #F5C2C2; border-radius:8px;"
                            "padding:10px; font-size:13px; color:#8B1E1E;");
    lay->addWidget(probleme);

    // Quantité demandée
    QHBoxLayout *ligneDemande = new QHBoxLayout;
    QLabel *lblDemande = new QLabel("Quantité demandée :");
    lblDemande->setStyleSheet("font-weight:bold;");
    QSpinBox *spinDemande = new QSpinBox;
    spinDemande->setRange(1, 100000);
    spinDemande->setValue(std::max(1, quantiteDemandee));
    spinDemande->setFixedWidth(120);
    QLabel *resume = new QLabel;
    ligneDemande->addWidget(lblDemande);
    ligneDemande->addWidget(spinDemande);
    ligneDemande->addSpacing(16);
    ligneDemande->addWidget(resume);
    ligneDemande->addStretch();
    lay->addLayout(ligneDemande);

    // Liste des alternatives
    QLabel *lblListe = new QLabel("Alternatives compatibles, classées par score de compatibilité :");
    lblListe->setStyleSheet("font-weight:bold; color:#17363A;");
    lay->addWidget(lblListe);

    QTableWidget *table = new QTableWidget;
    table->setStyleSheet(ui->tableStock->styleSheet());
    table->setColumnCount(6);
    table->setHorizontalHeaderLabels({"Produit", "Compatibilité", "Pourquoi ?", "Stock", "Expiration", "Prix (TND)"});
    table->verticalHeader()->setVisible(false);
    table->verticalHeader()->setDefaultSectionSize(42);
    table->horizontalHeader()->setFixedHeight(36);
    table->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    table->setSelectionBehavior(QAbstractItemView::SelectRows);
    table->setSelectionMode(QAbstractItemView::SingleSelection);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table->setFocusPolicy(Qt::NoFocus);
    table->setWordWrap(false);
    const QList<int> largeurs = {200, 130, 0, 70, 100, 90};
    for (int col = 0; col < largeurs.size(); ++col) {
        if (largeurs[col] == 0) {
            table->horizontalHeader()->setSectionResizeMode(col, QHeaderView::Stretch);
        } else {
            table->horizontalHeader()->setSectionResizeMode(col, QHeaderView::Fixed);
            table->setColumnWidth(col, largeurs[col]);
        }
    }
    lay->addWidget(table, 1);

    QLabel *aucune = new QLabel("Aucune alternative compatible (même usage, espèce compatible, en stock et non expirée).");
    aucune->setStyleSheet("color:#6B8080; font-size:13px; padding:20px;");
    aucune->setAlignment(Qt::AlignCenter);
    lay->addWidget(aucune, 1);

    // Quantité prise sur l'alternative
    QHBoxLayout *ligneAlt = new QHBoxLayout;
    QLabel *lblAlt = new QLabel("Quantité prise sur l'alternative :");
    lblAlt->setStyleSheet("font-weight:bold;");
    QSpinBox *spinAlt = new QSpinBox;
    spinAlt->setFixedWidth(120);
    QLabel *lblChoix = new QLabel;
    lblChoix->setStyleSheet("color:#2A8C86; font-weight:bold;");
    ligneAlt->addWidget(lblAlt);
    ligneAlt->addWidget(spinAlt);
    ligneAlt->addSpacing(16);
    ligneAlt->addWidget(lblChoix, 1);
    lay->addLayout(ligneAlt);

    // Boutons
    QHBoxLayout *ligneBoutons = new QHBoxLayout;
    QPushButton *btnCommander = new QPushButton;
    QPushButton *btnStockDispo = new QPushButton;
    QPushButton *btnAnnuler = new QPushButton("Annuler");
    QPushButton *btnValider = new QPushButton("  Valider la substitution");
    btnValider->setIcon(icone("check_white"));
    btnValider->setIconSize(QSize(16, 16));
    btnValider->setStyleSheet("QPushButton{background:#2A8C86;color:white;border:none;border-radius:6px;"
                              "padding:9px 18px;font-weight:bold;font-size:13px;}"
                              "QPushButton:hover{background:#237872;}"
                              "QPushButton:disabled{background:#B7D3D1;}");
    const QString styleContour = "QPushButton{background:white;color:%1;border:1px solid %1;border-radius:6px;"
                                 "padding:8px 14px;font-size:13px;}"
                                 "QPushButton:hover{background:#F0F4F4;}"
                                 "QPushButton:disabled{color:#A9B8B8;border-color:#D5E0E0;}";
    btnCommander->setStyleSheet(styleContour.arg("#2E7D32"));
    btnStockDispo->setStyleSheet(styleContour.arg("#2A8C86"));
    btnAnnuler->setStyleSheet(styleContour.arg("#6B8080"));
    for (QPushButton *b : {btnCommander, btnStockDispo, btnAnnuler, btnValider})
        b->setCursor(Qt::PointingHandCursor);

    const bool dejaCommande = commandeEnAttente(ref.nom);
    btnCommander->setText(dejaCommande ? "  Déjà commandé" : "  Commander « " + raccourcir(ref.nom, 22) + " »");
    btnCommander->setIcon(icone("cart_teal"));
    btnCommander->setIconSize(QSize(18, 18));
    btnCommander->setEnabled(!dejaCommande);
    btnStockDispo->setVisible(stockReel > 0);

    ligneBoutons->addWidget(btnCommander);
    ligneBoutons->addStretch();
    ligneBoutons->addWidget(btnAnnuler);
    ligneBoutons->addWidget(btnStockDispo);
    ligneBoutons->addWidget(btnValider);
    lay->addLayout(ligneBoutons);

    // ----- Logique de la fenêtre -----
    QVector<Alternative> alternatives;
    auto manquant = [&]() { return std::max(0, spinDemande->value() - utilisable); };

    auto majTexte = [&]() {
        const int l = table->currentRow();
        const int m = manquant();
        if (m == 0) {
            lblChoix->setText("Le stock disponible suffit : aucune substitution nécessaire.");
        } else if (l < 0 || l >= alternatives.size()) {
            lblChoix->setText("Sélectionnez une alternative dans la liste.");
        } else {
            const Produit &alt = produits[alternatives[l].index];
            const int pris = std::min(spinDemande->value(), utilisable);   // 0 si remplacement volontaire
            QString texte;
            if (pris > 0) texte = QString("%1 × « %2 » + ").arg(pris).arg(raccourcir(ref.nom, 22));
            texte += QString("%1 × « %2 »").arg(spinAlt->value()).arg(raccourcir(alt.nom, 26));
            const int reste = m - spinAlt->value();
            if (reste > 0) texte += QString("  (%1 non servi(s))").arg(reste);
            lblChoix->setText("→ " + texte);
        }
    };

    auto majChoix = [&]() {
        const int l = table->currentRow();
        const int m = manquant();
        const bool possible = (m > 0 && l >= 0 && l < alternatives.size());
        spinAlt->setEnabled(possible);
        btnValider->setEnabled(possible);
        if (possible) {
            const Produit &alt = produits[alternatives[l].index];
            spinAlt->blockSignals(true);
            spinAlt->setRange(1, alt.quantite);
            spinAlt->setValue(std::min(m, alt.quantite));
            spinAlt->blockSignals(false);
        }
        majTexte();
    };

    auto remplir = [&]() {
        int selection = alternativePreselectionnee;
        const int ligneActuelle = table->currentRow();
        if (ligneActuelle >= 0 && ligneActuelle < alternatives.size())
            selection = alternatives[ligneActuelle].index;

        const int m = manquant();
        resume->setText(QString("Disponible : <b>%1</b> &nbsp;·&nbsp; À remplacer : <b style='color:#D32F2F'>%2</b>")
                            .arg(utilisable).arg(m));
        btnStockDispo->setText(QString("Utiliser le stock disponible (%1)")
                                   .arg(std::min(stockReel, spinDemande->value())));

        alternatives = chercherAlternatives(indexProduit, std::max(1, m));
        table->blockSignals(true);
        table->setRowCount(0);
        table->setRowCount(alternatives.size());
        int ligneASelectionner = alternatives.isEmpty() ? -1 : 0;
        for (int l = 0; l < alternatives.size(); ++l) {
            const Alternative &a = alternatives[l];
            const Produit &p = produits[a.index];
            if (a.index == selection) ligneASelectionner = l;

            table->setItem(l, 0, new QTableWidgetItem(iconeCategorie(p.categorie), p.nom));
            const QString couleur = a.score >= 75 ? "#2E8B57" : (a.score >= 50 ? "#F5A623" : "#9AA9A9");
            table->setCellWidget(l, 1, creerBadge(QString("%1 %").arg(a.score), couleur, "white"));
            QTableWidgetItem *itRaisons = new QTableWidgetItem(a.raisons.join(" · "));
            itRaisons->setToolTip(a.raisons.join("\n"));
            table->setItem(l, 2, itRaisons);
            table->setItem(l, 3, new QTableWidgetItem(QString::number(p.quantite)));
            table->setItem(l, 4, new QTableWidgetItem(p.dateExpiration.toString("dd/MM/yyyy")));
            table->setItem(l, 5, new QTableWidgetItem(QString::number(p.prix, 'f', 3)));
        }
        table->blockSignals(false);
        table->setVisible(!alternatives.isEmpty());
        aucune->setVisible(alternatives.isEmpty());
        if (ligneASelectionner >= 0) table->selectRow(ligneASelectionner);
        majChoix();
    };

    int choix = 0;   // 1 = substitution, 2 = stock disponible seulement, 3 = commander
    connect(spinDemande, QOverload<int>::of(&QSpinBox::valueChanged), &dlg, [&](int) { remplir(); });
    connect(spinAlt, QOverload<int>::of(&QSpinBox::valueChanged), &dlg, [&](int) { majTexte(); });
    connect(table, &QTableWidget::currentCellChanged, &dlg, [&](int, int, int, int) { majChoix(); });
    connect(btnValider,    &QPushButton::clicked, &dlg, [&]() { choix = 1; dlg.accept(); });
    connect(btnStockDispo, &QPushButton::clicked, &dlg, [&]() { choix = 2; dlg.accept(); });
    connect(btnCommander,  &QPushButton::clicked, &dlg, [&]() { choix = 3; dlg.accept(); });
    connect(btnAnnuler,    &QPushButton::clicked, &dlg, &QDialog::reject);

    remplir();
    if (dlg.exec() != QDialog::Accepted || choix == 0) return;

    // ----- Application de la décision de l'utilisateur -----
    const QDate auj = QDate::currentDate();
    const int demande = spinDemande->value();
    // Substitution : on complète avec l'alternative. Stock seul : on sert ce qui est disponible.
    const int prisSurStock = std::min(demande, choix == 2 ? stockReel : utilisable);

    if (choix == 3) {
        if (creerCommande(indexProduit, analyserProduit(indexProduit).qteConseillee)) rafraichir();
        return;
    }

    const QSet<QString> avant = nomsEnAlerte();
    Produit &p = produits[indexProduit];
    if (prisSurStock > 0) {
        p.quantite -= prisSurStock;
        p.consommation[auj] += prisSurStock;
    }
    // La demande non servie par le produit d'origine est mémorisée (demande réelle)
    if (demande - prisSurStock > 0)
        p.demandeNonSatisfaite[auj] += demande - prisSurStock;

    if (choix == 1) {
        const int l = table->currentRow();
        const Alternative choisie = alternatives[l];
        const int qAlt = spinAlt->value();
        Produit &alt = produits[choisie.index];
        alt.quantite -= qAlt;
        alt.consommation[auj] += qAlt;

        Substitution s;
        s.date = QDateTime::currentDateTime();
        s.produitDemande = p.nom;
        s.alternative = alt.nom;
        s.quantite = qAlt;
        s.score = choisie.score;
        s.motif = motif;
        substitutions.append(s);

        const QString nomAlt = alt.nom;
        rafraichir();
        afficherToast("refresh_green", "Substitution validée",
                      QString("%1 × « %2 » utilisé(s) à la place de « %3 ».")
                          .arg(qAlt).arg(raccourcir(nomAlt, 24)).arg(raccourcir(ref.nom, 24)),
                      "#2E8B57");
    } else {
        rafraichir();
        afficherToast("sortie_teal", "Sortie de stock effectuée",
                      QString("%1 × « %2 » utilisé(s) (stock disponible).")
                          .arg(prisSurStock).arg(raccourcir(ref.nom, 26)),
                      "#2A8C86");
    }
    signalerNouvellesAlertes(avant);
}

void GPetManager::afficherSubstitutions()
{
    QTableWidget *t = ui->tableSubstitutionsStock;
    t->setRowCount(0);
    t->setRowCount(substitutions.size());

    for (int l = 0; l < substitutions.size(); ++l) {
        const Substitution &s = substitutions[substitutions.size() - 1 - l];   // plus récente en premier
        t->setItem(l, 0, new QTableWidgetItem(s.date.toString("dd/MM/yyyy HH:mm")));
        t->setItem(l, 1, new QTableWidgetItem(s.produitDemande));
        t->setItem(l, 2, new QTableWidgetItem(icone("refresh_teal"), s.alternative));
        t->setItem(l, 3, new QTableWidgetItem(QString::number(s.quantite)));
        const QString couleur = s.score >= 75 ? "#2E8B57" : (s.score >= 50 ? "#F5A623" : "#9AA9A9");
        t->setCellWidget(l, 4, creerBadge(QString("%1 %").arg(s.score), couleur, "white"));
        t->setItem(l, 5, new QTableWidgetItem(s.motif));
    }
    ajusterHauteurTableau(t, substitutions.size());
    t->setVisible(!substitutions.isEmpty());
    ui->lblAucuneSubstitutionStock->setVisible(substitutions.isEmpty());
}

// =====================================================================
//                         NOTIFICATIONS
// =====================================================================

void GPetManager::afficherNotifications()
{
    QMenu menu(this);
    menu.setStyleSheet("QMenu{background:white;border:1px solid #E0E8E8;padding:6px;}"
                       "QMenu::item{padding:7px 16px;color:#1E3A3A;}"
                       "QMenu::item:selected{background:#E6F2F1;}"
                       "QMenu::item:disabled{color:#6B8080;}"
                       "QMenu::separator{height:1px;background:#E0E8E8;margin:4px 8px;}");

    const QVector<int> liste = indicesAReapprovisionner();
    if (liste.isEmpty())
        menu.addAction(icone("check_green"), "Aucune alerte : le stock est sous contrôle")->setEnabled(false);

    for (int idx : liste) {
        const Produit &p = produits[idx];
        const Analyse a = analyserProduit(idx);
        const QString nomIcone = a.priorite == Critique ? "warning_red"
                               : (a.priorite == Urgente ? "warning_orange" : "info_teal");
        QAction *act = menu.addAction(icone(nomIcone), libellePriorite(a.priorite) + "  —  " + p.nom
                                      + "  (stock : " + QString::number(p.quantite)
                                      + ", rupture : " + textePrevision(a) + ")");
        connect(act, &QAction::triggered, this, [this, idx]() {
            changerPage(PAGE_STOCK);
            chargerDansFormulaire(idx);
        });
    }
    menu.addSeparator();
    QAction *ouvrir = menu.addAction(icone("clipboard_teal"), "Ouvrir le centre de réapprovisionnement");
    connect(ouvrir, &QAction::triggered, this, [this]() { changerPage(PAGE_REAPPRO); });

    menu.exec(ui->btnNotif->mapToGlobal(QPoint(0, ui->btnNotif->height())));
}

// =====================================================================
//                         EXPORT EXCEL
// =====================================================================

static bool ecrireCsv(QWidget *parent, const QString &nomParDefaut, const QString &contenu)
{
    const QString chemin = QFileDialog::getSaveFileName(parent, "Enregistrer pour Excel",
                               nomParDefaut, "Fichier Excel CSV (*.csv)");
    if (chemin.isEmpty()) return false;

    QFile fichier(chemin);
    if (!fichier.open(QIODevice::WriteOnly)) {
        QMessageBox::warning(parent, "Erreur", "Impossible de créer le fichier.");
        return false;
    }
    fichier.write("\xEF\xBB\xBF");   // BOM : Excel lit correctement les accents
    fichier.write(contenu.toUtf8());
    fichier.close();
    QMessageBox::information(parent, "Excel", "Le fichier a été généré :\n" + chemin);
    return true;
}

static QString nombreExcel(double v, int decimales)
{
    return QString::number(v, 'f', decimales).replace('.', ',');
}

void GPetManager::exporterExcel()
{
    const QVector<int> liste = indicesAReapprovisionner(true);
    if (liste.isEmpty()) {
        QMessageBox::information(this, "Excel", "Aucun produit à réapprovisionner.");
        return;
    }

    QString contenu = "Produit;Catégorie;Priorité;Stock;Seuil;Consommation moyenne / jour;"
                      "Rupture prévue;Quantité conseillée;Fournisseur;Prix unitaire (TND);"
                      "Montant estimé (TND);Commande en cours\n";
    for (int idx : liste) {
        const Produit &p = produits[idx];
        const Analyse a = analyserProduit(idx);
        QStringList col = {p.nom, p.categorie, libellePriorite(a.priorite),
                           QString::number(p.quantite), QString::number(p.seuil),
                           nombreExcel(a.consoMoyenne, 1), textePrevision(a),
                           QString::number(a.qteConseillee), p.fournisseur,
                           nombreExcel(p.prix, 3), nombreExcel(a.qteConseillee * p.prix, 3),
                           a.commandeEnCours ? "Oui" : "Non"};
        contenu += col.join(';') + "\n";
    }
    ecrireCsv(this, "suggestions_reapprovisionnement.csv", contenu);
}

void GPetManager::exporterCommandesExcel()
{
    if (commandes.isEmpty()) {
        QMessageBox::information(this, "Excel", "Aucune commande à exporter.");
        return;
    }
    QString contenu = "N°;Produit;Quantité;Fournisseur;Commandée le;Livraison;Montant (TND);Statut\n";
    for (const Commande &c : commandes) {
        QStringList col = {QString::number(c.numero), c.produit, QString::number(c.quantite),
                           c.fournisseur, c.dateCommande.toString("dd/MM/yyyy"),
                           c.dateLivraison.toString("dd/MM/yyyy"), nombreExcel(c.montant, 3), c.statut};
        contenu += col.join(';') + "\n";
    }
    ecrireCsv(this, "commandes_reapprovisionnement.csv", contenu);
}
