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

#endif