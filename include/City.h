// class City contains a vector of all the Districts that are in it
#ifndef CITY_H
#define CITY_H

#include <unordered_map>
using std::unordered_map;

#include "District.h"

class City
{
public:
    // get restaurants of the specified district in the current city
    vector<int> getRestaurantsDistrict(const string &district);
    
    // get restaurants from all districts in the current city
    vector<int> getRestaurantsAllDistricts();

    // add a restaurant in the spesified district in the current city
    void addRestaurant(const string &district, const int &ID);

private:
    string name;
    unordered_map<string, District> districts;
};



#endif