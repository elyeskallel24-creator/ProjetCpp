// =====================================================================
//                       MODULE RENDEZ-VOUS
//  Code du module RDV (ancien projet GRendezVous / classe "rdv") intégré
//  à MainWindow. Les widgets de la page sont dans mainwindow.ui
//  (pageRendezVous) et portent le préfixe "rdv".
// =====================================================================
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTableWidgetItem>
#include <QHeaderView>
#include <QMessageBox>
#include <QFileDialog>
#include <QPdfWriter>
#include <QPainter>
#include <QPageSize>
#include <QDesktopServices>
#include <QUrl>
#include <QDir>
#include <QFile>
#include <QDate>
#include <QChart>
#include <QChartView>
#include <QPieSeries>
#include <QPieSlice>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QProgressBar>
#include <QRegularExpression>

namespace {

// Couleur du badge de statut dans le tableau
void appliquerStyleStatutRdv(QTableWidgetItem *item, const QString &statut)
{
    item->setTextAlignment(Qt::AlignCenter);
    item->setFont(QFont("Segoe UI", 11, QFont::Medium));

    if (statut == "Confirmé") {
        item->setBackground(QColor(209, 250, 229));
        item->setForeground(QColor(6, 95, 70));
    } else if (statut == "En attente") {
        item->setBackground(QColor(254, 215, 170));
        item->setForeground(QColor(154, 52, 18));
    } else if (statut == "Annulé") {
        item->setBackground(QColor(254, 205, 211));
        item->setForeground(QColor(159, 18, 57));
    } else if (statut == "Terminé") {
        item->setBackground(QColor(219, 234, 254));
        item->setForeground(QColor(30, 64, 175));
    }
}

} // namespace

// ---------------------------------------------------------------------
//  Initialisation (appelée une seule fois par le constructeur)
// ---------------------------------------------------------------------
void MainWindow::initialiserModuleRendezVous()
{
    // Tableau
    ui->rdvTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->rdvTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->rdvTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->rdvTable->verticalHeader()->setVisible(false);
    ui->rdvTable->setShowGrid(false);

    // Listes déroulantes (données d'exemple, à remplacer par la base de données)
    ui->rdvComboAnimal->clear();
    ui->rdvComboAnimal->addItems({"Luna", "Milo", "Max", "Bella", "Rocky"});

    ui->rdvComboProprietaire->clear();
    ui->rdvComboProprietaire->addItems({"Karima", "Ahmed", "Sami", "Amel", "Sinda"});

    ui->rdvComboVeterinaire->clear();
    ui->rdvComboVeterinaire->addItems({"Dr Martin", "Dr Lefèvre", "Dr Garnier", "Dr Sami"});

    ui->rdvComboStatut->clear();
    ui->rdvComboStatut->addItems({"Confirmé", "En attente", "Annulé", "Terminé"});

    ui->rdvDateEdit->setDateTime(QDateTime::currentDateTime());

    // Graphiques et données
    creerDonutRdv();
    creerPicRdv();
    chargerDonneesInitialesRdv();

    // Boutons (connexions explicites : pas de slot on_xxx_clicked pour éviter
    // un double déclenchement avec connectSlotsByName)
    connect(ui->rdvBtnAjouter,     &QPushButton::clicked, this, &MainWindow::ajouterRdv);
    connect(ui->rdvBtnEnregistrer, &QPushButton::clicked, this, &MainWindow::ajouterRdv);
    connect(ui->rdvBtnExportPdf,   &QPushButton::clicked, this, &MainWindow::exporterPdfRdv);
}

// Bouton « Rendez-vous » du menu latéral
void MainWindow::on_btn_menu_rdv_clicked()
{
    ui->SWPetManager->setCurrentWidget(ui->pageRendezVous);
}

