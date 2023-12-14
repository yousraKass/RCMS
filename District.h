// class district contains a vector of restaurants ID that are in the specified district
#ifndef DISTRICT_H
#define DISTRICT_H

#include <iostream>
using std::cout;
using std::endl;
using std::string;
using std::move;

#include <vector>
using std::vector;

class District
{
public:
    District() = default;
    ~District() = default;

    vector<int> getRestaurantsDistrict() const;

    // add a restaurant
    void addRestaurant(const int &ID);
    void addRestaurant(int &&ID);

private:
    vector<int> restaurants;
};

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

#endif