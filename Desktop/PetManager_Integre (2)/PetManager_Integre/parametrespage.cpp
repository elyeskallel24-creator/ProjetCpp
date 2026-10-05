#include "parametrespage.h"
#include "customdialog.h"
#include "databasemanager.h"

#include <QCheckBox>
#include <QComboBox>
#include <QDesktopServices>
#include <QFileInfo>
#include <QFrame>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QScrollArea>
#include <QSettings>
#include <QUrl>
#include <QVBoxLayout>

// ------------------------------------------------------------ lecture des réglages
QString ParametresPage::responsable()
{
    QSettings s("PetManager", "PetManager");
    return s.value("general/responsable").toString();
}

QString ParametresPage::nomCentre()
{
    QSettings s("PetManager", "PetManager");
    return s.value("general/nomCentre").toString();
}

QString ParametresPage::pageDemarrage()
{
    QSettings s("PetManager", "PetManager");
    return s.value("general/pageDemarrage", "Accueil").toString();
}

bool ParametresPage::alerteSanteAnimaux()
{
    QSettings s("PetManager", "PetManager");
    return s.value("animaux/alerteSante", true).toBool();
}

// ------------------------------------------------------------ construction
ParametresPage::ParametresPage(QWidget *parent) : QWidget(parent)
{
    setObjectName("pageParametres");
    setAttribute(Qt::WA_StyledBackground, true);

    auto *racine = new QVBoxLayout(this);
    racine->setContentsMargins(24, 20, 24, 20);
    racine->setSpacing(16);

    // ---------------------------------------------------------- en-tête
    auto *entete = new QHBoxLayout;
    entete->setSpacing(14);
    auto *icone = new QLabel(QString::fromUtf8("⚙️"));
    icone->setObjectName("paIcone");
    icone->setAlignment(Qt::AlignCenter);
    entete->addWidget(icone);
    auto *textes = new QVBoxLayout;
    textes->setSpacing(2);
    auto *titre = new QLabel(QString::fromUtf8("Paramètres"));
    titre->setObjectName("paTitre");
    auto *sousTitre = new QLabel(QString::fromUtf8("Personnalisez l'application Pet Manager"));
    sousTitre->setObjectName("paSousTitre");
    textes->addWidget(titre);
    textes->addWidget(sousTitre);
    entete->addLayout(textes);
    entete->addStretch();
    racine->addLayout(entete);

    // ---------------------------------------------------------- cartes (dans une zone défilante)
    auto *zone = new QScrollArea;
    zone->setWidgetResizable(true);
    zone->setFrameShape(QFrame::NoFrame);
    auto *contenuZone = new QWidget;
    auto *grille = new QGridLayout(contenuZone);
    grille->setContentsMargins(0, 0, 8, 0);
    grille->setHorizontalSpacing(14);
    grille->setVerticalSpacing(14);
    grille->setColumnStretch(0, 1);
    grille->setColumnStretch(1, 1);

    auto ajouterChamp = [](QVBoxLayout *lay, const QString &texte, QWidget *champ) {
        auto *l = new QLabel(texte);
        l->setObjectName("paLabel");
        lay->addWidget(l);
        lay->addWidget(champ);
    };

    // Profil
    QVBoxLayout *lProfil = nullptr;
    QFrame *cProfil = creerCarte(QString::fromUtf8("👤  Profil"), lProfil);
    m_responsable = new QLineEdit;
    m_responsable->setPlaceholderText("Ex : Dr. Nessma Tounsi");
    m_responsable->setFixedHeight(34);
    ajouterChamp(lProfil, "Nom du responsable", m_responsable);
    m_centre = new QLineEdit;
    m_centre->setPlaceholderText(QString::fromUtf8("Ex : Clinique vétérinaire de Tunis"));
    m_centre->setFixedHeight(34);
    ajouterChamp(lProfil, "Nom du centre", m_centre);
    grille->addWidget(cProfil, 0, 0);

    // Démarrage
    QVBoxLayout *lDemarrage = nullptr;
    QFrame *cDemarrage = creerCarte(QString::fromUtf8("🚀  Démarrage"), lDemarrage);
    m_demarrage = new QComboBox;
    m_demarrage->addItems({"Accueil", "Animaux", "Stock", "Fournisseurs"});
    m_demarrage->setFixedHeight(34);
    ajouterChamp(lDemarrage, "Page affichée au lancement", m_demarrage);
    grille->addWidget(cDemarrage, 0, 1);

    // Alertes
    QVBoxLayout *lAlertes = nullptr;
    QFrame *cAlertes = creerCarte(QString::fromUtf8("🔔  Alertes"), lAlertes);
    m_alerteSante = new QCheckBox(QString::fromUtf8("Afficher l'alerte santé à la première ouverture de la page Animaux"));
    lAlertes->addWidget(m_alerteSante);
    grille->addWidget(cAlertes, 1, 0);

    // Données
    QVBoxLayout *lDonnees = nullptr;
    QFrame *cDonnees = creerCarte(QString::fromUtf8("🗄️  Données"), lDonnees);
    auto *libelleBase = new QLabel("Base de données (fournisseurs)");
    libelleBase->setObjectName("paLabel");
    lDonnees->addWidget(libelleBase);
    auto *cheminBase = new QLabel(DatabaseManager::instance().db().databaseName());
    cheminBase->setObjectName("paTexte");
    cheminBase->setWordWrap(true);
    cheminBase->setTextInteractionFlags(Qt::TextSelectableByMouse);
    lDonnees->addWidget(cheminBase);
    auto *btnDossier = new QPushButton(QString::fromUtf8("📂  Ouvrir le dossier"));
    btnDossier->setObjectName("paSecondaire");
    btnDossier->setCursor(Qt::PointingHandCursor);
    connect(btnDossier, &QPushButton::clicked, this, &ParametresPage::ouvrirDossierBase);
    lDonnees->addWidget(btnDossier, 0, Qt::AlignLeft);
    grille->addWidget(cDonnees, 1, 1);

    // À propos
    QVBoxLayout *lApropos = nullptr;
    QFrame *cApropos = creerCarte(QString::fromUtf8("ℹ️  À propos"), lApropos);
    auto *apropos = new QLabel(
        QString::fromUtf8("<b>Pet Manager</b> — gestion d'un centre vétérinaire<br>"
                          "Modules : Animaux · Stock · Fournisseurs<br>"
                          "Version de Qt : %1").arg(QString::fromLatin1(qVersion())));
    apropos->setObjectName("paTexte");
    apropos->setTextFormat(Qt::RichText);
    apropos->setWordWrap(true);
    lApropos->addWidget(apropos);
    grille->addWidget(cApropos, 2, 0, 1, 2);

    grille->setRowStretch(3, 1);
    zone->setWidget(contenuZone);
    racine->addWidget(zone, 1);

    // ---------------------------------------------------------- boutons du bas
    auto *boutons = new QHBoxLayout;
    boutons->setSpacing(10);
    boutons->addStretch();
    auto *btnReset = new QPushButton(QString::fromUtf8("Réinitialiser"));
    btnReset->setObjectName("paSecondaire");
    btnReset->setCursor(Qt::PointingHandCursor);
    connect(btnReset, &QPushButton::clicked, this, &ParametresPage::reinitialiser);
    boutons->addWidget(btnReset);
    auto *btnSave = new QPushButton(QString::fromUtf8("💾  Enregistrer"));
    btnSave->setObjectName("paPrincipal");
    btnSave->setCursor(Qt::PointingHandCursor);
    connect(btnSave, &QPushButton::clicked, this, &ParametresPage::enregistrer);
    boutons->addWidget(btnSave);
    racine->addLayout(boutons);

    // ---------------------------------------------------------- style (limité à cette page)
    setStyleSheet(R"(
#pageParametres { background:#F4F8F8; }
#paIcone { font-size:26px; background:#E6F2F1; border-radius:24px;
           min-width:48px; max-width:48px; min-height:48px; max-height:48px; }
#paTitre { font-size:22px; font-weight:bold; color:#2D3436; }
#paSousTitre { font-size:13px; color:#7B8A8A; }
#paCarte { background:#FFFFFF; border:1px solid #E3E8E7; border-radius:12px; }
#paCarteTitre { font-size:15px; font-weight:bold; color:#2A8C82; }
#paLabel { font-size:12px; font-weight:bold; color:#4E6B68; }
#paTexte { font-size:13px; color:#4E6B68; }
QCheckBox { font-size:13px; color:#2D3436; spacing:8px; }
QPushButton#paPrincipal { background:#2A8C82; color:#FFFFFF; border:none; border-radius:8px;
                          min-height:36px; padding:0 22px; font-size:13px; font-weight:bold; }
QPushButton#paPrincipal:hover { background:#23766D; }
QPushButton#paSecondaire { background:#FFFFFF; color:#2A8C82; border:1.5px solid #2A8C82; border-radius:8px;
                           min-height:34px; padding:0 18px; font-size:13px; font-weight:bold; }
