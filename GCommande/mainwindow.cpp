#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QCoreApplication>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QLabel>
#include <QPixmap>
#include <QPushButton>
#include <QTableWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);   // les couleurs sont dans le styleSheet de mainwindow.ui

    configurerLogo();
    configurerTableau();
    afficherFrequence();   // graphiques affichés dès l'ouverture
    afficherPrevision();

    // Boutons Fréquence / Prévision
    connect(ui->btnFrequence, &QPushButton::clicked, this, &MainWindow::afficherFrequence);
    connect(ui->btnPrevision, &QPushButton::clicked, this, &MainWindow::afficherPrevision);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::configurerLogo()
{
    QPixmap logo(":/images/logo.png");                       // via resources.qrc
    if (logo.isNull())
        logo.load(QCoreApplication::applicationDirPath() + "/images/logo.png");
    if (logo.isNull())
        logo.load("images/logo.png");
    if (logo.isNull()) {
        qWarning("Logo introuvable : ajouter resources.qrc au projet");
        return;
    }

    ui->label_logo->setText(QString());
    ui->label_logo->setAlignment(Qt::AlignCenter);
    ui->label_logo->setPixmap(logo.scaled(ui->label_logo->size(),
                                          Qt::KeepAspectRatio,
                                          Qt::SmoothTransformation));
}

void MainWindow::configurerTableau()
{
    QTableWidget *t = ui->tableWidget;

    t->setColumnWidth(0, 45);
    t->setColumnWidth(1, 95);
    t->setColumnWidth(2, 95);
    t->setColumnWidth(3, 90);
    t->setRowHeight(0, 40);

    // Badge de statut (colonne 3)
    QLabel *badge = new QLabel(QString::fromUtf8("Commandée"));
    badge->setObjectName("badgeCommandee");
    badge->setAlignment(Qt::AlignCenter);
    QWidget *celluleStatut = new QWidget;
    celluleStatut->setObjectName("cellContainer");
    QHBoxLayout *l1 = new QHBoxLayout(celluleStatut);
    l1->setContentsMargins(4, 9, 4, 9);
    l1->addWidget(badge);
    t->setCellWidget(0, 3, celluleStatut);

    // Boutons Modifier (U) / Supprimer (D) (colonne 4)
    QPushButton *btnU = new QPushButton("U");
    btnU->setObjectName("btnModifier");
    QPushButton *btnD = new QPushButton("D");
    btnD->setObjectName("btnSupprimer");
    QWidget *celluleActions = new QWidget;
    celluleActions->setObjectName("cellContainer");
    QHBoxLayout *l2 = new QHBoxLayout(celluleActions);
    l2->setContentsMargins(4, 0, 4, 0);
    l2->setSpacing(6);
    l2->addWidget(btnU);
    l2->addWidget(btnD);
    t->setCellWidget(0, 4, celluleActions);
}

void MainWindow::chargerGraphique(QLabel *label, const QString &chemin)
{
    QPixmap img(chemin);
    if (img.isNull()) {
        qWarning("Graphique introuvable : verifier resources.qrc");
        return;
    }
    label->setText(QString());
    label->setAlignment(Qt::AlignCenter);
    label->setPixmap(img.scaled(label->size(), Qt::KeepAspectRatio,
                                Qt::SmoothTransformation));
}

void MainWindow::afficherFrequence()
{
    // TODO : remplacer l'image par un vrai graphique calcule a partir des commandes
    chargerGraphique(ui->label_graph_freq, ":/images/graph_frequence.png");
}

void MainWindow::afficherPrevision()
{
    // TODO : remplacer l'image par un vrai graphique calcule a partir de l'historique
    chargerGraphique(ui->label_graph_prev, ":/images/graph_prevision.png");
}
