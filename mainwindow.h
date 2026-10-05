#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QString>

class QLabel;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void afficherFrequence();   // clic sur le bouton Fréquence
    void afficherPrevision();   // clic sur le bouton Prévision

private:
    void configurerLogo();      // met le logo dans label_logo
    void chargerGraphique(QLabel *label, const QString &chemin); // image dans un cadre
    void configurerTableau();   // largeurs, badge de statut, boutons U / D

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
