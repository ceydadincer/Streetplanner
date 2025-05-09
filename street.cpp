#include "street.h"
#include "city.h"
#include <QGraphicsTextItem>
#include <QGraphicsScene>

/**
 * @brief Konstruktor für die Klasse Street
 *
 * Initialisiert eine Strasse mit dem angegebenen Namen und den beiden verbundenen Staedten.
 *
 * @param name
 * @param city1
 * @param city2
 */
Street::Street(QString name, City* city1, City* city2): name(name), city1(city1), city2(city2) {}

/**
 * @brief Destruktor für die Klasse Street
*/
Street::~Street() {}

/**
 * @brief Eine Getter-Funktion für den Namen
 *
 * @return QString Der Name der Strasse
 */
QString Street::getName() const
{
    return name;
}

/**
 * @brief Eine Getter-Funktion für die erste Stadt
 *
 * @return City* Ein Zeiger auf die erste Stadt
 */
City* Street::getCity1() const
{
    return city1;
}

/**
 * @brief Eine Getter-Funktion für die zweite Stadt
 *
 * @return City* Ein Zeiger auf die zweite Stadt
 */
City* Street::getCity2() const
{
    return city2;
}

/**
 * @brief Zeichnet die Strasse zwischen zwei Staedte in der Karte
 *
 * Positioniert eine schwarze Linie, die die Stadt repraesentiert, in der Karte.
 *
 * @param scene Die QGraphicsScene, in der die Stadt gezeichnet werden soll
 */
void Street::draw(QGraphicsScene& scene) const
{
    qDebug() << "The street between " << city1->getName() << ", " << city2->getName() << " is drawn on the map.";
    QPen pen;
    pen.setColor(Qt::black);
    pen.setWidth(2);
    /*
    // fuer die Darstellung des Names der Strasse
    QGraphicsTextItem* text = new QGraphicsTextItem;
    double mitteX = (city1->getX()+city2->getX())/2;
    double mitteY = (city1->getY()+city2->getX())/2;
    text->setPos(mitteX, mitteY);
    text->setPlainText(name);
    scene.addItem(text); */
    scene.addLine(city1->getX(), city1->getY(), city2->getX(), city2->getY(),pen);
}

/**
 * @brief Zeichnet die Strasse zwischen zwei Staedte in der Karte
 *
 * Positioniert eine rote breite Linie, die die Stadt repraesentiert, in der Karte.
 * Wird benutzt, um die durch das Dijkstra Algorithmus gefundene Strassen zu zeigen.
 *
 * @param scene Die QGraphicsScene, in der die Stadt gezeichnet werden soll
 */
void Street::drawRed(QGraphicsScene& scene) const
{
    QPen pen;
    pen.setColor(Qt::red);
    pen.setWidth(3);

    scene.addLine(city1->getX(), city1->getY(), city2->getX(), city2->getY(), pen);
}


