#include "rdv.h"
#include "ui_rdv.h"

#include <QTableWidgetItem>
#include <QPushButton>
#include <QHeaderView>
#include <QMessageBox>
#include <QFileDialog>
#include <QPdfWriter>
#include <QPainter>
#include <QPageSize>
#include <QPageLayout>
#include <QDesktopServices>
#include <QUrl>
#include <QDateTime>
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

rdv::rdv(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::rdv)
{
    ui->setupUi(this);
    setWindowTitle("Pet Manage - Center Management");
    resize(1400, 900);

    // Configuration du tableau
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->setShowGrid(false);

    // Remplissage des ComboBox
    ui->comboAnimal->clear();
    ui->comboAnimal->addItems({"Luna", "Milo", "Max", "Bella", "Rocky"});

    ui->comboProprietaire->clear();
    ui->comboProprietaire->addItems({"Karima", "Ahmed", "Sami", "Amel", "Sinda"});

    ui->comboVeterinaire->clear();
    ui->comboVeterinaire->addItems({"Dr Martin", "Dr Lefèvre", "Dr Garnier", "Dr Sami"});

    ui->comboStatut->clear();
    ui->comboStatut->addItems({"Confirmé", "En attente", "Annulé", "Terminé"});

    // ⭐ Créer le bouton Export PDF dynamiquement
    creerBoutonExportPdf();

    // Charger graphiques et données
    creerDonut();
    creerPic();
    chargerDonneesInitiales();

    // Connexion du bouton Ajouter
    connect(ui->pushButton, &QPushButton::clicked, this, &rdv::on_btnAjouter_clicked);
}

rdv::~rdv()
{
    delete ui;
}

// ═══════════════════════════════════════════════════════════════
// ⭐ CRÉATION DYNAMIQUE DU BOUTON EXPORT PDF
// ═══════════════════════════════════════════════════════════════
void rdv::creerBoutonExportPdf()
{
    // Trouver le widget parent qui contient le bouton "+ Ajouter"
    QWidget *parentWidget = ui->pushButton->parentWidget();

    if (parentWidget && parentWidget->layout()) {
        // Créer le bouton Export PDF
        QPushButton *btnExport = new QPushButton("📄 Exporter PDF");
        btnExport->setCursor(Qt::PointingHandCursor);
        btnExport->setStyleSheet(R"(
            QPushButton {
                background-color: #ffffff;
                color: #059669;
                border: 2px solid #059669;
                border-radius: 8px;
                padding: 10px 20px;
                font-size: 14px;
                font-weight: bold;
            }
            QPushButton:hover {
                background-color: #ecfdf5;
            }
            QPushButton:pressed {
                background-color: #d1fae5;
            }
        )");

        // Ajouter le bouton à côté du bouton "+ Ajouter"
        parentWidget->layout()->addWidget(btnExport);

        // Connecter le signal clicked
        connect(btnExport, &QPushButton::clicked, this, &rdv::on_btnExportPdf_clicked);
    }
}

