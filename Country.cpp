#include "Country.h"

vector<int> Country::getRestaurantsDistrict(string wilaya, string city, string district)
{
    return wilayas[wilaya].getRestaurantsDistrict(city, district);
}

vector<int> Country::getRestaurantsAllDistricts(string wilaya, string city)
{
    return wilayas[wilaya].getRestaurantsAllDistricts(city);
}

vector<int> Country::getRestaurantsAllCities(string wilaya)
{
    return wilayas[wilaya].getRestaurantsAllCities();
}

vector<int> Country::getRestaurantsAllWilayas()
{
    vector<int> Result;
    for (auto &wilaya : wilayas)
    {
        vector<int> wilayaRestaurants = getRestaurantsAllCities(wilaya.first);
        for (int i = 0; i<wilayaRestaurants.size(); i++)
            Result.push_back(move(wilayaRestaurants[i]));
    }
    return Result;
}

void Country::addRestaurant(string wilaya, string city, string district, int ID)
{
    wilayas[wilaya].addRestaurant(city, district, ID);
}