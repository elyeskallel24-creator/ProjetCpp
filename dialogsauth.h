#ifndef DIALOGSAUTH_H
#define DIALOGSAUTH_H

#include <QString>

class QWidget;

namespace DialogsAuth {

// Choix du compte, "envoi" d'un code de vérification (simulé), puis nouveau mot de passe
void motDePasseOublie(QWidget *parent);

// Demande l'ancien mot de passe, puis le nouveau (utilisateur déjà connecté)
void changerMotDePasse(QWidget *parent, const QString &utilisateur);

}

#endif // DIALOGSAUTH_H