// ---------------------------------------------------------------------
//  Données initiales
// ---------------------------------------------------------------------
void MainWindow::chargerDonneesInitialesRdv()
{
    struct RDV {
        QString id, date, heure, animal, proprietaire, veterinaire, statut;
    };

    const QList<RDV> liste = {
        {"RDV001", "20/09/2026", "09:00", "🐶 Luna",  "Karima", "Dr Martin",  "Confirmé"},
        {"RDV002", "21/09/2026", "10:30", "🐱 Milo",  "Ahmed",  "Dr Lefèvre", "En attente"},
        {"RDV003", "22/09/2026", "14:00", "🐱 Max",   "Sami",   "Dr Martin",  "Confirmé"},
        {"RDV004", "23/09/2026", "11:00", "🐾 Bella", "Amel",   "Dr Garnier", "Annulé"},
        {"RDV005", "24/09/2026", "15:30", "🐶 Rocky", "Sinda",  "Dr Lefèvre", "Confirmé"}
    };

    ui->rdvTable->setRowCount(0);
    for (int i = 0; i < liste.size(); ++i) {
        ui->rdvTable->insertRow(i);
        ui->rdvTable->setItem(i, 0, new QTableWidgetItem(liste[i].id));
        ui->rdvTable->setItem(i, 1, new QTableWidgetItem(liste[i].date));
        ui->rdvTable->setItem(i, 2, new QTableWidgetItem(liste[i].heure));
        ui->rdvTable->setItem(i, 3, new QTableWidgetItem(liste[i].animal));
        ui->rdvTable->setItem(i, 4, new QTableWidgetItem(liste[i].proprietaire));
        ui->rdvTable->setItem(i, 5, new QTableWidgetItem(liste[i].veterinaire));

        auto *statutItem = new QTableWidgetItem(liste[i].statut);
        appliquerStyleStatutRdv(statutItem, liste[i].statut);
        ui->rdvTable->setItem(i, 6, statutItem);
        ui->rdvTable->setItem(i, 7, new QTableWidgetItem("✏️  👁️"));
    }
}

// ---------------------------------------------------------------------
//  Ajout d'un rendez-vous (boutons « + Ajouter » et « Enregistrer »)
// ---------------------------------------------------------------------
void MainWindow::ajouterRdv()
{
    const int ligne = ui->rdvTable->rowCount();
    ui->rdvTable->insertRow(ligne);

    const QString id = QString("RDV%1").arg(ligne + 1, 3, 10, QChar('0'));
    ui->rdvEditId->setText(id);

    ui->rdvTable->setItem(ligne, 0, new QTableWidgetItem(id));
    ui->rdvTable->setItem(ligne, 1, new QTableWidgetItem(
                                        ui->rdvDateEdit->date().toString("dd/MM/yyyy")));
    ui->rdvTable->setItem(ligne, 2, new QTableWidgetItem(
                                        ui->rdvTimeEdit->time().toString("HH:mm")));
    ui->rdvTable->setItem(ligne, 3, new QTableWidgetItem(
                                        "🐾 " + ui->rdvComboAnimal->currentText()));
    ui->rdvTable->setItem(ligne, 4, new QTableWidgetItem(
                                        ui->rdvComboProprietaire->currentText()));
    ui->rdvTable->setItem(ligne, 5, new QTableWidgetItem(
                                        ui->rdvComboVeterinaire->currentText()));

    const QString statut = ui->rdvComboStatut->currentText();
    auto *statutItem = new QTableWidgetItem(statut);
    appliquerStyleStatutRdv(statutItem, statut);
    ui->rdvTable->setItem(ligne, 6, statutItem);
    ui->rdvTable->setItem(ligne, 7, new QTableWidgetItem("✏️  🗑️"));

    QMessageBox::information(this, "Succès", "Rendez-vous enregistré avec succès !");
}

