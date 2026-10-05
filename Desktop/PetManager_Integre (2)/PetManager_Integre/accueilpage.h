#ifndef ACCUEILPAGE_H
#define ACCUEILPAGE_H

#include <QWidget>
#include <QString>
#include <QStringList>

class QLabel;
class QFrame;
class QVBoxLayout;

// Chiffres affichés sur l'accueil (remplis par MainWindow à partir des 3 modules)
struct AccueilDonnees {
    // Animaux
    int animaux = 0;
    int chiens = 0;
    int chats = 0;
    int lapins = 0;
    int animauxSurveillance = 0;
    // Stock
    int produits = 0;
    int ruptures = 0;
    int stockBas = 0;
    int expires = 0;
    int commandesEnAttente = 0;
    // Fournisseurs
    int fournisseurs = 0;
    int fournisseursActifs = 0;
    // Liste "À surveiller"
    QStringList alertes;
};

class AccueilPage : public QWidget
{
    Q_OBJECT
public:
    enum Module { Animaux = 0, Stock = 1, Fournisseurs = 2, Parametres = 3 };

    explicit AccueilPage(QWidget *parent = nullptr);

    void setDonnees(const AccueilDonnees &d);
    void actualiserSalutation();      // relit le nom du responsable / du centre

signals:
    void naviguerVers(int module);    // clic sur un bouton "Accès rapide"

private:
    QFrame *creerKpi(const QString &icone, const QString &titre, QLabel *&valeur, QLabel *&detail);

    QLabel *m_salutation = nullptr;
    QLabel *m_valeur[4] = {nullptr, nullptr, nullptr, nullptr};
    QLabel *m_detail[4] = {nullptr, nullptr, nullptr, nullptr};
    QVBoxLayout *m_listeAlertes = nullptr;
    QLabel *m_resume = nullptr;
};

#endif // ACCUEILPAGE_H
