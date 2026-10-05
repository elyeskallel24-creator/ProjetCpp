#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QResizeEvent>
#include "fournisseur.h"
#include <QList>
#include <QChartView>
#include <QChart>
#include <QBarSeries>
#include <QBarSet>
#include <QBarCategoryAxis>
#include <QValueAxis>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

protected:
    void resizeEvent(QResizeEvent *event) override;

private slots:
    void on_btn_enregistrer_clicked();
    void on_btn_modifier_clicked();
    void on_btn_annuler_clicked();
    void on_btn_supprimer_clicked(); // Added
    void on_lineEdit_recherche_textChanged(const QString &arg1);
    void on_comboBox_tri_currentIndexChanged(int index);
    void on_btn_export_pdf_clicked();
    void on_btn_export_excel_clicked();
    void on_comboBox_chart_currentIndexChanged(int index);
    void supprimerFournisseur(int id);
    void chargerFormulaire(int id, bool readOnly = false);

private:
    Ui::MainWindow *ui;
    void chargerTableau();
    void appliquerFiltreEtTri();
    void remplirTableau(const QList<Fournisseur> &liste);
    void viderFormulaire();
    void mettreAJourKPIs(const QList<Fournisseur> &liste);
    void mettreAJourGraphique(const QList<Fournisseur> &liste);
    void mettreAJourRecommandations(const QList<Fournisseur> &liste);

    enum FormMode { AddMode, EditMode, ViewMode };
    void setFormMode(FormMode mode);

    void showMessageBox(const QString &title, const QString &text, QMessageBox::Icon icon);
    bool showConfirmBox(const QString &text);
    bool validateForm(QString &errorMsg, QWidget *&focusWidget);

    QList<Fournisseur> m_fournisseurs;
    int m_currentId;
    QChartView *m_chartView = nullptr;
};
#endif // MAINWINDOW_H