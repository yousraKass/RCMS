#ifndef BSTRESTAURANT_H
#define BSTRESTAURANT_H
#include <iostream>
#include "RESTAURANT.h"
using namespace std;
class Prize_Winners;

class RestaurantTree
{
    friend class Prize_Winners;

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
    RestaurantTree();
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
    ~RestaurantTree();
};

// default constructor
RestaurantTree::RestaurantTree() : root(nullptr)
{
    totalRestaurants = 0;
}
void RestaurantTree::insert(const Restaurant R, Restaurant *&ROOT)
{
    if (ROOT == nullptr)
    {
        Restaurant *newnode = new Restaurant(R);
        ROOT = newnode;
        totalRestaurants++;
    }
    else if (!contains(R.getId(), ROOT))
    {
        if (R.getId() < ROOT->getId())
            insert(R, ROOT->leftChild);
        else if (R.getId() > ROOT->getId())
            insert(R, ROOT->rightChild);
    }
}
void RestaurantTree::insert(Restaurant &&R, Restaurant *&ROOT)
{
    if (ROOT == nullptr)
    {
        Restaurant *newnode = new Restaurant(R);
        ROOT = newnode;
        totalRestaurants++;
    }
    else if (!contains(R.getId(), ROOT))
    {
        if (R.getId() < ROOT->getId())
            insert(R, ROOT->leftChild);
        else if (R.getId() > ROOT->getId())
            insert(R, ROOT->rightChild);
    }
    // duplicates
}

bool RestaurantTree::contains(const int &key, Restaurant *ROOT) const
{

    if (ROOT == nullptr)
        return false;
    else if (ROOT->getId() == key)
        return true;
    else if (key < ROOT->getId())
        return contains(key, ROOT->leftChild);
    else if (key > ROOT->getId())
        return contains(key, ROOT->rightChild);
    else
        return ROOT;
}

// show data of all restaurants
void RestaurantTree::printHelper(Restaurant *ROOT) const
{
    if (ROOT != nullptr)
    {
        printHelper(ROOT->leftChild);
        ROOT->showRestaurantData();
        cout << "--------------------------------------------" << endl;
        cout << "--------------------------------------------" << endl;
        printHelper(ROOT->rightChild);
    }
}
// utility function to find a restaurant with an ID
Restaurant *RestaurantTree::getRestauranthelper(const int &key, Restaurant *ROOT) const
{
    if (ROOT == nullptr)
        return nullptr;
    else if (ROOT->getId() == key)
        return ROOT;
    else if (key < ROOT->getId())
        return getRestauranthelper(key, ROOT->leftChild);
    else
        return getRestauranthelper(key, ROOT->rightChild);
}
void RestaurantTree::makeEmpty(Restaurant *&ROOT)
{
    if (ROOT != nullptr)
    {

        makeEmpty(ROOT->leftChild);
        makeEmpty(ROOT->rightChild);
        delete ROOT;
        ROOT = nullptr;
    }
}

bool RestaurantTree::IsEmpty() const
{
    return (root == nullptr);
}

bool RestaurantTree::contains(const int &key)
{
    return contains(key, root);
}

void RestaurantTree::insert(const Restaurant &R)
{

    insert(R, root);
}
int RestaurantTree::getTotalRestaurants() const
{
    return totalRestaurants;
}
void RestaurantTree::printRestaurantsData() const
{
    cout << "Total number of restaurants is: " << getTotalRestaurants() << endl;
    printHelper(root);
}
Restaurant *RestaurantTree::getRestaurant(const int &key) const
{
    return getRestauranthelper(key, root);
}

//--> Remove all restaurants
void RestaurantTree::makeEmpty()
{
    makeEmpty(root);
}
RestaurantTree::~RestaurantTree()
{
    makeEmpty();
}
 

#endif
