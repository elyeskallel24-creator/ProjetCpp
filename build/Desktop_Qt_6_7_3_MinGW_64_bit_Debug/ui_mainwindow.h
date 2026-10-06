/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *pageLogin;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QFrame *frame;
    QVBoxLayout *verticalLayout_3;
    QLabel *labelTitle;
    QLineEdit *txtLoginUsername;
    QLineEdit *txtLoginPassword;
    QPushButton *btnLogin;
    QSpacerItem *verticalSpacer_2;
    QWidget *pageCRUD;
    QHBoxLayout *horizontalLayout;
    QFrame *frameSidebar;
    QVBoxLayout *verticalLayout_4;
    QLabel *labelLogo;
    QPushButton *btnAccueil;
    QPushButton *btnAnimaux;
    QPushButton *btnRdv;
    QPushButton *btnStock;
    QPushButton *btnCommandes;
    QPushButton *btnFournisseurs;
    QPushButton *btnEmployes;
    QPushButton *btnParametres;
    QSpacerItem *verticalSpacer_3;
    QPushButton *btnLogout;
    QFrame *frameContent;
    QVBoxLayout *verticalLayout_5;
    QFrame *frameHeader;
    QHBoxLayout *horizontalLayoutHeader;
    QLabel *labelTitleIcon;
    QLabel *labelPageTitle;
    QSpacerItem *horizontalSpacer;
    QFrame *frameBellContainer;
    QGridLayout *gridLayoutBell;
    QLabel *labelBell;
    QLabel *labelNotifBadge;
    QLabel *labelAvatar;
    QVBoxLayout *verticalLayoutUser;
    QLabel *labelUserName;
    QLabel *labelUserRole;
    QTabWidget *tabWidget;
    QWidget *tabListe;
    QVBoxLayout *verticalLayout_tabListe;
    QFrame *frameToolbar;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *txtRecherche;
    QComboBox *cmbTri;
    QTableWidget *tblEmployes;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btnAjouter;
    QPushButton *btnModifier;
    QPushButton *btnSupprimer;
    QPushButton *btnExporterPDF;
    QPushButton *btnExporterExcel;
    QWidget *tabStats;
    QVBoxLayout *verticalLayout_tabStats;
    QFrame *frameChartPoste;
    QVBoxLayout *layoutChartPoste;
    QFrame *frameChartStatut;
    QVBoxLayout *layoutChartStatut;
    QWidget *tabPlanning;
    QVBoxLayout *verticalLayout_tabPlanning;
    QPushButton *btnGenererPlanning;
    QTableWidget *tblPlanning;
    QWidget *tabCompetences;
    QVBoxLayout *verticalLayout_tabCompetences;
    QPushButton *btnVerifierAlertes;
    QTableWidget *tblCompetences;
    QFrame *frameForm;
    QVBoxLayout *verticalLayout_6;
    QLabel *labelFormTitle;
    QLineEdit *txtNom;
    QLineEdit *txtPrenom;
    QLineEdit *txtEmail;
    QLineEdit *txtTelephone;
    QComboBox *cmbPoste;
    QDoubleSpinBox *spnSalaire;
    QDateEdit *dateEmbauche;
    QComboBox *cmbStatut;
    QPushButton *btnEnregistrer;
    QPushButton *btnAnnuler;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1280, 720);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        pageLogin = new QWidget();
        pageLogin->setObjectName("pageLogin");
        verticalLayout_2 = new QVBoxLayout(pageLogin);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        frame = new QFrame(pageLogin);
        frame->setObjectName("frame");
        frame->setMinimumSize(QSize(400, 300));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame);
        verticalLayout_3->setObjectName("verticalLayout_3");
        labelTitle = new QLabel(frame);
        labelTitle->setObjectName("labelTitle");
        labelTitle->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(labelTitle);

        txtLoginUsername = new QLineEdit(frame);
        txtLoginUsername->setObjectName("txtLoginUsername");
        txtLoginUsername->setMinimumSize(QSize(0, 40));

        verticalLayout_3->addWidget(txtLoginUsername);

        txtLoginPassword = new QLineEdit(frame);
        txtLoginPassword->setObjectName("txtLoginPassword");
        txtLoginPassword->setEchoMode(QLineEdit::Password);
        txtLoginPassword->setMinimumSize(QSize(0, 40));

        verticalLayout_3->addWidget(txtLoginPassword);

        btnLogin = new QPushButton(frame);
        btnLogin->setObjectName("btnLogin");
        btnLogin->setMinimumSize(QSize(0, 40));

        verticalLayout_3->addWidget(btnLogin);


        verticalLayout_2->addWidget(frame, 0, Qt::AlignHCenter);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        stackedWidget->addWidget(pageLogin);
        pageCRUD = new QWidget();
        pageCRUD->setObjectName("pageCRUD");
        horizontalLayout = new QHBoxLayout(pageCRUD);
        horizontalLayout->setObjectName("horizontalLayout");
        frameSidebar = new QFrame(pageCRUD);
        frameSidebar->setObjectName("frameSidebar");
        frameSidebar->setMinimumSize(QSize(220, 0));
        frameSidebar->setMaximumSize(QSize(220, 16777215));
        verticalLayout_4 = new QVBoxLayout(frameSidebar);
        verticalLayout_4->setObjectName("verticalLayout_4");
        labelLogo = new QLabel(frameSidebar);
        labelLogo->setObjectName("labelLogo");
        labelLogo->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(labelLogo);

        btnAccueil = new QPushButton(frameSidebar);
        btnAccueil->setObjectName("btnAccueil");
        btnAccueil->setMinimumSize(QSize(0, 40));

        verticalLayout_4->addWidget(btnAccueil);

        btnAnimaux = new QPushButton(frameSidebar);
        btnAnimaux->setObjectName("btnAnimaux");
        btnAnimaux->setMinimumSize(QSize(0, 40));

        verticalLayout_4->addWidget(btnAnimaux);

        btnRdv = new QPushButton(frameSidebar);
        btnRdv->setObjectName("btnRdv");
        btnRdv->setMinimumSize(QSize(0, 40));

        verticalLayout_4->addWidget(btnRdv);

        btnStock = new QPushButton(frameSidebar);
        btnStock->setObjectName("btnStock");
        btnStock->setMinimumSize(QSize(0, 40));

        verticalLayout_4->addWidget(btnStock);

        btnCommandes = new QPushButton(frameSidebar);
        btnCommandes->setObjectName("btnCommandes");
        btnCommandes->setMinimumSize(QSize(0, 40));

        verticalLayout_4->addWidget(btnCommandes);

        btnFournisseurs = new QPushButton(frameSidebar);
        btnFournisseurs->setObjectName("btnFournisseurs");
        btnFournisseurs->setMinimumSize(QSize(0, 40));

        verticalLayout_4->addWidget(btnFournisseurs);

        btnEmployes = new QPushButton(frameSidebar);
        btnEmployes->setObjectName("btnEmployes");
        btnEmployes->setMinimumSize(QSize(0, 40));

        verticalLayout_4->addWidget(btnEmployes);

        btnParametres = new QPushButton(frameSidebar);
        btnParametres->setObjectName("btnParametres");
        btnParametres->setMinimumSize(QSize(0, 40));

        verticalLayout_4->addWidget(btnParametres);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_3);

        btnLogout = new QPushButton(frameSidebar);
        btnLogout->setObjectName("btnLogout");
        btnLogout->setMinimumSize(QSize(0, 40));

        verticalLayout_4->addWidget(btnLogout);


        horizontalLayout->addWidget(frameSidebar);

        frameContent = new QFrame(pageCRUD);
        frameContent->setObjectName("frameContent");
        verticalLayout_5 = new QVBoxLayout(frameContent);
        verticalLayout_5->setObjectName("verticalLayout_5");
        frameHeader = new QFrame(frameContent);
        frameHeader->setObjectName("frameHeader");
        horizontalLayoutHeader = new QHBoxLayout(frameHeader);
        horizontalLayoutHeader->setObjectName("horizontalLayoutHeader");
        horizontalLayoutHeader->setContentsMargins(0, 0, 0, 0);
        labelTitleIcon = new QLabel(frameHeader);
        labelTitleIcon->setObjectName("labelTitleIcon");

        horizontalLayoutHeader->addWidget(labelTitleIcon);

        labelPageTitle = new QLabel(frameHeader);
        labelPageTitle->setObjectName("labelPageTitle");

        horizontalLayoutHeader->addWidget(labelPageTitle);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayoutHeader->addItem(horizontalSpacer);

        frameBellContainer = new QFrame(frameHeader);
        frameBellContainer->setObjectName("frameBellContainer");
        frameBellContainer->setFrameShape(QFrame::NoFrame);
        gridLayoutBell = new QGridLayout(frameBellContainer);
        gridLayoutBell->setObjectName("gridLayoutBell");
        gridLayoutBell->setContentsMargins(0, 0, 0, 0);
        labelBell = new QLabel(frameBellContainer);
        labelBell->setObjectName("labelBell");

        gridLayoutBell->addWidget(labelBell, 0, 0, 1, 1);

        labelNotifBadge = new QLabel(frameBellContainer);
        labelNotifBadge->setObjectName("labelNotifBadge");

        gridLayoutBell->addWidget(labelNotifBadge, 0, 0, 1, 1, Qt::AlignRight|Qt::AlignTop);


        horizontalLayoutHeader->addWidget(frameBellContainer);

        labelAvatar = new QLabel(frameHeader);
        labelAvatar->setObjectName("labelAvatar");
        labelAvatar->setAlignment(Qt::AlignCenter);

        horizontalLayoutHeader->addWidget(labelAvatar);

        verticalLayoutUser = new QVBoxLayout();
        verticalLayoutUser->setObjectName("verticalLayoutUser");
        labelUserName = new QLabel(frameHeader);
        labelUserName->setObjectName("labelUserName");

        verticalLayoutUser->addWidget(labelUserName);

        labelUserRole = new QLabel(frameHeader);
        labelUserRole->setObjectName("labelUserRole");

        verticalLayoutUser->addWidget(labelUserRole);


        horizontalLayoutHeader->addLayout(verticalLayoutUser);


        verticalLayout_5->addWidget(frameHeader);

        tabWidget = new QTabWidget(frameContent);
        tabWidget->setObjectName("tabWidget");
        tabListe = new QWidget();
        tabListe->setObjectName("tabListe");
        verticalLayout_tabListe = new QVBoxLayout(tabListe);
        verticalLayout_tabListe->setObjectName("verticalLayout_tabListe");
        frameToolbar = new QFrame(tabListe);
        frameToolbar->setObjectName("frameToolbar");
        horizontalLayout_2 = new QHBoxLayout(frameToolbar);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        txtRecherche = new QLineEdit(frameToolbar);
        txtRecherche->setObjectName("txtRecherche");
        txtRecherche->setMinimumSize(QSize(0, 35));

        horizontalLayout_2->addWidget(txtRecherche);

        cmbTri = new QComboBox(frameToolbar);
        cmbTri->addItem(QString());
        cmbTri->addItem(QString());
        cmbTri->setObjectName("cmbTri");
        cmbTri->setMinimumSize(QSize(0, 35));

        horizontalLayout_2->addWidget(cmbTri);


        verticalLayout_tabListe->addWidget(frameToolbar);

        tblEmployes = new QTableWidget(tabListe);
        if (tblEmployes->columnCount() < 9)
            tblEmployes->setColumnCount(9);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tblEmployes->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tblEmployes->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tblEmployes->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tblEmployes->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tblEmployes->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tblEmployes->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tblEmployes->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tblEmployes->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tblEmployes->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        tblEmployes->setObjectName("tblEmployes");
        tblEmployes->setColumnCount(9);

        verticalLayout_tabListe->addWidget(tblEmployes);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        btnAjouter = new QPushButton(tabListe);
        btnAjouter->setObjectName("btnAjouter");
        btnAjouter->setMinimumSize(QSize(0, 35));

        horizontalLayout_3->addWidget(btnAjouter);

        btnModifier = new QPushButton(tabListe);
        btnModifier->setObjectName("btnModifier");
        btnModifier->setMinimumSize(QSize(0, 35));

        horizontalLayout_3->addWidget(btnModifier);

        btnSupprimer = new QPushButton(tabListe);
        btnSupprimer->setObjectName("btnSupprimer");
        btnSupprimer->setMinimumSize(QSize(0, 35));

        horizontalLayout_3->addWidget(btnSupprimer);

        btnExporterPDF = new QPushButton(tabListe);
        btnExporterPDF->setObjectName("btnExporterPDF");
        btnExporterPDF->setMinimumSize(QSize(0, 35));

        horizontalLayout_3->addWidget(btnExporterPDF);

        btnExporterExcel = new QPushButton(tabListe);
        btnExporterExcel->setObjectName("btnExporterExcel");
        btnExporterExcel->setMinimumSize(QSize(0, 35));

        horizontalLayout_3->addWidget(btnExporterExcel);


        verticalLayout_tabListe->addLayout(horizontalLayout_3);

        tabWidget->addTab(tabListe, QString());
        tabStats = new QWidget();
        tabStats->setObjectName("tabStats");
        verticalLayout_tabStats = new QVBoxLayout(tabStats);
        verticalLayout_tabStats->setObjectName("verticalLayout_tabStats");
        frameChartPoste = new QFrame(tabStats);
        frameChartPoste->setObjectName("frameChartPoste");
        frameChartPoste->setMinimumSize(QSize(0, 250));
        frameChartPoste->setFrameShape(QFrame::StyledPanel);
        layoutChartPoste = new QVBoxLayout(frameChartPoste);
        layoutChartPoste->setObjectName("layoutChartPoste");

        verticalLayout_tabStats->addWidget(frameChartPoste);

        frameChartStatut = new QFrame(tabStats);
        frameChartStatut->setObjectName("frameChartStatut");
        frameChartStatut->setMinimumSize(QSize(0, 250));
        frameChartStatut->setFrameShape(QFrame::StyledPanel);
        layoutChartStatut = new QVBoxLayout(frameChartStatut);
        layoutChartStatut->setObjectName("layoutChartStatut");

        verticalLayout_tabStats->addWidget(frameChartStatut);

        tabWidget->addTab(tabStats, QString());
        tabPlanning = new QWidget();
        tabPlanning->setObjectName("tabPlanning");
        verticalLayout_tabPlanning = new QVBoxLayout(tabPlanning);
        verticalLayout_tabPlanning->setObjectName("verticalLayout_tabPlanning");
        btnGenererPlanning = new QPushButton(tabPlanning);
        btnGenererPlanning->setObjectName("btnGenererPlanning");
        btnGenererPlanning->setMinimumSize(QSize(0, 40));

        verticalLayout_tabPlanning->addWidget(btnGenererPlanning);

        tblPlanning = new QTableWidget(tabPlanning);
        if (tblPlanning->columnCount() < 7)
            tblPlanning->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tblPlanning->setHorizontalHeaderItem(0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tblPlanning->setHorizontalHeaderItem(1, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tblPlanning->setHorizontalHeaderItem(2, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tblPlanning->setHorizontalHeaderItem(3, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tblPlanning->setHorizontalHeaderItem(4, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tblPlanning->setHorizontalHeaderItem(5, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tblPlanning->setHorizontalHeaderItem(6, __qtablewidgetitem15);
        tblPlanning->setObjectName("tblPlanning");
        tblPlanning->setColumnCount(7);

        verticalLayout_tabPlanning->addWidget(tblPlanning);

        tabWidget->addTab(tabPlanning, QString());
        tabCompetences = new QWidget();
        tabCompetences->setObjectName("tabCompetences");
        verticalLayout_tabCompetences = new QVBoxLayout(tabCompetences);
        verticalLayout_tabCompetences->setObjectName("verticalLayout_tabCompetences");
        btnVerifierAlertes = new QPushButton(tabCompetences);
        btnVerifierAlertes->setObjectName("btnVerifierAlertes");
        btnVerifierAlertes->setMinimumSize(QSize(0, 40));

        verticalLayout_tabCompetences->addWidget(btnVerifierAlertes);

        tblCompetences = new QTableWidget(tabCompetences);
        if (tblCompetences->columnCount() < 5)
            tblCompetences->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tblCompetences->setHorizontalHeaderItem(0, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tblCompetences->setHorizontalHeaderItem(1, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tblCompetences->setHorizontalHeaderItem(2, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tblCompetences->setHorizontalHeaderItem(3, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tblCompetences->setHorizontalHeaderItem(4, __qtablewidgetitem20);
        tblCompetences->setObjectName("tblCompetences");
        tblCompetences->setColumnCount(5);

        verticalLayout_tabCompetences->addWidget(tblCompetences);

        tabWidget->addTab(tabCompetences, QString());

        verticalLayout_5->addWidget(tabWidget);


        horizontalLayout->addWidget(frameContent);

        frameForm = new QFrame(pageCRUD);
        frameForm->setObjectName("frameForm");
        frameForm->setMinimumSize(QSize(350, 0));
        frameForm->setMaximumSize(QSize(350, 16777215));
        verticalLayout_6 = new QVBoxLayout(frameForm);
        verticalLayout_6->setObjectName("verticalLayout_6");
        labelFormTitle = new QLabel(frameForm);
        labelFormTitle->setObjectName("labelFormTitle");

        verticalLayout_6->addWidget(labelFormTitle);

        txtNom = new QLineEdit(frameForm);
        txtNom->setObjectName("txtNom");

        verticalLayout_6->addWidget(txtNom);

        txtPrenom = new QLineEdit(frameForm);
        txtPrenom->setObjectName("txtPrenom");

        verticalLayout_6->addWidget(txtPrenom);

        txtEmail = new QLineEdit(frameForm);
        txtEmail->setObjectName("txtEmail");

        verticalLayout_6->addWidget(txtEmail);

        txtTelephone = new QLineEdit(frameForm);
        txtTelephone->setObjectName("txtTelephone");

        verticalLayout_6->addWidget(txtTelephone);

        cmbPoste = new QComboBox(frameForm);
        cmbPoste->addItem(QString());
        cmbPoste->addItem(QString());
        cmbPoste->addItem(QString());
        cmbPoste->addItem(QString());
        cmbPoste->addItem(QString());
        cmbPoste->setObjectName("cmbPoste");

        verticalLayout_6->addWidget(cmbPoste);

        spnSalaire = new QDoubleSpinBox(frameForm);
        spnSalaire->setObjectName("spnSalaire");
        spnSalaire->setMaximum(999999.989999999990687);

        verticalLayout_6->addWidget(spnSalaire);

        dateEmbauche = new QDateEdit(frameForm);
        dateEmbauche->setObjectName("dateEmbauche");
        dateEmbauche->setCalendarPopup(true);

        verticalLayout_6->addWidget(dateEmbauche);

        cmbStatut = new QComboBox(frameForm);
        cmbStatut->addItem(QString());
        cmbStatut->addItem(QString());
        cmbStatut->addItem(QString());
        cmbStatut->setObjectName("cmbStatut");

        verticalLayout_6->addWidget(cmbStatut);

        btnEnregistrer = new QPushButton(frameForm);
        btnEnregistrer->setObjectName("btnEnregistrer");
        btnEnregistrer->setMinimumSize(QSize(0, 40));

        verticalLayout_6->addWidget(btnEnregistrer);

        btnAnnuler = new QPushButton(frameForm);
        btnAnnuler->setObjectName("btnAnnuler");
        btnAnnuler->setMinimumSize(QSize(0, 40));

        verticalLayout_6->addWidget(btnAnnuler);


        horizontalLayout->addWidget(frameForm);

        stackedWidget->addWidget(pageCRUD);

        verticalLayout->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1280, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);
        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Pet Manager - Gestion des Employ\303\251s", nullptr));
        labelTitle->setText(QCoreApplication::translate("MainWindow", "<h2>Connexion Employ\303\251</h2>", nullptr));
        txtLoginUsername->setPlaceholderText(QCoreApplication::translate("MainWindow", "Nom d'utilisateur", nullptr));
        txtLoginPassword->setPlaceholderText(QCoreApplication::translate("MainWindow", "Mot de passe", nullptr));
        btnLogin->setText(QCoreApplication::translate("MainWindow", "Se connecter", nullptr));
        labelLogo->setText(QCoreApplication::translate("MainWindow", "<h3>Pet Manager</h3>", nullptr));
        btnAccueil->setText(QCoreApplication::translate("MainWindow", "\360\237\217\240 Accueil", nullptr));
        btnAnimaux->setText(QCoreApplication::translate("MainWindow", "\360\237\220\276 Animaux", nullptr));
        btnRdv->setText(QCoreApplication::translate("MainWindow", "\360\237\223\205 Rendez-vous", nullptr));
        btnStock->setText(QCoreApplication::translate("MainWindow", "\360\237\223\246 Stock", nullptr));
        btnCommandes->setText(QCoreApplication::translate("MainWindow", "\360\237\233\222 Commandes", nullptr));
        btnFournisseurs->setText(QCoreApplication::translate("MainWindow", "\360\237\232\232 Fournisseurs", nullptr));
        btnEmployes->setText(QCoreApplication::translate("MainWindow", "\360\237\221\245 Employ\303\251s", nullptr));
        btnParametres->setText(QCoreApplication::translate("MainWindow", "\342\232\231\357\270\217 Param\303\250tres", nullptr));
        btnLogout->setText(QCoreApplication::translate("MainWindow", "\360\237\232\252 D\303\251connexion", nullptr));
        frameHeader->setStyleSheet(QCoreApplication::translate("MainWindow", "border-bottom: 1px solid #E0E0E0; padding-bottom: 12px; margin-bottom: 12px;", nullptr));
        labelTitleIcon->setStyleSheet(QCoreApplication::translate("MainWindow", "font-size: 28px;", nullptr));
        labelTitleIcon->setText(QCoreApplication::translate("MainWindow", "\360\237\221\245", nullptr));
        labelPageTitle->setText(QCoreApplication::translate("MainWindow", "Gestion des Employ\303\251s", nullptr));
        labelPageTitle->setStyleSheet(QCoreApplication::translate("MainWindow", "font-size: 24px; font-weight: bold; color: #2D3436;", nullptr));
        labelBell->setStyleSheet(QCoreApplication::translate("MainWindow", "font-size: 24px;", nullptr));
        labelBell->setText(QCoreApplication::translate("MainWindow", "\360\237\224\224", nullptr));
        labelNotifBadge->setStyleSheet(QCoreApplication::translate("MainWindow", "background-color: #D9534F; color: white; border-radius: 9px; font-size: 10px; font-weight: bold; padding: 2px 5px; min-width: 18px; min-height: 18px; qproperty-alignment: AlignCenter;", nullptr));
        labelNotifBadge->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        labelAvatar->setStyleSheet(QCoreApplication::translate("MainWindow", "font-size: 24px; color: #2A8C82; border: 2px solid #2A8C82; border-radius: 22px; min-width: 44px; min-height: 44px;", nullptr));
        labelAvatar->setText(QCoreApplication::translate("MainWindow", "\360\237\221\244", nullptr));
        labelUserName->setText(QCoreApplication::translate("MainWindow", "Dr. Sami Ben Ali", nullptr));
        labelUserName->setStyleSheet(QCoreApplication::translate("MainWindow", "font-weight: bold; font-size: 14px;", nullptr));
        labelUserRole->setText(QCoreApplication::translate("MainWindow", "M\303\251decin V\303\251t\303\251rinaire", nullptr));
        labelUserRole->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #6C757D; font-size: 12px;", nullptr));
        txtRecherche->setPlaceholderText(QCoreApplication::translate("MainWindow", "Rechercher par nom ou pr\303\251nom...", nullptr));
        cmbTri->setItemText(0, QCoreApplication::translate("MainWindow", "Aucun tri", nullptr));
        cmbTri->setItemText(1, QCoreApplication::translate("MainWindow", "Trier par poste", nullptr));

        QTableWidgetItem *___qtablewidgetitem = tblEmployes->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tblEmployes->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tblEmployes->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Pr\303\251nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tblEmployes->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tblEmployes->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "T\303\251l\303\251phone", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tblEmployes->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Poste", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tblEmployes->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "Salaire", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tblEmployes->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "Date Embauche", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tblEmployes->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "Statut", nullptr));
        btnAjouter->setText(QCoreApplication::translate("MainWindow", "\342\236\225 Ajouter", nullptr));
        btnModifier->setText(QCoreApplication::translate("MainWindow", "\342\234\217\357\270\217 Modifier", nullptr));
        btnSupprimer->setText(QCoreApplication::translate("MainWindow", "\360\237\227\221\357\270\217 Supprimer", nullptr));
        btnExporterPDF->setText(QCoreApplication::translate("MainWindow", "\360\237\223\204 Export PDF", nullptr));
        btnExporterExcel->setText(QCoreApplication::translate("MainWindow", "\360\237\223\212 Export Excel", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabListe), QCoreApplication::translate("MainWindow", "Liste des employ\303\251s", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabStats), QCoreApplication::translate("MainWindow", "Statistiques", nullptr));
        btnGenererPlanning->setText(QCoreApplication::translate("MainWindow", "\342\232\241 G\303\251n\303\251rer le Planning Intelligent", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tblPlanning->horizontalHeaderItem(0);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "Employ\303\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tblPlanning->horizontalHeaderItem(1);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "Poste", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tblPlanning->horizontalHeaderItem(2);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "Lundi", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tblPlanning->horizontalHeaderItem(3);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainWindow", "Mardi", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tblPlanning->horizontalHeaderItem(4);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("MainWindow", "Mercredi", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tblPlanning->horizontalHeaderItem(5);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("MainWindow", "Jeudi", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tblPlanning->horizontalHeaderItem(6);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("MainWindow", "Vendredi", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabPlanning), QCoreApplication::translate("MainWindow", "Planning Intelligent", nullptr));
        btnVerifierAlertes->setText(QCoreApplication::translate("MainWindow", "\342\232\240\357\270\217 V\303\251rifier les Alertes de Formation", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tblCompetences->horizontalHeaderItem(0);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("MainWindow", "Employ\303\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tblCompetences->horizontalHeaderItem(1);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("MainWindow", "Poste", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tblCompetences->horizontalHeaderItem(2);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("MainWindow", "Comp\303\251tences", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tblCompetences->horizontalHeaderItem(3);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("MainWindow", "Derni\303\250re Formation", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tblCompetences->horizontalHeaderItem(4);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("MainWindow", "Statut", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabCompetences), QCoreApplication::translate("MainWindow", "Comp\303\251tences & Formations", nullptr));
        labelFormTitle->setText(QCoreApplication::translate("MainWindow", "<h3>Formulaire Employ\303\251</h3>", nullptr));
        txtNom->setPlaceholderText(QCoreApplication::translate("MainWindow", "Nom *", nullptr));
        txtPrenom->setPlaceholderText(QCoreApplication::translate("MainWindow", "Pr\303\251nom *", nullptr));
        txtEmail->setPlaceholderText(QCoreApplication::translate("MainWindow", "Email *", nullptr));
        txtTelephone->setPlaceholderText(QCoreApplication::translate("MainWindow", "T\303\251l\303\251phone *", nullptr));
        cmbPoste->setItemText(0, QCoreApplication::translate("MainWindow", "V\303\251t\303\251rinaire", nullptr));
        cmbPoste->setItemText(1, QCoreApplication::translate("MainWindow", "Assistant", nullptr));
        cmbPoste->setItemText(2, QCoreApplication::translate("MainWindow", "Secr\303\251taire", nullptr));
        cmbPoste->setItemText(3, QCoreApplication::translate("MainWindow", "Toilettteur", nullptr));
        cmbPoste->setItemText(4, QCoreApplication::translate("MainWindow", "Gardien", nullptr));

        spnSalaire->setSuffix(QCoreApplication::translate("MainWindow", " TND", nullptr));
        dateEmbauche->setDisplayFormat(QCoreApplication::translate("MainWindow", "dd/MM/yyyy", nullptr));
        cmbStatut->setItemText(0, QCoreApplication::translate("MainWindow", "Actif", nullptr));
        cmbStatut->setItemText(1, QCoreApplication::translate("MainWindow", "En cong\303\251", nullptr));
        cmbStatut->setItemText(2, QCoreApplication::translate("MainWindow", "Inactif", nullptr));

        btnEnregistrer->setText(QCoreApplication::translate("MainWindow", "\360\237\222\276 Enregistrer", nullptr));
        btnAnnuler->setText(QCoreApplication::translate("MainWindow", "\342\235\214 Annuler", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
