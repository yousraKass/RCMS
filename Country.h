// class Country contains a vector of all Wilayas
#ifndef COUNTRY_H
#define COUNTRY_H

#include "Wilaya.h"

class Country
{
public:
    // get all restaurants in the specified district, city, wilaya
    vector<int> getRestaurantsDistrict(string wilaya, string city, string district);
    // get all restaurants of all districts in the specified city in the specified wilaya
    vector<int> getRestaurantsAllDistricts(string wilaya, string city);
    // get all the restaurants of the specified wilaya
    vector<int> getRestaurantsAllCities(string wilaya);
    // get all the restaurant of the country
    vector<int> getRestaurantsAllWilayas();

    // add a restaurant in the specified wilaya, city, country
    void addRestaurant(string wilaya, string city, string district, int ID);

private:
    unordered_map<string, Wilaya> wilayas;
};

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

#endif