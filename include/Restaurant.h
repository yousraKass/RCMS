#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <string>
#include <fstream>
#include <iostream>
using namespace std;


#include "SalesAndCosts.h"
#include "Rating.h"
#include "Date.h"

class AVLRestaurantTree;
class BSTRestaurantTree;
class PrizeWinners;

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
    friend class BSTRestaurantTree;
    friend class SalesAndCosts;
    friend class Rating;
    friend class AVLRestaurantTree;
    friend class PrizeWinners;

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
    public: 
    // constructor 
    Restaurant(string T, string Name, int id, const Date &creation, const int &employee); 
 
    //return the type of the restaurant : owned or franchised 
    string getType() const; 
 
    //return the number of employees in a restaurant 
    int getEmployeeNumber() const; 
 
    //return the name of the restaurant 
    string getName() const; 
 
    //return the ID of the restaurant  
    int getId() const; 
 
    //return the object of sales and costs that stores all information 
    // about the daily sales and detailed daily costs of the restaurant 
    SalesAndCosts getSalesCosts() const; 
 
    //return the rating of the restaurant 
    //an object of rating that stores ratings of all months 
    Rating getRating() const; 
 
    //return the creation date of the restaurant 
    Date getCreationDate() const; 
 
    // show the restaurant 's data 
    void showRestaurantData() const; 
 
    //operators overloading : = , > , < 
    bool operator==(const Restaurant &R); 
    bool operator<(const Restaurant &R); 
    bool operator>(const Restaurant &R); 
     
    //get the ratio of the monthly sales over the the spending on publicity 
    void getMonthlyRatio(int month, int year) const; 
 
    //get the ratio of the monthly sales over the the spending on publicity 
    //in a giving period 
    void getMonthlyRatioPeriod(int startMonth, int startYear, int endMonth, int endYear) const; 
 
    //display a report on sales on a given month 
    void reportOnsales(int month, int year) const; 
 
    //display the report of sales on a given period : start date,end date 
    void reportOnsales(int day1, int month1, int year1, int day2, int month2, int year2) const; 
 
    //fill the rating on a given month and year 
    //calls a function of the data member rating 
    void addRating(int month, int year, float rA, float rS, float rC, float rI, float rE); 
 
    //return the rating of the restaurant on a given month 
    float getRestaurantRating(int month, int year); 
 
    //return the amount of prize on a given month 
    void getPrize(int month, int year, float &aA, float &aS, float &aC, float &aI, float &aE); 
 
    //return the monthly sales of the five cuisines 
    void getMonthlySales(int month, int year, float &A, float &S, float &C, float &I, float &E) const; 
 
    //return the general monthly sales of the restaurant 
    float getMonthlySalesOfRestaurant(int month, int year) const ; 
 
    //fill the daily sales and costs  
    //calls a funtion of the data member Sales_And_Costs 
    void add_Sales_and_Costs(int year, int month, int day, float sA, float sS, float sC, float sI, float sE,float rent_cost,float emp_salary_cost,float elec_cost,float gas_cost,float veg_cost,float meat_cost,float other_cost, float pub_cost); 
 
    //return the general cost of the restaurant on a given period 
    float getGeneralCosts(int day1, int month1, int year1, int day2, int month2, int year2)const; 
 
    //return the general cost of a specific day 
    float getGeneralCosts(int day,int month,int year) const; 
 
    //return the publicity costs on a given period 
    float getPublicityCosts(int day1, int month1, int year1, int day2, int month2, int year2)const; 
 
    //return the publicity cost of a specific day  
    float getPublicityCosts(int day,int month,int year)const; 
 
};

#endif