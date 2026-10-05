#include "accueilpage.h"
#include "parametrespage.h"

#include <QDate>
#include <QFrame>
#include <QHBoxLayout>
#include <QLabel>
#include <QLayoutItem>
#include <QLocale>
#include <QPushButton>
#include <QVBoxLayout>

AccueilPage::AccueilPage(QWidget *parent) : QWidget(parent)
{
    setObjectName("pageAccueil");
    setAttribute(Qt::WA_StyledBackground, true);

    auto *racine = new QVBoxLayout(this);
    racine->setContentsMargins(24, 20, 24, 20);
    racine->setSpacing(16);

    // ---------------------------------------------------------- en-tête
    auto *entete = new QHBoxLayout;
    entete->setSpacing(14);
    auto *icone = new QLabel(QString::fromUtf8("🏠"));
    icone->setObjectName("acIcone");
    icone->setAlignment(Qt::AlignCenter);
    entete->addWidget(icone);

    auto *textes = new QVBoxLayout;
    textes->setSpacing(2);
    auto *titre = new QLabel("Accueil");
    titre->setObjectName("acTitre");
    m_salutation = new QLabel;
    m_salutation->setObjectName("acSousTitre");
    textes->addWidget(titre);
    textes->addWidget(m_salutation);
    entete->addLayout(textes);
    entete->addStretch();
    racine->addLayout(entete);

    // ---------------------------------------------------------- 4 indicateurs
    auto *kpis = new QHBoxLayout;
    kpis->setSpacing(14);
    const QStringList icones = {QString::fromUtf8("🐾"), QString::fromUtf8("📦"),
                                QString::fromUtf8("⚠️"), QString::fromUtf8("🚚")};
    const QStringList titres = {"Animaux", "Produits en stock", "Alertes stock", "Fournisseurs actifs"};
    for (int i = 0; i < 4; ++i)
        kpis->addWidget(creerKpi(icones[i], titres[i], m_valeur[i], m_detail[i]));
    racine->addLayout(kpis);

    // ---------------------------------------------------------- accès rapide
    auto *acces = new QFrame;
    acces->setObjectName("acCarte");
    auto *lAcces = new QVBoxLayout(acces);
    lAcces->setContentsMargins(18, 14, 18, 16);
    lAcces->setSpacing(10);
    auto *tAcces = new QLabel("Accès rapide");
    tAcces->setObjectName("acCarteTitre");
    lAcces->addWidget(tAcces);

    auto *rangee = new QHBoxLayout;
    rangee->setSpacing(10);
    const QStringList textesBoutons = {QString::fromUtf8("🐾  Animaux"), QString::fromUtf8("📦  Stock"),
                                       QString::fromUtf8("🚚  Fournisseurs"), QString::fromUtf8("⚙️  Paramètres")};
    const int modules[4] = {Animaux, Stock, Fournisseurs, Parametres};
    for (int i = 0; i < 4; ++i) {
        auto *b = new QPushButton(textesBoutons[i]);
        b->setObjectName("acAcces");
        b->setCursor(Qt::PointingHandCursor);
        const int module = modules[i];
        connect(b, &QPushButton::clicked, this, [this, module]() { emit naviguerVers(module); });
        rangee->addWidget(b);
    }
    lAcces->addLayout(rangee);
    racine->addWidget(acces);

    // ---------------------------------------------------------- bas : alertes + résumé
    auto *bas = new QHBoxLayout;
    bas->setSpacing(14);

    auto *carteAlertes = new QFrame;
    carteAlertes->setObjectName("acCarte");
    auto *lAlertes = new QVBoxLayout(carteAlertes);
    lAlertes->setContentsMargins(18, 14, 18, 16);
    lAlertes->setSpacing(8);
    auto *tAlertes = new QLabel(QString::fromUtf8("⚠️  À surveiller"));
    tAlertes->setObjectName("acCarteTitre");
    lAlertes->addWidget(tAlertes);
    m_listeAlertes = new QVBoxLayout;
    m_listeAlertes->setSpacing(0);
    lAlertes->addLayout(m_listeAlertes);
    lAlertes->addStretch();
    bas->addWidget(carteAlertes, 3);

    auto *carteResume = new QFrame;
    carteResume->setObjectName("acCarte");
    auto *lResume = new QVBoxLayout(carteResume);
    lResume->setContentsMargins(18, 14, 18, 16);
    lResume->setSpacing(8);
    auto *tResume = new QLabel(QString::fromUtf8("📋  Résumé"));
    tResume->setObjectName("acCarteTitre");
    lResume->addWidget(tResume);
    m_resume = new QLabel;
    m_resume->setObjectName("acResume");
    m_resume->setTextFormat(Qt::RichText);
    m_resume->setWordWrap(true);
    m_resume->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    lResume->addWidget(m_resume);
    lResume->addStretch();
    bas->addWidget(carteResume, 2);

    racine->addLayout(bas, 1);

    // ---------------------------------------------------------- style (limité à cette page)
    setStyleSheet(R"(
#pageAccueil { background:#F4F8F8; }
#acIcone { font-size:26px; background:#E6F2F1; border-radius:24px;
           min-width:48px; max-width:48px; min-height:48px; max-height:48px; }
#acTitre { font-size:22px; font-weight:bold; color:#2D3436; }
#acSousTitre { font-size:13px; color:#7B8A8A; }
#acKpi { background:#FFFFFF; border:1px solid #2A8C82; border-radius:12px; }
#acKpiIcone { font-size:26px; }
#acKpiTitre { font-size:12px; color:#4E6B68; }
#acKpiValeur { font-size:28px; font-weight:bold; color:#2A8C82; }
#acKpiDetail { font-size:11px; color:#7B8A8A; }
#acCarte { background:#FFFFFF; border:1px solid #E3E8E7; border-radius:12px; }
#acCarteTitre { font-size:15px; font-weight:bold; color:#2D3436; }
QPushButton#acAcces { background:#FFFFFF; color:#2A8C82; border:1px solid #DADDDC; border-radius:8px;
                      padding:12px 18px; font-size:13px; font-weight:bold; }