QPushButton#paSecondaire:hover { background:#E6F2F1; }
)");

    chargerDansFormulaire();
}

QFrame *ParametresPage::creerCarte(const QString &titre, QVBoxLayout *&contenu)
{
    auto *carte = new QFrame;
    carte->setObjectName("paCarte");
    contenu = new QVBoxLayout(carte);
    contenu->setContentsMargins(18, 14, 18, 16);
    contenu->setSpacing(8);
    auto *t = new QLabel(titre);
    t->setObjectName("paCarteTitre");
    contenu->addWidget(t);
    return carte;
}

void ParametresPage::chargerDansFormulaire()
{
    m_responsable->setText(responsable());
    m_centre->setText(nomCentre());
    const int i = m_demarrage->findText(pageDemarrage());
    m_demarrage->setCurrentIndex(i >= 0 ? i : 0);
    m_alerteSante->setChecked(alerteSanteAnimaux());
}

// ------------------------------------------------------------ actions
void ParametresPage::enregistrer()
{
    QSettings s("PetManager", "PetManager");
    s.setValue("general/responsable", m_responsable->text().trimmed());
    s.setValue("general/nomCentre", m_centre->text().trimmed());
    s.setValue("general/pageDemarrage", m_demarrage->currentText());
    s.setValue("animaux/alerteSante", m_alerteSante->isChecked());
    s.sync();

    emit reglagesEnregistres();
    CustomDialog::success(window(), QString::fromUtf8("Paramètres"),
                          QString::fromUtf8("Vos paramètres ont été enregistrés.\n"
                                            "La page de démarrage sera appliquée au prochain lancement."));
}

void ParametresPage::reinitialiser()
{
    if (!CustomDialog::confirm(window(), QString::fromUtf8("Réinitialiser"),
                               QString::fromUtf8("Rétablir tous les paramètres par défaut ?"),
                               QString::fromUtf8("Réinitialiser"), true))
        return;

    QSettings s("PetManager", "PetManager");
    s.remove("general");
    s.remove("animaux");
    s.sync();

    chargerDansFormulaire();
    emit reglagesEnregistres();
}

void ParametresPage::ouvrirDossierBase()
{
    const QString chemin = DatabaseManager::instance().db().databaseName();
    QDesktopServices::openUrl(QUrl::fromLocalFile(QFileInfo(chemin).absolutePath()));
}
