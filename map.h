#ifndef MAP_H
#define MAP_H
#include <QVector>
#include <QGraphicsScene>
#include "abstractmap.h"

// Deklarationen der Klassen, die von der Klasse benutzt wird
class City;
class Street;

/**
 *  \brief Klasse fuer eine Karte
 *
 * Speichert einen Vektor von Zeigern der Staedte und einen Vektor von Zeigern der Strassen.
 * Bietet verschiedene Funktionalitaeten, die Verwaltung und Darstellung der Karte.
 */
class Map: public AbstractMap
{
private:
    QVector<City*> cities; ///< ein Vektor fuer die Zeiger der Staedte
    QVector<Street*> streets; ///< ein Vektor fuer die Zeiger der Strassen

public:
    Map();
    ~Map();

    void draw(QGraphicsScene& scene) const;
    bool addCity(City* city) override;
    bool addStreet(Street* street) override;
    virtual City* findCity(const QString cityName) const override;
    virtual Street* findStreet(const City* city1, const City* city2) const override;
    virtual QVector<Street*> getStreetList(const City* city) const override;
    virtual City* getOppositeCity(const Street* street, const City* city) const override;
    virtual double getLength(const Street* street) const override;
};

#endif // MAP_H
