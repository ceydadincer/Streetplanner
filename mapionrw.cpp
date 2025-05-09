///////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
// Versuch 9
//////////////////////////////////////////////////////////////////////////////

#include "mapionrw.h"
#include "city.h"
#include "street.h"

MapIoNrw::MapIoNrw()
{
}

MapIoNrw::~MapIoNrw()
{
}

void MapIoNrw::fillMap(AbstractMap &map)
{
    City* aachen = new City("Aachen", -100, 100);
    City* bonn = new City("Bonn", 0,200);
    City* koeln = new City("Koeln", 0,0);
    City* duesseldorf = new City("Duesseldorf", 50,-100);

    Street* aachenKoeln = new Street("Aachen-Koeln Street", aachen, koeln);
    Street* bonnKoeln = new Street("Bonn-Koeln Street", bonn, koeln);
    Street* ddorfKoeln = new Street("Duesseldorf-Koeln Street", duesseldorf, koeln);

    map.addCity(aachen);
    map.addCity(bonn);
    map.addCity(koeln);
    map.addCity(duesseldorf);

    map.addStreet(aachenKoeln);
    map.addStreet(bonnKoeln);
    map.addStreet(ddorfKoeln);
}
