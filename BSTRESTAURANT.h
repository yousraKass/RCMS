#ifndef BSTRESTAURANT_H
#define BSTRESTAURANT_H
#include <iostream>
#include "RESTAURANT.h"

class RestaurantTree
{
private:
    Restaurant *root;
    int totalRestaurants;
    //--> Insert x
    void insert(const restaurant R, restaurant *&root)
    {
        if (root == nullptr)
        {
            Restaurant *newnode = new Restaurant(R);
            root = newnode;
            totalRestaurants++;
        }
        else if (!contains(R))
        {
            if (x < *root)
                insert(R, root);
            else if (R > *root)
                insert(R, root);
        }

        else
        {
            return;
        } // do nothing duplicate
    }
    void insert(restaurant &&R, restaurant *&root)
    {
        if (root == nullptr)
        {
            Restaurant *newnode = new Restaurant(R);
            root = newnode;
            totalRestaurants++;
        }
        else if (!contains(R))
        {
            if (x < *root)
                insert(R, root);
            else if (R > *root)
                insert(R, root);
        }

        else
        {
            return;
        } // do nothing duplicate
    }

    bool contains(const int &key, restaurant *&ROOT) const
    {

        if (ROOT == nullptr)
            return false;
        else if (ROOT->getId() == key)
            return true;
        else if (key < root->getId())
            return contains(key, ROOT->leftChild);
        else
            return contains(key, ROOT->rightChild)
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
            return contains(key, ROOT->rightChild)
    }
    void makeEmpty(Restaurant *&ROOT) if (!isEmpty())
    {
        makeEmpty(ROOT->leftChild);
        makeEmpty(ROOT->rightChild);
        delete root;
    }
    root = nullptr;

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
        return contains(root, key);
    }

    void insert(const Restaurant &R)
    {

        insertHelper(root, R);
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
    void makeEmpty() const
    {
        makeEmpty(root);
    }
    ~RestaurantTree()
    {
        makeEmpty();
    }
    void ReportOnsales(vector<int> restaurants, Date date)
    {
        for (auto ID : restaurants)
        {
            Restaurant *R = getRestaurant(ID);
            if (R != nullptr){
                            R->reposrtOnsales(date.getMonth(), date.getYear());

            }
            //add exception in case restaurant not found

        }
    }
    void ReportOnsales(int ID, Date start, Date end)
    {
        Restaurant *R = getRestaurant(ID);
        if (R != nullptr)
        {
            R->ReportOnsales(start, end);
        }
    }
};
#endif