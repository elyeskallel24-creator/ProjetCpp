/********************************************************************************
** Form generated from reading UI file 'rdv.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RDV_H
#define UI_RDV_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_rdv
{
public:
    QWidget *centralwidget;
    QFrame *menu;
    QLabel *labelLogo;
    QPushButton *btnAccueil;
    QPushButton *btnAnimaux;
    QPushButton *btnRendezVous;
    QPushButton *btnStocks;
    QPushButton *btnProprietaires;
    QPushButton *btnFournisseurs;
    QPushButton *btnEmployes;
    QPushButton *btnParametres;
    QWidget *contenu;
    QLineEdit *editRecherche;
    QComboBox *comboTri;
    QPushButton *btnAjouter;
    QTableWidget *tableWidget;
    QWidget *widgetDonut;
    QFrame *framePicJours;
    QFrame *framePicHeures;
    QPushButton *btnExportPdf;
    QFrame *modification;
    QLabel *labelPicTitre;
    QLabel *labelId;
    QLineEdit *lineEditId;
    QLabel *labelDate;
    QDateTimeEdit *dateEditRdv;
    QLabel *labelHeure;
    QTimeEdit *timeEditRdv;
    QLabel *labelAnimal;
    QComboBox *comboAnimal;
    QLabel *labelProprio;
    QComboBox *comboProprietaire;
    QLabel *labelVet;
    QComboBox *comboVeterinaire;
    QLabel *labelStatut;
    QComboBox *comboStatut;
    QPushButton *btnAnnuler;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *rdv)
    {
        if (rdv->objectName().isEmpty())
            rdv->setObjectName("rdv");
        rdv->resize(1280, 720);
        centralwidget = new QWidget(rdv);
        centralwidget->setObjectName("centralwidget");
        menu = new QFrame(centralwidget);
        menu->setObjectName("menu");
        menu->setGeometry(QRect(0, 0, 220, 720));
        labelLogo = new QLabel(menu);
        labelLogo->setObjectName("labelLogo");
        labelLogo->setGeometry(QRect(20, 20, 180, 50));
        btnAccueil = new QPushButton(menu);
        btnAccueil->setObjectName("btnAccueil");
        btnAccueil->setGeometry(QRect(15, 100, 190, 40));
        btnAnimaux = new QPushButton(menu);
        btnAnimaux->setObjectName("btnAnimaux");
        btnAnimaux->setGeometry(QRect(15, 150, 190, 40));
        btnRendezVous = new QPushButton(menu);
        btnRendezVous->setObjectName("btnRendezVous");
        btnRendezVous->setGeometry(QRect(15, 200, 190, 40));
        btnStocks = new QPushButton(menu);
        btnStocks->setObjectName("btnStocks");
        btnStocks->setGeometry(QRect(15, 250, 190, 40));
        btnProprietaires = new QPushButton(menu);
        btnProprietaires->setObjectName("btnProprietaires");
        btnProprietaires->setGeometry(QRect(15, 300, 190, 40));
        btnFournisseurs = new QPushButton(menu);
        btnFournisseurs->setObjectName("btnFournisseurs");
        btnFournisseurs->setGeometry(QRect(15, 350, 190, 40));
        btnEmployes = new QPushButton(menu);
        btnEmployes->setObjectName("btnEmployes");
        btnEmployes->setGeometry(QRect(15, 400, 190, 40));
        btnParametres = new QPushButton(menu);
        btnParametres->setObjectName("btnParametres");
        btnParametres->setGeometry(QRect(15, 450, 190, 40));
        contenu = new QWidget(centralwidget);
        contenu->setObjectName("contenu");
        contenu->setGeometry(QRect(220, 0, 790, 720));
        editRecherche = new QLineEdit(contenu);
        editRecherche->setObjectName("editRecherche");
        editRecherche->setGeometry(QRect(30, 90, 280, 35));
        comboTri = new QComboBox(contenu);
        comboTri->addItem(QString());
        comboTri->setObjectName("comboTri");
        comboTri->setGeometry(QRect(330, 90, 140, 35));
        btnAjouter = new QPushButton(contenu);
        btnAjouter->setObjectName("btnAjouter");
        btnAjouter->setGeometry(QRect(490, 90, 110, 35));
        tableWidget = new QTableWidget(contenu);
        if (tableWidget->columnCount() < 8)
            tableWidget->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(30, 145, 730, 250));
        tableWidget->setColumnCount(8);
        widgetDonut = new QWidget(contenu);
        widgetDonut->setObjectName("widgetDonut");
        widgetDonut->setGeometry(QRect(430, 430, 330, 250));
        framePicJours = new QFrame(contenu);
        framePicJours->setObjectName("framePicJours");
        framePicJours->setGeometry(QRect(30, 430, 190, 250));
        framePicHeures = new QFrame(contenu);
        framePicHeures->setObjectName("framePicHeures");
        framePicHeures->setGeometry(QRect(230, 430, 190, 250));
        btnExportPdf = new QPushButton(contenu);
        btnExportPdf->setObjectName("btnExportPdf");
        btnExportPdf->setGeometry(QRect(620, 90, 141, 41));
        btnExportPdf->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #ffffff;\n"
"    color: #059669;\n"
"    border: 2px solid #059669;\n"
"    border-radius: 8px;\n"
"    padding: 10px 20px;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #ecfdf5;\n"
"}"));
        modification = new QFrame(centralwidget);
        modification->setObjectName("modification");
        modification->setGeometry(QRect(1010, 0, 270, 720));
        labelPicTitre = new QLabel(modification);
        labelPicTitre->setObjectName("labelPicTitre");
        labelPicTitre->setGeometry(QRect(20, 20, 200, 30));
        labelId = new QLabel(modification);
        labelId->setObjectName("labelId");
        labelId->setGeometry(QRect(20, 70, 60, 20));
        lineEditId = new QLineEdit(modification);
        lineEditId->setObjectName("lineEditId");
        lineEditId->setGeometry(QRect(20, 95, 230, 30));
        lineEditId->setReadOnly(true);
        labelDate = new QLabel(modification);
        labelDate->setObjectName("labelDate");
        labelDate->setGeometry(QRect(20, 135, 60, 20));
        dateEditRdv = new QDateTimeEdit(modification);
        dateEditRdv->setObjectName("dateEditRdv");
        dateEditRdv->setGeometry(QRect(20, 160, 230, 30));
        dateEditRdv->setCalendarPopup(true);
        labelHeure = new QLabel(modification);
        labelHeure->setObjectName("labelHeure");
        labelHeure->setGeometry(QRect(20, 200, 60, 20));
        timeEditRdv = new QTimeEdit(modification);
        timeEditRdv->setObjectName("timeEditRdv");
        timeEditRdv->setGeometry(QRect(20, 225, 230, 30));
        labelAnimal = new QLabel(modification);
        labelAnimal->setObjectName("labelAnimal");
        labelAnimal->setGeometry(QRect(20, 265, 60, 20));
        comboAnimal = new QComboBox(modification);
        comboAnimal->setObjectName("comboAnimal");
        comboAnimal->setGeometry(QRect(20, 290, 230, 30));
        labelProprio = new QLabel(modification);
        labelProprio->setObjectName("labelProprio");
        labelProprio->setGeometry(QRect(20, 330, 80, 20));
        comboProprietaire = new QComboBox(modification);
        comboProprietaire->setObjectName("comboProprietaire");
        comboProprietaire->setGeometry(QRect(20, 355, 230, 30));
        labelVet = new QLabel(modification);
        labelVet->setObjectName("labelVet");
        labelVet->setGeometry(QRect(20, 395, 80, 20));
        comboVeterinaire = new QComboBox(modification);
        comboVeterinaire->setObjectName("comboVeterinaire");
        comboVeterinaire->setGeometry(QRect(20, 420, 230, 30));
        labelStatut = new QLabel(modification);
        labelStatut->setObjectName("labelStatut");
        labelStatut->setGeometry(QRect(20, 460, 60, 20));
        comboStatut = new QComboBox(modification);
        comboStatut->addItem(QString());
        comboStatut->addItem(QString());
        comboStatut->addItem(QString());
        comboStatut->addItem(QString());
        comboStatut->setObjectName("comboStatut");
        comboStatut->setGeometry(QRect(20, 485, 230, 30));
        btnAnnuler = new QPushButton(modification);
        btnAnnuler->setObjectName("btnAnnuler");
        btnAnnuler->setGeometry(QRect(20, 550, 105, 35));
        pushButton = new QPushButton(modification);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(135, 550, 115, 35));
        rdv->setCentralWidget(centralwidget);
        menubar = new QMenuBar(rdv);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1280, 26));
        rdv->setMenuBar(menubar);
        statusbar = new QStatusBar(rdv);
        statusbar->setObjectName("statusbar");
        rdv->setStatusBar(statusbar);

        retranslateUi(rdv);

        QMetaObject::connectSlotsByName(rdv);
    } // setupUi

    void retranslateUi(QMainWindow *rdv)
    {
        rdv->setWindowTitle(QCoreApplication::translate("rdv", "Pet Manage - Gestion des rendez-vous", nullptr));
        menu->setStyleSheet(QCoreApplication::translate("rdv", "QFrame#menu { background-color: #eafaf1; border-right: 1px solid #d5f5e3; }", nullptr));
        labelLogo->setText(QCoreApplication::translate("rdv", "<b style='color:#0e6655; font-size:16px;'>\360\237\220\276 Pet Manage</b><br><span style='color:#7f8c8d; font-size:10px;'>- Center Management -</span>", nullptr));
        btnAccueil->setText(QCoreApplication::translate("rdv", "  Accueil", nullptr));
        btnAnimaux->setText(QCoreApplication::translate("rdv", "  Animaux", nullptr));
        btnRendezVous->setStyleSheet(QCoreApplication::translate("rdv", "background-color: #d4efdf; color: #0e6655; font-weight: bold; border-radius: 8px;", nullptr));
        btnRendezVous->setText(QCoreApplication::translate("rdv", "  Rendez-Vous", nullptr));
        btnStocks->setText(QCoreApplication::translate("rdv", "  Stocks", nullptr));
        btnProprietaires->setText(QCoreApplication::translate("rdv", "  Commande", nullptr));
        btnFournisseurs->setText(QCoreApplication::translate("rdv", "  Fournisseurs", nullptr));
        btnEmployes->setText(QCoreApplication::translate("rdv", "  Employ\303\251s", nullptr));
        btnParametres->setText(QCoreApplication::translate("rdv", "  Param\303\251tres", nullptr));
        contenu->setStyleSheet(QCoreApplication::translate("rdv", "background-color: #f8f9f9;", nullptr));
        editRecherche->setPlaceholderText(QCoreApplication::translate("rdv", "\360\237\224\215 Rechercher un rendez-vous...", nullptr));
        comboTri->setItemText(0, QCoreApplication::translate("rdv", "Trier par : Date", nullptr));

        btnAjouter->setStyleSheet(QCoreApplication::translate("rdv", "background-color: #0e6655; color: white; font-weight: bold; border-radius: 6px;", nullptr));
        btnAjouter->setText(QCoreApplication::translate("rdv", "+ Ajouter", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("rdv", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("rdv", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("rdv", "Heure", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("rdv", "Animal", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("rdv", "Propri\303\251taire", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("rdv", "V\303\251t\303\251rinaire", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("rdv", "Statut", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("rdv", "Actions", nullptr));
        framePicJours->setStyleSheet(QCoreApplication::translate("rdv", "background: white; border-radius: 10px;", nullptr));
        framePicHeures->setStyleSheet(QCoreApplication::translate("rdv", "background: white; border-radius: 10px;", nullptr));
        btnExportPdf->setText(QCoreApplication::translate("rdv", " Exporter PDF", nullptr));
        modification->setStyleSheet(QCoreApplication::translate("rdv", "QFrame#modification { background-color: white; border-left: 1px solid #e0e0e0; }", nullptr));
        labelPicTitre->setStyleSheet(QCoreApplication::translate("rdv", "font-weight: bold; font-size: 14px; color: #2c3e50;", nullptr));
        labelPicTitre->setText(QCoreApplication::translate("rdv", "Modifier le rendez-vous", nullptr));
        labelId->setText(QCoreApplication::translate("rdv", "ID", nullptr));
        labelDate->setText(QCoreApplication::translate("rdv", "Date", nullptr));
        labelHeure->setText(QCoreApplication::translate("rdv", "Heure", nullptr));
        labelAnimal->setText(QCoreApplication::translate("rdv", "Animal", nullptr));
        labelProprio->setText(QCoreApplication::translate("rdv", "Propri\303\251taire", nullptr));
        labelVet->setText(QCoreApplication::translate("rdv", "V\303\251t\303\251rinaire", nullptr));
        labelStatut->setText(QCoreApplication::translate("rdv", "Statut", nullptr));
        comboStatut->setItemText(0, QCoreApplication::translate("rdv", "Confirm\303\251", nullptr));
        comboStatut->setItemText(1, QCoreApplication::translate("rdv", "En attente", nullptr));
        comboStatut->setItemText(2, QCoreApplication::translate("rdv", "Annul\303\251", nullptr));
        comboStatut->setItemText(3, QCoreApplication::translate("rdv", "Termin\303\251", nullptr));

        btnAnnuler->setStyleSheet(QCoreApplication::translate("rdv", "border: 1px solid #0e6655; color: #0e6655; border-radius: 6px; font-weight: bold;", nullptr));
        btnAnnuler->setText(QCoreApplication::translate("rdv", "Annuler", nullptr));
        pushButton->setStyleSheet(QCoreApplication::translate("rdv", "background-color: #0e6655; color: white; border-radius: 6px; font-weight: bold;", nullptr));
        pushButton->setText(QCoreApplication::translate("rdv", "Enregistrer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class rdv: public Ui_rdv {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RDV_H
