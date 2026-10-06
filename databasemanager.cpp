#include "databasemanager.h"
#include <QStandardPaths>
#include <QDir>
#include <QDebug>

DatabaseManager& DatabaseManager::instance() {
    static DatabaseManager inst;
    return inst;
}

DatabaseManager::DatabaseManager() {
    m_db = QSqlDatabase::addDatabase("QSQLITE");

    // Use current directory for simplicity and reliability
    QString dbPath = QDir::currentPath() + "/employes.db";
    m_db.setDatabaseName(dbPath);

    qDebug() << "Database path:" << dbPath;
}

DatabaseManager::~DatabaseManager() {
    close();
}

bool DatabaseManager::open() {
    if (m_db.isOpen()) return true;

    bool ok = m_db.open();
    if (!ok) {
        qDebug() << "Database open error:" << m_db.lastError().text();
        qDebug() << "Database path:" << m_db.databaseName();
        return false;
    }

    qDebug() << "Database opened successfully";
    createTables();
    return true;
}

void DatabaseManager::close() {
    if (m_db.isOpen()) {
        m_db.close();
        qDebug() << "Database closed";
    }
}

QSqlDatabase DatabaseManager::getDatabase() {
    return m_db;
}

bool DatabaseManager::createTables() {
    QSqlQuery query(m_db);

    // Drop old table if exists to remove UNIQUE constraint
    query.exec("DROP TABLE IF EXISTS employe");

    QString sql = R"(
        CREATE TABLE employe (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            nom TEXT NOT NULL,
            prenom TEXT NOT NULL,
            email TEXT,
            telephone TEXT,
            poste TEXT NOT NULL,
            salaire REAL DEFAULT 0,
            dateEmbauche TEXT NOT NULL,
            statut TEXT DEFAULT 'Actif'
        )
    )";

    if (!query.exec(sql)) {
        qDebug() << "Table creation error:" << query.lastError().text();
        return false;
    }

    qDebug() << "Table 'employe' created successfully";
    return true;
}