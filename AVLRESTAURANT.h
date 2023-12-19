#ifndef AVLRESTAURANT_H
#define AVLRESTAURANT_H
#include <iostream>
#include "RESTAURANT.h"
class Prize_Winners;

class AVLRestaurantTree
{
    friend class Prize_Winners;

private:
    static const int ALLOWED_IMBALANCE = 1;

    Restaurant *root;
    int totalRestaurants;
    // Insert x in two version lvalue , rvlaue
    void insert(const Restaurant R, Restaurant *&ROOT);
    void insert(Restaurant &&R, Restaurant *&ROOT);
    // return true if a restaurant with Id=key is found
    bool contains(const int &key, Restaurant *&ROOT) const;
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

// default constructor
AVLRestaurantTree::AVLRestaurantTree() : root(nullptr)
{
    totalRestaurants = 0;
}
void AVLRestaurantTree::insert(const Restaurant R, Restaurant *&ROOT)
{
    if (ROOT == nullptr)
    {
        Restaurant *newnode = new Restaurant(R);
        ROOT = newnode;
        totalRestaurants++;
    }

    else
    {
        if (R.getId() < ROOT->getId())
            insert(R, ROOT);
        else if (R.getId() > ROOT->getId())
            insert(R, ROOT);
    }
    balance(ROOT);
}
void AVLRestaurantTree::insert(Restaurant &&R, Restaurant *&ROOT)
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
    balance(ROOT);
}

bool AVLRestaurantTree::contains(const int &key, Restaurant *&ROOT) const
{

    if (ROOT == nullptr)
        return false;
    else if (ROOT->getId() == key)
        return true;
    else if (key < ROOT->getId())
        return contains(key, ROOT->leftChild);
    else
        return contains(key, ROOT->rightChild);
}

// show data of all restaurants
void AVLRestaurantTree::printHelper(Restaurant *ROOT) const
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
Restaurant *AVLRestaurantTree::getRestauranthelper(const int &key, Restaurant *ROOT) const
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
void AVLRestaurantTree::makeEmpty(Restaurant *&ROOT)
{
    if (ROOT != nullptr)
    {
        makeEmpty(ROOT->leftChild);
        makeEmpty(ROOT->rightChild);
        delete ROOT;
        ROOT = nullptr; // Set the pointer to null after deletion
    }
}

// utility function that counts a height of the AVL
int AVLRestaurantTree::height(Restaurant *temp)
{
    if (temp == NULL)
        return -1;
    return 1 + max(height(temp->leftChild), height(temp->rightChild));
}

void AVLRestaurantTree::rotateWithLeftChild(Restaurant *&k2)
{
    Restaurant *k1 = k2->leftChild;
    k2->leftChild = k1->rightChild;
    k1->rightChild = k2;
    k2->heightNode = max(height(k2->leftChild), height(k2->rightChild)) + 1;
    k1->heightNode = max(height(k1->leftChild), k2->heightNode) + 1;
    k2 = k1;
}

void AVLRestaurantTree::rotateWithRightChild(Restaurant *&k1)
{
    Restaurant *k2 = k1->rightChild;
    k1->rightChild = k2->leftChild;
    k2->leftChild = k1;
    k1->heightNode = max(height(k1->leftChild), height(k1->rightChild)) + 1;
    k2->heightNode = max(k1->heightNode, height(k2->rightChild)) + 1;
    k1 = k2;
}

void AVLRestaurantTree::doubleWithLeftChild(Restaurant *&k3)
{
    rotateWithRightChild(k3->leftChild);
    rotateWithLeftChild(k3);
}

void AVLRestaurantTree::doubleWithRightChild(Restaurant *&k1)
{
    rotateWithLeftChild(k1->rightChild);
    rotateWithRightChild(k1);
}

void AVLRestaurantTree::balance(Restaurant *&t)
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

bool AVLRestaurantTree::IsEmpty() const
{
    return (root == nullptr);
}

bool AVLRestaurantTree::contains(const int &key)
{
    return contains(key, root);
}

void AVLRestaurantTree::insert(const Restaurant &R)
{
    insert(R, root);
}
int AVLRestaurantTree::getTotalRestaurants() const
{
    return totalRestaurants;
}
void AVLRestaurantTree::printRestaurantsData() const
{
    cout << "Total number of restaurants is: " << getTotalRestaurants() << endl;
    printHelper(root);
}
Restaurant *AVLRestaurantTree::getRestaurant(const int &key) const
{

    return getRestauranthelper(key, root);
}

//--> Remove all restaurants
void AVLRestaurantTree::makeEmpty()
{
    makeEmpty(root);
}
AVLRestaurantTree::~AVLRestaurantTree()
{
    makeEmpty();
}

#endif