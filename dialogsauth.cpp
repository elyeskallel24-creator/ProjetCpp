#include "dialogsauth.h"
#include "authmanager.h"
#include "customdialog.h"
#include "langue.h"

#include <QComboBox>
#include <QDialog>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QRandomGenerator>
#include <QVBoxLayout>

namespace {

const char *STYLE_DIALOGUE = R"(
QDialog { background:#FFFFFF; }
#dlgTitre { font-size:18px; font-weight:bold; color:#2A8C82; }
#dlgTexte { font-size:13px; color:#4E6B68; }
#dlgLabel { font-size:12px; font-weight:bold; color:#4E6B68; }
#dlgCode { background:#E6F2F1; color:#1E635B; border-radius:8px; padding:8px 12px;
           font-size:14px; font-weight:bold; }
QPushButton#dlgPrincipal { background:#2A8C82; color:#FFFFFF; border:none; border-radius:8px;
                           min-height:36px; padding:0 20px; font-size:13px; font-weight:bold; }
QPushButton#dlgPrincipal:hover { background:#23766D; }
QPushButton#dlgSecondaire { background:#FFFFFF; color:#2A8C82; border:1.5px solid #2A8C82; border-radius:8px;
                            min-height:34px; padding:0 16px; font-size:13px; font-weight:bold; }
QPushButton#dlgSecondaire:hover { background:#E6F2F1; }
)";

QLabel *creerLabel(const QString &texte, const char *nom)
{
    auto *l = new QLabel(texte);
    l->setObjectName(nom);
    l->setWordWrap(true);
    return l;
}

QLineEdit *creerChampMotDePasse()
{
    auto *e = new QLineEdit;
    e->setEchoMode(QLineEdit::Password);
    e->setFixedHeight(34);
    return e;
}

QPushButton *creerBouton(const QString &texte, const char *nom)
{
    auto *b = new QPushButton(texte);
    b->setObjectName(nom);
    b->setCursor(Qt::PointingHandCursor);
    return b;
}

} // namespace

// =====================================================================
//                         Mot de passe oublié
// =====================================================================
void DialogsAuth::motDePasseOublie(QWidget *parent)
{
    QDialog d(parent);
    d.setWindowTitle(Langue::t("oubli_titre"));
    d.setModal(true);
    d.setMinimumWidth(430);
    d.setLayoutDirection(Langue::direction());
    d.setStyleSheet(STYLE_DIALOGUE);

    auto *lay = new QVBoxLayout(&d);
    lay->setContentsMargins(24, 22, 24, 20);
    lay->setSpacing(8);

    lay->addWidget(creerLabel(QString::fromUtf8("🔑  ") + Langue::t("oubli_titre"), "dlgTitre"));
    lay->addWidget(creerLabel(Langue::t("oubli_sous"), "dlgTexte"));
    lay->addSpacing(4);

    // Choix du compte + envoi du code
    lay->addWidget(creerLabel(Langue::t("login_user"), "dlgLabel"));
    auto *rangeeCompte = new QHBoxLayout;
    auto *choixCompte = new QComboBox;
    choixCompte->setFixedHeight(34);
    for (const QString &id : AuthManager::utilisateurs())
        choixCompte->addItem(AuthManager::emoji(id) + "  " + AuthManager::nomAffiche(id), id);
    auto *btnEnvoyer = creerBouton(Langue::t("oubli_envoyer"), "dlgSecondaire");
    rangeeCompte->addWidget(choixCompte, 1);
    rangeeCompte->addWidget(btnEnvoyer);
    lay->addLayout(rangeeCompte);

    auto *infoCode = creerLabel(QString(), "dlgCode");
    infoCode->hide();
    lay->addWidget(infoCode);

    // Code + nouveau mot de passe
    lay->addWidget(creerLabel(Langue::t("oubli_code"), "dlgLabel"));
    auto *champCode = new QLineEdit;
    champCode->setMaxLength(4);
    champCode->setFixedHeight(34);
    lay->addWidget(champCode);

    lay->addWidget(creerLabel(Langue::t("oubli_nouveau"), "dlgLabel"));
    auto *champNouveau = creerChampMotDePasse();
    lay->addWidget(champNouveau);

    lay->addWidget(creerLabel(Langue::t("oubli_confirmer"), "dlgLabel"));
    auto *champConfirmer = creerChampMotDePasse();
    lay->addWidget(champConfirmer);

    lay->addSpacing(6);
    auto *boutons = new QHBoxLayout;
    boutons->addStretch();
    auto *btnAnnuler = creerBouton(Langue::t("btn_annuler"), "dlgSecondaire");
    auto *btnValider = creerBouton(Langue::t("oubli_valider"), "dlgPrincipal");
    boutons->addWidget(btnAnnuler);
    boutons->addWidget(btnValider);
    lay->addLayout(boutons);

    QString codeAttendu;

    QObject::connect(btnEnvoyer, &QPushButton::clicked, &d, [&]() {
        codeAttendu = QString::number(QRandomGenerator::global()->bounded(1000, 10000));
        infoCode->setText(Langue::t("oubli_code_envoye").arg(codeAttendu));
        infoCode->show();
        champCode->setFocus();
    });
    QObject::connect(btnAnnuler, &QPushButton::clicked, &d, &QDialog::reject);
    QObject::connect(btnValider, &QPushButton::clicked, &d, [&]() {
        const QString titreErreur = Langue::t("titre_erreur");
        if (codeAttendu.isEmpty()) {
            CustomDialog::error(&d, titreErreur, Langue::t("oubli_pas_code"));
            return;
        }
        if (champCode->text().trimmed() != codeAttendu) {
            CustomDialog::error(&d, titreErreur, Langue::t("oubli_err_code"));
            return;
        }
        if (champNouveau->text().size() < 4) {
            CustomDialog::error(&d, titreErreur, Langue::t("oubli_err_court"));
            return;
        }
        if (champNouveau->text() != champConfirmer->text()) {
            CustomDialog::error(&d, titreErreur, Langue::t("oubli_err_diff"));
            return;
        }
        AuthManager::definirMotDePasse(choixCompte->currentData().toString(), champNouveau->text());
        CustomDialog::success(&d, Langue::t("titre_succes"), Langue::t("oubli_ok"));
        d.accept();
    });

    d.exec();
}

