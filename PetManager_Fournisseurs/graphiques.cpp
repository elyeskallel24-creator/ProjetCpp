#include "graphiques.h"
#include <QPainter>
#include <QPainterPath>
#include <QFontMetrics>
#include <algorithm>
#include <cmath>

// Arrondit le maximum d'un axe à une valeur "ronde"
static double arrondirMax(double v)
{
    if (v <= 5) return 5;
    double pas = v <= 20 ? 5 : (v <= 100 ? 10 : std::pow(10.0, std::floor(std::log10(v))));
    return std::ceil(v / pas) * pas;
}

// Pas "lisible" pour un axe : 1, 2, 5, 10, 20, 50...
static double pasLisible(double brut)
{
    double base = 1;
    while (true) {
        for (double m : {1.0, 2.0, 5.0})
            if (m * base >= brut) return m * base;
        base *= 10;
    }
}

// ===================== Courbes =====================

void GraphiqueCourbes::setDonnees(const QStringList &etiquettes, const QStringList &noms,
                                  const QList<QList<double>> &valeurs, const QList<QColor> &couleurs)
{
    m_etiquettes = etiquettes;
    m_noms = noms;
    m_valeurs = valeurs;
    m_couleurs = couleurs;
    update();
}

void GraphiqueCourbes::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);
    QFont f = font();
    f.setPointSize(7);
    p.setFont(f);
    QFontMetrics fm(f);

    if (m_noms.isEmpty()) {
        p.setPen(QColor("#6B8080"));
        p.drawText(rect(), Qt::AlignCenter, "Aucune consommation sur la période");
        return;
    }

    double vmax = 0;
    for (const QList<double> &serie : m_valeurs)
        for (double v : serie) vmax = std::max(vmax, v);
    // 4 graduations entières : 0, pas, 2 x pas, 3 x pas, 4 x pas
    const double pas = pasLisible(std::max(1.0, vmax / 4.0));
    vmax = pas * 4;

    const double margeG = 26, margeD = 16, margeH = 8, margeB = 36;
    QRectF zone(margeG, margeH, width() - margeG - margeD, height() - margeH - margeB);
    const int n = m_etiquettes.size();
    auto xPour = [&](int i) { return zone.left() + (n > 1 ? i * zone.width() / (n - 1) : 0.0); };
    auto yPour = [&](double v) { return zone.bottom() - v / vmax * zone.height(); };

    // Grille et axe Y
    for (int k = 0; k <= 4; ++k) {
        double v = vmax * k / 4.0;
        double y = yPour(v);
        p.setPen(QPen(QColor("#E8EEEE"), 1));
        p.drawLine(QPointF(zone.left(), y), QPointF(zone.right(), y));
        p.setPen(QColor("#6B8080"));
        p.drawText(QRectF(0, y - 6, margeG - 4, 12), Qt::AlignRight | Qt::AlignVCenter,
                   QString::number(v, 'f', 0));
    }

    // Axe X (une étiquette sur "pas" si la période est longue)
    const int pasEtiquettes = std::max(1, (n + 6) / 7);
    for (int i = 0; i < n; i += pasEtiquettes)
        p.drawText(QRectF(xPour(i) - 18, zone.bottom() + 3, 36, 12), Qt::AlignCenter, m_etiquettes[i]);

    // Courbes
    for (int s = 0; s < m_valeurs.size(); ++s) {
        QPainterPath chemin;
        for (int i = 0; i < m_valeurs[s].size(); ++i) {
            QPointF pt(xPour(i), yPour(m_valeurs[s][i]));
            if (i == 0) chemin.moveTo(pt);
            else        chemin.lineTo(pt);
        }
        p.setPen(QPen(m_couleurs[s], 2));
        p.setBrush(Qt::NoBrush);
        p.drawPath(chemin);
        if (n <= 10) {
            p.setBrush(m_couleurs[s]);
            for (int i = 0; i < m_valeurs[s].size(); ++i)
                p.drawEllipse(QPointF(xPour(i), yPour(m_valeurs[s][i])), 2.5, 2.5);
        }
    }

    // Légende
    double x = 6;
    const double y = height() - 10;
    for (int s = 0; s < m_noms.size(); ++s) {
        QString nom = fm.elidedText(m_noms[s], Qt::ElideRight, 85);
        p.setPen(Qt::NoPen);
        p.setBrush(m_couleurs[s]);
        p.drawEllipse(QPointF(x + 4, y), 4, 4);
        p.setPen(QColor("#1E3A3A"));
        p.drawText(QPointF(x + 12, y + 3), nom);
        x += 12 + fm.horizontalAdvance(nom) + 12;
    }
}

