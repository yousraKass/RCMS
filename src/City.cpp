#include "City.h"



vector<int> City::getRestaurantsDistrict(const string &district)
{
    return districts[district].getRestaurantsDistrict();
}

vector<int> City::getRestaurantsAllDistricts()
{
    vector<int> Result;
    for (const auto &district : districts)
    {
        const vector<int> &districtRestaurants = getRestaurantsDistrict(district.first);
        for(int i = 0; i<districtRestaurants.size(); i++){
            Result.push_back(move(districtRestaurants[i]));
        }
    }
    return Result;
}

void City::addRestaurant(const string &district, const int &ID)
{
    districts[district].addRestaurant(ID);
}