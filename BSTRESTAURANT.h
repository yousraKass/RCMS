#ifndef RESTAURANT_H
#define RESTAURANT_H
#include <iostream>
#include "RESTAURANT.h"

class RestaurantTree
{
private:

    Restaurant *root;
    int totalRestaurants;
    //--> Insert x
    void insert(const Restaurant R, Restaurant *&ROOT)
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
                insert(R, ROOT);
            else if (R.getId() > ROOT->getId())
                insert(R, ROOT);
        }

    }
    void insert(Restaurant &&R, Restaurant *&ROOT)
    {
        if (ROOT == nullptr)
        {
            Restaurant *newnode = new Restaurant(R);
            ROOT = newnode;
            totalRestaurants++;
        }
        else if (!contains(R.getId(), ROOT))
        {
            if (R < *ROOT)
                insert(R, ROOT);
            else if (R > *ROOT)
                insert(R, ROOT);
        }
    }

    Restaurant *contains(const int &key, Restaurant *&ROOT) const
    {

        if (ROOT == nullptr)
            return nullptr;
        else if (ROOT->getId() == key)
            return ROOT;
        else if (key < ROOT->getId())
            return contains(key, ROOT->leftChild);
        else
            return contains(key, ROOT->rightChild);
    }

    // show data of all restaurants
    void printHelper(Restaurant *ROOT) const
    {
        if (ROOT != nullptr)
        {
            printHelper(ROOT->leftChild);
            ROOT->showRestaurantData();
            printHelper(ROOT->rightChild);
        }
    }
    // utility function to find a restaurant with an ID
    Restaurant *getRestauranthelper(const int &key, Restaurant *ROOT) const
    {
        if (ROOT == nullptr)
            return nullptr;
        else if (ROOT->getId() == key)
            return ROOT;
        else if (key < root->getId())
            return contains(key, ROOT->leftChild);
        else
            return contains(key, ROOT->rightChild);
    }
    void makeEmpty(Restaurant *&ROOT)
    {
        if (!IsEmpty())
        {
            makeEmpty(ROOT->leftChild);
            makeEmpty(ROOT->rightChild);
            delete ROOT;
        }
        ROOT = nullptr;
    }

   

   


public:
    // default constructor
    RestaurantTree() : root(nullptr)
    {
        totalRestaurants = 0;
    }
    bool IsEmpty() const
    {
        return (root == nullptr);
    }

    bool contains(const int &key)
    {
        return contains(key, root) != nullptr;
    }

    void insert(const Restaurant &R)
    {

        insert(R, root);
    }
    int getTotalRestaurants() const
    {
        return totalRestaurants;
    }
    void printRestaurantsData() const
    {
        cout << "Total number of restaurants is: " << getTotalRestaurants << endl;
        printHelper(root);
    }
    Restaurant *getRestaurant(const int &key) const
    {

        return getRestauranthelper(key, root);
    }

    //--> Remove all restaurants
    void makeEmpty()
    {
        makeEmpty(root);
    }
    ~RestaurantTree()
    {
        makeEmpty();
    }

    void reportOnsales(vector<int> restaurants, Date date)
    {
        for (auto ID : restaurants)
        {
            Restaurant *R = getRestaurant(ID);
            if (R != nullptr)
            {
                R->reportOnsales(date.getMonth(), date.getYear());
            }
            // add exception in case restaurant not found
        }
    }
    void reportOnsales(int ID, Date start, Date end)
    {
        Restaurant *R = getRestaurant(ID);
        if (R != nullptr)
        {
            R->reportOnsales(start, end);
        }
    }
};
#endif
