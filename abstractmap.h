///////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
// Versuch 9
//////////////////////////////////////////////////////////////////////////////

#ifndef ABSTRACTMAP
#define ABSTRACTMAP

//  Aendern Sie an dieser Datei nichts!
//  Entfernen Sie lediglich den Kommentar vor den Funktionen,
//  nachdem Sie diese in der Klasse Map implementiert haben.
//  Die Schnittstellen (Signaturen) der Funktionen
//  werden genau so gebraucht.

// geaenderte Teile sind markiert

#include <QString>
#include <QVector>

class City;
class Street;

class AbstractMap
{
public:

    /// virtual Destructor (sodass der richtige Konstruktor aufgerufen werden kann)
    virtual ~AbstractMap();

    /**
     * @brief Adds the provided city to this map.
     * @param Pointer to city to be added
     * @return true if the street has beed added.
     */
    virtual bool addCity(City*) = 0;

    /**
     * @brief Adds the provided street to this map. If the cities linked by the street
     *  have not been added to this map before, the street is not added.
     * @param Pointer to the street to be added
     * @return true if the street has beed added.
     */
    virtual bool addStreet(Street*) = 0;

    /**
     * @brief Search for a city in this map by given name.
     * @param name
     * @return the city pointer, if city not found nullptr
     */
    virtual City* findCity(const QString cityName) const = 0;

    virtual Street* findStreet(const City* city1, const City* city2) const = 0;
    /**
     * @brief Search for streets in this map.
     * @param city where you want the street_list from
     * @return A list of all streets in this map connected to provided city.
     */
    virtual QVector<Street*> getStreetList(const City* city) const = 0;

    /**
     * @brief Look for opposite city.
     * @param street
     * @param city
     * @return Opposite city of the street. If city has no connection to street returns nullptr.
     */
    virtual City* getOppositeCity(const Street* street, const City* city) const = 0;

    /**
     * @brief Calculate the street length.
     * @param street
     * @return Length of the street
     */
    virtual double getLength(const Street* street) const = 0;
};

#endif // ABSTRACTMAP
