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
    void insert(const Restaurant R, Restaurant *&ROOT);
    void insert(Restaurant &&R, Restaurant *&ROOT);

    Restaurant *contains(const int &key, Restaurant *&ROOT) const;
    // show data of all restaurants
    void printHelper(Restaurant *ROOT) const;
    // utility function to find a restaurant with an ID
    Restaurant *getRestauranthelper(const int &key, Restaurant *ROOT) const;
    void makeEmpty(Restaurant *&ROOT);

    // utility function that counts a height of the AVL
    int height(Restaurant *temp);
    void rotateWithLeftChild(Restaurant *&k2);
    void rotateWithRightChild(Restaurant *&k1);
    void doubleWithLeftChild(Restaurant *&k3);

    void doubleWithRightChild(Restaurant *&k1);

    void balance(Restaurant *&t);

public:
    // default constructor
    AVLRestaurantTree();

    bool IsEmpty() const;

    bool contains(const int &key);

    void insert(const Restaurant &R);

    int getTotalRestaurants() const;
    void printRestaurantsData() const;
    Restaurant *getRestaurant(const int &key) const;
    //--> Remove all restaurants
    void makeEmpty();

    ~AVLRestaurantTree();

    void reportOnsales(vector<int> restaurants, Date date);

    void reportOnsales(int ID, Date start, Date end);
};
#endif
void AVLRestaurantTree::insert(const Restaurant R, Restaurant *&ROOT)
{
    if (ROOT == nullptr)
    {
        Restaurant *newnode = new Restaurant(R);
        ROOT = newnode;
        totalRestaurants++;
    }

    else if (R.getId() < ROOT->getId())
        insert(R, ROOT->leftChild);
    else if (R.getId() > ROOT->getId())
        insert(R, ROOT->rightChild);

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
        if (R < *ROOT)
            insert(R, ROOT);
        else if (R > *ROOT)
            insert(R, ROOT);
    }
    balance(ROOT);
}

Restaurant *AVLRestaurantTree::contains(const int &key, Restaurant *&ROOT) const
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
        return contains(key, ROOT->leftChild);
    else
        return contains(key, ROOT->rightChild);
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

// default constructor
AVLRestaurantTree::AVLRestaurantTree() : root(nullptr)
{
    totalRestaurants = 0;
}
bool AVLRestaurantTree::IsEmpty() const
{
    return (root == nullptr);
}

bool AVLRestaurantTree::contains(const int &key)
{
    return contains(key, root) != nullptr;
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

/*void AVLRestaurantTree::reportOnsales(vector<int> restaurants, Date date)
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
void AVLRestaurantTree::reportOnsales(int ID, Date start, Date end)
{
    Restaurant *R = getRestaurant(ID);
    if (R != nullptr)
    {
        R->reportOnsales(start, end);
    }
}*/