// ---------------------------------------------------------------------
//  Graphique en anneau « Répartition des rendez-vous »
// ---------------------------------------------------------------------
void MainWindow::creerDonutRdv()
{
    const QStringList noms = {"Consultation", "Vaccination", "Contrôle", "Urgence"};
    const QList<int> valeurs = {45, 30, 20, 15};
    const QList<QColor> couleurs = {QColor(46, 204, 113), QColor(52, 152, 219),
                                    QColor(243, 156, 18), QColor(231, 76, 60)};

    auto *serie = new QPieSeries();
    serie->setHoleSize(0.50);

    for (int i = 0; i < noms.size(); ++i) {
        QPieSlice *s = serie->append(noms[i], valeurs[i]);
        s->setBrush(couleurs[i]);
        s->setLabel(QString("%1%").arg(valeurs[i]));
        s->setLabelVisible(true);
        s->setLabelColor(Qt::white);
        s->setLabelFont(QFont("Segoe UI", 10, QFont::Bold));
        s->setLabelPosition(QPieSlice::LabelInsideTangential);
    }

    auto *chart = new QChart();
    chart->addSeries(serie);
    chart->legend()->hide();
    chart->setBackgroundVisible(false);
    chart->setMargins(QMargins(0, 0, 0, 0));

    auto *vue = new QChartView(chart);
    vue->setRenderHint(QPainter::Antialiasing);
    vue->setFixedSize(200, 200);

    auto *lblTotal = new QLabel("Total\n100%");
    lblTotal->setAlignment(Qt::AlignCenter);
    lblTotal->setStyleSheet("font-size: 14px; font-weight: bold; color: #1e293b; background: transparent;");
    lblTotal->setFixedSize(80, 50);
    lblTotal->setParent(vue);
    lblTotal->move(60, 75);
    lblTotal->raise();

    auto *widgetLegende = new QWidget();
    auto *layoutLegende = new QVBoxLayout(widgetLegende);
    layoutLegende->setContentsMargins(0, 0, 0, 0);
    layoutLegende->setSpacing(8);

    for (int i = 0; i < noms.size(); ++i) {
        auto *ligneItem = new QHBoxLayout();
        ligneItem->setSpacing(8);

        auto *pastille = new QLabel();
        pastille->setFixedSize(12, 12);
        pastille->setStyleSheet(QString("background-color: %1; border-radius: 6px;").arg(couleurs[i].name()));

        auto *texteItem = new QLabel(QString("%1  <b>%2%</b>").arg(noms[i]).arg(valeurs[i]));
        texteItem->setStyleSheet("font-size: 12px; color: #475569;");

        ligneItem->addWidget(pastille);
        ligneItem->addWidget(texteItem);
        layoutLegende->addLayout(ligneItem);
    }

    auto *lblTitre = new QLabel("Répartition des rendez-vous");
    lblTitre->setStyleSheet("font-size: 14px; font-weight: bold; color: #1e293b; padding-bottom: 5px;");

    if (ui->rdvWidgetDonut->layout())
        delete ui->rdvWidgetDonut->layout();

    auto *mainLayout = new QVBoxLayout(ui->rdvWidgetDonut);
    mainLayout->setContentsMargins(15, 15, 15, 15);
    mainLayout->setSpacing(5);
    mainLayout->addWidget(lblTitre);

    auto *ligneContenu = new QHBoxLayout();
    ligneContenu->setContentsMargins(0, 0, 0, 0);
    ligneContenu->setSpacing(15);
    ligneContenu->addWidget(vue);
    ligneContenu->addWidget(widgetLegende);
    ligneContenu->addStretch();

    mainLayout->addLayout(ligneContenu);
}

// ---------------------------------------------------------------------
//  Graphiques en barres (jours / heures les plus demandés)
// ---------------------------------------------------------------------
void MainWindow::remplirPicRdv(QFrame *cadre, const QString &titre,
                               const QStringList &noms, const QList<int> &valeurs)
{
    if (cadre->layout())
        delete cadre->layout();

    auto *grille = new QGridLayout(cadre);
    grille->setContentsMargins(15, 15, 15, 15);
    grille->setSpacing(10);
    grille->setColumnStretch(0, 1);
    grille->setColumnStretch(1, 2);
    grille->setColumnStretch(2, 0);

    auto *lblTitre = new QLabel(titre);
    lblTitre->setStyleSheet("font-weight: bold; color: #1e293b; font-size: 14px; padding-bottom: 10px;");
    lblTitre->setWordWrap(true);
    grille->addWidget(lblTitre, 0, 0, 1, 3);

    for (int i = 0; i < noms.size(); ++i) {
        auto *nom = new QLabel(noms[i]);
        nom->setStyleSheet("font-size: 12px; color: #475569;");
        nom->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
        grille->addWidget(nom, i + 1, 0);

        auto *barre = new QProgressBar();
        barre->setRange(0, 100);
        barre->setValue(valeurs[i]);
        barre->setTextVisible(false);
        barre->setFixedHeight(8);
        barre->setMinimumWidth(80);
        barre->setStyleSheet("QProgressBar { background: #e2e8f0; border-radius: 4px; border: none; }"
                             " QProgressBar::chunk { background: #10b981; border-radius: 4px; }");
        grille->addWidget(barre, i + 1, 1);

        auto *pct = new QLabel(QString("%1%").arg(valeurs[i]));
        pct->setStyleSheet("font-size: 12px; color: #64748b; font-weight: 600;");
        pct->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
        pct->setFixedWidth(40);
        grille->addWidget(pct, i + 1, 2);
    }
}

