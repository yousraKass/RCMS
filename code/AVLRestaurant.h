#ifndef AVLRESTAURANT_H
#define AVLRESTAURANT_H
#include <iostream>
#include "Restaurant.h"
class PrizeWinners;

class AVLRestaurantTree
{
    friend class PrizeWinners;

private:
    static const int ALLOWED_IMBALANCE = 1;

    Restaurant *root;
    int totalRestaurants;

    // Insert x in two version lvalue , rvlaue
    void insert(const Restaurant R, Restaurant *&ROOT);
    void insert(Restaurant &&R, Restaurant *&ROOT);
    
    // return true if a restaurant with Id=key is found
    bool contains(const int &key, Restaurant *ROOT) const;

    // show data of all restaurants
    void printHelper(Restaurant *ROOT) const;

    // utility function to find a restaurant with specific ID and return a pointer to its location, else it will return nullptr
    Restaurant *getRestauranthelper(const int &key, Restaurant *ROOT) const;

    // remove all restaurants
    void makeEmpty(Restaurant *&ROOT);

    // utility function that counts a height of a node
    int height(Restaurant *temp);

    // left rotation
    void rotateWithLeftChild(Restaurant *&k2);

    // right rotation
    void rotateWithRightChild(Restaurant *&k1);

    // left right rotation
    void doubleWithLeftChild(Restaurant *&k3);

    // right left rotation
    void doubleWithRightChild(Restaurant *&k1);
    
    // balance the AVL tree
    void balance(Restaurant *&t);

public:
    // default constructor
    AVLRestaurantTree();
    // check wether a restaurant with Id=key excist in the AVL tree
    bool contains(const int &key);
    // insert a new restaurant
    void insert(const Restaurant &R);
    // get the totale number of restaurants
    int getTotalRestaurants() const;
    // show the data of all restaurants
    void printRestaurantsData() const;
    // return a pointer to the restaurant with the Id=key , otherwise return nullptr
    Restaurant *getRestaurant(const int &key) const;
    // Remove all restaurants
    void makeEmpty();
    // destructor
    // check wether the tree is empty
    bool IsEmpty() const;
    ~AVLRestaurantTree();
};


#endif