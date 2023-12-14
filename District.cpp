#include "District.h"

vector<int> District::getRestaurantsDistrict() const
{
    return restaurants;
}

// add a restaurant
void District::addRestaurant(const int &ID)
{
    restaurants.push_back(ID);
}

void District::addRestaurant(int &&ID)
{
    restaurants.push_back(move(ID));
}