void MainWindow::creerPicRdv()
{
    remplirPicRdv(ui->rdvFramePicJours, "📅 Jours les plus demandés",
                  {"Lundi", "Mercredi", "Vendredi", "Mardi", "Jeudi"},
                  {22, 20, 18, 16, 14});

    remplirPicRdv(ui->rdvFramePicHeures, "🕒 Heures les plus demandées",
                  {"09:00 - 11:00", "11:00 - 13:00", "14:00 - 16:00",
                   "16:00 - 18:00", "Autres"},
                  {32, 28, 24, 10, 6});
}

// ---------------------------------------------------------------------
//  Export PDF de la liste des rendez-vous
// ---------------------------------------------------------------------
void MainWindow::exporterPdfRdv()
{
    const QString cheminFichier = QFileDialog::getSaveFileName(
        this,
        "Exporter en PDF",
        QDir::homePath() + "/rendez-vous_" + QDate::currentDate().toString("dd-MM-yyyy") + ".pdf",
        "Fichiers PDF (*.pdf)");

    if (cheminFichier.isEmpty())
        return;

    QFile file(cheminFichier);
    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::warning(this, "Erreur", "Impossible d'écrire le fichier.");
        return;
    }

    QPdfWriter pdfWriter(&file);
    pdfWriter.setPageSize(QPageSize(QPageSize::A4));
    pdfWriter.setResolution(300);

    QPainter painter(&pdfWriter);
    int yPos = 300;

    // Titre du document
    painter.setFont(QFont("Segoe UI", 18, QFont::Bold));
    painter.setPen(QColor(14, 102, 85));
    painter.drawText(300, yPos, "Pet Manage - Liste des Rendez-vous");
    yPos += 150;

    // Ligne de séparation
    painter.setPen(QPen(QColor(200, 200, 200), 2));
    painter.drawLine(300, yPos, 2200, yPos);
    yPos += 200;

    // En-têtes du tableau
    painter.setFont(QFont("Segoe UI", 10, QFont::Bold));
    painter.setPen(Qt::black);
    const int colonnesX[] = {300, 600, 900, 1200, 1500, 1800, 2100};
    const QStringList enTetes = {"ID", "Date", "Heure", "Animal", "Propriétaire", "Vétérinaire", "Statut"};
    for (int i = 0; i < enTetes.size(); ++i)
        painter.drawText(colonnesX[i], yPos, enTetes[i]);
    yPos += 100;

    // Contenu du tableau
    painter.setFont(QFont("Segoe UI", 10, QFont::Normal));
    const int nbLignes = ui->rdvTable->rowCount();
    const int nbColonnes = qMin(7, ui->rdvTable->columnCount());

    for (int row = 0; row < nbLignes; ++row) {
        for (int col = 0; col < nbColonnes; ++col) {
            QTableWidgetItem *item = ui->rdvTable->item(row, col);
            if (item) {
                const QString texte = item->text().remove(QRegularExpression("[^\\w\\s:/.-]"));
                painter.drawText(colonnesX[col], yPos, texte.trimmed());
            }
        }
        yPos += 120;
        if (yPos > 3300) {
            pdfWriter.newPage();
            yPos = 300;
        }
    }

    painter.end();
    file.close();

    QMessageBox::information(this, "Succès",
                             "Le fichier PDF a été exporté avec succès !\n\n" + cheminFichier);
    QDesktopServices::openUrl(QUrl::fromLocalFile(cheminFichier));
}