QPushButton#acAcces:hover { background:#E6F2F1; border:1px solid #2A8C82; }
#acLigne { font-size:13px; color:#2D3436; padding:7px 0; border-bottom:1px solid #EDF1F0; }
#acVide { font-size:13px; color:#2A8C82; padding:6px 0; }
#acResume { font-size:13px; color:#4E6B68; }
)");

    actualiserSalutation();
    setDonnees(AccueilDonnees());
}

QFrame *AccueilPage::creerKpi(const QString &icone, const QString &titre, QLabel *&valeur, QLabel *&detail)
{
    auto *carte = new QFrame;
    carte->setObjectName("acKpi");
    auto *h = new QHBoxLayout(carte);
    h->setContentsMargins(16, 14, 16, 14);
    h->setSpacing(12);

    auto *ic = new QLabel(icone);
    ic->setObjectName("acKpiIcone");
    ic->setAlignment(Qt::AlignCenter);
    ic->setFixedWidth(40);
    h->addWidget(ic);

    auto *v = new QVBoxLayout;
    v->setSpacing(0);
    auto *t = new QLabel(titre);
    t->setObjectName("acKpiTitre");
    valeur = new QLabel("0");
    valeur->setObjectName("acKpiValeur");
    detail = new QLabel;
    detail->setObjectName("acKpiDetail");
    detail->setWordWrap(true);
    v->addWidget(t);
    v->addWidget(valeur);
    v->addWidget(detail);
    h->addLayout(v, 1);
    return carte;
}

void AccueilPage::actualiserSalutation()
{
    const QString responsable = ParametresPage::responsable().trimmed();
    const QString centre = ParametresPage::nomCentre().trimmed();
    const QString date = QLocale(QLocale::French).toString(QDate::currentDate(), "dddd d MMMM yyyy");

    QString texte = responsable.isEmpty() ? QString::fromUtf8("Bonjour 👋")
                                          : QString::fromUtf8("Bonjour ") + responsable + QString::fromUtf8(" 👋");
    texte += QString::fromUtf8("  —  ") + date;
    if (!centre.isEmpty())
        texte += QString::fromUtf8("  ·  ") + centre;
    m_salutation->setText(texte);
}

void AccueilPage::setDonnees(const AccueilDonnees &d)
{
    actualiserSalutation();

    // Indicateurs
    m_valeur[0]->setText(QString::number(d.animaux));
    m_detail[0]->setText(QString("%1 sous surveillance").arg(d.animauxSurveillance));

    m_valeur[1]->setText(QString::number(d.produits));
    m_detail[1]->setText(QString("%1 commande(s) en attente").arg(d.commandesEnAttente));

    m_valeur[2]->setText(QString::number(d.ruptures + d.stockBas + d.expires));
    m_detail[2]->setText(QString("%1 rupture · %2 stock bas · %3 expiré")
                             .arg(d.ruptures).arg(d.stockBas).arg(d.expires));

    m_valeur[3]->setText(QString::number(d.fournisseursActifs));
    m_detail[3]->setText(QString("sur %1 fournisseur(s)").arg(d.fournisseurs));

    // Liste "À surveiller" : on vide, puis on reconstruit
    while (QLayoutItem *item = m_listeAlertes->takeAt(0)) {
        delete item->widget();
        delete item;
    }
    if (d.alertes.isEmpty()) {
        auto *vide = new QLabel(QString::fromUtf8("✅  Rien à signaler, tout va bien."));
        vide->setObjectName("acVide");
        m_listeAlertes->addWidget(vide);
    } else {
        const int maxLignes = 8;
        for (int i = 0; i < d.alertes.size() && i < maxLignes; ++i) {
            auto *ligne = new QLabel(d.alertes[i]);
            ligne->setObjectName("acLigne");
            ligne->setWordWrap(true);
            m_listeAlertes->addWidget(ligne);
        }
        if (d.alertes.size() > maxLignes) {
            auto *reste = new QLabel(QString("… et %1 autre(s)").arg(d.alertes.size() - maxLignes));
            reste->setObjectName("acVide");
            m_listeAlertes->addWidget(reste);
        }
    }

    // Résumé
    const QString resume =
        QString::fromUtf8("<p><b>🐾 Animaux</b><br>%1 chien(s) · %2 chat(s) · %3 lapin(s)<br>%4 sous surveillance</p>")
            .arg(d.chiens).arg(d.chats).arg(d.lapins).arg(d.animauxSurveillance) +
        QString::fromUtf8("<p><b>📦 Stock</b><br>%1 produit(s) · %2 commande(s) en attente</p>")
            .arg(d.produits).arg(d.commandesEnAttente) +
        QString::fromUtf8("<p><b>🚚 Fournisseurs</b><br>%1 au total · %2 actif(s)</p>")
            .arg(d.fournisseurs).arg(d.fournisseursActifs);
    m_resume->setText(resume);
}
