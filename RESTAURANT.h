#ifndef RESTAURANT_H
#define RESTAURANT_H
#include <string>
#include "DailySalesAndCosts.h"
#include "Rating.h"
#include "date.h"
#include <fstream>
#include <iostream>
using namespace std;
class AVLRestaurantTree;
class RestaurantTree;

//enum type that indicates if the restaurant is owned/franchised
enum Type
{
    owned,
    Franchised
};
class Restaurant
{
    //declare friend class that they need direct access to restaurant's private data members
    friend class RestaurantTree;
    friend class Sales_and_Costs;
    friend class Rating;
    friend class AVLRestaurantTree;
//declaring private data members of the class Restaurant
private:
    Type info;
    string name;
    int ID;
    Sales_and_Costs SalesAndCosts;
    Rating rating;
    Date creationDate;
    int employee_num;
    Restaurant *leftChild;
    Restaurant *rightChild;
    int heightNode;

public:
   // constructor
    Restaurant(const string &T, const string &Name,const int &id, const Date &creation, const int &employee);
    // Return the type of the restaurant
    string getType() const;
     //return the number of employees in the restaurant
    int getEmployeeNumber() const;
    //return the restaurant's name
    string getName() const;
    //return the restaurant's Id
    int getId() const;
    //return the restaurant's sales and costs (object)
    Sales_and_Costs getSalesCosts() const;
    //return the restaurant's rating (object)
    Rating getRating() const;
    //return the restaurant's creation date (object)
    Date getCreationDate() const;

    // show the restaurant 's data
    void showRestaurantData() const;
    //overloading the operators ==,<,>
    bool operator==(const Restaurant &R);
    bool operator<(const Restaurant &R);
    bool operator>(const Restaurant &R);
    //return the restaurant's Monthly ratio of the sales over the publicity cost in mm/yyyy
    void getMonthlyRatio(int month, int year) const;
    //return the restaurant's Monthly ratio of the sales over the publicity cost in a specific period of time
    void getMonthlyRatioPeriod(int startMonth, int startYear, int endMonth, int endYear) const;
    //report on sales of the restaurant in a given month and year (calls a function of the sales and costs object)
    void reportOnsales(int month, int year) const;
    //report on sales of the restaurant in a given period (calls a function of the sales and costs object)
    void reportOnsales(int day1, int month1, int year1, int day2, int month2, int year2) const;
    //add the restaurant's rating from the creation date till now
    void addRating(int month, int year, float rA, float rS, float rC, float rI, float rE);
    //return the monthly rating of a restaurant (average of the five cuisine)
    float getRestaurantRating(int month, int year);
    //get the prize Amount of a specific month
    void getAmountOfPrize(int month, int year, float &aA, float &aS, float &aC, float &aI, float &aE);
    //show the sales of a specific month for each cuisine and the restaurant
    void getMonthlySales(int month, int year, float &A, float &S, float &C, float &I, float &E) const;
    //get the sales of the restaurant on a given month
    float getMonthlySalesOfRestaurant(int month, int year) const ;
     //add the restaurant's daily sales , daily costs from the creation date till now
    void add_Sales_and_Costs(int year, int month, int day, float sA, float sS, float sC, float sI, float sE, float pub_Cost, float gen_Cost);
};


void Restaurant::getMonthlyRatioPeriod(int startMonth, int startYear, int endMonth, int endYear) const
{
    SalesAndCosts.Ratio(startMonth, startYear, endMonth, endYear, creationDate.getYear());
}

void Restaurant::getMonthlyRatio(int month, int year) const
{
    SalesAndCosts.Ratio(month, year, creationDate.getYear());
}

Restaurant::Restaurant(const string &T, const string &Name,const int &id, const Date &creation, const int &employee){

    if (T == "Owned")
    {
        info = owned;
    }
    else
    {
        info = Franchised;
    }
    leftChild = nullptr;
    rightChild = nullptr;
}

string Restaurant::getType() const
{
    return (info == 0 ? "Owned " : "Franchised");
}

int Restaurant::getEmployeeNumber() const
{
    return employee_num;
}

string Restaurant::getName() const
{
    return name;
}

int Restaurant::getId() const
{
    return ID;
}

Sales_and_Costs Restaurant::getSalesCosts() const
{
    return SalesAndCosts;
}

Rating Restaurant::getRating() const
{
    return rating;
}

Date Restaurant::getCreationDate() const
{
    return creationDate;
}

// show the restaurant 's data
void Restaurant::showRestaurantData() const
{
    cout << "Name : " << getName() << endl;
    cout << "Id : " << getId() << endl;
    cout << "Type : " << getType() << endl;
    cout << "Creation  ";
    creationDate.DisplayDate();
}

bool Restaurant::operator==(const Restaurant &R)
{
    return this->getId() == R.getId();
}

bool Restaurant::operator<(const Restaurant &R)
{
    return this->getId() < R.getId();
}

bool Restaurant::operator>(const Restaurant &R)
{
    return this->getId() > R.getId();
}

void Restaurant::addRating(int month, int year, float rA, float rS, float rC, float rI, float rE)
{
    int sYear = creationDate.getYear();
    int sMonth = creationDate.getMonth();
    rating.AddRating(month, year, rA, rS, rC, rI, rE, sYear, sMonth);
}

float Restaurant::getRestaurantRating(int month, int year)
{
    int sYear = creationDate.getYear();
    return rating.GetRestaurantRating(month, year, sYear);
}

void Restaurant::getAmountOfPrize(int month, int year, float &aA, float &aS, float &aC, float &aI, float &aE)
{
    int sYear = creationDate.getYear();
    rating.GetAmountOfPrize(month, year, aA, aS, aC, aI, aE, sYear);
}

void Restaurant::getMonthlySales(int month, int year, float &A, float &S, float &C, float &I, float &E) const
{
    int sYear = creationDate.getYear();
    SalesAndCosts.GetMonthlySales(month, year, A, S, C, I, E, sYear);
}

float Restaurant::getMonthlySalesOfRestaurant(int month, int year) const
{
    int sYear = creationDate.getYear();
    return SalesAndCosts.GetMonthlySalesOfRestaurant(month,year,sYear);
}

void Restaurant::reportOnsales(int month, int year) const
{
    int sYear = creationDate.getYear();
    SalesAndCosts.reportOnsales(month, year, sYear);
}

void Restaurant::reportOnsales(int day1, int month1, int year1, int day2, int month2, int year2) const
{
    int sYear = creationDate.getYear();
    SalesAndCosts.reportOnsales(day1, month1, year1, day2, month2, year2, sYear);
}

void Restaurant::add_Sales_and_Costs(int year, int month, int day, float sA, float sS, float sC, float sI, float sE, float pub_Cost, float gen_Cost)
{
    int sYear = creationDate.getYear();
    SalesAndCosts.Add_Sales_and_Costs(year, month, day, sA, sS, sC, sI, sE, pub_Cost, gen_Cost, sYear);
}

#endif