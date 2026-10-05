#ifndef RDV_H
#define RDV_H

#include <QMainWindow>
#include <QFrame>
#include <QStringList>
#include <QList>

QT_BEGIN_NAMESPACE
namespace Ui { class rdv; }
QT_END_NAMESPACE

class rdv : public QMainWindow
{
    Q_OBJECT

public:
    explicit rdv(QWidget *parent = nullptr);
    ~rdv() override;

private slots:
    void on_btnAjouter_clicked();
    void on_btnExportPdf_clicked();
    void chargerDonneesInitiales();

private:
    void creerDonut();
    void creerPic();
    void remplirPic(QFrame *cadre, const QString &titre,
                    const QStringList &noms, const QList<int> &valeurs);
    void creerBoutonExportPdf();

    Ui::rdv *ui;
};

#endif // RDV_H