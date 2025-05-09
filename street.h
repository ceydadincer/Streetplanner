
#ifndef STREET_H
#define STREET_H
#include <QGraphicsScene>

// Deklaration der Klasse, die von der Klasse benutzt wird
class City;

/**
 * \brief Klasse fuer eine Strasse
 *
 * Speichert den Namen und die von der Strasse verbundene Staedte.
 * Zeigt die Strasse auf der Karte.
 */
class Street
{
private:
    QString name; ///< der Name der Strasse
    City* city1; ///< einer der Staedte, die die Strasse verbindet
    City* city2; ///< die andere Staedt, die die Strasse verbindet

public:

    Street(QString name, City* city1, City* city2);
    ~Street();

    QString getName() const;
    City* getCity1() const;
    City* getCity2() const;
    void draw(QGraphicsScene& scene) const;
    void drawRed(QGraphicsScene& scene) const;
};

#endif // STREET_H