// ═══════════════════════════════════════════════════════════════
// ⭐ CHARGEMENT DES DONNÉES INITIALES
// ═══════════════════════════════════════════════════════════════
void rdv::chargerDonneesInitiales()
{
    struct RDV {
        QString id, date, heure, animal, proprietaire, veterinaire, statut;
    };

    QList<RDV> liste = {
        {"RDV001", "20/09/2026", "09:00", "🐶 Luna",   "Karima", "Dr Martin",   "Confirmé"},
        {"RDV002", "21/09/2026", "10:30", "🐱 Milo",   "Ahmed",  "Dr Lefèvre",  "En attente"},
        {"RDV003", "22/09/2026", "14:00", "🐱 Max",    "Sami",   "Dr Martin",   "Confirmé"},
        {"RDV004", "23/09/2026", "11:00", " Bella",  "Amel",   "Dr Garnier",  "Annulé"},
        {"RDV005", "24/09/2026", "15:30", "🐶 Rocky",  "Sinda",  "Dr Lefèvre",  "Confirmé"}
    };

    ui->tableWidget->setRowCount(0);
    for (int i = 0; i < liste.size(); ++i) {
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(liste[i].id));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(liste[i].date));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(liste[i].heure));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(liste[i].animal));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(liste[i].proprietaire));
        ui->tableWidget->setItem(i, 5, new QTableWidgetItem(liste[i].veterinaire));

        // Badge de statut coloré
        QTableWidgetItem *statutItem = new QTableWidgetItem(liste[i].statut);
        statutItem->setTextAlignment(Qt::AlignCenter);
        statutItem->setFont(QFont("Segoe UI", 11, QFont::Medium));

        if (liste[i].statut == "Confirmé") {
            statutItem->setBackground(QColor(209, 250, 229));
            statutItem->setForeground(QColor(6, 95, 70));
        } else if (liste[i].statut == "En attente") {
            statutItem->setBackground(QColor(254, 215, 170));
            statutItem->setForeground(QColor(154, 52, 18));
        } else if (liste[i].statut == "Annulé") {
            statutItem->setBackground(QColor(254, 205, 211));
            statutItem->setForeground(QColor(159, 18, 57));
        } else if (liste[i].statut == "Terminé") {
            statutItem->setBackground(QColor(219, 234, 254));
            statutItem->setForeground(QColor(30, 64, 175));
        }

        ui->tableWidget->setItem(i, 6, statutItem);
        ui->tableWidget->setItem(i, 7, new QTableWidgetItem("✏️  ️  👁️"));
    }
}

// ═══════════════════════════════════════════════════════════════
//  BOUTON AJOUTER
// ═══════════════════════════════════════════════════════════════
void rdv::on_btnAjouter_clicked()
{
    int ligne = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(ligne);

    QString id = QString("RDV%1").arg(ligne + 1, 3, 10, QChar('0'));
    ui->lineEditId->setText(id);

    ui->tableWidget->setItem(ligne, 0, new QTableWidgetItem(id));
    ui->tableWidget->setItem(ligne, 1, new QTableWidgetItem(
                                           ui->dateEditRdv->date().toString("dd/MM/yyyy")));
    ui->tableWidget->setItem(ligne, 2, new QTableWidgetItem(
                                           ui->timeEditRdv->time().toString("HH:mm")));
    ui->tableWidget->setItem(ligne, 3, new QTableWidgetItem(
                                           "🐾 " + ui->comboAnimal->currentText()));
    ui->tableWidget->setItem(ligne, 4, new QTableWidgetItem(
                                           ui->comboProprietaire->currentText()));
    ui->tableWidget->setItem(ligne, 5, new QTableWidgetItem(
                                           ui->comboVeterinaire->currentText()));

    // Badge coloré pour le statut
    QTableWidgetItem *statutItem = new QTableWidgetItem(ui->comboStatut->currentText());
    statutItem->setTextAlignment(Qt::AlignCenter);
    statutItem->setFont(QFont("Segoe UI", 11, QFont::Medium));

    QString statut = ui->comboStatut->currentText();
    if (statut == "Confirmé") {
        statutItem->setBackground(QColor(209, 250, 229));
        statutItem->setForeground(QColor(6, 95, 70));
    } else if (statut == "En attente") {
        statutItem->setBackground(QColor(254, 215, 170));
        statutItem->setForeground(QColor(154, 52, 18));
    } else if (statut == "Annulé") {
        statutItem->setBackground(QColor(254, 205, 211));
        statutItem->setForeground(QColor(159, 18, 57));
    } else if (statut == "Terminé") {
        statutItem->setBackground(QColor(219, 234, 254));
        statutItem->setForeground(QColor(30, 64, 175));
    }

    ui->tableWidget->setItem(ligne, 6, statutItem);
    ui->tableWidget->setItem(ligne, 7, new QTableWidgetItem("✏️  🗑️  ️"));

    QMessageBox::information(this, "Succès", "Rendez-vous enregistré avec succès !");
}

