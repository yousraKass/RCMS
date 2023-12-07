#ifndef CITY_H
#define CITY_H

#include <unordered_map>
using std::unordered_map;

#include "District.h"

class City
{
public:
    // report on sales
    vector<int> getRestaurantsDistrict(string district);
    vector<int> getRestaurantsAllDistricts();

    // add a restaurant
    void addRestaurant(string district, int ID);

private:
    string name;
    unordered_map<string, District> districts;
};

vector<int> City::getRestaurantsDistrict(string district)
{
    return districts[district].getRestaurantsDistrict();
}

vector<int> City::getRestaurantsAllDistricts()
{
    vector<int> Result;
    for (const auto &district : districts)
    {
        const vector<int> &districtRestaurants = getRestaurantsDistrict(district.first);
        Result.insert(Result.end(), districtRestaurants.begin(), districtRestaurants.end());
    }
    return Result;
}


// add a restaurant
void City::addRestaurant(string district, int ID)
{
    districts[district].addRestaurant(ID);
}

#endif