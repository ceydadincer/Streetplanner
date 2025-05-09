#include "city.h"
#include <QGraphicsTextItem>

/**
 * @brief Konstruktor für die Klasse City
 *
 * Initialisiert eine Stadt mit dem angegebenen Namen und Koordinaten.
 *
 * @param name
 * @param x
 * @param y
 */
City::City(QString name, int x, int y): name(name), x(x), y(y) {}

/**
 * @brief Destruktor für die Klasse City
*/
City::~City() {}


/**
 * @brief Eine Getter-Funktion für den Namen
 *
 * @return QString Der Name der Stadt
 */
QString City::getName() const
{
    return name;
}

/**
 * @brief Eine Getter-Funktion für die x-Koordinate
 *
 * @return int Die x-Koordinate der Stadt
 */
int City::getX() const
{
    return x;
}

/**
 * @brief Eine Getter-Funktion für die y-Koordinate
 *
 * @return int Die y-Koordinate der Stadt
 */
int City::getY() const
{
    return y;
}

/**
 * @brief Zeichnet die Stadt in der Karte
 *
 * Positioniert den Namen der Stadt und einen roten Punkt, der die Stadt repraesentiert,
 * in der Karte.
 *
 * @param scene Die QGraphicsScene, in der die Stadt gezeichnet werden soll
 */
void City::draw(QGraphicsScene& scene) const
{
    qDebug() << "The city " << getName() << " is drawn at the position (" << x << ", " << y << ") on the map";

    // fuegt einen roten Kreis mit einem Durchmesser von 4 Pixels zur Karte
    // an der Position (x-2, y-2) hinzu, also einen Punkt
    scene.addEllipse(x - 2, y - 2, 4, 4, QPen(Qt::red), QBrush(Qt::red, Qt::SolidPattern));

    // fuer den Namen der Stadt
    QGraphicsTextItem* text = new QGraphicsTextItem;

    // Positionierung des Names
    text->setPos(x, y);

    // setzt den Text auf den Namen
    text->setPlainText(name);

    // fuegt den Namen zur Karte hinzu
    scene.addItem(text);

}



