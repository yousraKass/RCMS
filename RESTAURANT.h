#ifndef RESTAURANT_H
#define RESTAURANT_H
#include <string>
#include "SalesAndCosts.h"
#include "Rating.h"
#include "date.h"
#include <fstream>
#include <iostream>
using namespace std;
class AVLRestaurantTree;
class RestaurantTree;
class Prize_Winners;

enum cuisine
{
    ALGERIAN,
    SYRIAN,
    CHINESE,
    INDIAN,
    EUROPIAN
};
enum Type
{
    owned,
    Franchised
};
class Restaurant
{
    friend class RestaurantTree;
    friend class SalesAndCosts;
    friend class Rating;
    friend class AVLRestaurantTree;
    friend class Prize_Winners;

private:
    Type info;
    string name;
    int ID;
    SalesAndCosts Sales_and_Costs;
    Rating rating;
    Date creationDate;
    int employee_num;
    Restaurant *leftChild;
    Restaurant *rightChild;
    int heightNode;

public:
    // SALES AND COSTS TREATED IN THEIR CLASSES
    // SALES AND COSTS TREATED IN THEIR CLASSES
    Restaurant(string T, string Name, int id, const Date &creation, const int &employee);

    // have to check what it will return (to be done while testing)
    string getType() const;

    int getEmployeeNumber() const;

    string getName() const;

    int getId() const;

    SalesAndCosts getSalesCosts() const;

    Rating getRating() const;

    Date getCreationDate() const;

    // show the restaurant 's data
    void showRestaurantData() const;
    bool operator==(const Restaurant &R);
    bool operator<(const Restaurant &R);
    bool operator>(const Restaurant &R);
    
    void getMonthlyRatio(int month, int year) const;
    void getMonthlyRatioPeriod(int startMonth, int startYear, int endMonth, int endYear) const;
    void reportOnsales(int month, int year) const;
    void reportOnsales(int day1, int month1, int year1, int day2, int month2, int year2) const;

    //void reportOnsales(Date start, Date end);
    void addRating(int month, int year, float rA, float rS, float rC, float rI, float rE);
    float getRestaurantRating(int month, int year);
    void getPrize(int month, int year, float &aA, float &aS, float &aC, float &aI, float &aE);
    void getMonthlySales(int month, int year, float &A, float &S, float &C, float &I, float &E) const;
    float getMonthlySalesOfRestaurant(int month, int year) const ;
    void add_Sales_and_Costs(int year, int month, int day, float sA, float sS, float sC, float sI, float sE,float rent_cost,float emp_salary_cost,float elec_cost,float gas_cost,float veg_cost,float meat_cost,float other_cost, float pub_cost);
    float getGeneralCosts(int day1, int month1, int year1, int day2, int month2, int year2)const;
    float getGeneralCosts(int day,int month,int year) const;
    float getPublicityCosts(int day1, int month1, int year1, int day2, int month2, int year2)const;
    float getPublicityCosts(int day,int month,int year)const;

};
void Restaurant::getMonthlyRatioPeriod(int startMonth, int startYear, int endMonth, int endYear) const
{
    Sales_and_Costs.Ratio(startMonth, startYear, endMonth, endYear, creationDate.getYear());
}
void Restaurant::getMonthlyRatio(int month, int year) const
{
    Sales_and_Costs.Ratio(month, year, creationDate.getYear());
}

Restaurant::Restaurant(string T, string Name, int id, const Date &creation, const int &employee) : ID(id), name(Name), creationDate(creation), employee_num(employee), heightNode(0)
{
    if (T == "owned")
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

// have to check what it will return (to be done while testing)
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

SalesAndCosts Restaurant::getSalesCosts() const
{
    return Sales_and_Costs;
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



/*void Restaurant::reportOnsales(Date start, Date end)
{
    this->SalesAndCosts.reportOnsales(start.getDay(), start.getMonth(), start.getYear(), end.getDay(), end.getMonth(), end.getYear(), creationDate.getYear());
}*/

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

void Restaurant::getPrize(int month, int year, float &aA, float &aS, float &aC, float &aI, float &aE)
{
    int sYear = creationDate.getYear();
    float A,S,C,I,E;
    rating.GetAmountOfPrize(month, year, aA, aS, aC, aI, aE, sYear);
    Sales_and_Costs.GetCumulativeSales(month,year,A,S,C,I,E,sYear);
    aA+=A;
    aS+=S;
    aC+=C;
    aI+=I;
    aE+=E;
}

void Restaurant::getMonthlySales(int month, int year, float &A, float &S, float &C, float &I, float &E) const
{
    int sYear = creationDate.getYear();
    Sales_and_Costs.GetMonthlySales(month, year, A, S, C, I, E, sYear);
}

float Restaurant::getMonthlySalesOfRestaurant(int month, int year) const
{
    cout << "entered" << endl;
    int sYear = creationDate.getYear();
    return Sales_and_Costs.GetMonthlySalesOfRestaurant(month,year,sYear);
}

void Restaurant::reportOnsales(int month, int year) const
{
    cout<<"Restaurant's name : "<<this->getName()<<"   , ID : "<<this->getId()<<endl;
    int sYear = creationDate.getYear();
    Sales_and_Costs.reportOnsales(month, year, sYear);
}

void Restaurant::reportOnsales(int day1, int month1, int year1, int day2, int month2, int year2) const
{
    cout<<"Restaurant's name : "<<this->getName()<<"   , ID : "<<this->getId()<<endl;
    int sYear = creationDate.getYear();
    Sales_and_Costs.reportOnsales(day1, month1, year1, day2, month2, year2, sYear);
}

void Restaurant::add_Sales_and_Costs(int year, int month, int day, float sA, float sS, float sC, float sI, float sE,float rent_cost,float emp_salary_cost,float elec_cost,float gas_cost,float veg_cost,float meat_cost,float other_cost, float pub_cost)
{
    int sYear = creationDate.getYear();
    Sales_and_Costs.Add_SalesAndCosts(year, month, day, sA, sS, sC, sI, sE,rent_cost,emp_salary_cost,elec_cost,gas_cost,veg_cost,meat_cost,other_cost,pub_cost,sYear);
}

float Restaurant::getGeneralCosts(int day1, int month1, int year1, int day2, int month2, int year2)const
{
    int sYear = creationDate.getYear();
    return Sales_and_Costs.GetGeneralCosts(day1,month1,year1,day2,month2,year2,sYear);
}

float Restaurant::getGeneralCosts(int day,int month,int year) const
{
    int sYear = creationDate.getYear();
    return Sales_and_Costs.GetGeneralCosts(day,month,year,sYear);
}

float Restaurant::getPublicityCosts(int day1, int month1, int year1, int day2, int month2, int year2)const
{
    int sYear = creationDate.getYear();
    return Sales_and_Costs.GetPublicityCosts(day1,month1,year1,day2,month2,year2,sYear);
}

float Restaurant::getPublicityCosts(int day,int month,int year)const
{
    int sYear = creationDate.getYear();
    return Sales_and_Costs.GetPublicityCosts(day,month,year,sYear);
}


#endif
