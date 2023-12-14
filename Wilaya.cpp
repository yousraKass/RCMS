#include "Wilaya.h"

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