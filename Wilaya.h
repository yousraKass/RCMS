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
        for(int i = 0; i< cityRestaurants.size(); i++)
            Result.push_back(move(cityRestaurants[i]));
    }
    return Result;
}

void Wilaya::addRestaurant(string city, string district, int ID)
{
    cities[city].addRestaurant(district, ID);
}

#endif