// =====================================================================
//                       Changer mon mot de passe
// =====================================================================
void DialogsAuth::changerMotDePasse(QWidget *parent, const QString &utilisateur)
{
    QDialog d(parent);
    d.setWindowTitle(Langue::t("mdp_titre"));
    d.setModal(true);
    d.setMinimumWidth(400);
    d.setLayoutDirection(Langue::direction());
    d.setStyleSheet(STYLE_DIALOGUE);

    auto *lay = new QVBoxLayout(&d);
    lay->setContentsMargins(24, 22, 24, 20);
    lay->setSpacing(8);

    lay->addWidget(creerLabel(AuthManager::emoji(utilisateur) + "  " + Langue::t("mdp_titre"), "dlgTitre"));
    lay->addSpacing(4);

    lay->addWidget(creerLabel(Langue::t("mdp_actuel"), "dlgLabel"));
    auto *champActuel = creerChampMotDePasse();
    lay->addWidget(champActuel);

    lay->addWidget(creerLabel(Langue::t("oubli_nouveau"), "dlgLabel"));
    auto *champNouveau = creerChampMotDePasse();
    lay->addWidget(champNouveau);

    lay->addWidget(creerLabel(Langue::t("oubli_confirmer"), "dlgLabel"));
    auto *champConfirmer = creerChampMotDePasse();
    lay->addWidget(champConfirmer);

    lay->addSpacing(6);
    auto *boutons = new QHBoxLayout;
    boutons->addStretch();
    auto *btnAnnuler = creerBouton(Langue::t("btn_annuler"), "dlgSecondaire");
    auto *btnValider = creerBouton(Langue::t("enreg"), "dlgPrincipal");
    boutons->addWidget(btnAnnuler);
    boutons->addWidget(btnValider);
    lay->addLayout(boutons);

    QObject::connect(btnAnnuler, &QPushButton::clicked, &d, &QDialog::reject);
    QObject::connect(btnValider, &QPushButton::clicked, &d, [&]() {
        const QString titreErreur = Langue::t("titre_erreur");
        if (!AuthManager::verifier(utilisateur, champActuel->text())) {
            CustomDialog::error(&d, titreErreur, Langue::t("mdp_err_actuel"));
            return;
        }
        if (champNouveau->text().size() < 4) {
            CustomDialog::error(&d, titreErreur, Langue::t("oubli_err_court"));
            return;
        }
        if (champNouveau->text() != champConfirmer->text()) {
            CustomDialog::error(&d, titreErreur, Langue::t("oubli_err_diff"));
            return;
        }
        AuthManager::definirMotDePasse(utilisateur, champNouveau->text());
        CustomDialog::success(&d, Langue::t("titre_succes"), Langue::t("mdp_ok"));
        d.accept();
    });

    d.exec();
}
