#ifndef CITY_H
#define CITY_H
#include <QMainWindow>
#include <QGraphicsView> // QGraphicsScene
#include <QRegularExpression>

/**
 * \brief Klasse fuer eine Stadt
 *
 * Speichert den Namen, die x-Koordinate und die y-Koordinate einer Stadt.
 * Zeigt die Stadt auf der Karte.
 */
class City
{
private:

    QString name; ///< der Name der Stadt
    int x; ///< die x-Koordinate der Stadt
    int y; ///< die y-Koordinate der Stadt
public:

    City(QString name, int x, int y);
    ~City();

    QString getName() const;
    int getX() const;
    int getY() const;
    void draw(QGraphicsScene& scene) const;
};

#endif // CITY_H
