#ifndef DISTRICT_H
#define DISTRICT_H

#include <iostream>
using std::cout;
using std::endl;
using std::string;

#include <vector>
using std::vector;

class District
{
public:
    // constructor and destructor
    District();
    ~District();

    const vector<int> getRestaurantsDistrict() const;

    // add a restaurant
    void addRestaurant(const int &ID);
    void addRestaurant(int &&ID);

private:
    vector<int> restaurants;
};

District::District()
{
}
District::~District()
{
}

const vector<int> District::getRestaurantsDistrict() const
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
    restaurants.push_back(std::move(ID));
}

#endif

/*
big five
insert remove
*/