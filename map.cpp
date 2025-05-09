#include "map.h"
#include "city.h"
#include "street.h"
#include <cmath> //sqrt
#include <QMessageBox>

/**
 *  @brief Standartkonstruktor fuer die Klasse Map
 */
Map::Map() {}


/**
 *  @brief Destruktor fuer die Klasse Map
 */
Map::~Map() {}


/**
 * @brief Zeichnet alle Staedte und Strassen in der Karte
 *
 * Ruft die draw-Funktion für jede Stadt und jede Strasse auf.
 *
 * @param scene
 */
void Map::draw(QGraphicsScene& scene) const
{
    for (City* city : cities)
    {
        city->draw(scene);
    }

    for (Street* street: streets)
    {
        street->draw(scene);
    }
}


/**
 * @brief Fuegt eine Stadt zur Karte hinzu
 *
 * Ueberprueft zuerst, ob die angegebene Stadt im System schon existiert.
 *
 * @param city
 * @return true, wenn die Strasse hinzugefuegt werden kann, false, wenn nicht
 */
bool Map::addCity(City* city)
{
    QMessageBox msgBox;
    QString text;
    for (City* searchedCity: cities)
    {
        if (city->getName() == searchedCity->getName()) // diese Stadt existiert schon im System
        {
            text = "This city is already in the system.";
            qDebug() << text;
            msgBox.setText(text);
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.setDefaultButton(QMessageBox::Ok);
            msgBox.exec();
            return false;
        }
    }

    cities.push_back(city);
    qDebug() << "The city " << city->getName() << " has been added to the system.";
    return true;
}


/**
 * @brief Fuegt eine Strasse zur Karte hinzu und gibt eine Debug-Information aus
 *
 * Ueberprueft zuerst, ob die angegebene Stadt im System schon existiert und ob
 * die verbundene Staedte im System existieren.
 *
 * @param city
 * @return true, wenn die Strasse hinzugefuegt werden kann, false, wenn nicht
 */
bool Map::addStreet(Street* street)
{
    QMessageBox msgBox;
    QString text;
    bool same;
    bool opposite;
    for (Street* searchedStreet: streets)
    {
        same = street->getCity1() == searchedStreet->getCity1() && street->getCity2() == searchedStreet->getCity2();
        opposite = street->getCity1() == searchedStreet->getCity2() && street->getCity2() == searchedStreet->getCity1();
        if (same || opposite) // diese Strasse existiert schon im System
        {
            text = "This street is already in the system.";
            qDebug() << text;
            msgBox.setText(text);
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.setDefaultButton(QMessageBox::Ok);
            msgBox.exec();
            return false;
        }
    }
    bool city1Found = false;
    bool city2Found = false;

    // ueberprueft, ob die von der Strasse verbundene Staedte im System vorhanden sind
    for (City* city : cities)
    {
        if (city->getName() == street->getCity1()->getName()) city1Found = true;

        if (city->getName() == street->getCity2()->getName()) city2Found = true;
    }

    if (!(city1Found && city2Found))
    {
        text = "The cities that are connected by the street are not in the system.";
        qDebug() << text;
        msgBox.setText(text);
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.exec();
        return false;
    }

    streets.push_back(street);
    qDebug() << "The street " << street->getName() << " has been added to the system.";
    return true;
}



/**
 * @brief Sucht eine Stadt mit dem angegebenen Namen in der Karte
 * @param name Der Name der zu suchenden Stadt
 * @return Ein Zeiger auf die Stadt, falls die Stadt gefunden wird, sonst nullptr
 */
City* Map::findCity(const QString cityName) const
{
    for (City* city: cities)
    {
        if (city->getName() == cityName)
        {
            return city;
        }
    }
    qDebug() << "The city with the given name doesn't exist in the system.";
    return nullptr;
}


/**
 * @brief Sucht eine Strasse mit den angegebenen Staedten in der Karte
 * @param city1 eine Stadt
 * @param city2 eine weitere Stadt
 * @return Ein Zeiger auf die Strasse, falls die Strasse gefunden wird, sonst nullptr
 */
Street* Map::findStreet(const City* city1, const City* city2) const
{

    bool city1Found = false;
    bool city2Found = false;

    for (City* searchedCity: cities)
    {
        if (city1 == searchedCity) city1Found = true;
        if (city2 == searchedCity) city2Found = true;

    }

    if (!(city1Found && city2Found))
    {
        qDebug() << "The provided cities are not in the system.";
        return nullptr;
    }

    for (Street* street: streets)
    {
        if (street->getCity1() == city1 && street->getCity2() == city2)
        {
            return street;
        }

        if (street->getCity2() == city1 && street->getCity1() == city2)
        {
            return street;
        }
    }

    qDebug() << "The street with the given cities doesn't exist in the system";
    return nullptr;
}


/**
 * @brief Sucht nach der Strassen in der Karte, die mit der angegebenen Staedt verbunden sind.
 * @param city Die Stadt, von der die Strassenliste erhalten wird.
 * @return Ein Vektor aller mit der angegebenen Stadt verbundenen Strassen in der Karte.
 */
QVector<Street*> Map::getStreetList(const City* city) const
{
    QVector<Street*> connectedStreets;
    for (Street* street: streets)
    {
        if (street->getCity1() == city || street->getCity2() == city)
        {
            connectedStreets.push_back(street);
        }
    }
    return connectedStreets;
}

/**
 * @brief Sucht nach der gegenueberliegenden Stadt der angegebenen Strasse
 * @param street
 * @param city
 * @return Ein Zeiger auf die gegenueberliegende Stadt der Strasse.
 * Wenn es sie nicht gibt, nullptr
 */
City* Map::getOppositeCity(const Street* street, const City* city) const
{
    if (findCity(city->getName()) == nullptr)
    {
        qDebug() << "The provided city doesn't exist in the system.";
        return nullptr;
    }
    if (findStreet(street->getCity1(), street->getCity2()) == nullptr)
    {
        qDebug() << "The provided street doesn't exist in the system.";
        return nullptr;
    }

    if (street->getCity1() == city)
    {
        return street->getCity2();
    }
    if (street->getCity2() == city)
    {
        return street->getCity1();
    }

    qDebug() << "The provided street isn't connected to the provided city.";
    return nullptr;
}

/**
 * @brief Berechnet die Laenge der Strasse
 * @param street Die Straße, deren Laenge berechnet werden soll
 * @return Die Laenge der Strasse
 */
double Map::getLength(const Street* street) const
{
    double xDifference= abs(street->getCity1()->getX() - street->getCity2()->getX());
    double yDifference= abs(street->getCity1()->getY() - street->getCity2()->getY());
    double length = sqrt(xDifference*xDifference + yDifference*yDifference);
    return length;
}