// ===================== Camembert (anneau) =====================

void GraphiqueCamembert::setDonnees(const QStringList &noms, const QList<double> &valeurs,
                                    const QList<QColor> &couleurs)
{
    m_noms = noms;
    m_valeurs = valeurs;
    m_couleurs = couleurs;
    update();
}

void GraphiqueCamembert::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);
    QFont f = font();
    f.setPointSize(8);
    p.setFont(f);

    double total = 0;
    for (double v : m_valeurs) total += v;
    if (total <= 0) {
        p.setPen(QColor("#6B8080"));
        p.drawText(rect(), Qt::AlignCenter, "Aucune donnée");
        return;
    }

    const double d = std::min(height() - 10.0, width() * 0.5);
    QRectF cercle(8, (height() - d) / 2, d, d);

    int angle = 90 * 16;
    for (int i = 0; i < m_valeurs.size(); ++i) {
        int span = -qRound(m_valeurs[i] / total * 360.0 * 16);
        p.setPen(QPen(Qt::white, 2));
        p.setBrush(m_couleurs[i]);
        p.drawPie(cercle, angle, span);
        angle += span;
    }

    // Trou central + total
    const double r = d * 0.30;
    p.setPen(Qt::NoPen);
    p.setBrush(Qt::white);
    p.drawEllipse(cercle.center(), r, r);
    QFont fb = f;
    fb.setBold(true);
    p.setFont(fb);
    p.setPen(QColor("#17363A"));
    p.drawText(QRectF(cercle.center().x() - r, cercle.center().y() - r, 2 * r, 2 * r),
               Qt::AlignCenter, QString::number(total, 'f', 0) + "\nunités");

    // Légende
    p.setFont(f);
    double x = cercle.right() + 14;
    double y = height() / 2.0 - m_noms.size() * 36 / 2.0;
    for (int i = 0; i < m_noms.size(); ++i) {
        p.setPen(Qt::NoPen);
        p.setBrush(m_couleurs[i]);
        p.drawRoundedRect(QRectF(x, y + 3, 10, 10), 2, 2);
        p.setPen(QColor("#1E3A3A"));
        p.drawText(QPointF(x + 16, y + 12), m_noms[i]);
        p.setPen(QColor("#6B8080"));
        int pct = qRound(m_valeurs[i] / total * 100);
        p.drawText(QPointF(x + 16, y + 27), QString("%1 (%2 %)").arg(m_valeurs[i], 0, 'f', 0).arg(pct));
        y += 36;
    }
}

// ===================== Barres =====================

void GraphiqueBarres::setDonnees(const QStringList &noms, const QList<double> &valeurs,
                                 const QList<QColor> &couleurs, const QString &suffixe)
{
    m_noms = noms;
    m_valeurs = valeurs;
    m_couleurs = couleurs;
    m_suffixe = suffixe;
    update();
}

void GraphiqueBarres::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);
    QFont f = font();
    f.setPointSize(8);
    p.setFont(f);
    QFontMetrics fm(f);

    const int n = m_valeurs.size();
    if (n == 0) return;

    double vmax = 0;
    for (double v : m_valeurs) vmax = std::max(vmax, v);
    vmax = arrondirMax(vmax);

    QRectF zone(10, 20, width() - 20, height() - 44);
    const double emplacement = zone.width() / n;
    const double largeurBarre = std::min(emplacement * 0.55, 50.0);

    p.setPen(QPen(QColor("#E0E8E8"), 1));
    p.drawLine(QPointF(zone.left(), zone.bottom()), QPointF(zone.right(), zone.bottom()));

    for (int i = 0; i < n; ++i) {
        double cx = zone.left() + emplacement * (i + 0.5);
        double h = m_valeurs[i] / vmax * zone.height();
        QRectF barre(cx - largeurBarre / 2, zone.bottom() - h, largeurBarre, h);

        p.setPen(Qt::NoPen);
        p.setBrush(m_couleurs[i]);
        if (h > 0) p.drawRoundedRect(barre, 4, 4);

        // Valeur au-dessus
        p.setPen(QColor("#17363A"));
        QString texte = QString::number(m_valeurs[i], 'f', 0) + m_suffixe;
        p.drawText(QRectF(cx - emplacement / 2, barre.top() - 16, emplacement, 14), Qt::AlignCenter, texte);

        // Nom en dessous
        p.setPen(QColor("#1E3A3A"));
        QString nom = fm.elidedText(m_noms[i], Qt::ElideRight, int(emplacement) - 4);
        p.drawText(QRectF(cx - emplacement / 2, zone.bottom() + 4, emplacement, 16), Qt::AlignCenter, nom);
    }
}
