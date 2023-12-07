#ifndef COUNTRY_H
#define COUNTRY_H

#include "Wilaya.h"

class Country
{
public:
    // report on sales
    vector<int> getRestaurantsDistrict(string wilaya, string city, string district);
    vector<int> getRestaurantsAllDistricts(string wilaya, string city);

    vector<int> getRestaurantsAllCities(string wilaya);

    vector<int> getRestaurantsAllWilayas();

    // add a restaurant
    void addRestaurant(string wilaya, string city, string district, int ID);

private:
    unordered_map<string, Wilaya> wilayas;
};

// report on sales
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
    for(auto & wilaya: wilayas){
        vector<int> wilayaRestaurants = getRestaurantsAllCities(wilaya.first);
        Result.insert(Result.end(), wilayaRestaurants.begin(), wilayaRestaurants.end());
    }
    return Result;
}

// add a restaurant
void Country::addRestaurant(string wilaya, string city, string district, int ID)
{
    wilayas[wilaya].addRestaurant(city, district, ID);
}

#endif