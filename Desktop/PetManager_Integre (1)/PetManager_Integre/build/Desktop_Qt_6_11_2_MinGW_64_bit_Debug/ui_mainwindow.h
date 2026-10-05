/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
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
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *layout_main;
    QFrame *frame_sidebar;
    QVBoxLayout *layout_sidebar;
    QLabel *label_logo;
    QPushButton *btn_menu_accueil;
    QPushButton *btn_menu_animaux;
    QPushButton *btn_menu_rdv;
    QPushButton *btn_menu_stock;
    QPushButton *btn_menu_commandes;
    QPushButton *btn_menu_fournisseurs;
    QPushButton *btn_menu_employes;
    QPushButton *btn_menu_parametres;
    QSpacerItem *verticalSpacer;
    QStackedWidget *SWPetManager;
    QWidget *pageFournisseurs;
    QHBoxLayout *layout_pageFournisseurs;
    QFrame *frame_content;
    QVBoxLayout *layout_content;
    QFrame *frame_header;
    QHBoxLayout *layout_header;
    QLabel *label_title_icon;
    QLabel *label_page_title;
    QSpacerItem *hSpacer_header;
    QFrame *frame_bell_container;
    QGridLayout *layout_bell_grid;
    QLabel *label_bell;
    QLabel *label_notif_badge;
    QLabel *label_avatar;
    QVBoxLayout *layout_user;
    QLabel *label_user_name;
    QLabel *label_user_role;
    QFrame *frame_kpis;
    QHBoxLayout *layout_kpis;
    QFrame *card_kpi1;
    QHBoxLayout *layout_kpi1;
    QLabel *label_kpi1_icon;
    QVBoxLayout *layout_kpi1_txt;
    QLabel *label_kpi1_title;
    QLabel *label_kpi1_value;
    QFrame *card_kpi2;
    QHBoxLayout *layout_kpi2;
    QLabel *label_kpi2_icon;
    QVBoxLayout *layout_kpi2_txt;
    QLabel *label_kpi2_title;
    QLabel *label_kpi2_value;
    QFrame *card_kpi3;
    QHBoxLayout *layout_kpi3;
    QLabel *label_kpi3_icon;
    QVBoxLayout *layout_kpi3_txt;
    QLabel *label_kpi3_title;
    QLabel *label_kpi3_value;
    QFrame *frame_toolbar;
    QHBoxLayout *layout_toolbar;
    QLineEdit *lineEdit_recherche;
    QComboBox *comboBox_tri;
    QFrame *frame_table;
    QVBoxLayout *layout_table;
    QTableWidget *tableWidget_fournisseurs;
    QLabel *label_table_footer;
    QFrame *frame_bottom;
    QHBoxLayout *layout_bottom;
    QFrame *card_chart;
    QVBoxLayout *layout_card_chart;
    QHBoxLayout *layout_chart_head;
    QLabel *label_chart_title;
    QComboBox *comboBox_chart;
    QFrame *frame_chart;
    QVBoxLayout *layout_chart_container;
    QFrame *card_alerts;
    QVBoxLayout *layout_card_alerts;
    QHBoxLayout *layout_alerts_head;
    QLabel *label_alerts_title;
    QLabel *label_alerts_badge;
    QListWidget *listWidget_alertes;
    QFrame *card_suggestions;
    QVBoxLayout *layout_card_sugg;
    QHBoxLayout *layout_sugg_head;
    QLabel *label_sugg_title;
    QComboBox *comboBox_rec_type;
    QListWidget *listWidget_suggestions;
    QFrame *frame_right;
    QVBoxLayout *layout_right;
    QLabel *label_form_title;
    QScrollArea *scrollArea_form;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *layout_form;
    QLabel *label_nom;
    QLineEdit *lineEdit_nom;
    QLabel *label_contact;
    QLineEdit *lineEdit_contact;
    QHBoxLayout *layout_tel_email;
    QVBoxLayout *layout_tel;
    QLabel *label_tel;
    QLineEdit *lineEdit_tel;
    QVBoxLayout *layout_email;
    QLabel *label_email;
    QLineEdit *lineEdit_email;
    QLabel *label_adresse;
    QLineEdit *lineEdit_adresse;
    QHBoxLayout *layout_type_status;
    QVBoxLayout *layout_type;
    QLabel *label_type;
    QComboBox *comboBox_type;
    QVBoxLayout *layout_status;
    QLabel *label_status;
    QComboBox *comboBox_status;
    QHBoxLayout *layout_quantite_prix;
    QVBoxLayout *layout_quantite;
    QLabel *label_quantite;
    QSpinBox *spinBox_quantite;
    QVBoxLayout *layout_prix;
    QLabel *label_prix;
    QDoubleSpinBox *doubleSpinBox_prix;
    QLabel *label_date;
    QDateEdit *dateEdit_contrat;
    QPushButton *btn_enregistrer;
    QHBoxLayout *layout_mod_ann;
    QPushButton *btn_modifier;
    QPushButton *btn_annuler;
    QPushButton *btn_supprimer;
    QFrame *card_export;
    QVBoxLayout *layout_card_export;
    QLabel *label_export_title;
    QLabel *label_export_desc;
    QHBoxLayout *layout_export_btns;
    QPushButton *btn_export_pdf;
    QPushButton *btn_export_excel;
    QWidget *pageStock;
    QVBoxLayout *layoutModuleStock;
    QFrame *frameHeader;
    QHBoxLayout *layoutHeader;
    QLabel *lblIconeTitre;
    QLabel *lblTitre;
    QSpacerItem *espaceHeader;
    QPushButton *btnNotif;
    QSpacerItem *espaceAvatar;
    QLabel *lblAvatar;
    QWidget *widgetUtilisateur;
    QLabel *lblNomMedecin;
    QLabel *lblRole;
    QStackedWidget *stackStock;
    QWidget *pageGestionStock;
    QVBoxLayout *layoutPageStock;
    QScrollArea *scrollStock;
    QWidget *contenuStock;
    QVBoxLayout *layoutContenu;
    QWidget *zoneHautStock;
    QHBoxLayout *layout_zoneHaut;
    QWidget *colonneGaucheStock;
    QVBoxLayout *layout_colonneGauche;
    QWidget *ligneCartesStock;
    QHBoxLayout *layout_ligneCartes;
    QFrame *frameCarte1Stock;
    QLabel *lblCarte1IconeStock;
    QLabel *lblCarte1TitreStock;
    QLabel *lblValeurTotalStock;
    QFrame *frameCarte2Stock;
    QLabel *lblCarte2IconeStock;
    QLabel *lblCarte2TitreStock;
    QLabel *lblValeurReapproStock;
    QFrame *frameCarte3Stock;
    QLabel *lblCarte3IconeStock;
    QLabel *lblCarte3TitreStock;
    QLabel *lblValeurStock;
    QWidget *ligneRechercheStock;
    QHBoxLayout *layout_ligneRecherche;
    QLineEdit *txtRechercheStock;
    QComboBox *cmbTriStock;
    QTableWidget *tableStock;
    QLabel *lblAffichageStock;
    QWidget *ligneBlocsStock;
    QHBoxLayout *layout_ligneBlocs;
    QFrame *frameAlertesStock;
    QVBoxLayout *layoutAlertes;
    QWidget *enteteAlertesStock;
    QHBoxLayout *layout_enteteAlertes;
    QLabel *lblAlerteTitreStock;
    QSpacerItem *espaceAlertes;
    QLabel *lblAlerteBadgeStock;
    QWidget *ligneAlerte1Stock;
    QHBoxLayout *layout_ligneAlerte1;
    QLabel *lblAlerte1Stock;
    QLabel *lblQte1Stock;
    QWidget *ligneAlerte2Stock;
    QHBoxLayout *layout_ligneAlerte2;
    QLabel *lblAlerte2Stock;
    QLabel *lblQte2Stock;
    QWidget *ligneAlerte3Stock;
    QHBoxLayout *layout_ligneAlerte3;
    QLabel *lblAlerte3Stock;
    QLabel *lblQte3Stock;
    QSpacerItem *espaceBasAlertes;
    QPushButton *btnVoirToutStock;
    QFrame *frameAlternatifsStock;
    QVBoxLayout *layoutAlternatifs;
    QLabel *lblAltTitreStock;
    QLabel *lblAltPourStock;
    QFrame *frameAlt1Stock;
    QHBoxLayout *layoutAlt1;
    QLabel *lblAltIcone1Stock;
    QWidget *textesAlt1Stock;
    QVBoxLayout *layout_textesAlt1;
    QLabel *lblAltNom1Stock;
    QLabel *lblAltCat1Stock;
    QLabel *lblAltQte1Stock;
    QLabel *lblAltFleche1Stock;
    QFrame *frameAlt2Stock;
    QHBoxLayout *layoutAlt2;
    QLabel *lblAltIcone2Stock;
    QWidget *textesAlt2Stock;
    QVBoxLayout *layout_textesAlt2;
    QLabel *lblAltNom2Stock;
    QLabel *lblAltCat2Stock;
    QLabel *lblAltQte2Stock;
    QLabel *lblAltFleche2Stock;
    QLabel *lblAucuneAltStock;
    QSpacerItem *espaceBasAlternatifs;
    QWidget *colonneDroiteStock;
    QVBoxLayout *layout_colonneDroite;
    QFrame *frameFormulaireStock;
    QLabel *lblFormTitreStock;
    QLabel *lblSeparateurStock;
    QLabel *lblNomStock;
    QLineEdit *txtNomStock;
    QLabel *lblCategorieStock;
    QComboBox *cmbCategorieStock;
    QLabel *lblEspeceStock;
    QComboBox *cmbEspeceStock;
    QLabel *lblUsageStock;
    QComboBox *cmbUsageStock;
    QLabel *lblQuantiteStock;
    QSpinBox *spinQuantiteStock;
    QLabel *lblSeuilStock;
    QSpinBox *spinSeuilStock;
    QLabel *lblDateStock;
    QDateEdit *dateExpirationStock;
    QLabel *lblFournisseurStock;
    QLineEdit *txtFournisseurStock;
    QLabel *lblPrixStock;
    QDoubleSpinBox *spinPrixStock;
    QPushButton *btnEnregistrerStock;
    QPushButton *btnModifierStock;
    QPushButton *btnAnnulerStock;
    QPushButton *btnSupprimerStock;
    QFrame *frameExportStock;
    QLabel *lblExportIconeStock;
    QLabel *lblExportTitreStock;
    QLabel *lblExportSousTitreStock;
    QPushButton *btnOuvrirReapproStock;
    QPushButton *btnExcelStock;
    QSpacerItem *espaceColonneDroite;
    QLabel *lblStatsTitreStock;
    QWidget *ligneStatsStock;
    QHBoxLayout *layout_ligneStats;
    QFrame *frameGraphiqueStock;
    QVBoxLayout *layoutGraphique;
    QWidget *enteteGraphiqueStock;
    QHBoxLayout *layout_enteteGraphique;
    QLabel *lblGraphTitreStock;
    QSpacerItem *espaceGraphique;
    QComboBox *cmbPeriodeStock;
    QWidget *widgetGraphiqueStock;
    QFrame *frameStat1Stock;
    QVBoxLayout *layout_frameStat1;
    QLabel *lblStat1TitreStock;
    QWidget *widgetCamembertStock;
    QLabel *lblSubstTitreStock;
    QFrame *frameSubstitutionsStock;
    QVBoxLayout *layoutSubstitutions;
    QLabel *lblSubstInfoStock;
    QTableWidget *tableSubstitutionsStock;
    QLabel *lblAucuneSubstitutionStock;
    QSpacerItem *espaceBas;
    QWidget *pageReappro;
    QVBoxLayout *layoutPageReappro;
    QScrollArea *scrollReappro;
    QWidget *contenuReappro;
    QVBoxLayout *layoutContenuReappro;
    QWidget *barreReappro;
    QHBoxLayout *layout_barreReappro;
    QPushButton *btnRetourStock;
    QSpacerItem *espaceBarreReappro;
    QLabel *lblDelaiStock;
    QSpinBox *spinDelaiStock;
    QSpacerItem *espaceParam;
    QLabel *lblCouvertureStock;
    QSpinBox *spinCouvertureStock;
    QLabel *lblExplicationStock;
    QLabel *lblCompteursStock;
    QFrame *frameSuggestionsStock;
    QVBoxLayout *layoutSuggestions;
    QWidget *enteteSuggestionsStock;
    QHBoxLayout *layout_enteteSuggestions;
    QLabel *lblSuggTitreStock;
    QSpacerItem *espaceSugg;
    QPushButton *btnToutSelectionnerStock;
    QPushButton *btnCommanderSelectionStock;
    QPushButton *btnExcelSuggestionsStock;
    QTableWidget *tableSuggestionsStock;
    QLabel *lblAucuneSuggestionStock;
    QFrame *frameCommandesStock;
    QVBoxLayout *layoutCommandes;
    QWidget *enteteCommandesStock;
    QHBoxLayout *layout_enteteCommandes;
    QLabel *lblCmdTitreStock;
    QSpacerItem *espaceCmd;
    QPushButton *btnExcelCommandesStock;
    QTableWidget *tableCommandesStock;
    QLabel *lblAucuneCommandeStock;
    QSpacerItem *espaceBasReappro;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setMinimumSize(QSize(1280, 720));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        layout_main = new QHBoxLayout(centralwidget);
        layout_main->setObjectName("layout_main");
        frame_sidebar = new QFrame(centralwidget);
        frame_sidebar->setObjectName("frame_sidebar");
        frame_sidebar->setMaximumSize(QSize(230, 16777215));
        layout_sidebar = new QVBoxLayout(frame_sidebar);
        layout_sidebar->setObjectName("layout_sidebar");
        label_logo = new QLabel(frame_sidebar);
        label_logo->setObjectName("label_logo");

        layout_sidebar->addWidget(label_logo);

        btn_menu_accueil = new QPushButton(frame_sidebar);
        btn_menu_accueil->setObjectName("btn_menu_accueil");

        layout_sidebar->addWidget(btn_menu_accueil);

        btn_menu_animaux = new QPushButton(frame_sidebar);
        btn_menu_animaux->setObjectName("btn_menu_animaux");

        layout_sidebar->addWidget(btn_menu_animaux);

        btn_menu_rdv = new QPushButton(frame_sidebar);
        btn_menu_rdv->setObjectName("btn_menu_rdv");

        layout_sidebar->addWidget(btn_menu_rdv);

        btn_menu_stock = new QPushButton(frame_sidebar);
        btn_menu_stock->setObjectName("btn_menu_stock");

        layout_sidebar->addWidget(btn_menu_stock);

        btn_menu_commandes = new QPushButton(frame_sidebar);
        btn_menu_commandes->setObjectName("btn_menu_commandes");

        layout_sidebar->addWidget(btn_menu_commandes);

        btn_menu_fournisseurs = new QPushButton(frame_sidebar);
        btn_menu_fournisseurs->setObjectName("btn_menu_fournisseurs");

        layout_sidebar->addWidget(btn_menu_fournisseurs);

        btn_menu_employes = new QPushButton(frame_sidebar);
        btn_menu_employes->setObjectName("btn_menu_employes");

        layout_sidebar->addWidget(btn_menu_employes);

        btn_menu_parametres = new QPushButton(frame_sidebar);
        btn_menu_parametres->setObjectName("btn_menu_parametres");

        layout_sidebar->addWidget(btn_menu_parametres);

        verticalSpacer = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        layout_sidebar->addItem(verticalSpacer);


        layout_main->addWidget(frame_sidebar);

        SWPetManager = new QStackedWidget(centralwidget);
        SWPetManager->setObjectName("SWPetManager");
        pageFournisseurs = new QWidget();
        pageFournisseurs->setObjectName("pageFournisseurs");
        layout_pageFournisseurs = new QHBoxLayout(pageFournisseurs);
        layout_pageFournisseurs->setObjectName("layout_pageFournisseurs");
        layout_pageFournisseurs->setContentsMargins(0, 0, 0, 0);
        frame_content = new QFrame(pageFournisseurs);
        frame_content->setObjectName("frame_content");
        layout_content = new QVBoxLayout(frame_content);
        layout_content->setObjectName("layout_content");
        frame_header = new QFrame(frame_content);
        frame_header->setObjectName("frame_header");
        layout_header = new QHBoxLayout(frame_header);
        layout_header->setObjectName("layout_header");
        label_title_icon = new QLabel(frame_header);
        label_title_icon->setObjectName("label_title_icon");

        layout_header->addWidget(label_title_icon);

        label_page_title = new QLabel(frame_header);
        label_page_title->setObjectName("label_page_title");

        layout_header->addWidget(label_page_title);

        hSpacer_header = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        layout_header->addItem(hSpacer_header);

        frame_bell_container = new QFrame(frame_header);
        frame_bell_container->setObjectName("frame_bell_container");
        frame_bell_container->setFrameShape(QFrame::NoFrame);
        layout_bell_grid = new QGridLayout(frame_bell_container);
        layout_bell_grid->setObjectName("layout_bell_grid");
        layout_bell_grid->setContentsMargins(0, 0, 0, 0);
        label_bell = new QLabel(frame_bell_container);
        label_bell->setObjectName("label_bell");

        layout_bell_grid->addWidget(label_bell, 0, 0, 1, 1);

        label_notif_badge = new QLabel(frame_bell_container);
        label_notif_badge->setObjectName("label_notif_badge");

        layout_bell_grid->addWidget(label_notif_badge, 0, 0, 1, 1, Qt::AlignTop|Qt::AlignRight);


        layout_header->addWidget(frame_bell_container);

        label_avatar = new QLabel(frame_header);
        label_avatar->setObjectName("label_avatar");
        label_avatar->setAlignment(Qt::AlignCenter);

        layout_header->addWidget(label_avatar);

        layout_user = new QVBoxLayout();
        layout_user->setObjectName("layout_user");
        label_user_name = new QLabel(frame_header);
        label_user_name->setObjectName("label_user_name");

        layout_user->addWidget(label_user_name);

        label_user_role = new QLabel(frame_header);
        label_user_role->setObjectName("label_user_role");

        layout_user->addWidget(label_user_role);


        layout_header->addLayout(layout_user);


        layout_content->addWidget(frame_header);

        frame_kpis = new QFrame(frame_content);
        frame_kpis->setObjectName("frame_kpis");
        layout_kpis = new QHBoxLayout(frame_kpis);
        layout_kpis->setObjectName("layout_kpis");
        card_kpi1 = new QFrame(frame_kpis);
        card_kpi1->setObjectName("card_kpi1");
        layout_kpi1 = new QHBoxLayout(card_kpi1);
        layout_kpi1->setObjectName("layout_kpi1");
        label_kpi1_icon = new QLabel(card_kpi1);
        label_kpi1_icon->setObjectName("label_kpi1_icon");

        layout_kpi1->addWidget(label_kpi1_icon);

        layout_kpi1_txt = new QVBoxLayout();
        layout_kpi1_txt->setObjectName("layout_kpi1_txt");
        label_kpi1_title = new QLabel(card_kpi1);
        label_kpi1_title->setObjectName("label_kpi1_title");
        label_kpi1_title->setAlignment(Qt::AlignLeft);

        layout_kpi1_txt->addWidget(label_kpi1_title);

        label_kpi1_value = new QLabel(card_kpi1);
        label_kpi1_value->setObjectName("label_kpi1_value");
        label_kpi1_value->setAlignment(Qt::AlignLeft);

        layout_kpi1_txt->addWidget(label_kpi1_value);


        layout_kpi1->addLayout(layout_kpi1_txt);


        layout_kpis->addWidget(card_kpi1);

        card_kpi2 = new QFrame(frame_kpis);
        card_kpi2->setObjectName("card_kpi2");
        layout_kpi2 = new QHBoxLayout(card_kpi2);
        layout_kpi2->setObjectName("layout_kpi2");
        label_kpi2_icon = new QLabel(card_kpi2);
        label_kpi2_icon->setObjectName("label_kpi2_icon");

        layout_kpi2->addWidget(label_kpi2_icon);

        layout_kpi2_txt = new QVBoxLayout();
        layout_kpi2_txt->setObjectName("layout_kpi2_txt");
        label_kpi2_title = new QLabel(card_kpi2);
        label_kpi2_title->setObjectName("label_kpi2_title");
        label_kpi2_title->setAlignment(Qt::AlignLeft);

        layout_kpi2_txt->addWidget(label_kpi2_title);

        label_kpi2_value = new QLabel(card_kpi2);
        label_kpi2_value->setObjectName("label_kpi2_value");
        label_kpi2_value->setAlignment(Qt::AlignLeft);

        layout_kpi2_txt->addWidget(label_kpi2_value);


        layout_kpi2->addLayout(layout_kpi2_txt);


        layout_kpis->addWidget(card_kpi2);

        card_kpi3 = new QFrame(frame_kpis);
        card_kpi3->setObjectName("card_kpi3");
        layout_kpi3 = new QHBoxLayout(card_kpi3);
        layout_kpi3->setObjectName("layout_kpi3");
        label_kpi3_icon = new QLabel(card_kpi3);
        label_kpi3_icon->setObjectName("label_kpi3_icon");

        layout_kpi3->addWidget(label_kpi3_icon);

        layout_kpi3_txt = new QVBoxLayout();
        layout_kpi3_txt->setObjectName("layout_kpi3_txt");
        label_kpi3_title = new QLabel(card_kpi3);
        label_kpi3_title->setObjectName("label_kpi3_title");
        label_kpi3_title->setAlignment(Qt::AlignLeft);

        layout_kpi3_txt->addWidget(label_kpi3_title);

        label_kpi3_value = new QLabel(card_kpi3);
        label_kpi3_value->setObjectName("label_kpi3_value");
        label_kpi3_value->setAlignment(Qt::AlignLeft);

        layout_kpi3_txt->addWidget(label_kpi3_value);


        layout_kpi3->addLayout(layout_kpi3_txt);


        layout_kpis->addWidget(card_kpi3);


        layout_content->addWidget(frame_kpis);

        frame_toolbar = new QFrame(frame_content);
        frame_toolbar->setObjectName("frame_toolbar");
        layout_toolbar = new QHBoxLayout(frame_toolbar);
        layout_toolbar->setObjectName("layout_toolbar");
        lineEdit_recherche = new QLineEdit(frame_toolbar);
        lineEdit_recherche->setObjectName("lineEdit_recherche");

        layout_toolbar->addWidget(lineEdit_recherche);

        comboBox_tri = new QComboBox(frame_toolbar);
        comboBox_tri->addItem(QString());
        comboBox_tri->addItem(QString());
        comboBox_tri->addItem(QString());
        comboBox_tri->setObjectName("comboBox_tri");

        layout_toolbar->addWidget(comboBox_tri);


        layout_content->addWidget(frame_toolbar);

        frame_table = new QFrame(frame_content);
        frame_table->setObjectName("frame_table");
        layout_table = new QVBoxLayout(frame_table);
        layout_table->setObjectName("layout_table");
        tableWidget_fournisseurs = new QTableWidget(frame_table);
        tableWidget_fournisseurs->setObjectName("tableWidget_fournisseurs");

        layout_table->addWidget(tableWidget_fournisseurs);

        label_table_footer = new QLabel(frame_table);
        label_table_footer->setObjectName("label_table_footer");

        layout_table->addWidget(label_table_footer);


        layout_content->addWidget(frame_table);

        frame_bottom = new QFrame(frame_content);
        frame_bottom->setObjectName("frame_bottom");
        layout_bottom = new QHBoxLayout(frame_bottom);
        layout_bottom->setObjectName("layout_bottom");
        card_chart = new QFrame(frame_bottom);
        card_chart->setObjectName("card_chart");
        layout_card_chart = new QVBoxLayout(card_chart);
        layout_card_chart->setObjectName("layout_card_chart");
        layout_chart_head = new QHBoxLayout();
        layout_chart_head->setObjectName("layout_chart_head");
        label_chart_title = new QLabel(card_chart);
        label_chart_title->setObjectName("label_chart_title");

        layout_chart_head->addWidget(label_chart_title);

        comboBox_chart = new QComboBox(card_chart);
        comboBox_chart->addItem(QString());
        comboBox_chart->addItem(QString());
        comboBox_chart->setObjectName("comboBox_chart");

        layout_chart_head->addWidget(comboBox_chart);


        layout_card_chart->addLayout(layout_chart_head);

        frame_chart = new QFrame(card_chart);
        frame_chart->setObjectName("frame_chart");
        frame_chart->setMinimumSize(QSize(0, 180));
        layout_chart_container = new QVBoxLayout(frame_chart);
        layout_chart_container->setObjectName("layout_chart_container");

        layout_card_chart->addWidget(frame_chart);


        layout_bottom->addWidget(card_chart);

        card_alerts = new QFrame(frame_bottom);
        card_alerts->setObjectName("card_alerts");
        layout_card_alerts = new QVBoxLayout(card_alerts);
        layout_card_alerts->setObjectName("layout_card_alerts");
        layout_alerts_head = new QHBoxLayout();
        layout_alerts_head->setObjectName("layout_alerts_head");
        label_alerts_title = new QLabel(card_alerts);
        label_alerts_title->setObjectName("label_alerts_title");

        layout_alerts_head->addWidget(label_alerts_title);

        label_alerts_badge = new QLabel(card_alerts);
        label_alerts_badge->setObjectName("label_alerts_badge");

        layout_alerts_head->addWidget(label_alerts_badge);


        layout_card_alerts->addLayout(layout_alerts_head);

        listWidget_alertes = new QListWidget(card_alerts);
        listWidget_alertes->setObjectName("listWidget_alertes");

        layout_card_alerts->addWidget(listWidget_alertes);


        layout_bottom->addWidget(card_alerts);

        card_suggestions = new QFrame(frame_bottom);
        card_suggestions->setObjectName("card_suggestions");
        layout_card_sugg = new QVBoxLayout(card_suggestions);
        layout_card_sugg->setObjectName("layout_card_sugg");
        layout_sugg_head = new QHBoxLayout();
        layout_sugg_head->setObjectName("layout_sugg_head");
        label_sugg_title = new QLabel(card_suggestions);
        label_sugg_title->setObjectName("label_sugg_title");

        layout_sugg_head->addWidget(label_sugg_title);

        comboBox_rec_type = new QComboBox(card_suggestions);
        comboBox_rec_type->addItem(QString());
        comboBox_rec_type->addItem(QString());
        comboBox_rec_type->addItem(QString());
        comboBox_rec_type->addItem(QString());
        comboBox_rec_type->setObjectName("comboBox_rec_type");

        layout_sugg_head->addWidget(comboBox_rec_type);


        layout_card_sugg->addLayout(layout_sugg_head);

        listWidget_suggestions = new QListWidget(card_suggestions);
        listWidget_suggestions->setObjectName("listWidget_suggestions");

        layout_card_sugg->addWidget(listWidget_suggestions);


        layout_bottom->addWidget(card_suggestions);


        layout_content->addWidget(frame_bottom);


        layout_pageFournisseurs->addWidget(frame_content);

        frame_right = new QFrame(pageFournisseurs);
        frame_right->setObjectName("frame_right");
        frame_right->setMinimumSize(QSize(360, 0));
        frame_right->setMaximumSize(QSize(360, 16777215));
        layout_right = new QVBoxLayout(frame_right);
        layout_right->setObjectName("layout_right");
        layout_right->setContentsMargins(12, 12, 12, 12);
        label_form_title = new QLabel(frame_right);
        label_form_title->setObjectName("label_form_title");

        layout_right->addWidget(label_form_title);

        scrollArea_form = new QScrollArea(frame_right);
        scrollArea_form->setObjectName("scrollArea_form");
        scrollArea_form->setFrameShape(QFrame::NoFrame);
        scrollArea_form->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 320, 600));
        layout_form = new QVBoxLayout(scrollAreaWidgetContents);
        layout_form->setSpacing(4);
        layout_form->setObjectName("layout_form");
        layout_form->setContentsMargins(0, 0, 0, 0);
        label_nom = new QLabel(scrollAreaWidgetContents);
        label_nom->setObjectName("label_nom");

        layout_form->addWidget(label_nom);

        lineEdit_nom = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_nom->setObjectName("lineEdit_nom");

        layout_form->addWidget(lineEdit_nom);

        label_contact = new QLabel(scrollAreaWidgetContents);
        label_contact->setObjectName("label_contact");

        layout_form->addWidget(label_contact);

        lineEdit_contact = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_contact->setObjectName("lineEdit_contact");

        layout_form->addWidget(lineEdit_contact);

        layout_tel_email = new QHBoxLayout();
        layout_tel_email->setObjectName("layout_tel_email");
        layout_tel = new QVBoxLayout();
        layout_tel->setObjectName("layout_tel");
        label_tel = new QLabel(scrollAreaWidgetContents);
        label_tel->setObjectName("label_tel");

        layout_tel->addWidget(label_tel);

        lineEdit_tel = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_tel->setObjectName("lineEdit_tel");

        layout_tel->addWidget(lineEdit_tel);


        layout_tel_email->addLayout(layout_tel);

        layout_email = new QVBoxLayout();
        layout_email->setObjectName("layout_email");
        label_email = new QLabel(scrollAreaWidgetContents);
        label_email->setObjectName("label_email");

        layout_email->addWidget(label_email);

        lineEdit_email = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_email->setObjectName("lineEdit_email");

        layout_email->addWidget(lineEdit_email);


        layout_tel_email->addLayout(layout_email);


        layout_form->addLayout(layout_tel_email);

        label_adresse = new QLabel(scrollAreaWidgetContents);
        label_adresse->setObjectName("label_adresse");

        layout_form->addWidget(label_adresse);

        lineEdit_adresse = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_adresse->setObjectName("lineEdit_adresse");

        layout_form->addWidget(lineEdit_adresse);

        layout_type_status = new QHBoxLayout();
        layout_type_status->setObjectName("layout_type_status");
        layout_type = new QVBoxLayout();
        layout_type->setObjectName("layout_type");
        label_type = new QLabel(scrollAreaWidgetContents);
        label_type->setObjectName("label_type");

        layout_type->addWidget(label_type);

        comboBox_type = new QComboBox(scrollAreaWidgetContents);
        comboBox_type->addItem(QString());
        comboBox_type->addItem(QString());
        comboBox_type->addItem(QString());
        comboBox_type->addItem(QString());
        comboBox_type->addItem(QString());
        comboBox_type->setObjectName("comboBox_type");

        layout_type->addWidget(comboBox_type);


        layout_type_status->addLayout(layout_type);

        layout_status = new QVBoxLayout();
        layout_status->setObjectName("layout_status");
        label_status = new QLabel(scrollAreaWidgetContents);
        label_status->setObjectName("label_status");

        layout_status->addWidget(label_status);

        comboBox_status = new QComboBox(scrollAreaWidgetContents);
        comboBox_status->addItem(QString());
        comboBox_status->addItem(QString());
        comboBox_status->addItem(QString());
        comboBox_status->setObjectName("comboBox_status");

        layout_status->addWidget(comboBox_status);


        layout_type_status->addLayout(layout_status);


        layout_form->addLayout(layout_type_status);

        layout_quantite_prix = new QHBoxLayout();
        layout_quantite_prix->setObjectName("layout_quantite_prix");
        layout_quantite = new QVBoxLayout();
        layout_quantite->setObjectName("layout_quantite");
        label_quantite = new QLabel(scrollAreaWidgetContents);
        label_quantite->setObjectName("label_quantite");

        layout_quantite->addWidget(label_quantite);

        spinBox_quantite = new QSpinBox(scrollAreaWidgetContents);
        spinBox_quantite->setObjectName("spinBox_quantite");
        spinBox_quantite->setMaximum(999999);

        layout_quantite->addWidget(spinBox_quantite);


        layout_quantite_prix->addLayout(layout_quantite);

        layout_prix = new QVBoxLayout();
        layout_prix->setObjectName("layout_prix");
        label_prix = new QLabel(scrollAreaWidgetContents);
        label_prix->setObjectName("label_prix");

        layout_prix->addWidget(label_prix);

        doubleSpinBox_prix = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_prix->setObjectName("doubleSpinBox_prix");
        doubleSpinBox_prix->setDecimals(3);
        doubleSpinBox_prix->setMaximum(999999);

        layout_prix->addWidget(doubleSpinBox_prix);


        layout_quantite_prix->addLayout(layout_prix);


        layout_form->addLayout(layout_quantite_prix);

        label_date = new QLabel(scrollAreaWidgetContents);
        label_date->setObjectName("label_date");

        layout_form->addWidget(label_date);

        dateEdit_contrat = new QDateEdit(scrollAreaWidgetContents);
        dateEdit_contrat->setObjectName("dateEdit_contrat");
        dateEdit_contrat->setCalendarPopup(true);

        layout_form->addWidget(dateEdit_contrat);

        scrollArea_form->setWidget(scrollAreaWidgetContents);

        layout_right->addWidget(scrollArea_form);

        btn_enregistrer = new QPushButton(frame_right);
        btn_enregistrer->setObjectName("btn_enregistrer");
        btn_enregistrer->setMinimumSize(QSize(0, 36));

        layout_right->addWidget(btn_enregistrer);

        layout_mod_ann = new QHBoxLayout();
        layout_mod_ann->setObjectName("layout_mod_ann");
        btn_modifier = new QPushButton(frame_right);
        btn_modifier->setObjectName("btn_modifier");
        btn_modifier->setMinimumSize(QSize(0, 36));
        btn_modifier->setEnabled(false);

        layout_mod_ann->addWidget(btn_modifier);

        btn_annuler = new QPushButton(frame_right);
        btn_annuler->setObjectName("btn_annuler");
        btn_annuler->setMinimumSize(QSize(0, 36));
        btn_annuler->setEnabled(false);

        layout_mod_ann->addWidget(btn_annuler);


        layout_right->addLayout(layout_mod_ann);

        btn_supprimer = new QPushButton(frame_right);
        btn_supprimer->setObjectName("btn_supprimer");
        btn_supprimer->setMinimumSize(QSize(0, 36));

        layout_right->addWidget(btn_supprimer);

        card_export = new QFrame(frame_right);
        card_export->setObjectName("card_export");
        layout_card_export = new QVBoxLayout(card_export);
        layout_card_export->setObjectName("layout_card_export");
        label_export_title = new QLabel(card_export);
        label_export_title->setObjectName("label_export_title");

        layout_card_export->addWidget(label_export_title);

        label_export_desc = new QLabel(card_export);
        label_export_desc->setObjectName("label_export_desc");
        label_export_desc->setWordWrap(true);

        layout_card_export->addWidget(label_export_desc);

        layout_export_btns = new QHBoxLayout();
        layout_export_btns->setObjectName("layout_export_btns");
        btn_export_pdf = new QPushButton(card_export);
        btn_export_pdf->setObjectName("btn_export_pdf");

        layout_export_btns->addWidget(btn_export_pdf);

        btn_export_excel = new QPushButton(card_export);
        btn_export_excel->setObjectName("btn_export_excel");

        layout_export_btns->addWidget(btn_export_excel);


        layout_card_export->addLayout(layout_export_btns);


        layout_right->addWidget(card_export);


        layout_pageFournisseurs->addWidget(frame_right);

        SWPetManager->addWidget(pageFournisseurs);
        pageStock = new QWidget();
        pageStock->setObjectName("pageStock");
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI")});
        font.setPointSize(10);
        pageStock->setFont(font);
        layoutModuleStock = new QVBoxLayout(pageStock);
        layoutModuleStock->setSpacing(0);
        layoutModuleStock->setObjectName("layoutModuleStock");
        layoutModuleStock->setContentsMargins(0, 0, 0, 0);
        frameHeader = new QFrame(pageStock);
        frameHeader->setObjectName("frameHeader");
        frameHeader->setMinimumSize(QSize(0, 80));
        frameHeader->setMaximumSize(QSize(16777215, 80));
        layoutHeader = new QHBoxLayout(frameHeader);
        layoutHeader->setSpacing(10);
        layoutHeader->setObjectName("layoutHeader");
        layoutHeader->setContentsMargins(20, 0, 25, 0);
        lblIconeTitre = new QLabel(frameHeader);
        lblIconeTitre->setObjectName("lblIconeTitre");
        lblIconeTitre->setMinimumSize(QSize(34, 34));
        lblIconeTitre->setMaximumSize(QSize(34, 34));
        lblIconeTitre->setScaledContents(true);

        layoutHeader->addWidget(lblIconeTitre);

        lblTitre = new QLabel(frameHeader);
        lblTitre->setObjectName("lblTitre");

        layoutHeader->addWidget(lblTitre);

        espaceHeader = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        layoutHeader->addItem(espaceHeader);

        btnNotif = new QPushButton(frameHeader);
        btnNotif->setObjectName("btnNotif");
        btnNotif->setMinimumSize(QSize(40, 40));
        btnNotif->setMaximumSize(QSize(40, 40));
        btnNotif->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icones/bell_teal.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnNotif->setIcon(icon);
        btnNotif->setIconSize(QSize(24, 24));

        layoutHeader->addWidget(btnNotif);

        espaceAvatar = new QSpacerItem(10, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        layoutHeader->addItem(espaceAvatar);

        lblAvatar = new QLabel(frameHeader);
        lblAvatar->setObjectName("lblAvatar");
        lblAvatar->setMinimumSize(QSize(44, 44));
        lblAvatar->setMaximumSize(QSize(44, 44));
        lblAvatar->setAlignment(Qt::AlignCenter);

        layoutHeader->addWidget(lblAvatar);

        widgetUtilisateur = new QWidget(frameHeader);
        widgetUtilisateur->setObjectName("widgetUtilisateur");
        widgetUtilisateur->setMinimumSize(QSize(150, 44));
        widgetUtilisateur->setMaximumSize(QSize(150, 44));
        lblNomMedecin = new QLabel(widgetUtilisateur);
        lblNomMedecin->setObjectName("lblNomMedecin");
        lblNomMedecin->setGeometry(QRect(0, 2, 150, 20));
        lblRole = new QLabel(widgetUtilisateur);
        lblRole->setObjectName("lblRole");
        lblRole->setGeometry(QRect(0, 22, 150, 18));

        layoutHeader->addWidget(widgetUtilisateur);


        layoutModuleStock->addWidget(frameHeader);

        stackStock = new QStackedWidget(pageStock);
        stackStock->setObjectName("stackStock");
        pageGestionStock = new QWidget();
        pageGestionStock->setObjectName("pageGestionStock");
        layoutPageStock = new QVBoxLayout(pageGestionStock);
        layoutPageStock->setSpacing(0);
        layoutPageStock->setObjectName("layoutPageStock");
        layoutPageStock->setContentsMargins(0, 0, 0, 0);
        scrollStock = new QScrollArea(pageGestionStock);
        scrollStock->setObjectName("scrollStock");
        scrollStock->setFrameShape(QFrame::NoFrame);
        scrollStock->setWidgetResizable(true);
        contenuStock = new QWidget();
        contenuStock->setObjectName("contenuStock");
        contenuStock->setGeometry(QRect(0, 0, 1100, 1200));
        layoutContenu = new QVBoxLayout(contenuStock);
        layoutContenu->setSpacing(18);
        layoutContenu->setObjectName("layoutContenu");
        layoutContenu->setContentsMargins(20, 16, 20, 25);
        zoneHautStock = new QWidget(contenuStock);
        zoneHautStock->setObjectName("zoneHautStock");
        layout_zoneHaut = new QHBoxLayout(zoneHautStock);
        layout_zoneHaut->setSpacing(18);
        layout_zoneHaut->setObjectName("layout_zoneHaut");
        layout_zoneHaut->setContentsMargins(0, 0, 0, 0);
        colonneGaucheStock = new QWidget(zoneHautStock);
        colonneGaucheStock->setObjectName("colonneGaucheStock");
        layout_colonneGauche = new QVBoxLayout(colonneGaucheStock);
        layout_colonneGauche->setSpacing(14);
        layout_colonneGauche->setObjectName("layout_colonneGauche");
        layout_colonneGauche->setContentsMargins(0, 0, 0, 0);
        ligneCartesStock = new QWidget(colonneGaucheStock);
        ligneCartesStock->setObjectName("ligneCartesStock");
        layout_ligneCartes = new QHBoxLayout(ligneCartesStock);
        layout_ligneCartes->setSpacing(14);
        layout_ligneCartes->setObjectName("layout_ligneCartes");
        layout_ligneCartes->setContentsMargins(0, 0, 0, 0);
        frameCarte1Stock = new QFrame(ligneCartesStock);
        frameCarte1Stock->setObjectName("frameCarte1Stock");
        frameCarte1Stock->setMinimumSize(QSize(190, 82));
        frameCarte1Stock->setMaximumSize(QSize(16777215, 82));
        lblCarte1IconeStock = new QLabel(frameCarte1Stock);
        lblCarte1IconeStock->setObjectName("lblCarte1IconeStock");
        lblCarte1IconeStock->setGeometry(QRect(18, 25, 32, 32));
        lblCarte1IconeStock->setScaledContents(true);
        lblCarte1IconeStock->setPixmap(QPixmap(QString::fromUtf8(":/icones/box_teal.png")));
        lblCarte1TitreStock = new QLabel(frameCarte1Stock);
        lblCarte1TitreStock->setObjectName("lblCarte1TitreStock");
        lblCarte1TitreStock->setGeometry(QRect(64, 12, 220, 22));
        lblValeurTotalStock = new QLabel(frameCarte1Stock);
        lblValeurTotalStock->setObjectName("lblValeurTotalStock");
        lblValeurTotalStock->setGeometry(QRect(64, 34, 220, 36));

        layout_ligneCartes->addWidget(frameCarte1Stock);

        frameCarte2Stock = new QFrame(ligneCartesStock);
        frameCarte2Stock->setObjectName("frameCarte2Stock");
        frameCarte2Stock->setMinimumSize(QSize(190, 82));
        frameCarte2Stock->setMaximumSize(QSize(16777215, 82));
        lblCarte2IconeStock = new QLabel(frameCarte2Stock);
        lblCarte2IconeStock->setObjectName("lblCarte2IconeStock");
        lblCarte2IconeStock->setGeometry(QRect(18, 25, 32, 32));
        lblCarte2IconeStock->setScaledContents(true);
        lblCarte2IconeStock->setPixmap(QPixmap(QString::fromUtf8(":/icones/warning_red.png")));
        lblCarte2TitreStock = new QLabel(frameCarte2Stock);
        lblCarte2TitreStock->setObjectName("lblCarte2TitreStock");
        lblCarte2TitreStock->setGeometry(QRect(64, 12, 220, 22));
        lblValeurReapproStock = new QLabel(frameCarte2Stock);
        lblValeurReapproStock->setObjectName("lblValeurReapproStock");
        lblValeurReapproStock->setGeometry(QRect(64, 34, 220, 36));

        layout_ligneCartes->addWidget(frameCarte2Stock);

        frameCarte3Stock = new QFrame(ligneCartesStock);
        frameCarte3Stock->setObjectName("frameCarte3Stock");
        frameCarte3Stock->setMinimumSize(QSize(190, 82));
        frameCarte3Stock->setMaximumSize(QSize(16777215, 82));
        lblCarte3IconeStock = new QLabel(frameCarte3Stock);
        lblCarte3IconeStock->setObjectName("lblCarte3IconeStock");
        lblCarte3IconeStock->setGeometry(QRect(18, 25, 32, 32));
        lblCarte3IconeStock->setScaledContents(true);
        lblCarte3IconeStock->setPixmap(QPixmap(QString::fromUtf8(":/icones/coins_orange.png")));
        lblCarte3TitreStock = new QLabel(frameCarte3Stock);
        lblCarte3TitreStock->setObjectName("lblCarte3TitreStock");
        lblCarte3TitreStock->setGeometry(QRect(64, 12, 220, 22));
        lblValeurStock = new QLabel(frameCarte3Stock);
        lblValeurStock->setObjectName("lblValeurStock");
        lblValeurStock->setGeometry(QRect(64, 34, 220, 36));

        layout_ligneCartes->addWidget(frameCarte3Stock);


        layout_colonneGauche->addWidget(ligneCartesStock);

        ligneRechercheStock = new QWidget(colonneGaucheStock);
        ligneRechercheStock->setObjectName("ligneRechercheStock");
        layout_ligneRecherche = new QHBoxLayout(ligneRechercheStock);
        layout_ligneRecherche->setSpacing(14);
        layout_ligneRecherche->setObjectName("layout_ligneRecherche");
        layout_ligneRecherche->setContentsMargins(0, 0, 0, 0);
        txtRechercheStock = new QLineEdit(ligneRechercheStock);
        txtRechercheStock->setObjectName("txtRechercheStock");
        txtRechercheStock->setMinimumSize(QSize(200, 42));
        txtRechercheStock->setMaximumSize(QSize(16777215, 42));

        layout_ligneRecherche->addWidget(txtRechercheStock);

        cmbTriStock = new QComboBox(ligneRechercheStock);
        cmbTriStock->setObjectName("cmbTriStock");
        cmbTriStock->setMinimumSize(QSize(330, 42));
        cmbTriStock->setMaximumSize(QSize(330, 42));
        cmbTriStock->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        layout_ligneRecherche->addWidget(cmbTriStock);


        layout_colonneGauche->addWidget(ligneRechercheStock);

        tableStock = new QTableWidget(colonneGaucheStock);
        tableStock->setObjectName("tableStock");

        layout_colonneGauche->addWidget(tableStock);

        lblAffichageStock = new QLabel(colonneGaucheStock);
        lblAffichageStock->setObjectName("lblAffichageStock");

        layout_colonneGauche->addWidget(lblAffichageStock);

        ligneBlocsStock = new QWidget(colonneGaucheStock);
        ligneBlocsStock->setObjectName("ligneBlocsStock");
        layout_ligneBlocs = new QHBoxLayout(ligneBlocsStock);
        layout_ligneBlocs->setSpacing(14);
        layout_ligneBlocs->setObjectName("layout_ligneBlocs");
        layout_ligneBlocs->setContentsMargins(0, 0, 0, 0);
        frameAlertesStock = new QFrame(ligneBlocsStock);
        frameAlertesStock->setObjectName("frameAlertesStock");
        frameAlertesStock->setMinimumSize(QSize(260, 195));
        frameAlertesStock->setMaximumSize(QSize(16777215, 195));
        layoutAlertes = new QVBoxLayout(frameAlertesStock);
        layoutAlertes->setSpacing(8);
        layoutAlertes->setObjectName("layoutAlertes");
        layoutAlertes->setContentsMargins(14, 12, 14, 10);
        enteteAlertesStock = new QWidget(frameAlertesStock);
        enteteAlertesStock->setObjectName("enteteAlertesStock");
        layout_enteteAlertes = new QHBoxLayout(enteteAlertesStock);
        layout_enteteAlertes->setSpacing(8);
        layout_enteteAlertes->setObjectName("layout_enteteAlertes");
        layout_enteteAlertes->setContentsMargins(0, 0, 0, 0);
        lblAlerteTitreStock = new QLabel(enteteAlertesStock);
        lblAlerteTitreStock->setObjectName("lblAlerteTitreStock");

        layout_enteteAlertes->addWidget(lblAlerteTitreStock);

        espaceAlertes = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        layout_enteteAlertes->addItem(espaceAlertes);

        lblAlerteBadgeStock = new QLabel(enteteAlertesStock);
        lblAlerteBadgeStock->setObjectName("lblAlerteBadgeStock");
        lblAlerteBadgeStock->setMinimumSize(QSize(22, 22));
        lblAlerteBadgeStock->setMaximumSize(QSize(22, 22));
        lblAlerteBadgeStock->setAlignment(Qt::AlignCenter);

        layout_enteteAlertes->addWidget(lblAlerteBadgeStock);


        layoutAlertes->addWidget(enteteAlertesStock);

        ligneAlerte1Stock = new QWidget(frameAlertesStock);
        ligneAlerte1Stock->setObjectName("ligneAlerte1Stock");
        layout_ligneAlerte1 = new QHBoxLayout(ligneAlerte1Stock);
        layout_ligneAlerte1->setSpacing(8);
        layout_ligneAlerte1->setObjectName("layout_ligneAlerte1");
        layout_ligneAlerte1->setContentsMargins(0, 0, 0, 0);
        lblAlerte1Stock = new QLabel(ligneAlerte1Stock);
        lblAlerte1Stock->setObjectName("lblAlerte1Stock");
        lblAlerte1Stock->setTextFormat(Qt::RichText);

        layout_ligneAlerte1->addWidget(lblAlerte1Stock);

        lblQte1Stock = new QLabel(ligneAlerte1Stock);
        lblQte1Stock->setObjectName("lblQte1Stock");
        lblQte1Stock->setMinimumSize(QSize(70, 0));
        lblQte1Stock->setMaximumSize(QSize(70, 16777215));
        lblQte1Stock->setAlignment(Qt::AlignRight|Qt::AlignVCenter);

        layout_ligneAlerte1->addWidget(lblQte1Stock);


        layoutAlertes->addWidget(ligneAlerte1Stock);

        ligneAlerte2Stock = new QWidget(frameAlertesStock);
        ligneAlerte2Stock->setObjectName("ligneAlerte2Stock");
        layout_ligneAlerte2 = new QHBoxLayout(ligneAlerte2Stock);
        layout_ligneAlerte2->setSpacing(8);
        layout_ligneAlerte2->setObjectName("layout_ligneAlerte2");
        layout_ligneAlerte2->setContentsMargins(0, 0, 0, 0);
        lblAlerte2Stock = new QLabel(ligneAlerte2Stock);
        lblAlerte2Stock->setObjectName("lblAlerte2Stock");
        lblAlerte2Stock->setTextFormat(Qt::RichText);

        layout_ligneAlerte2->addWidget(lblAlerte2Stock);

        lblQte2Stock = new QLabel(ligneAlerte2Stock);
        lblQte2Stock->setObjectName("lblQte2Stock");
        lblQte2Stock->setMinimumSize(QSize(70, 0));
        lblQte2Stock->setMaximumSize(QSize(70, 16777215));
        lblQte2Stock->setAlignment(Qt::AlignRight|Qt::AlignVCenter);

        layout_ligneAlerte2->addWidget(lblQte2Stock);


        layoutAlertes->addWidget(ligneAlerte2Stock);

        ligneAlerte3Stock = new QWidget(frameAlertesStock);
        ligneAlerte3Stock->setObjectName("ligneAlerte3Stock");
        layout_ligneAlerte3 = new QHBoxLayout(ligneAlerte3Stock);
        layout_ligneAlerte3->setSpacing(8);
        layout_ligneAlerte3->setObjectName("layout_ligneAlerte3");
        layout_ligneAlerte3->setContentsMargins(0, 0, 0, 0);
        lblAlerte3Stock = new QLabel(ligneAlerte3Stock);
        lblAlerte3Stock->setObjectName("lblAlerte3Stock");
        lblAlerte3Stock->setTextFormat(Qt::RichText);

        layout_ligneAlerte3->addWidget(lblAlerte3Stock);

        lblQte3Stock = new QLabel(ligneAlerte3Stock);
        lblQte3Stock->setObjectName("lblQte3Stock");
        lblQte3Stock->setMinimumSize(QSize(70, 0));
        lblQte3Stock->setMaximumSize(QSize(70, 16777215));
        lblQte3Stock->setAlignment(Qt::AlignRight|Qt::AlignVCenter);

        layout_ligneAlerte3->addWidget(lblQte3Stock);


        layoutAlertes->addWidget(ligneAlerte3Stock);

        espaceBasAlertes = new QSpacerItem(40, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        layoutAlertes->addItem(espaceBasAlertes);

        btnVoirToutStock = new QPushButton(frameAlertesStock);
        btnVoirToutStock->setObjectName("btnVoirToutStock");
        btnVoirToutStock->setMinimumSize(QSize(120, 24));
        btnVoirToutStock->setMaximumSize(QSize(120, 24));
        btnVoirToutStock->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        layoutAlertes->addWidget(btnVoirToutStock);


        layout_ligneBlocs->addWidget(frameAlertesStock);

        frameAlternatifsStock = new QFrame(ligneBlocsStock);
        frameAlternatifsStock->setObjectName("frameAlternatifsStock");
        frameAlternatifsStock->setMinimumSize(QSize(260, 195));
        frameAlternatifsStock->setMaximumSize(QSize(16777215, 195));
        layoutAlternatifs = new QVBoxLayout(frameAlternatifsStock);
        layoutAlternatifs->setSpacing(6);
        layoutAlternatifs->setObjectName("layoutAlternatifs");
        layoutAlternatifs->setContentsMargins(12, 10, 12, 10);
        lblAltTitreStock = new QLabel(frameAlternatifsStock);
        lblAltTitreStock->setObjectName("lblAltTitreStock");

        layoutAlternatifs->addWidget(lblAltTitreStock);

        lblAltPourStock = new QLabel(frameAlternatifsStock);
        lblAltPourStock->setObjectName("lblAltPourStock");

        layoutAlternatifs->addWidget(lblAltPourStock);

        frameAlt1Stock = new QFrame(frameAlternatifsStock);
        frameAlt1Stock->setObjectName("frameAlt1Stock");
        frameAlt1Stock->setMinimumSize(QSize(0, 58));
        frameAlt1Stock->setMaximumSize(QSize(16777215, 58));
        frameAlt1Stock->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        layoutAlt1 = new QHBoxLayout(frameAlt1Stock);
        layoutAlt1->setSpacing(8);
        layoutAlt1->setObjectName("layoutAlt1");
        layoutAlt1->setContentsMargins(8, 4, 10, 4);
        lblAltIcone1Stock = new QLabel(frameAlt1Stock);
        lblAltIcone1Stock->setObjectName("lblAltIcone1Stock");
        lblAltIcone1Stock->setMinimumSize(QSize(34, 0));
        lblAltIcone1Stock->setMaximumSize(QSize(34, 16777215));

        layoutAlt1->addWidget(lblAltIcone1Stock);

        textesAlt1Stock = new QWidget(frameAlt1Stock);
        textesAlt1Stock->setObjectName("textesAlt1Stock");
        layout_textesAlt1 = new QVBoxLayout(textesAlt1Stock);
        layout_textesAlt1->setSpacing(0);
        layout_textesAlt1->setObjectName("layout_textesAlt1");
        layout_textesAlt1->setContentsMargins(0, 0, 0, 0);
        lblAltNom1Stock = new QLabel(textesAlt1Stock);
        lblAltNom1Stock->setObjectName("lblAltNom1Stock");

        layout_textesAlt1->addWidget(lblAltNom1Stock);

        lblAltCat1Stock = new QLabel(textesAlt1Stock);
        lblAltCat1Stock->setObjectName("lblAltCat1Stock");

        layout_textesAlt1->addWidget(lblAltCat1Stock);

        lblAltQte1Stock = new QLabel(textesAlt1Stock);
        lblAltQte1Stock->setObjectName("lblAltQte1Stock");

        layout_textesAlt1->addWidget(lblAltQte1Stock);


        layoutAlt1->addWidget(textesAlt1Stock);

        lblAltFleche1Stock = new QLabel(frameAlt1Stock);
        lblAltFleche1Stock->setObjectName("lblAltFleche1Stock");
        lblAltFleche1Stock->setMinimumSize(QSize(12, 0));
        lblAltFleche1Stock->setMaximumSize(QSize(12, 16777215));

        layoutAlt1->addWidget(lblAltFleche1Stock);


        layoutAlternatifs->addWidget(frameAlt1Stock);

        frameAlt2Stock = new QFrame(frameAlternatifsStock);
        frameAlt2Stock->setObjectName("frameAlt2Stock");
        frameAlt2Stock->setMinimumSize(QSize(0, 58));
        frameAlt2Stock->setMaximumSize(QSize(16777215, 58));
        frameAlt2Stock->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        layoutAlt2 = new QHBoxLayout(frameAlt2Stock);
        layoutAlt2->setSpacing(8);
        layoutAlt2->setObjectName("layoutAlt2");
        layoutAlt2->setContentsMargins(8, 4, 10, 4);
        lblAltIcone2Stock = new QLabel(frameAlt2Stock);
        lblAltIcone2Stock->setObjectName("lblAltIcone2Stock");
        lblAltIcone2Stock->setMinimumSize(QSize(34, 0));
        lblAltIcone2Stock->setMaximumSize(QSize(34, 16777215));

        layoutAlt2->addWidget(lblAltIcone2Stock);

        textesAlt2Stock = new QWidget(frameAlt2Stock);
        textesAlt2Stock->setObjectName("textesAlt2Stock");
        layout_textesAlt2 = new QVBoxLayout(textesAlt2Stock);
        layout_textesAlt2->setSpacing(0);
        layout_textesAlt2->setObjectName("layout_textesAlt2");
        layout_textesAlt2->setContentsMargins(0, 0, 0, 0);
        lblAltNom2Stock = new QLabel(textesAlt2Stock);
        lblAltNom2Stock->setObjectName("lblAltNom2Stock");

        layout_textesAlt2->addWidget(lblAltNom2Stock);

        lblAltCat2Stock = new QLabel(textesAlt2Stock);
        lblAltCat2Stock->setObjectName("lblAltCat2Stock");

        layout_textesAlt2->addWidget(lblAltCat2Stock);

        lblAltQte2Stock = new QLabel(textesAlt2Stock);
        lblAltQte2Stock->setObjectName("lblAltQte2Stock");

        layout_textesAlt2->addWidget(lblAltQte2Stock);


        layoutAlt2->addWidget(textesAlt2Stock);

        lblAltFleche2Stock = new QLabel(frameAlt2Stock);
        lblAltFleche2Stock->setObjectName("lblAltFleche2Stock");
        lblAltFleche2Stock->setMinimumSize(QSize(12, 0));
        lblAltFleche2Stock->setMaximumSize(QSize(12, 16777215));

        layoutAlt2->addWidget(lblAltFleche2Stock);


        layoutAlternatifs->addWidget(frameAlt2Stock);

        lblAucuneAltStock = new QLabel(frameAlternatifsStock);
        lblAucuneAltStock->setObjectName("lblAucuneAltStock");
        lblAucuneAltStock->setWordWrap(true);

        layoutAlternatifs->addWidget(lblAucuneAltStock);

        espaceBasAlternatifs = new QSpacerItem(40, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        layoutAlternatifs->addItem(espaceBasAlternatifs);


        layout_ligneBlocs->addWidget(frameAlternatifsStock);

        layout_ligneBlocs->setStretch(0, 1);
        layout_ligneBlocs->setStretch(1, 1);

        layout_colonneGauche->addWidget(ligneBlocsStock);


        layout_zoneHaut->addWidget(colonneGaucheStock);

        colonneDroiteStock = new QWidget(zoneHautStock);
        colonneDroiteStock->setObjectName("colonneDroiteStock");
        colonneDroiteStock->setMinimumSize(QSize(290, 0));
        colonneDroiteStock->setMaximumSize(QSize(290, 16777215));
        layout_colonneDroite = new QVBoxLayout(colonneDroiteStock);
        layout_colonneDroite->setSpacing(14);
        layout_colonneDroite->setObjectName("layout_colonneDroite");
        layout_colonneDroite->setContentsMargins(0, 0, 0, 0);
        frameFormulaireStock = new QFrame(colonneDroiteStock);
        frameFormulaireStock->setObjectName("frameFormulaireStock");
        frameFormulaireStock->setMinimumSize(QSize(290, 698));
        frameFormulaireStock->setMaximumSize(QSize(290, 698));
        lblFormTitreStock = new QLabel(frameFormulaireStock);
        lblFormTitreStock->setObjectName("lblFormTitreStock");
        lblFormTitreStock->setGeometry(QRect(15, 14, 260, 26));
        lblSeparateurStock = new QLabel(frameFormulaireStock);
        lblSeparateurStock->setObjectName("lblSeparateurStock");
        lblSeparateurStock->setGeometry(QRect(0, 50, 290, 1));
        lblNomStock = new QLabel(frameFormulaireStock);
        lblNomStock->setObjectName("lblNomStock");
        lblNomStock->setGeometry(QRect(15, 62, 260, 20));
        lblNomStock->setTextFormat(Qt::RichText);
        txtNomStock = new QLineEdit(frameFormulaireStock);
        txtNomStock->setObjectName("txtNomStock");
        txtNomStock->setGeometry(QRect(15, 82, 260, 32));
        lblCategorieStock = new QLabel(frameFormulaireStock);
        lblCategorieStock->setObjectName("lblCategorieStock");
        lblCategorieStock->setGeometry(QRect(15, 120, 260, 20));
        lblCategorieStock->setTextFormat(Qt::RichText);
        cmbCategorieStock = new QComboBox(frameFormulaireStock);
        cmbCategorieStock->setObjectName("cmbCategorieStock");
        cmbCategorieStock->setGeometry(QRect(15, 140, 260, 32));
        cmbCategorieStock->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        lblEspeceStock = new QLabel(frameFormulaireStock);
        lblEspeceStock->setObjectName("lblEspeceStock");
        lblEspeceStock->setGeometry(QRect(15, 178, 126, 20));
        lblEspeceStock->setTextFormat(Qt::RichText);
        cmbEspeceStock = new QComboBox(frameFormulaireStock);
        cmbEspeceStock->setObjectName("cmbEspeceStock");
        cmbEspeceStock->setGeometry(QRect(15, 198, 126, 32));
        cmbEspeceStock->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        lblUsageStock = new QLabel(frameFormulaireStock);
        lblUsageStock->setObjectName("lblUsageStock");
        lblUsageStock->setGeometry(QRect(149, 178, 126, 20));
        lblUsageStock->setTextFormat(Qt::RichText);
        cmbUsageStock = new QComboBox(frameFormulaireStock);
        cmbUsageStock->setObjectName("cmbUsageStock");
        cmbUsageStock->setGeometry(QRect(149, 198, 126, 32));
        cmbUsageStock->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        lblQuantiteStock = new QLabel(frameFormulaireStock);
        lblQuantiteStock->setObjectName("lblQuantiteStock");
        lblQuantiteStock->setGeometry(QRect(15, 236, 260, 20));
        lblQuantiteStock->setTextFormat(Qt::RichText);
        spinQuantiteStock = new QSpinBox(frameFormulaireStock);
        spinQuantiteStock->setObjectName("spinQuantiteStock");
        spinQuantiteStock->setGeometry(QRect(15, 256, 260, 32));
        lblSeuilStock = new QLabel(frameFormulaireStock);
        lblSeuilStock->setObjectName("lblSeuilStock");
        lblSeuilStock->setGeometry(QRect(15, 294, 260, 20));
        lblSeuilStock->setTextFormat(Qt::RichText);
        spinSeuilStock = new QSpinBox(frameFormulaireStock);
        spinSeuilStock->setObjectName("spinSeuilStock");
        spinSeuilStock->setGeometry(QRect(15, 314, 260, 32));
        lblDateStock = new QLabel(frameFormulaireStock);
        lblDateStock->setObjectName("lblDateStock");
        lblDateStock->setGeometry(QRect(15, 352, 260, 20));
        lblDateStock->setTextFormat(Qt::RichText);
        dateExpirationStock = new QDateEdit(frameFormulaireStock);
        dateExpirationStock->setObjectName("dateExpirationStock");
        dateExpirationStock->setGeometry(QRect(15, 372, 260, 32));
        dateExpirationStock->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        lblFournisseurStock = new QLabel(frameFormulaireStock);
        lblFournisseurStock->setObjectName("lblFournisseurStock");
        lblFournisseurStock->setGeometry(QRect(15, 410, 260, 20));
        lblFournisseurStock->setTextFormat(Qt::RichText);
        txtFournisseurStock = new QLineEdit(frameFormulaireStock);
        txtFournisseurStock->setObjectName("txtFournisseurStock");
        txtFournisseurStock->setGeometry(QRect(15, 430, 260, 32));
        lblPrixStock = new QLabel(frameFormulaireStock);
        lblPrixStock->setObjectName("lblPrixStock");
        lblPrixStock->setGeometry(QRect(15, 468, 260, 20));
        lblPrixStock->setTextFormat(Qt::RichText);
        spinPrixStock = new QDoubleSpinBox(frameFormulaireStock);
        spinPrixStock->setObjectName("spinPrixStock");
        spinPrixStock->setGeometry(QRect(15, 488, 260, 32));
        btnEnregistrerStock = new QPushButton(frameFormulaireStock);
        btnEnregistrerStock->setObjectName("btnEnregistrerStock");
        btnEnregistrerStock->setGeometry(QRect(15, 544, 260, 40));
        btnEnregistrerStock->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icones/save_white.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnEnregistrerStock->setIcon(icon1);
        btnEnregistrerStock->setIconSize(QSize(18, 18));
        btnModifierStock = new QPushButton(frameFormulaireStock);
        btnModifierStock->setObjectName("btnModifierStock");
        btnModifierStock->setGeometry(QRect(15, 592, 126, 40));
        btnModifierStock->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icones/pencil_teal.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnModifierStock->setIcon(icon2);
        btnModifierStock->setIconSize(QSize(18, 18));
        btnAnnulerStock = new QPushButton(frameFormulaireStock);
        btnAnnulerStock->setObjectName("btnAnnulerStock");
        btnAnnulerStock->setGeometry(QRect(149, 592, 126, 40));
        btnAnnulerStock->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icones/croix_grey.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnAnnulerStock->setIcon(icon3);
        btnAnnulerStock->setIconSize(QSize(14, 14));
        btnSupprimerStock = new QPushButton(frameFormulaireStock);
        btnSupprimerStock->setObjectName("btnSupprimerStock");
        btnSupprimerStock->setGeometry(QRect(15, 640, 260, 40));
        btnSupprimerStock->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icones/trash_red.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnSupprimerStock->setIcon(icon4);
        btnSupprimerStock->setIconSize(QSize(18, 18));

        layout_colonneDroite->addWidget(frameFormulaireStock);

        frameExportStock = new QFrame(colonneDroiteStock);
        frameExportStock->setObjectName("frameExportStock");
        frameExportStock->setMinimumSize(QSize(290, 104));
        frameExportStock->setMaximumSize(QSize(290, 104));
        lblExportIconeStock = new QLabel(frameExportStock);
        lblExportIconeStock->setObjectName("lblExportIconeStock");
        lblExportIconeStock->setGeometry(QRect(12, 12, 26, 26));
        lblExportIconeStock->setScaledContents(true);
        lblExportIconeStock->setPixmap(QPixmap(QString::fromUtf8(":/icones/clipboard_teal.png")));
        lblExportTitreStock = new QLabel(frameExportStock);
        lblExportTitreStock->setObjectName("lblExportTitreStock");
        lblExportTitreStock->setGeometry(QRect(46, 8, 235, 20));
        lblExportSousTitreStock = new QLabel(frameExportStock);
        lblExportSousTitreStock->setObjectName("lblExportSousTitreStock");
        lblExportSousTitreStock->setGeometry(QRect(46, 28, 235, 18));
        btnOuvrirReapproStock = new QPushButton(frameExportStock);
        btnOuvrirReapproStock->setObjectName("btnOuvrirReapproStock");
        btnOuvrirReapproStock->setGeometry(QRect(12, 58, 130, 34));
        btnOuvrirReapproStock->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icones/clipboard_white.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnOuvrirReapproStock->setIcon(icon5);
        btnOuvrirReapproStock->setIconSize(QSize(18, 18));
        btnExcelStock = new QPushButton(frameExportStock);
        btnExcelStock->setObjectName("btnExcelStock");
        btnExcelStock->setGeometry(QRect(148, 58, 130, 34));
        btnExcelStock->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icones/download_white.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnExcelStock->setIcon(icon6);
        btnExcelStock->setIconSize(QSize(18, 18));

        layout_colonneDroite->addWidget(frameExportStock);

        espaceColonneDroite = new QSpacerItem(40, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        layout_colonneDroite->addItem(espaceColonneDroite);


        layout_zoneHaut->addWidget(colonneDroiteStock);


        layoutContenu->addWidget(zoneHautStock);

        lblStatsTitreStock = new QLabel(contenuStock);
        lblStatsTitreStock->setObjectName("lblStatsTitreStock");
        lblStatsTitreStock->setMinimumSize(QSize(0, 30));

        layoutContenu->addWidget(lblStatsTitreStock);

        ligneStatsStock = new QWidget(contenuStock);
        ligneStatsStock->setObjectName("ligneStatsStock");
        layout_ligneStats = new QHBoxLayout(ligneStatsStock);
        layout_ligneStats->setSpacing(14);
        layout_ligneStats->setObjectName("layout_ligneStats");
        layout_ligneStats->setContentsMargins(0, 0, 0, 0);
        frameGraphiqueStock = new QFrame(ligneStatsStock);
        frameGraphiqueStock->setObjectName("frameGraphiqueStock");
        frameGraphiqueStock->setMinimumSize(QSize(400, 300));
        frameGraphiqueStock->setMaximumSize(QSize(16777215, 300));
        layoutGraphique = new QVBoxLayout(frameGraphiqueStock);
        layoutGraphique->setSpacing(6);
        layoutGraphique->setObjectName("layoutGraphique");
        layoutGraphique->setContentsMargins(14, 10, 14, 10);
        enteteGraphiqueStock = new QWidget(frameGraphiqueStock);
        enteteGraphiqueStock->setObjectName("enteteGraphiqueStock");
        layout_enteteGraphique = new QHBoxLayout(enteteGraphiqueStock);
        layout_enteteGraphique->setSpacing(8);
        layout_enteteGraphique->setObjectName("layout_enteteGraphique");
        layout_enteteGraphique->setContentsMargins(0, 0, 0, 0);
        lblGraphTitreStock = new QLabel(enteteGraphiqueStock);
        lblGraphTitreStock->setObjectName("lblGraphTitreStock");

        layout_enteteGraphique->addWidget(lblGraphTitreStock);

        espaceGraphique = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        layout_enteteGraphique->addItem(espaceGraphique);

        cmbPeriodeStock = new QComboBox(enteteGraphiqueStock);
        cmbPeriodeStock->setObjectName("cmbPeriodeStock");
        cmbPeriodeStock->setMinimumSize(QSize(150, 30));
        cmbPeriodeStock->setMaximumSize(QSize(150, 30));
        cmbPeriodeStock->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        layout_enteteGraphique->addWidget(cmbPeriodeStock);


        layoutGraphique->addWidget(enteteGraphiqueStock);

        widgetGraphiqueStock = new QWidget(frameGraphiqueStock);
        widgetGraphiqueStock->setObjectName("widgetGraphiqueStock");
        widgetGraphiqueStock->setMinimumSize(QSize(0, 230));

        layoutGraphique->addWidget(widgetGraphiqueStock);


        layout_ligneStats->addWidget(frameGraphiqueStock);

        frameStat1Stock = new QFrame(ligneStatsStock);
        frameStat1Stock->setObjectName("frameStat1Stock");
        frameStat1Stock->setMinimumSize(QSize(320, 300));
        frameStat1Stock->setMaximumSize(QSize(16777215, 300));
        layout_frameStat1 = new QVBoxLayout(frameStat1Stock);
        layout_frameStat1->setSpacing(6);
        layout_frameStat1->setObjectName("layout_frameStat1");
        layout_frameStat1->setContentsMargins(14, 10, 14, 10);
        lblStat1TitreStock = new QLabel(frameStat1Stock);
        lblStat1TitreStock->setObjectName("lblStat1TitreStock");
        lblStat1TitreStock->setMinimumSize(QSize(0, 30));

        layout_frameStat1->addWidget(lblStat1TitreStock);

        widgetCamembertStock = new QWidget(frameStat1Stock);
        widgetCamembertStock->setObjectName("widgetCamembertStock");
        widgetCamembertStock->setMinimumSize(QSize(0, 230));

        layout_frameStat1->addWidget(widgetCamembertStock);


        layout_ligneStats->addWidget(frameStat1Stock);

        layout_ligneStats->setStretch(0, 3);
        layout_ligneStats->setStretch(1, 2);

        layoutContenu->addWidget(ligneStatsStock);

        lblSubstTitreStock = new QLabel(contenuStock);
        lblSubstTitreStock->setObjectName("lblSubstTitreStock");
        lblSubstTitreStock->setMinimumSize(QSize(0, 30));

        layoutContenu->addWidget(lblSubstTitreStock);

        frameSubstitutionsStock = new QFrame(contenuStock);
        frameSubstitutionsStock->setObjectName("frameSubstitutionsStock");
        layoutSubstitutions = new QVBoxLayout(frameSubstitutionsStock);
        layoutSubstitutions->setSpacing(10);
        layoutSubstitutions->setObjectName("layoutSubstitutions");
        layoutSubstitutions->setContentsMargins(16, 14, 16, 16);
        lblSubstInfoStock = new QLabel(frameSubstitutionsStock);
        lblSubstInfoStock->setObjectName("lblSubstInfoStock");
        lblSubstInfoStock->setWordWrap(true);

        layoutSubstitutions->addWidget(lblSubstInfoStock);

        tableSubstitutionsStock = new QTableWidget(frameSubstitutionsStock);
        tableSubstitutionsStock->setObjectName("tableSubstitutionsStock");

        layoutSubstitutions->addWidget(tableSubstitutionsStock);

        lblAucuneSubstitutionStock = new QLabel(frameSubstitutionsStock);
        lblAucuneSubstitutionStock->setObjectName("lblAucuneSubstitutionStock");

        layoutSubstitutions->addWidget(lblAucuneSubstitutionStock);


        layoutContenu->addWidget(frameSubstitutionsStock);

        espaceBas = new QSpacerItem(40, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        layoutContenu->addItem(espaceBas);

        scrollStock->setWidget(contenuStock);

        layoutPageStock->addWidget(scrollStock);

        stackStock->addWidget(pageGestionStock);
        pageReappro = new QWidget();
        pageReappro->setObjectName("pageReappro");
        layoutPageReappro = new QVBoxLayout(pageReappro);
        layoutPageReappro->setSpacing(0);
        layoutPageReappro->setObjectName("layoutPageReappro");
        layoutPageReappro->setContentsMargins(0, 0, 0, 0);
        scrollReappro = new QScrollArea(pageReappro);
        scrollReappro->setObjectName("scrollReappro");
        scrollReappro->setFrameShape(QFrame::NoFrame);
        scrollReappro->setWidgetResizable(true);
        contenuReappro = new QWidget();
        contenuReappro->setObjectName("contenuReappro");
        contenuReappro->setGeometry(QRect(0, 0, 1100, 900));
        layoutContenuReappro = new QVBoxLayout(contenuReappro);
        layoutContenuReappro->setSpacing(16);
        layoutContenuReappro->setObjectName("layoutContenuReappro");
        layoutContenuReappro->setContentsMargins(20, 16, 20, 25);
        barreReappro = new QWidget(contenuReappro);
        barreReappro->setObjectName("barreReappro");
        layout_barreReappro = new QHBoxLayout(barreReappro);
        layout_barreReappro->setSpacing(10);
        layout_barreReappro->setObjectName("layout_barreReappro");
        layout_barreReappro->setContentsMargins(0, 0, 0, 0);
        btnRetourStock = new QPushButton(barreReappro);
        btnRetourStock->setObjectName("btnRetourStock");
        btnRetourStock->setMinimumSize(QSize(170, 38));
        btnRetourStock->setMaximumSize(QSize(170, 38));
        btnRetourStock->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icones/fleche_gauche_teal.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnRetourStock->setIcon(icon7);
        btnRetourStock->setIconSize(QSize(18, 18));

        layout_barreReappro->addWidget(btnRetourStock);

        espaceBarreReappro = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        layout_barreReappro->addItem(espaceBarreReappro);

        lblDelaiStock = new QLabel(barreReappro);
        lblDelaiStock->setObjectName("lblDelaiStock");

        layout_barreReappro->addWidget(lblDelaiStock);

        spinDelaiStock = new QSpinBox(barreReappro);
        spinDelaiStock->setObjectName("spinDelaiStock");
        spinDelaiStock->setMinimumSize(QSize(130, 38));
        spinDelaiStock->setMaximumSize(QSize(130, 38));

        layout_barreReappro->addWidget(spinDelaiStock);

        espaceParam = new QSpacerItem(14, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        layout_barreReappro->addItem(espaceParam);

        lblCouvertureStock = new QLabel(barreReappro);
        lblCouvertureStock->setObjectName("lblCouvertureStock");

        layout_barreReappro->addWidget(lblCouvertureStock);

        spinCouvertureStock = new QSpinBox(barreReappro);
        spinCouvertureStock->setObjectName("spinCouvertureStock");
        spinCouvertureStock->setMinimumSize(QSize(130, 38));
        spinCouvertureStock->setMaximumSize(QSize(130, 38));

        layout_barreReappro->addWidget(spinCouvertureStock);


        layoutContenuReappro->addWidget(barreReappro);

        lblExplicationStock = new QLabel(contenuReappro);
        lblExplicationStock->setObjectName("lblExplicationStock");
        lblExplicationStock->setTextFormat(Qt::RichText);
        lblExplicationStock->setWordWrap(true);

        layoutContenuReappro->addWidget(lblExplicationStock);

        lblCompteursStock = new QLabel(contenuReappro);
        lblCompteursStock->setObjectName("lblCompteursStock");
        lblCompteursStock->setTextFormat(Qt::RichText);

        layoutContenuReappro->addWidget(lblCompteursStock);

        frameSuggestionsStock = new QFrame(contenuReappro);
        frameSuggestionsStock->setObjectName("frameSuggestionsStock");
        layoutSuggestions = new QVBoxLayout(frameSuggestionsStock);
        layoutSuggestions->setSpacing(10);
        layoutSuggestions->setObjectName("layoutSuggestions");
        layoutSuggestions->setContentsMargins(16, 14, 16, 16);
        enteteSuggestionsStock = new QWidget(frameSuggestionsStock);
        enteteSuggestionsStock->setObjectName("enteteSuggestionsStock");
        layout_enteteSuggestions = new QHBoxLayout(enteteSuggestionsStock);
        layout_enteteSuggestions->setSpacing(10);
        layout_enteteSuggestions->setObjectName("layout_enteteSuggestions");
        layout_enteteSuggestions->setContentsMargins(0, 0, 0, 0);
        lblSuggTitreStock = new QLabel(enteteSuggestionsStock);
        lblSuggTitreStock->setObjectName("lblSuggTitreStock");

        layout_enteteSuggestions->addWidget(lblSuggTitreStock);

        espaceSugg = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        layout_enteteSuggestions->addItem(espaceSugg);

        btnToutSelectionnerStock = new QPushButton(enteteSuggestionsStock);
        btnToutSelectionnerStock->setObjectName("btnToutSelectionnerStock");
        btnToutSelectionnerStock->setMinimumSize(QSize(165, 36));
        btnToutSelectionnerStock->setMaximumSize(QSize(165, 36));
        btnToutSelectionnerStock->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/icones/check_teal.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnToutSelectionnerStock->setIcon(icon8);
        btnToutSelectionnerStock->setIconSize(QSize(16, 16));

        layout_enteteSuggestions->addWidget(btnToutSelectionnerStock);

        btnCommanderSelectionStock = new QPushButton(enteteSuggestionsStock);
        btnCommanderSelectionStock->setObjectName("btnCommanderSelectionStock");
        btnCommanderSelectionStock->setMinimumSize(QSize(230, 36));
        btnCommanderSelectionStock->setMaximumSize(QSize(230, 36));
        btnCommanderSelectionStock->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/icones/cart_white.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnCommanderSelectionStock->setIcon(icon9);
        btnCommanderSelectionStock->setIconSize(QSize(18, 18));

        layout_enteteSuggestions->addWidget(btnCommanderSelectionStock);

        btnExcelSuggestionsStock = new QPushButton(enteteSuggestionsStock);
        btnExcelSuggestionsStock->setObjectName("btnExcelSuggestionsStock");
        btnExcelSuggestionsStock->setMinimumSize(QSize(110, 36));
        btnExcelSuggestionsStock->setMaximumSize(QSize(110, 36));
        btnExcelSuggestionsStock->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnExcelSuggestionsStock->setIcon(icon6);
        btnExcelSuggestionsStock->setIconSize(QSize(18, 18));

        layout_enteteSuggestions->addWidget(btnExcelSuggestionsStock);


        layoutSuggestions->addWidget(enteteSuggestionsStock);

        tableSuggestionsStock = new QTableWidget(frameSuggestionsStock);
        tableSuggestionsStock->setObjectName("tableSuggestionsStock");

        layoutSuggestions->addWidget(tableSuggestionsStock);

        lblAucuneSuggestionStock = new QLabel(frameSuggestionsStock);
        lblAucuneSuggestionStock->setObjectName("lblAucuneSuggestionStock");

        layoutSuggestions->addWidget(lblAucuneSuggestionStock);


        layoutContenuReappro->addWidget(frameSuggestionsStock);

        frameCommandesStock = new QFrame(contenuReappro);
        frameCommandesStock->setObjectName("frameCommandesStock");
        layoutCommandes = new QVBoxLayout(frameCommandesStock);
        layoutCommandes->setSpacing(10);
        layoutCommandes->setObjectName("layoutCommandes");
        layoutCommandes->setContentsMargins(16, 14, 16, 16);
        enteteCommandesStock = new QWidget(frameCommandesStock);
        enteteCommandesStock->setObjectName("enteteCommandesStock");
        layout_enteteCommandes = new QHBoxLayout(enteteCommandesStock);
        layout_enteteCommandes->setSpacing(10);
        layout_enteteCommandes->setObjectName("layout_enteteCommandes");
        layout_enteteCommandes->setContentsMargins(0, 0, 0, 0);
        lblCmdTitreStock = new QLabel(enteteCommandesStock);
        lblCmdTitreStock->setObjectName("lblCmdTitreStock");

        layout_enteteCommandes->addWidget(lblCmdTitreStock);

        espaceCmd = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        layout_enteteCommandes->addItem(espaceCmd);

        btnExcelCommandesStock = new QPushButton(enteteCommandesStock);
        btnExcelCommandesStock->setObjectName("btnExcelCommandesStock");
        btnExcelCommandesStock->setMinimumSize(QSize(110, 36));
        btnExcelCommandesStock->setMaximumSize(QSize(110, 36));
        btnExcelCommandesStock->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnExcelCommandesStock->setIcon(icon6);
        btnExcelCommandesStock->setIconSize(QSize(18, 18));

        layout_enteteCommandes->addWidget(btnExcelCommandesStock);


        layoutCommandes->addWidget(enteteCommandesStock);

        tableCommandesStock = new QTableWidget(frameCommandesStock);
        tableCommandesStock->setObjectName("tableCommandesStock");

        layoutCommandes->addWidget(tableCommandesStock);

        lblAucuneCommandeStock = new QLabel(frameCommandesStock);
        lblAucuneCommandeStock->setObjectName("lblAucuneCommandeStock");

        layoutCommandes->addWidget(lblAucuneCommandeStock);


        layoutContenuReappro->addWidget(frameCommandesStock);

        espaceBasReappro = new QSpacerItem(40, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        layoutContenuReappro->addItem(espaceBasReappro);

        scrollReappro->setWidget(contenuReappro);

        layoutPageReappro->addWidget(scrollReappro);

        stackStock->addWidget(pageReappro);

        layoutModuleStock->addWidget(stackStock);

        SWPetManager->addWidget(pageStock);

        layout_main->addWidget(SWPetManager);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        SWPetManager->setCurrentIndex(0);
        stackStock->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Pet Manager - Smart Pet Care Center", nullptr));
        btn_menu_accueil->setText(QCoreApplication::translate("MainWindow", " Accueil", nullptr));
        btn_menu_animaux->setText(QCoreApplication::translate("MainWindow", "\360\237\220\276 Animaux", nullptr));
        btn_menu_rdv->setText(QCoreApplication::translate("MainWindow", "\360\237\223\205 Rendez-vous", nullptr));
        btn_menu_stock->setText(QCoreApplication::translate("MainWindow", "\360\237\223\246 Stock", nullptr));
        btn_menu_commandes->setText(QCoreApplication::translate("MainWindow", "\360\237\233\222 Commandes", nullptr));
        btn_menu_fournisseurs->setText(QCoreApplication::translate("MainWindow", "\360\237\232\232 Fournisseurs", nullptr));
        btn_menu_employes->setText(QCoreApplication::translate("MainWindow", " Employ\303\251s", nullptr));
        btn_menu_parametres->setText(QCoreApplication::translate("MainWindow", "\342\232\231\357\270\217 Param\303\250tres", nullptr));
        label_title_icon->setText(QCoreApplication::translate("MainWindow", "\360\237\232\232", nullptr));
        label_title_icon->setStyleSheet(QCoreApplication::translate("MainWindow", "font-size: 28px;", nullptr));
        label_page_title->setText(QCoreApplication::translate("MainWindow", "Gestion des fournisseurs", nullptr));
        label_bell->setText(QCoreApplication::translate("MainWindow", "\360\237\224\224", nullptr));
        label_bell->setStyleSheet(QCoreApplication::translate("MainWindow", "font-size: 24px;", nullptr));
        label_notif_badge->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_notif_badge->setStyleSheet(QCoreApplication::translate("MainWindow", "background-color: #D9534F; color: white; border-radius: 9px; font-size: 10px; font-weight: bold; padding: 2px 5px; min-width: 18px; min-height: 18px; qproperty-alignment: AlignCenter;", nullptr));
        label_avatar->setText(QCoreApplication::translate("MainWindow", "\360\237\221\244", nullptr));
        label_avatar->setStyleSheet(QCoreApplication::translate("MainWindow", "font-size: 24px; color: #2A8C82; border: 2px solid #2A8C82; border-radius: 22px; min-width: 44px; min-height: 44px;", nullptr));
        label_user_name->setText(QCoreApplication::translate("MainWindow", "Dr. Sami Ben Ali", nullptr));
        label_user_role->setText(QCoreApplication::translate("MainWindow", "M\303\251decin V\303\251t\303\251rinaire", nullptr));
        label_kpi1_icon->setText(QCoreApplication::translate("MainWindow", "\360\237\232\232", nullptr));
        label_kpi1_icon->setStyleSheet(QCoreApplication::translate("MainWindow", "font-size: 32px;", nullptr));
        label_kpi1_title->setText(QCoreApplication::translate("MainWindow", "Total fournisseurs", nullptr));
        label_kpi1_value->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_kpi2_icon->setText(QCoreApplication::translate("MainWindow", "\342\234\205", nullptr));
        label_kpi2_icon->setStyleSheet(QCoreApplication::translate("MainWindow", "font-size: 32px;", nullptr));
        label_kpi2_title->setText(QCoreApplication::translate("MainWindow", "Fournisseurs actifs", nullptr));
        label_kpi2_value->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_kpi3_icon->setText(QCoreApplication::translate("MainWindow", "\342\255\220", nullptr));
        label_kpi3_icon->setStyleSheet(QCoreApplication::translate("MainWindow", "font-size: 32px;", nullptr));
        label_kpi3_title->setText(QCoreApplication::translate("MainWindow", "Fiabilit\303\251 moyenne", nullptr));
        label_kpi3_value->setText(QCoreApplication::translate("MainWindow", "\342\200\224", nullptr));
        lineEdit_recherche->setPlaceholderText(QCoreApplication::translate("MainWindow", "Rechercher un fournisseur par nom...", nullptr));
        comboBox_tri->setItemText(0, QCoreApplication::translate("MainWindow", "Aucun tri", nullptr));
        comboBox_tri->setItemText(1, QCoreApplication::translate("MainWindow", "Nom (A \342\206\222 Z)", nullptr));
        comboBox_tri->setItemText(2, QCoreApplication::translate("MainWindow", "Nom (Z \342\206\222 A)", nullptr));

        label_table_footer->setText(QCoreApplication::translate("MainWindow", "Affichage de 0 sur 0 fournisseurs", nullptr));
        label_chart_title->setText(QCoreApplication::translate("MainWindow", " Statistiques", nullptr));
        comboBox_chart->setItemText(0, QCoreApplication::translate("MainWindow", "Nombre par type", nullptr));
        comboBox_chart->setItemText(1, QCoreApplication::translate("MainWindow", "R\303\251partition par statut", nullptr));

        label_alerts_title->setText(QCoreApplication::translate("MainWindow", "\342\232\240\357\270\217 Alertes contrat", nullptr));
        label_alerts_badge->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_sugg_title->setText(QCoreApplication::translate("MainWindow", "\360\237\222\241 Recommandations", nullptr));
        comboBox_rec_type->setItemText(0, QCoreApplication::translate("MainWindow", "Tous les types", nullptr));
        comboBox_rec_type->setItemText(1, QCoreApplication::translate("MainWindow", "Alimentation", nullptr));
        comboBox_rec_type->setItemText(2, QCoreApplication::translate("MainWindow", "M\303\251dicaments", nullptr));
        comboBox_rec_type->setItemText(3, QCoreApplication::translate("MainWindow", "\303\211quipement", nullptr));

        label_form_title->setText(QCoreApplication::translate("MainWindow", "+  Ajouter un fournisseur", nullptr));
        label_nom->setText(QCoreApplication::translate("MainWindow", "Nom *", nullptr));
        lineEdit_nom->setPlaceholderText(QCoreApplication::translate("MainWindow", "Ex : Ben Ali Distribution", nullptr));
        label_contact->setText(QCoreApplication::translate("MainWindow", "Contact", nullptr));
        lineEdit_contact->setPlaceholderText(QCoreApplication::translate("MainWindow", "Ex : Mohamed Ben Ali", nullptr));
        label_tel->setText(QCoreApplication::translate("MainWindow", "T\303\251l\303\251phone *", nullptr));
        lineEdit_tel->setPlaceholderText(QCoreApplication::translate("MainWindow", "Ex : 22 123 456", nullptr));
        label_email->setText(QCoreApplication::translate("MainWindow", "Email *", nullptr));
        lineEdit_email->setPlaceholderText(QCoreApplication::translate("MainWindow", "Ex : contact@fournisseur.tn", nullptr));
        label_adresse->setText(QCoreApplication::translate("MainWindow", "Adresse", nullptr));
        lineEdit_adresse->setPlaceholderText(QCoreApplication::translate("MainWindow", "Ex : 12 av. Habib Bourguiba, Tunis", nullptr));
        label_type->setText(QCoreApplication::translate("MainWindow", "Type de produit *", nullptr));
        comboBox_type->setItemText(0, QCoreApplication::translate("MainWindow", "Alimentation", nullptr));
        comboBox_type->setItemText(1, QCoreApplication::translate("MainWindow", "Accessoires", nullptr));
        comboBox_type->setItemText(2, QCoreApplication::translate("MainWindow", "Soins et hygi\303\250ne", nullptr));
        comboBox_type->setItemText(3, QCoreApplication::translate("MainWindow", "M\303\251dicaments", nullptr));
        comboBox_type->setItemText(4, QCoreApplication::translate("MainWindow", "\303\211quipement", nullptr));

        label_status->setText(QCoreApplication::translate("MainWindow", "Statut *", nullptr));
        comboBox_status->setItemText(0, QCoreApplication::translate("MainWindow", "Actif", nullptr));
        comboBox_status->setItemText(1, QCoreApplication::translate("MainWindow", "Suspendu", nullptr));
        comboBox_status->setItemText(2, QCoreApplication::translate("MainWindow", "Inactif", nullptr));

        label_quantite->setText(QCoreApplication::translate("MainWindow", "Quantit\303\251 *", nullptr));
        label_prix->setText(QCoreApplication::translate("MainWindow", "Prix unitaire (TND) *", nullptr));
        doubleSpinBox_prix->setSuffix(QCoreApplication::translate("MainWindow", " TND", nullptr));
        label_date->setText(QCoreApplication::translate("MainWindow", "Date de contrat *", nullptr));
        dateEdit_contrat->setDisplayFormat(QCoreApplication::translate("MainWindow", "dd/MM/yyyy", nullptr));
        btn_enregistrer->setText(QCoreApplication::translate("MainWindow", "\360\237\222\276 Enregistrer", nullptr));
        btn_modifier->setText(QCoreApplication::translate("MainWindow", "\342\234\217\357\270\217 Modifier", nullptr));
        btn_annuler->setText(QCoreApplication::translate("MainWindow", "\342\235\214 Annuler", nullptr));
        btn_supprimer->setText(QCoreApplication::translate("MainWindow", "\360\237\227\221 Supprimer", nullptr));
        label_export_title->setText(QCoreApplication::translate("MainWindow", "\360\237\223\244 Export", nullptr));
        label_export_desc->setText(QCoreApplication::translate("MainWindow", "G\303\251n\303\251rez la liste compl\303\250te pour l'archivage.", nullptr));
        btn_export_pdf->setText(QCoreApplication::translate("MainWindow", "\360\237\223\204 Exporter PDF", nullptr));
        btn_export_excel->setText(QCoreApplication::translate("MainWindow", "\360\237\223\212 Exporter Excel", nullptr));
        pageStock->setStyleSheet(QCoreApplication::translate("MainWindow", "#pageStock { background-color:#F4F8F8; }\n"
"#contenuStock { background-color:#F4F8F8; }\n"
"\n"
"/* ----- Champs de saisie (style commun \303\240 toute l'application) ----- */\n"
"QLineEdit, QComboBox, QSpinBox, QDoubleSpinBox, QDateEdit {\n"
"  border:1px solid #D5E0E0; border-radius:6px; padding:0 10px;\n"
"  background:white; color:#1E3A3A; font-size:13px; min-height:30px; }\n"
"QLineEdit:focus, QComboBox:focus, QSpinBox:focus, QDoubleSpinBox:focus, QDateEdit:focus {\n"
"  border:1px solid #2A8C86; }\n"
"QComboBox::drop-down, QDateEdit::drop-down {\n"
"  subcontrol-origin:padding; subcontrol-position:center right; width:30px; border:none; }\n"
"QComboBox::down-arrow, QDateEdit::down-arrow {\n"
"  image:url(:/icones/fleche_bas.png); width:12px; height:12px; }\n"
"QComboBox QAbstractItemView {\n"
"  background:white; color:#1E3A3A; border:1px solid #D5E0E0; outline:0; padding:4px;\n"
"  selection-background-color:#E6F2F1; selection-color:#1E3A3A; }\n"
"QComboBox QAbstractItemView::item {\n"
"  min-height:30p"
                        "x; padding-left:8px; color:#1E3A3A; background:white; }\n"
"QComboBox QAbstractItemView::item:hover, QComboBox QAbstractItemView::item:selected {\n"
"  background:#E6F2F1; color:#1E3A3A; }\n"
"QSpinBox::up-button, QDoubleSpinBox::up-button {\n"
"  subcontrol-origin:border; subcontrol-position:top right; width:28px;\n"
"  border:none; border-left:1px solid #E0E8E8; border-top-right-radius:6px; }\n"
"QSpinBox::down-button, QDoubleSpinBox::down-button {\n"
"  subcontrol-origin:border; subcontrol-position:bottom right; width:28px;\n"
"  border:none; border-left:1px solid #E0E8E8; border-bottom-right-radius:6px; }\n"
"QSpinBox::up-button:hover, QDoubleSpinBox::up-button:hover,\n"
"QSpinBox::down-button:hover, QDoubleSpinBox::down-button:hover { background:#E6F2F1; }\n"
"QSpinBox::up-arrow, QDoubleSpinBox::up-arrow { image:url(:/icones/fleche_haut.png); width:10px; height:10px; }\n"
"QSpinBox::down-arrow, QDoubleSpinBox::down-arrow { image:url(:/icones/fleche_bas.png); width:10px; height:10px; }\n"
"\n"
"/* ----- Ba"
                        "rre de d\303\251filement ----- */\n"
"QScrollArea { background:transparent; border:none; }\n"
"QScrollBar:vertical { background:transparent; width:10px; margin:0; }\n"
"QScrollBar::handle:vertical { background:#C5D6D5; border-radius:5px; min-height:40px; }\n"
"QScrollBar::handle:vertical:hover { background:#2A8C86; }\n"
"QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical { height:0; }\n"
"QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical { background:none; }\n"
"QScrollBar:horizontal { background:transparent; height:10px; margin:0; }\n"
"QScrollBar::handle:horizontal { background:#C5D6D5; border-radius:5px; min-width:40px; }\n"
"QScrollBar::add-line:horizontal, QScrollBar::sub-line:horizontal { width:0; }\n"
"\n"
"QToolTip { background:white; color:#1E3A3A; border:1px solid #D5E0E0; padding:4px; }", nullptr));
        frameHeader->setStyleSheet(QCoreApplication::translate("MainWindow", ".QFrame { background-color:#F4F8F8; border:none; border-bottom:1px solid #E0E8E8; }", nullptr));
        lblIconeTitre->setText(QString());
        lblTitre->setStyleSheet(QCoreApplication::translate("MainWindow", "color:#17363A; font-size:26px; font-weight:bold;", nullptr));
        lblTitre->setText(QCoreApplication::translate("MainWindow", "Gestion de stock", nullptr));
        btnNotif->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton{border:none;background:transparent;font-size:22px;} QPushButton:hover{background:#E6F2F1;border-radius:8px;}", nullptr));
        btnNotif->setText(QString());
#if QT_CONFIG(tooltip)
        btnNotif->setToolTip(QCoreApplication::translate("MainWindow", "Notifications du stock", nullptr));
#endif // QT_CONFIG(tooltip)
        lblAvatar->setStyleSheet(QCoreApplication::translate("MainWindow", "border:2px solid #2A8C86; border-radius:22px; background:white;", nullptr));
        lblAvatar->setText(QString());
        lblNomMedecin->setStyleSheet(QCoreApplication::translate("MainWindow", "color:#17363A; font-size:13px; font-weight:bold;", nullptr));
        lblNomMedecin->setText(QCoreApplication::translate("MainWindow", "Dr. Sami Ben Ali", nullptr));
        lblRole->setStyleSheet(QCoreApplication::translate("MainWindow", "color:#6B8080; font-size:10px;", nullptr));
        lblRole->setText(QCoreApplication::translate("MainWindow", "M\303\251decin V\303\251t\303\251rinaire", nullptr));
        frameCarte1Stock->setStyleSheet(QCoreApplication::translate("MainWindow", ".QFrame { background-color:#E4F2F1; border:1px solid #CFE5E3; border-radius:10px; }", nullptr));
        lblCarte1TitreStock->setStyleSheet(QCoreApplication::translate("MainWindow", "color:#1E3A3A; font-size:12px;", nullptr));
        lblCarte1TitreStock->setText(QCoreApplication::translate("MainWindow", "Total des produits", nullptr));
        lblValeurTotalStock->setStyleSheet(QCoreApplication::translate("MainWindow", "color:#17363A; font-size:24px; font-weight:bold;", nullptr));
        lblValeurTotalStock->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        frameCarte2Stock->setStyleSheet(QCoreApplication::translate("MainWindow", ".QFrame { background-color:#E4F2F1; border:1px solid #CFE5E3; border-radius:10px; }", nullptr));
        lblCarte2TitreStock->setStyleSheet(QCoreApplication::translate("MainWindow", "color:#1E3A3A; font-size:12px;", nullptr));
        lblCarte2TitreStock->setText(QCoreApplication::translate("MainWindow", "\303\200 r\303\251approvisionner", nullptr));
        lblValeurReapproStock->setStyleSheet(QCoreApplication::translate("MainWindow", "color:#D32F2F; font-size:24px; font-weight:bold;", nullptr));
        lblValeurReapproStock->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        frameCarte3Stock->setStyleSheet(QCoreApplication::translate("MainWindow", ".QFrame { background-color:#E4F2F1; border:1px solid #CFE5E3; border-radius:10px; }", nullptr));
        lblCarte3TitreStock->setStyleSheet(QCoreApplication::translate("MainWindow", "color:#1E3A3A; font-size:12px;", nullptr));
        lblCarte3TitreStock->setText(QCoreApplication::translate("MainWindow", "Valeur du stock", nullptr));
        lblValeurStock->setStyleSheet(QCoreApplication::translate("MainWindow", "color:#17363A; font-size:24px; font-weight:bold;", nullptr));
        lblValeurStock->setText(QCoreApplication::translate("MainWindow", "0 TND", nullptr));
        txtRechercheStock->setPlaceholderText(QCoreApplication::translate("MainWindow", "Rechercher un produit par nom...", nullptr));
        tableStock->setStyleSheet(QCoreApplication::translate("MainWindow", "QTableWidget { background:white; border:1px solid #E0E8E8; border-radius:10px;\n"
"  gridline-color:#EEF2F2; font-size:12px; color:#1E3A3A; }\n"
"QHeaderView::section { background:#F7FAFA; color:#1E3A3A; font-weight:bold; font-size:12px;\n"
"  border:none; border-bottom:1px solid #E0E8E8; padding-left:8px; }\n"
"QTableWidget::item { padding-left:8px; }\n"
"QTableWidget::item:selected { background:#E6F2F1; color:#1E3A3A; }\n"
"QTableWidget::indicator { width:16px; height:16px; }", nullptr));
        lblAffichageStock->setStyleSheet(QCoreApplication::translate("MainWindow", "color:#6B8080; font-size:10px;", nullptr));
        lblAffichageStock->setText(QString());
        frameAlertesStock->setStyleSheet(QCoreApplication::translate("MainWindow", ".QFrame { background-color:white; border:1px solid #E0E8E8; border-radius:10px; }", nullptr));
        lblAlerteTitreStock->setStyleSheet(QCoreApplication::translate("MainWindow", "color:#17363A; font-size:13px; font-weight:bold;", nullptr));
        lblAlerteTitreStock->setText(QCoreApplication::translate("MainWindow", "\303\200 r\303\251approvisionner", nullptr));
        lblAlerteBadgeStock->setStyleSheet(QCoreApplication::translate("MainWindow", "background:#E53935;color:white;border-radius:11px;font-size:10px;font-weight:bold;", nullptr));
        lblAlerteBadgeStock->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        lblAlerte1Stock->setStyleSheet(QCoreApplication::translate("MainWindow", "color:#1E3A3A; font-size:12px;", nullptr));
        lblAlerte1Stock->setText(QString());
        lblQte1Stock->setStyleSheet(QCoreApplication::translate("MainWindow", "color:#6B8080; font-size:10px;", nullptr));
        lblQte1Stock->setText(QString());
        lblAlerte2Stock->setStyleSheet(QCoreApplication::translate("MainWindow", "color:#1E3A3A; font-size:12px;", nullptr));
        lblAlerte2Stock->setText(QString());
        lblQte2Stock->setStyleSheet(QCoreApplication::translate("MainWindow", "color:#6B8080; font-size:10px;", nullptr));
        lblQte2Stock->setText(QString());
        lblAlerte3Stock->setStyleSheet(QCoreApplication::translate("MainWindow", "color:#1E3A3A; font-size:12px;", nullptr));
        lblAlerte3Stock->setText(QString());
        lblQte3Stock->setStyleSheet(QCoreApplication::translate("MainWindow", "color:#6B8080; font-size:10px;", nullptr));
        lblQte3Stock->setText(QString());
        btnVoirToutStock->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton{border:none;background:transparent;color:#2A8C86;font-size:11px;font-weight:bold;text-align:left;}QPushButton:hover{text-decoration:underline;}", nullptr));
        btnVoirToutStock->setText(QCoreApplication::translate("MainWindow", "Voir tout \342\206\222", nullptr));
        frameAlternatifsStock->setStyleSheet(QCoreApplication::translate("MainWindow", ".QFrame { background-color:white; border:1px solid #E0E8E8; border-radius:10px; }", nullptr));
        lblAltTitreStock->setStyleSheet(QCoreApplication::translate("MainWindow", "color:#17363A; font-size:13px; font-weight:bold;", nullptr));
        lblAltTitreStock->setText(QCoreApplication::translate("MainWindow", "Alternatives sugg\303\251r\303\251es", nullptr));
        lblAltPourStock->setStyleSheet(QCoreApplication::translate("MainWindow", "color:#6B8080; font-size:10px;", nullptr));
        lblAltPourStock->setText(QString());
        frameAlt1Stock->setStyleSheet(QCoreApplication::translate("MainWindow", ".QFrame { background-color:#FAFCFC; border:1px solid #E0E8E8; border-radius:8px; }\n"
".QFrame:hover { background-color:#E6F2F1; border:1px solid #2A8C86; }", nullptr));
#if QT_CONFIG(tooltip)
        frameAlt1Stock->setToolTip(QCoreApplication::translate("MainWindow", "Utiliser ce produit comme alternative", nullptr));
#endif // QT_CONFIG(tooltip)
        lblAltIcone1Stock->setStyleSheet(QCoreApplication::translate("MainWindow", "font-size:24px;", nullptr));
        lblAltIcone1Stock->setText(QString());
        lblAltNom1Stock->setStyleSheet(QCoreApplication::translate("MainWindow", "color:#17363A;font-size:11px;font-weight:bold;", nullptr));
        lblAltNom1Stock->setText(QString());
        lblAltCat1Stock->setStyleSheet(QCoreApplication::translate("MainWindow", "color:#6B8080; font-size:10px;", nullptr));
        lblAltCat1Stock->setText(QString());
        lblAltQte1Stock->setStyleSheet(QCoreApplication::translate("MainWindow", "color:#6B8080; font-size:10px;", nullptr));
        lblAltQte1Stock->setText(QString());
        lblAltFleche1Stock->setStyleSheet(QCoreApplication::translate("MainWindow", "color:#6B8080;font-size:18px;", nullptr));
        lblAltFleche1Stock->setText(QCoreApplication::translate("MainWindow", "\342\200\272", nullptr));
        frameAlt2Stock->setStyleSheet(QCoreApplication::translate("MainWindow", ".QFrame { background-color:#FAFCFC; border:1px solid #E0E8E8; border-radius:8px; }\n"
".QFrame:hover { background-color:#E6F2F1; border:1px solid #2A8C86; }", nullptr));
#if QT_CONFIG(tooltip)
        frameAlt2Stock->setToolTip(QCoreApplication::translate("MainWindow", "Utiliser ce produit comme alternative", nullptr));
#endif // QT_CONFIG(tooltip)
        lblAltIcone2Stock->setStyleSheet(QCoreApplication::translate("MainWindow", "font-size:24px;", nullptr));
        lblAltIcone2Stock->setText(QString());
        lblAltNom2Stock->setStyleSheet(QCoreApplication::translate("MainWindow", "color:#17363A;font-size:11px;font-weight:bold;", nullptr));
        lblAltNom2Stock->setText(QString());
        lblAltCat2Stock->setStyleSheet(QCoreApplication::translate("MainWindow", "color:#6B8080; font-size:10px;", nullptr));
        lblAltCat2Stock->setText(QString());
        lblAltQte2Stock->setStyleSheet(QCoreApplication::translate("MainWindow", "color:#6B8080; font-size:10px;", nullptr));
        lblAltQte2Stock->setText(QString());
        lblAltFleche2Stock->setStyleSheet(QCoreApplication::translate("MainWindow", "color:#6B8080;font-size:18px;", nullptr));
        lblAltFleche2Stock->setText(QCoreApplication::translate("MainWindow", "\342\200\272", nullptr));
        lblAucuneAltStock->setStyleSheet(QCoreApplication::translate("MainWindow", "color:#6B8080; font-size:10px;", nullptr));
        lblAucuneAltStock->setText(QCoreApplication::translate("MainWindow", "Aucune alternative compatible (m\303\252me usage et m\303\252me esp\303\250ce).", nullptr));
        frameFormulaireStock->setStyleSheet(QCoreApplication::translate("MainWindow", ".QFrame { background-color:white; border:1px solid #E0E8E8; border-radius:10px; }", nullptr));
        lblFormTitreStock->setStyleSheet(QCoreApplication::translate("MainWindow", "color:#17363A;font-size:15px;font-weight:bold;", nullptr));
        lblFormTitreStock->setText(QCoreApplication::translate("MainWindow", "Ajouter un produit", nullptr));
        lblSeparateurStock->setStyleSheet(QCoreApplication::translate("MainWindow", "background:#E0E8E8;", nullptr));
        lblSeparateurStock->setText(QString());
        lblNomStock->setStyleSheet(QCoreApplication::translate("MainWindow", "color:#17363A; font-size:13px;", nullptr));
        lblNomStock->setText(QCoreApplication::translate("MainWindow", "Nom du produit <span style=\"color:#E53935\">*</span>", nullptr));
        txtNomStock->setPlaceholderText(QCoreApplication::translate("MainWindow", "Ex : Croquettes premium chien", nullptr));
        lblCategorieStock->setStyleSheet(QCoreApplication::translate("MainWindow", "color:#17363A; font-size:13px;", nullptr));
        lblCategorieStock->setText(QCoreApplication::translate("MainWindow", "Cat\303\251gorie <span style=\"color:#E53935\">*</span>", nullptr));
        lblEspeceStock->setStyleSheet(QCoreApplication::translate("MainWindow", "color:#17363A; font-size:13px;", nullptr));
        lblEspeceStock->setText(QCoreApplication::translate("MainWindow", "Esp\303\250ce <span style=\"color:#E53935\">*</span>", nullptr));
        lblUsageStock->setStyleSheet(QCoreApplication::translate("MainWindow", "color:#17363A; font-size:13px;", nullptr));
        lblUsageStock->setText(QCoreApplication::translate("MainWindow", "Usage <span style=\"color:#E53935\">*</span>", nullptr));
        lblQuantiteStock->setStyleSheet(QCoreApplication::translate("MainWindow", "color:#17363A; font-size:13px;", nullptr));
        lblQuantiteStock->setText(QCoreApplication::translate("MainWindow", "Quantit\303\251 <span style=\"color:#E53935\">*</span>", nullptr));
        lblSeuilStock->setStyleSheet(QCoreApplication::translate("MainWindow", "color:#17363A; font-size:13px;", nullptr));
        lblSeuilStock->setText(QCoreApplication::translate("MainWindow", "Seuil minimal <span style=\"color:#E53935\">*</span>", nullptr));
        lblDateStock->setStyleSheet(QCoreApplication::translate("MainWindow", "color:#17363A; font-size:13px;", nullptr));
        lblDateStock->setText(QCoreApplication::translate("MainWindow", "Date d'expiration <span style=\"color:#E53935\">*</span>", nullptr));
        lblFournisseurStock->setStyleSheet(QCoreApplication::translate("MainWindow", "color:#17363A; font-size:13px;", nullptr));
        lblFournisseurStock->setText(QCoreApplication::translate("MainWindow", "Fournisseur <span style=\"color:#E53935\">*</span>", nullptr));
        txtFournisseurStock->setPlaceholderText(QCoreApplication::translate("MainWindow", "Ex : Fournisseur ABC", nullptr));
        lblPrixStock->setStyleSheet(QCoreApplication::translate("MainWindow", "color:#17363A; font-size:13px;", nullptr));
        lblPrixStock->setText(QCoreApplication::translate("MainWindow", "Prix unitaire (TND) <span style=\"color:#E53935\">*</span>", nullptr));
        btnEnregistrerStock->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton { background-color:#2A8C86; color:white; border:none; border-radius:6px; font-size:14px; font-weight:bold; }\n"
"QPushButton:hover { background-color:#237872; }\n"
"QPushButton:disabled { background-color:#B7D3D1; color:white; }", nullptr));
        btnEnregistrerStock->setText(QCoreApplication::translate("MainWindow", "  Enregistrer", nullptr));
        btnModifierStock->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton { background:white; color:#2A8C86; border:1px solid #2A8C86; border-radius:6px; font-size:14px; }\n"
"QPushButton:hover { background-color:#E6F2F1; }\n"
"QPushButton:disabled { color:#A9B8B8; border:1px solid #D5E0E0; background:#F4F7F7; }", nullptr));
        btnModifierStock->setText(QCoreApplication::translate("MainWindow", "  Modifier", nullptr));
        btnAnnulerStock->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton { background:white; color:#5F7373; border:1px solid #B9C9C9; border-radius:6px; font-size:14px; }\n"
"QPushButton:hover { background-color:#F0F4F4; }\n"
"QPushButton:disabled { color:#A9B8B8; border:1px solid #D5E0E0; background:#F4F7F7; }", nullptr));
        btnAnnulerStock->setText(QCoreApplication::translate("MainWindow", "  Annuler", nullptr));
#if QT_CONFIG(tooltip)
        btnAnnulerStock->setToolTip(QCoreApplication::translate("MainWindow", "Annuler la modification et vider le formulaire", nullptr));
#endif // QT_CONFIG(tooltip)
        btnSupprimerStock->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton { background:white; color:#D32F2F; border:1px solid #E57373; border-radius:6px; font-size:14px; }\n"
"QPushButton:hover { background-color:#FDECEC; }", nullptr));
        btnSupprimerStock->setText(QCoreApplication::translate("MainWindow", "  Supprimer", nullptr));
        frameExportStock->setStyleSheet(QCoreApplication::translate("MainWindow", ".QFrame { background-color:#E4F2F1; border:1px solid #CFE5E3; border-radius:10px; }", nullptr));
        lblExportTitreStock->setStyleSheet(QCoreApplication::translate("MainWindow", "color:#17363A; font-size:12px; font-weight:bold;", nullptr));
        lblExportTitreStock->setText(QCoreApplication::translate("MainWindow", "R\303\251approvisionnement intelligent", nullptr));
        lblExportSousTitreStock->setStyleSheet(QCoreApplication::translate("MainWindow", "color:#6B8080; font-size:10px;", nullptr));
        lblExportSousTitreStock->setText(QCoreApplication::translate("MainWindow", "Pr\303\251visions, commandes et r\303\251ception.", nullptr));
        btnOuvrirReapproStock->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton { background-color:#2A8C86; color:white; border:none; border-radius:6px; font-size:14px; font-weight:bold; }\n"
"QPushButton:hover { background-color:#237872; }\n"
"QPushButton:disabled { background-color:#B7D3D1; color:white; }", nullptr));
        btnOuvrirReapproStock->setText(QCoreApplication::translate("MainWindow", "  Ouvrir", nullptr));
#if QT_CONFIG(tooltip)
        btnOuvrirReapproStock->setToolTip(QCoreApplication::translate("MainWindow", "Ouvrir le centre de r\303\251approvisionnement", nullptr));
#endif // QT_CONFIG(tooltip)
        btnExcelStock->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton { background-color:#2E7D32; color:white; border:none; border-radius:6px; font-size:14px; font-weight:bold; }\n"
"QPushButton:hover { background-color:#256628; }", nullptr));
        btnExcelStock->setText(QCoreApplication::translate("MainWindow", "  Excel", nullptr));
#if QT_CONFIG(tooltip)
        btnExcelStock->setToolTip(QCoreApplication::translate("MainWindow", "T\303\251l\303\251charger les suggestions de commande en Excel", nullptr));
#endif // QT_CONFIG(tooltip)
        lblStatsTitreStock->setStyleSheet(QCoreApplication::translate("MainWindow", "color:#17363A; font-size:18px; font-weight:bold;", nullptr));
        lblStatsTitreStock->setText(QCoreApplication::translate("MainWindow", "Statistiques du stock", nullptr));
        frameGraphiqueStock->setStyleSheet(QCoreApplication::translate("MainWindow", ".QFrame { background-color:white; border:1px solid #E0E8E8; border-radius:10px; }", nullptr));
        lblGraphTitreStock->setStyleSheet(QCoreApplication::translate("MainWindow", "color:#17363A; font-size:13px; font-weight:bold;", nullptr));
        lblGraphTitreStock->setText(QCoreApplication::translate("MainWindow", "\303\211volution de la consommation", nullptr));
        cmbPeriodeStock->setStyleSheet(QCoreApplication::translate("MainWindow", "font-size:11px;", nullptr));
        frameStat1Stock->setStyleSheet(QCoreApplication::translate("MainWindow", ".QFrame { background-color:white; border:1px solid #E0E8E8; border-radius:10px; }", nullptr));
        lblStat1TitreStock->setStyleSheet(QCoreApplication::translate("MainWindow", "color:#17363A; font-size:13px; font-weight:bold;", nullptr));
        lblStat1TitreStock->setText(QCoreApplication::translate("MainWindow", "R\303\251partition des produits par cat\303\251gorie", nullptr));
        lblSubstTitreStock->setStyleSheet(QCoreApplication::translate("MainWindow", "color:#17363A; font-size:18px; font-weight:bold;", nullptr));
        lblSubstTitreStock->setText(QCoreApplication::translate("MainWindow", "Historique des substitutions", nullptr));
        frameSubstitutionsStock->setStyleSheet(QCoreApplication::translate("MainWindow", ".QFrame { background-color:white; border:1px solid #E0E8E8; border-radius:10px; }", nullptr));
        lblSubstInfoStock->setStyleSheet(QCoreApplication::translate("MainWindow", "color:#1E3A3A; font-size:12px;", nullptr));
        lblSubstInfoStock->setText(QCoreApplication::translate("MainWindow", "Chaque substitution valid\303\251e est enregistr\303\251e ici. La quantit\303\251 remplac\303\251e est compt\303\251e dans la demande r\303\251elle du produit manquant, pour que le r\303\251approvisionnement intelligent en tienne compte.", nullptr));
        tableSubstitutionsStock->setStyleSheet(QCoreApplication::translate("MainWindow", "QTableWidget { background:white; border:1px solid #E0E8E8; border-radius:10px;\n"
"  gridline-color:#EEF2F2; font-size:12px; color:#1E3A3A; }\n"
"QHeaderView::section { background:#F7FAFA; color:#1E3A3A; font-weight:bold; font-size:12px;\n"
"  border:none; border-bottom:1px solid #E0E8E8; padding-left:8px; }\n"
"QTableWidget::item { padding-left:8px; }\n"
"QTableWidget::item:selected { background:#E6F2F1; color:#1E3A3A; }\n"
"QTableWidget::indicator { width:16px; height:16px; }", nullptr));
        lblAucuneSubstitutionStock->setStyleSheet(QCoreApplication::translate("MainWindow", "color:#6B8080; font-size:12px;", nullptr));
        lblAucuneSubstitutionStock->setText(QCoreApplication::translate("MainWindow", "Aucune substitution pour le moment.", nullptr));
        contenuReappro->setStyleSheet(QCoreApplication::translate("MainWindow", "#contenuReappro { background-color:#F4F8F8; }", nullptr));
        btnRetourStock->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton { background:white; color:#2A8C86; border:1px solid #2A8C86; border-radius:6px; font-size:14px; }\n"
"QPushButton:hover { background-color:#E6F2F1; }\n"
"QPushButton:disabled { color:#A9B8B8; border:1px solid #D5E0E0; background:#F4F7F7; }", nullptr));
        btnRetourStock->setText(QCoreApplication::translate("MainWindow", "  Retour au stock", nullptr));
        lblDelaiStock->setStyleSheet(QCoreApplication::translate("MainWindow", "color:#17363A; font-size:13px;", nullptr));
        lblDelaiStock->setText(QCoreApplication::translate("MainWindow", "D\303\251lai de livraison :", nullptr));
#if QT_CONFIG(tooltip)
        spinDelaiStock->setToolTip(QCoreApplication::translate("MainWindow", "Nombre de jours entre la commande et la livraison", nullptr));
#endif // QT_CONFIG(tooltip)
        lblCouvertureStock->setStyleSheet(QCoreApplication::translate("MainWindow", "color:#17363A; font-size:13px;", nullptr));
        lblCouvertureStock->setText(QCoreApplication::translate("MainWindow", "Couverture souhait\303\251e :", nullptr));
#if QT_CONFIG(tooltip)
        spinCouvertureStock->setToolTip(QCoreApplication::translate("MainWindow", "Nombre de jours de consommation que la commande doit couvrir", nullptr));
#endif // QT_CONFIG(tooltip)
        lblExplicationStock->setStyleSheet(QCoreApplication::translate("MainWindow", "background:#E4F2F1; border:1px solid #CFE5E3; border-radius:10px; padding:12px; color:#1E3A3A; font-size:12px;", nullptr));
        lblExplicationStock->setText(QCoreApplication::translate("MainWindow", "<b>Comment \303\247a marche ?</b> Pour chaque produit, le syst\303\250me calcule la consommation moyenne des 30 derniers jours, pr\303\251voit la date de rupture (en tenant compte de la date d'expiration) et la compare au d\303\251lai de livraison. Il propose ensuite la quantit\303\251 \303\240 commander pour couvrir le d\303\251lai et la p\303\251riode souhait\303\251e. <b>Critique</b> : rupture avant la livraison possible \302\267 <b>Urgent</b> : quantit\303\251 \342\211\244 seuil \302\267 <b>Pr\303\251ventif</b> : rupture pr\303\251vue dans moins d'une semaine apr\303\250s le d\303\251lai. Un produit d\303\251j\303\240 command\303\251 n'est jamais propos\303\251 deux fois.", nullptr));
        lblCompteursStock->setStyleSheet(QCoreApplication::translate("MainWindow", "font-size:13px; color:#1E3A3A;", nullptr));
        lblCompteursStock->setText(QString());
        frameSuggestionsStock->setStyleSheet(QCoreApplication::translate("MainWindow", ".QFrame { background-color:white; border:1px solid #E0E8E8; border-radius:10px; }", nullptr));
        lblSuggTitreStock->setStyleSheet(QCoreApplication::translate("MainWindow", "color:#17363A; font-size:15px; font-weight:bold;", nullptr));
        lblSuggTitreStock->setText(QCoreApplication::translate("MainWindow", "Suggestions de r\303\251approvisionnement", nullptr));
        btnToutSelectionnerStock->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton { background:white; color:#2A8C86; border:1px solid #2A8C86; border-radius:6px; font-size:14px; }\n"
"QPushButton:hover { background-color:#E6F2F1; }\n"
"QPushButton:disabled { color:#A9B8B8; border:1px solid #D5E0E0; background:#F4F7F7; }", nullptr));
        btnToutSelectionnerStock->setText(QCoreApplication::translate("MainWindow", "  Tout s\303\251lectionner", nullptr));
        btnCommanderSelectionStock->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton { background-color:#2A8C86; color:white; border:none; border-radius:6px; font-size:14px; font-weight:bold; }\n"
"QPushButton:hover { background-color:#237872; }\n"
"QPushButton:disabled { background-color:#B7D3D1; color:white; }", nullptr));
        btnCommanderSelectionStock->setText(QCoreApplication::translate("MainWindow", "  Commander la s\303\251lection", nullptr));
        btnExcelSuggestionsStock->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton { background-color:#2E7D32; color:white; border:none; border-radius:6px; font-size:14px; font-weight:bold; }\n"
"QPushButton:hover { background-color:#256628; }", nullptr));
        btnExcelSuggestionsStock->setText(QCoreApplication::translate("MainWindow", "  Excel", nullptr));
        tableSuggestionsStock->setStyleSheet(QCoreApplication::translate("MainWindow", "QTableWidget { background:white; border:1px solid #E0E8E8; border-radius:10px;\n"
"  gridline-color:#EEF2F2; font-size:12px; color:#1E3A3A; }\n"
"QHeaderView::section { background:#F7FAFA; color:#1E3A3A; font-weight:bold; font-size:12px;\n"
"  border:none; border-bottom:1px solid #E0E8E8; padding-left:8px; }\n"
"QTableWidget::item { padding-left:8px; }\n"
"QTableWidget::item:selected { background:#E6F2F1; color:#1E3A3A; }\n"
"QTableWidget::indicator { width:16px; height:16px; }", nullptr));
        lblAucuneSuggestionStock->setStyleSheet(QCoreApplication::translate("MainWindow", "color:#2E8B57; font-size:13px; font-weight:bold;", nullptr));
        lblAucuneSuggestionStock->setText(QCoreApplication::translate("MainWindow", "Aucun produit \303\240 r\303\251approvisionner : le stock est sous contr\303\264le.", nullptr));
        frameCommandesStock->setStyleSheet(QCoreApplication::translate("MainWindow", ".QFrame { background-color:white; border:1px solid #E0E8E8; border-radius:10px; }", nullptr));
        lblCmdTitreStock->setStyleSheet(QCoreApplication::translate("MainWindow", "color:#17363A; font-size:15px; font-weight:bold;", nullptr));
        lblCmdTitreStock->setText(QCoreApplication::translate("MainWindow", "Commandes de r\303\251approvisionnement", nullptr));
        btnExcelCommandesStock->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton { background-color:#2E7D32; color:white; border:none; border-radius:6px; font-size:14px; font-weight:bold; }\n"
"QPushButton:hover { background-color:#256628; }", nullptr));
        btnExcelCommandesStock->setText(QCoreApplication::translate("MainWindow", "  Excel", nullptr));
        tableCommandesStock->setStyleSheet(QCoreApplication::translate("MainWindow", "QTableWidget { background:white; border:1px solid #E0E8E8; border-radius:10px;\n"
"  gridline-color:#EEF2F2; font-size:12px; color:#1E3A3A; }\n"
"QHeaderView::section { background:#F7FAFA; color:#1E3A3A; font-weight:bold; font-size:12px;\n"
"  border:none; border-bottom:1px solid #E0E8E8; padding-left:8px; }\n"
"QTableWidget::item { padding-left:8px; }\n"
"QTableWidget::item:selected { background:#E6F2F1; color:#1E3A3A; }\n"
"QTableWidget::indicator { width:16px; height:16px; }", nullptr));
        lblAucuneCommandeStock->setStyleSheet(QCoreApplication::translate("MainWindow", "color:#6B8080; font-size:12px;", nullptr));
        lblAucuneCommandeStock->setText(QCoreApplication::translate("MainWindow", "Aucune commande pour le moment.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
