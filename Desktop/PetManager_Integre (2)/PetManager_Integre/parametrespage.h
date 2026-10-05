#ifndef PARAMETRESPAGE_H
#define PARAMETRESPAGE_H

#include <QWidget>
#include <QString>

class QFrame;
class QLineEdit;
class QComboBox;
class QCheckBox;
class QVBoxLayout;

// Page "Paramètres" : réglages enregistrés avec QSettings (organisation "PetManager")
class ParametresPage : public QWidget
{
    Q_OBJECT
public:
    explicit ParametresPage(QWidget *parent = nullptr);

    // Lecture des réglages (utilisable depuis n'importe quel module)
    static QString responsable();
    static QString nomCentre();
    static QString pageDemarrage();      // "Accueil", "Animaux", "Stock" ou "Fournisseurs"
    static bool alerteSanteAnimaux();

signals:
    void reglagesEnregistres();

private slots:
    void enregistrer();
    void reinitialiser();
    void ouvrirDossierBase();

private:
    void chargerDansFormulaire();
    QFrame *creerCarte(const QString &titre, QVBoxLayout *&contenu);

    QLineEdit *m_responsable = nullptr;
    QLineEdit *m_centre = nullptr;
    QComboBox *m_demarrage = nullptr;
    QCheckBox *m_alerteSante = nullptr;
};

#endif // PARAMETRESPAGE_H
