#include "mainwindow.h"
#include "databasemanager.h" // IMPORTANT : Inclus pour la base de données
#include <QApplication>
#include <QFile>
#include <QMessageBox>
#include <QStyleFactory>
#include <QPalette>
#include <QDir>
#include <QCoreApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    // 1. Initialiser la base de données AVANT de créer la fenêtre principale
    if (!DatabaseManager::instance().open()) {
        QMessageBox::critical(nullptr, "Erreur critique", "Impossible d'ouvrir la base de données. L'application va se fermer.");
        return 1;
    }

    // 2. Style Fusion pour uniformité entre Windows/Mac/Linux
    a.setStyle(QStyleFactory::create("Fusion"));

    // 3. Palette de base avec tes couleurs exactes
    QPalette palette;
    palette.setColor(QPalette::Window, QColor("#F4F8F8"));
    palette.setColor(QPalette::WindowText, QColor("#2D3436"));
    palette.setColor(QPalette::Base, QColor("#FFFFFF"));
    palette.setColor(QPalette::AlternateBase, QColor("#F4F8F8"));
    palette.setColor(QPalette::Text, QColor("#2D3436"));
    palette.setColor(QPalette::Button, QColor("#FFFFFF"));
    palette.setColor(QPalette::ButtonText, QColor("#2D3436"));
    palette.setColor(QPalette::Highlight, QColor("#2A8C82"));
    palette.setColor(QPalette::HighlightedText, QColor("#FFFFFF"));
    a.setPalette(palette);

    // 4. Charger la feuille de style personnalisée (theme.qss)
    QString themePath = QCoreApplication::applicationDirPath() + "/theme.qss";
    QFile themeFile(themePath);
    if (themeFile.open(QFile::ReadOnly | QFile::Text)) {
        a.setStyleSheet(themeFile.readAll());
        themeFile.close();
    } else {
        // Fallback : essayer dans le dossier courant (pour Qt Creator)
        themePath = QDir::currentPath() + "/theme.qss";
        themeFile.setFileName(themePath);
        if (themeFile.open(QFile::ReadOnly | QFile::Text)) {
            a.setStyleSheet(themeFile.readAll());
            themeFile.close();
        }
    }

    MainWindow w;
    w.show();
    return a.exec();
}