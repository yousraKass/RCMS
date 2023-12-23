#include "BSTRestaurant.h"

// default constructor
BSTRestaurantTree::BSTRestaurantTree() : root(nullptr)
{
    totalRestaurants = 0;
}
void BSTRestaurantTree::insert(const Restaurant R, Restaurant *&ROOT)
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
}
void BSTRestaurantTree::insert(Restaurant &&R, Restaurant *&ROOT)
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

bool BSTRestaurantTree::contains(const int &key, Restaurant *ROOT) const
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
void BSTRestaurantTree::printHelper(Restaurant *ROOT) const
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
Restaurant *BSTRestaurantTree::getRestauranthelper(const int &key, Restaurant *ROOT) const
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
void BSTRestaurantTree::makeEmpty(Restaurant *&ROOT)
{
    if (ROOT != nullptr)
    {

        makeEmpty(ROOT->leftChild);
        makeEmpty(ROOT->rightChild);
        delete ROOT;
        ROOT = nullptr;
    }
}

bool BSTRestaurantTree::IsEmpty() const
{
    return (root == nullptr);
}

bool BSTRestaurantTree::contains(const int &key)
{
    return contains(key, root);
}

void BSTRestaurantTree::insert(const Restaurant &R)
{

    insert(R, root);
}
int BSTRestaurantTree::getTotalRestaurants() const
{
    return totalRestaurants;
}
void BSTRestaurantTree::printRestaurantsData() const
{
    cout << "Total number of restaurants is: " << getTotalRestaurants() << endl;
    printHelper(root);
}
Restaurant *BSTRestaurantTree::getRestaurant(const int &key) const
{
    return getRestauranthelper(key, root);
}

//--> Remove all restaurants
void BSTRestaurantTree::makeEmpty()
{
    makeEmpty(root);
}
BSTRestaurantTree::~BSTRestaurantTree()
{
    makeEmpty();
}
