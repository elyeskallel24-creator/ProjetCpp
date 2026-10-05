#ifndef GRAPHIQUES_H
#define GRAPHIQUES_H

#include <QWidget>
#include <QStringList>
#include <QList>
#include <QColor>

// Graphiques dessinés avec QPainter (aucun module supplémentaire à installer)

class GraphiqueCourbes : public QWidget
{
public:
    explicit GraphiqueCourbes(QWidget *parent = nullptr) : QWidget(parent) {}
    void setDonnees(const QStringList &etiquettes, const QStringList &noms,
                    const QList<QList<double>> &valeurs, const QList<QColor> &couleurs);
protected:
    void paintEvent(QPaintEvent *event) override;
private:
    QStringList m_etiquettes;
    QStringList m_noms;
    QList<QList<double>> m_valeurs;
    QList<QColor> m_couleurs;
};

class GraphiqueCamembert : public QWidget
{
public:
    explicit GraphiqueCamembert(QWidget *parent = nullptr) : QWidget(parent) {}
    void setDonnees(const QStringList &noms, const QList<double> &valeurs, const QList<QColor> &couleurs);
protected:
    void paintEvent(QPaintEvent *event) override;
private:
    QStringList m_noms;
    QList<double> m_valeurs;
    QList<QColor> m_couleurs;
};

class GraphiqueBarres : public QWidget
{
public:
    explicit GraphiqueBarres(QWidget *parent = nullptr) : QWidget(parent) {}
    void setDonnees(const QStringList &noms, const QList<double> &valeurs,
                    const QList<QColor> &couleurs, const QString &suffixe = QString());
protected:
    void paintEvent(QPaintEvent *event) override;
private:
    QStringList m_noms;
    QList<double> m_valeurs;
    QList<QColor> m_couleurs;
    QString m_suffixe;
};

#endif // GRAPHIQUES_H
