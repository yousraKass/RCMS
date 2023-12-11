#ifndef BSTRESTAURANT_H
#define BSTRESTAURANT_H
#include <iostream>
#include "RESTAURANT.h"
using namespace std;
class RestaurantTree
{
private:
    Restaurant *root;
    int totalRestaurants;
    //--> Insert x
    void insert(const Restaurant R, Restaurant *&ROOT);
    void insert(Restaurant &&R, Restaurant *&ROOT);
    
    Restaurant *contains(const int &key, Restaurant *&ROOT) const;
    // show data of all restaurants
    void printHelper(Restaurant *ROOT) const;
    // utility function to find a restaurant with an ID
    Restaurant *getRestauranthelper(const int &key, Restaurant *ROOT) const;
    void makeEmpty(Restaurant *&ROOT);


public:
    // default constructor
    RestaurantTree();
    bool IsEmpty() const;

    bool contains(const int &key);

    void insert(const Restaurant &R);
    int getTotalRestaurants() const;
    void printRestaurantsData() const;
    Restaurant *getRestaurant(const int &key) const;
    //--> Remove all restaurants
    void makeEmpty();
    ~RestaurantTree();

   // void reportOnsales(vector<int> restaurants, Date date);
   // void reportOnsales(int ID, Date start, Date end);
};
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
        //duplicates
    }

    Restaurant *RestaurantTree::contains(const int &key, Restaurant *&ROOT) const
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
    void RestaurantTree::printHelper(Restaurant *ROOT) const
    {
        if (ROOT != nullptr)
        {
            printHelper(ROOT->leftChild);
            ROOT->showRestaurantData();
            cout<<"--------------------------------------------"<<endl;
            cout<<"--------------------------------------------"<<endl;
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
            return contains(key, ROOT->leftChild);
        else
            return contains(key, ROOT->rightChild);
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


    // default constructor
    RestaurantTree::RestaurantTree() : root(nullptr)
    {
        totalRestaurants = 0;
    }
    bool RestaurantTree::IsEmpty() const
    {
        return (root == nullptr);
    }

    bool RestaurantTree::contains(const int &key)
    {
        return contains(key, root) != nullptr;
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

    /*void RestaurantTree::reportOnsales(vector<int> restaurants, Date date)
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
    void RestaurantTree::reportOnsales(int ID, Date start, Date end)
    {
        Restaurant *R = getRestaurant(ID);
        if (R != nullptr)
        {
            R->reportOnsales(start, end);
        }
    }*/
#endif
