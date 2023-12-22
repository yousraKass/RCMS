#ifndef BSTRESTAURANT_H
#define BSTRESTAURANT_H

#include "Restaurant.h"

#include <iostream>
using namespace std;

class PrizeWinners;

class BSTRestaurantTree
{
    friend class PrizeWinners;

private:
    Restaurant *root;
    int totalRestaurants;

    //************Utility functions************
    // Insert x with two version
    void insert(const Restaurant R, Restaurant *&ROOT);
    void insert(Restaurant &&R, Restaurant *&ROOT);

    // search for x return true if found, else false
    bool contains(const int &key, Restaurant *ROOT) const;

    // show data of all restaurants
    void printHelper(Restaurant *ROOT) const;

    // utility function to find a restaurant with an ID, returns a pointer to the restaurant if found , else return nullptr
    Restaurant *getRestauranthelper(const int &key, Restaurant *ROOT) const;

    // destroy the the BST
    void makeEmpty(Restaurant *&ROOT);

public:
    // default constructor
    BSTRestaurantTree();

    // return true if empty,false otherwise
    bool IsEmpty() const;

    // return true if restaurant with Id =key is found
    bool contains(const int &key);

    // insert restaurant
    void insert(const Restaurant &R);

    // return the total number of restaurants
    int getTotalRestaurants() const;

    // show data of all restaurant in the BST
    void printRestaurantsData() const;

    // return a pointer to the restaurant with Id=key
    Restaurant *getRestaurant(const int &key) const;

    // Remove all restaurants start with left tree, right tree then the root
    void makeEmpty();
    
    // destructor that will call makeEmpty
    ~BSTRestaurantTree();
};


#endif
