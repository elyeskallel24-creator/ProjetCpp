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
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page_5;
    QFrame *frameSidebar;
    QLabel *label_logo;
    QPushButton *btnAccueil;
    QPushButton *btnAnimaux;
    QPushButton *btnRendezvous;
    QPushButton *btnStock;
    QPushButton *btnCommande;
    QPushButton *btnFournisseurs;
    QPushButton *btnEmployees;
    QLabel *label_titre;
    QLabel *label_soustitre;
    QLineEdit *lineEdit_recherche;
    QLabel *label_filtre;
    QComboBox *comboStatut;
    QLabel *label_tri;
    QLineEdit *lineEdit_date;
    QPushButton *btnAjouter;
    QPushButton *btnFrequence;
    QPushButton *btnPrevision;
    QTableWidget *tableWidget;
    QFrame *frame_ajout;
    QLabel *label_titre_ajout;
    QLineEdit *lineEdit_datecmd_C;
    QLineEdit *lineEdit_cmdliv_C;
    QLineEdit *lineEdit_f_C;
    QLineEdit *lineEdit_qte_C;
    QPushButton *btnEnregistrer;
    QFrame *frame_details;
    QLabel *label_titre_details;
    QLabel *label_cle_0;
    QLabel *label_val_0;
    QLabel *label_cle_1;
    QLabel *label_val_1;
    QLabel *label_cle_2;
    QLabel *label_val_2;
    QLabel *label_cle_3;
    QLabel *label_val_3;
    QLabel *label_cle_4;
    QLabel *label_val_4;
    QPushButton *btnExporter;
    QFrame *frame_freq;
    QLabel *label_titre_freq;
    QLabel *label_graph_freq;
    QFrame *frame_prev;
    QLabel *label_titre_prev;
    QLabel *label_graph_prev;
    QWidget *page_6;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        MainWindow->setStyleSheet(QString::fromUtf8("* { font-family: \"Segoe UI\", sans-serif; font-size: 9pt; }\n"
"QMainWindow, QWidget#centralwidget, QStackedWidget, QWidget#page_5, QWidget#page_6 { background-color: #F3F6F9; }\n"
"QLabel { background: transparent; color: #1F2937; }\n"
"\n"
"QFrame#frameSidebar { background-color: #0B5D63; border: none; }\n"
"QFrame#frameSidebar QPushButton { background-color: transparent; color: #E6F4F3; border: none; border-radius: 6px; text-align: left; padding-left: 8px; font-size: 9pt; }\n"
"QFrame#frameSidebar QPushButton:hover { background-color: rgba(255,255,255,0.14); }\n"
"QFrame#frameSidebar QPushButton#btnCommande { background-color: #137A80; color: white; font-weight: bold; }\n"
"\n"
"QLabel#label_titre { color: #0F2A43; font-size: 16pt; font-weight: bold; }\n"
"QLabel#label_soustitre { color: #6B7280; }\n"
"\n"
"QLineEdit, QComboBox { background-color: white; color: #1F2937; border: 1px solid #D1D5DB; border-radius: 6px; padding: 1px 8px; selection-background-color: #0F766E; }\n"
"QLineEdit:focus, QComboBox:foc"
                        "us { border: 1px solid #0F766E; }\n"
"QComboBox::drop-down { border: none; width: 22px; }\n"
"QComboBox QAbstractItemView { background: white; color: #1F2937; border: 1px solid #D1D5DB; selection-background-color: #E6F4F3; selection-color: #0B5D63; }\n"
"\n"
"QPushButton#btnAjouter, QPushButton#btnEnregistrer, QPushButton#btnExporter { background-color: #0F766E; color: white; border: none; border-radius: 6px; font-weight: bold; }\n"
"QPushButton#btnAjouter:hover, QPushButton#btnEnregistrer:hover, QPushButton#btnExporter:hover { background-color: #0B5D63; }\n"
"QPushButton#btnModifier, QPushButton#btnSupprimer { border: none; border-radius: 5px; color: white; font-weight: bold; min-width: 22px; max-width: 22px; min-height: 22px; max-height: 22px; }\n"
"QPushButton#btnModifier { background-color: #0F766E; }\n"
"QPushButton#btnSupprimer { background-color: #DC2626; }\n"
"\n"
"QTableWidget { background-color: white; color: #1F2937; border: 1px solid #E5E7EB; border-radius: 10px; selection-background-color: #E6F4F3"
                        "; selection-color: #0B5D63; }\n"
"QTableWidget::item { padding-left: 6px; border-bottom: 1px solid #EEF2F6; }\n"
"QHeaderView::section { background-color: #F8FAFC; color: #374151; border: none; border-bottom: 1px solid #E5E7EB; padding: 6px; font-weight: bold; }\n"
"QWidget#cellContainer { background: transparent; }\n"
"QLabel#badgeCommandee, QLabel#label_val_3 { background-color: #DBEAFE; color: #1D4ED8; border-radius: 9px; font-weight: bold; }\n"
"\n"
"QFrame#frame_ajout, QFrame#frame_details, QFrame#frame_freq, QFrame#frame_prev { background-color: white; border: 1px solid #E5E7EB; border-radius: 10px; }\n"
"QFrame#frame_ajout QLabel, QFrame#frame_details QLabel, QFrame#frame_freq QLabel, QFrame#frame_prev QLabel { border: none; }\n"
"QLabel#label_titre_ajout, QLabel#label_titre_details, QLabel#label_titre_freq, QLabel#label_titre_prev { background-color: #0F766E; color: white; font-weight: bold; padding-left: 10px; border-top-left-radius: 9px; border-top-right-radius: 9px; }\n"
"QLabel#label_cle_0, QLabel#"
                        "label_cle_1, QLabel#label_cle_2, QLabel#label_cle_3, QLabel#label_cle_4 { color: #6B7280; }\n"
"QLabel#label_val_0, QLabel#label_val_1, QLabel#label_val_2, QLabel#label_val_4 { color: #111827; font-weight: bold; }\n"
"QLabel#label_graph_freq, QLabel#label_graph_prev { background-color: #F3F6F9; color: #9CA3AF; border-radius: 8px; }\n"
"\n"
"QPushButton#btnFrequence, QPushButton#btnPrevision { background-color: white; color: #0F766E; border: 1px solid #0F766E; border-radius: 6px; font-weight: bold; }\n"
"QPushButton#btnFrequence:hover, QPushButton#btnPrevision:hover { background-color: #E6F4F3; }\n"
"QPushButton#btnFrequence:pressed, QPushButton#btnPrevision:pressed { background-color: #CDE9E7; }\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 0, 800, 600));
        page_5 = new QWidget();
        page_5->setObjectName("page_5");
        frameSidebar = new QFrame(page_5);
        frameSidebar->setObjectName("frameSidebar");
        frameSidebar->setGeometry(QRect(0, 0, 110, 600));
        label_logo = new QLabel(frameSidebar);
        label_logo->setObjectName("label_logo");
        label_logo->setGeometry(QRect(9, 10, 92, 92));
        label_logo->setAlignment(Qt::AlignCenter);
        btnAccueil = new QPushButton(frameSidebar);
        btnAccueil->setObjectName("btnAccueil");
        btnAccueil->setGeometry(QRect(8, 116, 94, 30));
        btnAnimaux = new QPushButton(frameSidebar);
        btnAnimaux->setObjectName("btnAnimaux");
        btnAnimaux->setGeometry(QRect(8, 154, 94, 30));
        btnRendezvous = new QPushButton(frameSidebar);
        btnRendezvous->setObjectName("btnRendezvous");
        btnRendezvous->setGeometry(QRect(8, 192, 94, 30));
        btnStock = new QPushButton(frameSidebar);
        btnStock->setObjectName("btnStock");
        btnStock->setGeometry(QRect(8, 230, 94, 30));
        btnCommande = new QPushButton(frameSidebar);
        btnCommande->setObjectName("btnCommande");
        btnCommande->setGeometry(QRect(8, 268, 94, 30));
        btnFournisseurs = new QPushButton(frameSidebar);
        btnFournisseurs->setObjectName("btnFournisseurs");
        btnFournisseurs->setGeometry(QRect(8, 306, 94, 30));
        btnEmployees = new QPushButton(frameSidebar);
        btnEmployees->setObjectName("btnEmployees");
        btnEmployees->setGeometry(QRect(8, 344, 94, 30));
        label_titre = new QLabel(page_5);
        label_titre->setObjectName("label_titre");
        label_titre->setGeometry(QRect(130, 10, 500, 30));
        label_soustitre = new QLabel(page_5);
        label_soustitre->setObjectName("label_soustitre");
        label_soustitre->setGeometry(QRect(130, 38, 500, 20));
        lineEdit_recherche = new QLineEdit(page_5);
        lineEdit_recherche->setObjectName("lineEdit_recherche");
        lineEdit_recherche->setGeometry(QRect(130, 72, 160, 26));
        label_filtre = new QLabel(page_5);
        label_filtre->setObjectName("label_filtre");
        label_filtre->setGeometry(QRect(305, 72, 55, 26));
        comboStatut = new QComboBox(page_5);
        comboStatut->addItem(QString());
        comboStatut->addItem(QString());
        comboStatut->addItem(QString());
        comboStatut->addItem(QString());
        comboStatut->setObjectName("comboStatut");
        comboStatut->setGeometry(QRect(360, 72, 115, 26));
        label_tri = new QLabel(page_5);
        label_tri->setObjectName("label_tri");
        label_tri->setGeometry(QRect(495, 72, 70, 26));
        lineEdit_date = new QLineEdit(page_5);
        lineEdit_date->setObjectName("lineEdit_date");
        lineEdit_date->setGeometry(QRect(565, 72, 215, 26));
        btnAjouter = new QPushButton(page_5);
        btnAjouter->setObjectName("btnAjouter");
        btnAjouter->setGeometry(QRect(130, 108, 160, 28));
        btnFrequence = new QPushButton(page_5);
        btnFrequence->setObjectName("btnFrequence");
        btnFrequence->setGeometry(QRect(302, 108, 110, 28));
        btnPrevision = new QPushButton(page_5);
        btnPrevision->setObjectName("btnPrevision");
        btnPrevision->setGeometry(QRect(422, 108, 110, 28));
        tableWidget = new QTableWidget(page_5);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
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
        if (tableWidget->rowCount() < 1)
            tableWidget->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setItem(0, 0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setItem(0, 1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setItem(0, 2, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setItem(0, 3, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setItem(0, 4, __qtablewidgetitem9);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(130, 146, 418, 235));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setShowGrid(false);
        tableWidget->setRowCount(1);
        tableWidget->setColumnCount(5);
        tableWidget->horizontalHeader()->setStretchLastSection(true);
        tableWidget->verticalHeader()->setVisible(false);
        frame_ajout = new QFrame(page_5);
        frame_ajout->setObjectName("frame_ajout");
        frame_ajout->setGeometry(QRect(560, 146, 220, 235));
        label_titre_ajout = new QLabel(frame_ajout);
        label_titre_ajout->setObjectName("label_titre_ajout");
        label_titre_ajout->setGeometry(QRect(0, 0, 220, 30));
        lineEdit_datecmd_C = new QLineEdit(frame_ajout);
        lineEdit_datecmd_C->setObjectName("lineEdit_datecmd_C");
        lineEdit_datecmd_C->setGeometry(QRect(12, 42, 196, 26));
        lineEdit_cmdliv_C = new QLineEdit(frame_ajout);
        lineEdit_cmdliv_C->setObjectName("lineEdit_cmdliv_C");
        lineEdit_cmdliv_C->setGeometry(QRect(12, 76, 196, 26));
        lineEdit_f_C = new QLineEdit(frame_ajout);
        lineEdit_f_C->setObjectName("lineEdit_f_C");
        lineEdit_f_C->setGeometry(QRect(12, 110, 196, 26));
        lineEdit_qte_C = new QLineEdit(frame_ajout);
        lineEdit_qte_C->setObjectName("lineEdit_qte_C");
        lineEdit_qte_C->setGeometry(QRect(12, 144, 196, 26));
        btnEnregistrer = new QPushButton(frame_ajout);
        btnEnregistrer->setObjectName("btnEnregistrer");
        btnEnregistrer->setGeometry(QRect(12, 190, 196, 30));
        frame_details = new QFrame(page_5);
        frame_details->setObjectName("frame_details");
        frame_details->setGeometry(QRect(130, 395, 230, 190));
        label_titre_details = new QLabel(frame_details);
        label_titre_details->setObjectName("label_titre_details");
        label_titre_details->setGeometry(QRect(0, 0, 230, 30));
        label_cle_0 = new QLabel(frame_details);
        label_cle_0->setObjectName("label_cle_0");
        label_cle_0->setGeometry(QRect(12, 40, 115, 20));
        label_val_0 = new QLabel(frame_details);
        label_val_0->setObjectName("label_val_0");
        label_val_0->setGeometry(QRect(132, 40, 88, 20));
        label_cle_1 = new QLabel(frame_details);
        label_cle_1->setObjectName("label_cle_1");
        label_cle_1->setGeometry(QRect(12, 62, 115, 20));
        label_val_1 = new QLabel(frame_details);
        label_val_1->setObjectName("label_val_1");
        label_val_1->setGeometry(QRect(132, 62, 88, 20));
        label_cle_2 = new QLabel(frame_details);
        label_cle_2->setObjectName("label_cle_2");
        label_cle_2->setGeometry(QRect(12, 84, 115, 20));
        label_val_2 = new QLabel(frame_details);
        label_val_2->setObjectName("label_val_2");
        label_val_2->setGeometry(QRect(132, 84, 88, 20));
        label_cle_3 = new QLabel(frame_details);
        label_cle_3->setObjectName("label_cle_3");
        label_cle_3->setGeometry(QRect(12, 106, 115, 20));
        label_val_3 = new QLabel(frame_details);
        label_val_3->setObjectName("label_val_3");
        label_val_3->setGeometry(QRect(132, 106, 88, 20));
        label_cle_4 = new QLabel(frame_details);
        label_cle_4->setObjectName("label_cle_4");
        label_cle_4->setGeometry(QRect(12, 128, 115, 20));
        label_val_4 = new QLabel(frame_details);
        label_val_4->setObjectName("label_val_4");
        label_val_4->setGeometry(QRect(132, 128, 88, 20));
        btnExporter = new QPushButton(frame_details);
        btnExporter->setObjectName("btnExporter");
        btnExporter->setGeometry(QRect(12, 155, 100, 26));
        frame_freq = new QFrame(page_5);
        frame_freq->setObjectName("frame_freq");
        frame_freq->setGeometry(QRect(375, 395, 200, 190));
        label_titre_freq = new QLabel(frame_freq);
        label_titre_freq->setObjectName("label_titre_freq");
        label_titre_freq->setGeometry(QRect(0, 0, 200, 30));
        label_graph_freq = new QLabel(frame_freq);
        label_graph_freq->setObjectName("label_graph_freq");
        label_graph_freq->setGeometry(QRect(12, 42, 176, 134));
        label_graph_freq->setAlignment(Qt::AlignCenter);
        frame_prev = new QFrame(page_5);
        frame_prev->setObjectName("frame_prev");
        frame_prev->setGeometry(QRect(590, 395, 190, 190));
        label_titre_prev = new QLabel(frame_prev);
        label_titre_prev->setObjectName("label_titre_prev");
        label_titre_prev->setGeometry(QRect(0, 0, 190, 30));
        label_graph_prev = new QLabel(frame_prev);
        label_graph_prev->setObjectName("label_graph_prev");
        label_graph_prev->setGeometry(QRect(12, 42, 166, 134));
        label_graph_prev->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(page_5);
        page_6 = new QWidget();
        page_6->setObjectName("page_6");
        stackedWidget->addWidget(page_6);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Pet Manager - Gestion des commandes", nullptr));
        label_logo->setText(QCoreApplication::translate("MainWindow", "LOGO", nullptr));
        btnAccueil->setText(QCoreApplication::translate("MainWindow", "Accueil", nullptr));
        btnAnimaux->setText(QCoreApplication::translate("MainWindow", "Animaux", nullptr));
        btnRendezvous->setText(QCoreApplication::translate("MainWindow", "Rendez-vous", nullptr));
        btnStock->setText(QCoreApplication::translate("MainWindow", "Stock", nullptr));
        btnCommande->setText(QCoreApplication::translate("MainWindow", "Commandes", nullptr));
        btnFournisseurs->setText(QCoreApplication::translate("MainWindow", "Fournisseurs", nullptr));
        btnEmployees->setText(QCoreApplication::translate("MainWindow", "Employ\303\251s", nullptr));
        label_titre->setText(QCoreApplication::translate("MainWindow", "Gestion des commandes", nullptr));
        label_soustitre->setText(QCoreApplication::translate("MainWindow", "Suivez vos commandes et gardez votre stock \303\240 jour.", nullptr));
        lineEdit_recherche->setPlaceholderText(QCoreApplication::translate("MainWindow", "Rechercher par ID ...", nullptr));
        label_filtre->setText(QCoreApplication::translate("MainWindow", "Statut :", nullptr));
        comboStatut->setItemText(0, QCoreApplication::translate("MainWindow", "Tous", nullptr));
        comboStatut->setItemText(1, QCoreApplication::translate("MainWindow", "Command\303\251e", nullptr));
        comboStatut->setItemText(2, QCoreApplication::translate("MainWindow", "Livr\303\251e", nullptr));
        comboStatut->setItemText(3, QCoreApplication::translate("MainWindow", "Supprim\303\251e", nullptr));

        label_tri->setText(QCoreApplication::translate("MainWindow", "Trier par :", nullptr));
        lineEdit_date->setPlaceholderText(QCoreApplication::translate("MainWindow", "Entrer la date de livraison", nullptr));
        btnAjouter->setText(QCoreApplication::translate("MainWindow", "+ Nouvelle commande", nullptr));
        btnFrequence->setText(QCoreApplication::translate("MainWindow", "Fr\303\251quence", nullptr));
        btnPrevision->setText(QCoreApplication::translate("MainWindow", "Pr\303\251vision", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Date commande", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Date livraison", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Statut", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Actions", nullptr));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->item(0, 0);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "C001", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->item(0, 1);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "03/10/2026", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->item(0, 2);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "06/10/2026", nullptr));
        tableWidget->setSortingEnabled(__sortingEnabled);

        label_titre_ajout->setText(QCoreApplication::translate("MainWindow", "Ajouter une commande", nullptr));
        lineEdit_datecmd_C->setPlaceholderText(QCoreApplication::translate("MainWindow", "Entrer la date de commande", nullptr));
        lineEdit_cmdliv_C->setPlaceholderText(QCoreApplication::translate("MainWindow", "Entrer la date de livraison", nullptr));
        lineEdit_f_C->setPlaceholderText(QCoreApplication::translate("MainWindow", "Entrer le nom du fournisseur", nullptr));
        lineEdit_qte_C->setPlaceholderText(QCoreApplication::translate("MainWindow", "Entrer la quantit\303\251", nullptr));
        btnEnregistrer->setText(QCoreApplication::translate("MainWindow", "Enregistrer", nullptr));
        label_titre_details->setText(QCoreApplication::translate("MainWindow", "D\303\251tails d'une commande", nullptr));
        label_cle_0->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        label_val_0->setText(QCoreApplication::translate("MainWindow", "C001", nullptr));
        label_cle_1->setText(QCoreApplication::translate("MainWindow", "Date de commande", nullptr));
        label_val_1->setText(QCoreApplication::translate("MainWindow", "03/10/2026", nullptr));
        label_cle_2->setText(QCoreApplication::translate("MainWindow", "Date de livraison", nullptr));
        label_val_2->setText(QCoreApplication::translate("MainWindow", "06/10/2026", nullptr));
        label_cle_3->setText(QCoreApplication::translate("MainWindow", "Statut", nullptr));
        label_val_3->setText(QCoreApplication::translate("MainWindow", "Command\303\251e", nullptr));
        label_cle_4->setText(QCoreApplication::translate("MainWindow", "Montant total", nullptr));
        label_val_4->setText(QCoreApplication::translate("MainWindow", "XXX TND", nullptr));
        btnExporter->setText(QCoreApplication::translate("MainWindow", "Exporter", nullptr));
        label_titre_freq->setText(QCoreApplication::translate("MainWindow", "Fr\303\251quence", nullptr));
        label_graph_freq->setText(QCoreApplication::translate("MainWindow", "Graphique", nullptr));
        label_titre_prev->setText(QCoreApplication::translate("MainWindow", "Pr\303\251vision", nullptr));
        label_graph_prev->setText(QCoreApplication::translate("MainWindow", "Graphique", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