// ═══════════════════════════════════════════════════════════════
// ⭐ GRAPHIQUE DONUT
// ═══════════════════════════════════════════════════════════════
void rdv::creerDonut()
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

    QLabel *lblTotal = new QLabel("Total\n100%");
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
        QHBoxLayout *ligneItem = new QHBoxLayout();
        ligneItem->setSpacing(8);

        QLabel *pastille = new QLabel();
        pastille->setFixedSize(12, 12);
        pastille->setStyleSheet(QString("background-color: %1; border-radius: 6px;").arg(couleurs[i].name()));

        QLabel *texteItem = new QLabel(QString("%1  <b>%2%</b>").arg(noms[i]).arg(valeurs[i]));
        texteItem->setStyleSheet("font-size: 12px; color: #475569;");

        ligneItem->addWidget(pastille);
        ligneItem->addWidget(texteItem);
        layoutLegende->addLayout(ligneItem);
    }

    QLabel *lblTitre = new QLabel("Répartition des rendez-vous");
    lblTitre->setStyleSheet("font-size: 14px; font-weight: bold; color: #1e293b; padding-bottom: 5px;");

    if (ui->widgetDonut->layout())
        delete ui->widgetDonut->layout();

    QVBoxLayout *mainLayout = new QVBoxLayout(ui->widgetDonut);
    mainLayout->setContentsMargins(15, 15, 15, 15);
    mainLayout->setSpacing(5);

    mainLayout->addWidget(lblTitre);

    QHBoxLayout *ligneContenu = new QHBoxLayout();
    ligneContenu->setContentsMargins(0, 0, 0, 0);
    ligneContenu->setSpacing(15);
    ligneContenu->addWidget(vue);
    ligneContenu->addWidget(widgetLegende);
    ligneContenu->addStretch();

    mainLayout->addLayout(ligneContenu);
}

// ═══════════════════════════════════════════════════════════════
// ⭐ GRAPHIQUE BARRES
// ═══════════════════════════════════════════════════════════════
void rdv::remplirPic(QFrame *cadre, const QString &titre,
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
        barre->setStyleSheet("QProgressBar { background: #e2e8f0; border-radius: 4px; border: none; } QProgressBar::chunk { background: #10b981; border-radius: 4px; }");
        grille->addWidget(barre, i + 1, 1);

        auto *pct = new QLabel(QString("%1%").arg(valeurs[i]));
        pct->setStyleSheet("font-size: 12px; color: #64748b; font-weight: 600;");
        pct->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
        pct->setFixedWidth(40);
        grille->addWidget(pct, i + 1, 2);
    }
}

void rdv::creerPic()
{
    remplirPic(ui->framePicJours, "📅 Jours les plus demandés",
               {"Lundi", "Mercredi", "Vendredi", "Mardi", "Jeudi"},
               {22, 20, 18, 16, 14});

    remplirPic(ui->framePicHeures, " Heures les plus demandées",
               {"09:00 - 11:00", "11:00 - 13:00", "14:00 - 16:00",
                "16:00 - 18:00", "Autres"},
               {32, 28, 24, 10, 6});
}

// ═══════════════════════════════════════════════════════════════
// ⭐ EXPORT PDF - GÉNÉRATION DU FICHIER
// ═══════════════════════════════════════════════════════════════
void rdv::on_btnExportPdf_clicked()
{
    QString cheminFichier = QFileDialog::getSaveFileName(
        this,
        "Exporter en PDF",
        QDir::homePath() + "/rendez-vous_" + QDate::currentDate().toString("dd-MM-yyyy") + ".pdf",
        "Fichiers PDF (*.pdf)"
        );

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
    int colonnesX[] = {300, 600, 900, 1200, 1500, 1800, 2100};
    QStringList enTetes = {"ID", "Date", "Heure", "Animal", "Propriétaire", "Vétérinaire", "Statut"};
    for (int i = 0; i < enTetes.size(); ++i) {
        painter.drawText(colonnesX[i], yPos, enTetes[i]);
    }
    yPos += 100;

    // Contenu du tableau
    painter.setFont(QFont("Segoe UI", 10, QFont::Normal));
    int nbLignes = ui->tableWidget->rowCount();
    int nbColonnes = qMin(7, ui->tableWidget->columnCount());

    for (int row = 0; row < nbLignes; ++row) {
        for (int col = 0; col < nbColonnes; ++col) {
            QTableWidgetItem *item = ui->tableWidget->item(row, col);
            if (item) {
                QString texte = item->text().remove(QRegularExpression("[^\\w\\s:/.-]"));
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

    QMessageBox::information(this, "Succès", "Le fichier PDF a été exporté avec succès !\n\n" + cheminFichier);
    QDesktopServices::openUrl(QUrl::fromLocalFile(cheminFichier));
}