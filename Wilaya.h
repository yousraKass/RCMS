// class Wilaya contains a vector of all Cities in it
#ifndef WILAYA_H
#define WILAYA_H

#include "City.h"

class Wilaya
{
public:
    // get restaurants of the specified city and the specified district in the current wilaya
    vector<int> getRestaurantsDistrict(string city, string district);

    // get restaurants of all districts in the specified city in the current wilaya
    vector<int> getRestaurantsAllDistricts(string city);

    // get restaurants of all cities in the current wilaya
    vector<int> getRestaurantsAllCities();

    // add a restaurant in the specified city and district in the current wilaya
    void addRestaurant(string city, string district, int ID);

private:
    string wilaya;
    unordered_map<string, City> cities;
};

#endif