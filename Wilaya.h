#ifndef WILAYA_H
#define WILAYA_H

#include "City.h"

class Wilaya
{
public:
    // report on sales
    vector<int> getRestaurantsDistrict(string city, string district);
    vector<int> getRestaurantsAllDistricts(string city);

    vector<int> getRestaurantsAllCities();

    // add a restaurant
    void addRestaurant(string city, string district, int ID);

private:
    string wilaya;
    unordered_map<string, City> cities;
};

// report on sales
vector<int> Wilaya::getRestaurantsDistrict(string city, string district)
{
    return cities[city].getRestaurantsDistrict(district);
}

vector<int> Wilaya::getRestaurantsAllDistricts(string city)
{
    return cities[city].getRestaurantsAllDistricts();
}

vector<int> Wilaya::getRestaurantsAllCities()
{
    vector<int> Result;
    for (auto &city : cities)
    {
        vector<int> cityRestaurants = getRestaurantsAllDistricts(city.first);
        Result.insert(Result.end(), cityRestaurants.begin(), cityRestaurants.end());
    }
    return Result;
}

// add a restaurant
void Wilaya::addRestaurant(string city, string district, int ID)
{
    cities[city].addRestaurant(district, ID);
}

#endif