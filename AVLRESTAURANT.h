#ifndef AVLRESTAURANT_H
#define AVLRESTAURANT_H
#include <iostream>
#include "RESTAURANT.h"

class AVLRestaurantTree
{
private:
    static const int ALLOWED_IMBALANCE = 1;

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

        balance(ROOT);
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
        balance(ROOT);
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

    // utility function that counts a height of the AVL
    int height(Restaurant *temp)
    {
        if (temp == NULL)
            return -1;
        return 1 + max(height(temp->leftChild), height(temp->rightChild));
    }

    void rotateWithLeftChild(Restaurant *&k2)
    {
        Restaurant *k1 = k2->leftChild;
        k2->leftChild = k1->rightChild;
        k1->rightChild = k2;
        k2->heightNode = max(height(k2->leftChild), height(k2->rightChild)) + 1;
        k1->heightNode = max(height(k1->leftChild), k2->heightNode) + 1;
        k2 = k1;
    }

    void rotateWithRightChild(Restaurant *&k1)
    {
        Restaurant *k2 = k1->rightChild;
        k1->rightChild = k2->leftChild;
        k2->leftChild = k1;
        k1->heightNode = max(height(k1->leftChild), height(k1->rightChild)) + 1;
        k2->heightNode = max(k1->heightNode, height(k2->rightChild)) + 1;
        k1 = k2;
    }

    void doubleWithLeftChild(Restaurant *&k3)
    {
        rotateWithRightChild(k3->leftChild);
        rotateWithLeftChild(k3);
    }

    void doubleWithRightChild(Restaurant *&k1)
    {
        rotateWithLeftChild(k1->rightChild);
        rotateWithRightChild(k1);
    }

    void balance(Restaurant *&t)
    {
        if (t == nullptr)
            return;
        if (height(t->leftChild) - height(t->rightChild) > ALLOWED_IMBALANCE)
        {
            // left left subtree unballenced
            if (height(t->leftChild->leftChild) > height(t->leftChild->rightChild))
            {
                rotateWithLeftChild(t);
            }
            else
                doubleWithLeftChild(t);
        }
        // unbalenced from right
        else if (height(t->rightChild) - height(t->leftChild) > ALLOWED_IMBALANCE)
        {
            // right left subtree unbalenced
            if (height(t->rightChild->leftChild) > height(t->rightChild->rightChild))
            {
                doubleWithRightChild(t);
            }
            else
                rotateWithRightChild(t);
        }
        t->heightNode = max(height(t->leftChild), height(t->rightChild)) + 1;
    }

public:
    // default constructor
    AVLRestaurantTree() : root(nullptr)
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
    ~AVLRestaurantTree()
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
