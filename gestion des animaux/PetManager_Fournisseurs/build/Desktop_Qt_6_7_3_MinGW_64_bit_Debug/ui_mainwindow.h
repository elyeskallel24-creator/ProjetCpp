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
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
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

        frame_content = new QFrame(centralwidget);
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


        layout_main->addWidget(frame_content);

        frame_right = new QFrame(centralwidget);
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


        layout_main->addWidget(frame_right);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

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
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
