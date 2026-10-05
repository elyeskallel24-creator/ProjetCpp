#ifndef GPETMANAGER_H
#define GPETMANAGER_H

#include <QMainWindow>
#include <QDate>
#include <QDateTime>
#include <QStringList>
#include <QVector>
#include <QMap>
#include <QList>
#include <QSet>
#include <QPointer>
#include <QFrame>
#include <QIcon>
#include <functional>

class QLabel;
class QPushButton;
class QTimer;
class QTableWidget;
class GraphiqueCourbes;
class GraphiqueCamembert;

QT_BEGIN_NAMESPACE
namespace Ui { class GPetManager; }
QT_END_NAMESPACE

struct Produit {
    QString nom;
    QString categorie;
    QString espece;                  // "Chien", "Chat" ou "Toutes"
    QString usage;                   // "Nutrition", "Soin", "Vaccination", ...
    int quantite = 0;
    int seuil = 0;
    QDate dateExpiration;
    QString fournisseur;
    double prix = 0;
    QMap<QDate, int> consommation;   // quantité utilisée par jour
    QMap<QDate, int> demandeNonSatisfaite;  // demandée mais remplacée / non servie
};

// Alternative proposée pour un produit indisponible
struct Alternative {
    int index = -1;                  // indice du produit alternatif
    int score = 0;                   // compatibilité de 0 à 100 %
    QStringList raisons;             // critères qui expliquent le score
};

// Trace d'une substitution validée par l'utilisateur
struct Substitution {
    QDateTime date;
    QString produitDemande;
    QString alternative;
    int quantite = 0;
    int score = 0;
    QString motif;
};

struct Commande {
    int numero = 0;
    QString produit;                 // nom du produit commandé
    int quantite = 0;
    QString fournisseur;
    QDate dateCommande;
    QDate dateLivraison;             // prévue (ou réelle une fois reçue)
    double montant = 0;
    QString statut;                  // "En attente", "Reçue", "Annulée"
};

// Résultat de l'analyse prédictive d'un produit
struct Analyse {
    double consoMoyenne = 0;         // unités par jour (30 derniers jours)
    double joursRestants = -1;       // -1 = inconnu (aucune consommation)
    QDate dateRupture;               // date prévue où le stock sera inutilisable
    int priorite = 0;                // 0 aucune, 1 préventive, 2 urgente, 3 critique
    int qteConseillee = 0;
    bool commandeEnCours = false;
};

class GPetManager : public QMainWindow
{
    Q_OBJECT

public:
    explicit GPetManager(QWidget *parent = nullptr);
    ~GPetManager();

protected:
    // Clic sur une carte "alternative" du panneau
    bool eventFilter(QObject *objet, QEvent *evenement) override;

private slots:
    void changerPage(int index);
    void rafraichir();
    void enregistrerProduit();
    void modifierProduit();
    void supprimerProduit();
    void annulerEdition();
    void exporterExcel();
    void exporterCommandesExcel();
    void afficherNotifications();
    void commanderSelection();
    void toutSelectionner();

private:
    enum Etat { OK = 0, StockBas = 1, Rupture = 2, Expire = 3 };
    enum Priorite { Aucune = 0, Preventive = 1, Urgente = 2, Critique = 3 };

    Ui::GPetManager *ui;
    QVector<Produit> produits;
    QVector<Commande> commandes;
    QVector<Substitution> substitutions;
    int indexRefAlternatives = -1;
    int prochainNumero = 1001;
    int indexEnEdition = -1;
    QVector<int> indexAlternatives;
    QList<QPushButton*> boutonsNav;
    QLabel *badgeNotif = nullptr;
    QPointer<QFrame> toast;
    QTimer *timerToast = nullptr;

    GraphiqueCourbes   *graphConso = nullptr;
    GraphiqueCamembert *graphCategories = nullptr;

    // Configuration
    void configurerNavigation();
    void configurerTableau();
    void configurerFormulaire();
    void configurerReappro();
    void configurerGraphiques();
    void chargerDonneesExemple();

    // Affichage page Stock
    void afficherTableau();
    void mettreAJourCartes();
    void mettreAJourAlertes();
    void mettreAJourAlternatives();
    void mettreAJourGraphiqueConso();
    void mettreAJourStatistiques();

    // Affichage page Réapprovisionnement
    void afficherSuggestions();
    void afficherCommandes();
    void afficherSubstitutions();

    // Formulaire / CRUD
    void chargerDansFormulaire(int index);
    void viderFormulaire();
    void mettreAJourModeFormulaire();
    bool lireFormulaire(Produit &p, bool nouveau);
    void sortieDeStock(int index);

    // Métier : substitution par un produit alternatif
    QVector<Alternative> chercherAlternatives(int indexProduit, int besoin) const;
    void ouvrirSubstitution(int indexProduit, int quantiteDemandee, int alternativePreselectionnee = -1);

    // Métier : réapprovisionnement intelligent
    Etat etatProduit(const Produit &p) const;
    QString libelleEtat(Etat e) const;
    Analyse analyserProduit(int index) const;
    QString libellePriorite(int priorite) const;
    QString couleurPriorite(int priorite) const;
    QString textePrevision(const Analyse &a) const;
    QVector<int> indicesAReapprovisionner(bool inclureCommandes = false) const;
    QSet<QString> nomsEnAlerte() const;
    void signalerNouvellesAlertes(const QSet<QString> &avant);
    bool commandeEnAttente(const QString &nomProduit) const;
    int indiceProduit(const QString &nom) const;
    bool creerCommande(int indexProduit, int quantite, bool silencieux = false);
    void receptionnerCommande(int indexCommande);
    void annulerCommande(int indexCommande);

    // Notification "toast" en bas à droite
    void afficherToast(const QString &nomIcone, const QString &titre, const QString &message,
                       const QString &couleur, const QString &texteBouton = QString(),
                       std::function<void()> action = nullptr);

    // Outils d'affichage
    QWidget* creerBadge(const QString &texte, const QString &fond, const QString &couleur);
    QWidget* creerActions(int index);
    QIcon iconeCategorie(const QString &categorie) const;
    static QIcon icone(const QString &nom);
    void ajusterHauteurTableau(QTableWidget *t, int lignes);
};

#endif // GPETMANAGER_H
