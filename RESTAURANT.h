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

class Restaurant
{
    friend class RestaurantTree;
    friend class Sales_and_Costs;
    friend class Rating;
    friend class AVLRestaurantTree;

private:
    enum Type
    {
        owned,
        Franchised
    };

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
    // SALES AND COSTS TREATED IN THEIR CLASSES
    // SALES AND COSTS TREATED IN THEIR CLASSES
    Restaurant(string T, string Name, int id, const Date &creation, const int &employee) : ID(id), name(Name), creationDate(creation), employee_num(employee), heightNode(0)
    {
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

    // have to check what it will return (to be done while testing)
    Type getType() const
    {
        return info;
    }
    int getEmployeeNumber() const
    {
        return employee_num;
    }
    string getName() const
    {
        return name;
    }
    int getId() const
    {
        return ID;
    }
    Sales_and_Costs getSalesCosts() const
    {
        return SalesAndCosts;
    }
    Rating getRating() const
    {
        return rating;
    }

    Date getCreationDate() const
    {
        return creationDate;
    }

    /* to be discussed
    //  used to add restaurant to the file
    // what abt country , city... how to include them
    void addRestaurantFile()
    {

        fstream RestaurantFile;
        string fileName = "Restaurants.csv ";
        RestaurantFile.open(fileName, ios::out | ios::app);
        // RestaurantFile << "ID,Name,Type,Creation date,employee number,country,city,district" << endl;

        if (RestaurantDataBase.is_open())
        {
            RestaurantFile << to_string(getId()) << ",";

            RestaurantFile << getName() << ",";
            RestaurantFile << getType() << "," << getCreationDate().TextFormat() << to_string(getEmployeeNumber()) << "\n";

            cout << "\nInformation saved successfully \n";
        }
        // ask about
        system("pause");
        system("cls");
        RestaurantDataBase.close();
    }
*/
    // show the restaurant 's data
    void showRestaurantData() const
    {
        cout << "Name : " << getName() << endl;
        cout << "Id : " << getId() << endl;
        cout << "Type : " << getType() << endl;
        cout << "Creation date ";
        creationDate.DisplayDate();
    }

    bool operator==(const Restaurant &R)
    {
        return this->getId() == R.getId();
    }

    bool operator<(const Restaurant &R)
    {
        return this->getId() < R.getId();
    }
    bool operator>(const Restaurant &R)
    {
        return this->getId() > R.getId();
    }
    void reportOnsales(int month, int year)
    {
        this->SalesAndCosts.reportOnsales(month, year, creationDate.getYear());
    }
    void reportOnsales(Date start, Date end)
    {
        this->SalesAndCosts.reportOnsales(start.getDay(), start.getMonth(), start.getYear(), end.getDay(), end.getMonth(), end.getYear(), creationDate.getYear());
    }

    void addRating(int month, int year, float rA, float rS, float rC, float rI, float rE)
    {
        int sYear = creationDate.getYear();
        rating.AddRating(month, year, rA, rS, rC, rI, rE, sYear);
    } 

    float getRestaurantRating(int month, int year)
    {
        int sYear = creationDate.getYear();
        return rating.GetRestaurantRating(month, year, sYear);
        
    }

    void getAmountOfPrize(int month, int year, float &aA, float &aS, float &aC, float &aI, float &aE)
    {
        int sYear = creationDate.getYear();
        rating.GetAmountOfPrize(month, year, aA, aS, aC, aI, aE, sYear);
    }

    void getMonthlySales(int month, int year, float &A, float &S, float &C, float &I, float &E) const
    {
        int sYear = creationDate.getYear();
        SalesAndCosts.GetMonthlySales(month, year, A, S, C, I, E, sYear);
    }

    float getMonthlySalesOfRestaurant(int month, int year) const
    {
        int sYear = creationDate.getYear();
        return SalesAndCosts.GetMonthlySalesOfRestaurant(month, year, sYear);
    }

    void reportOnsales(int month, int year) const
    {
        int sYear = creationDate.getYear();
        SalesAndCosts.reportOnsales(month, year, sYear);
    }

    void reportOnsales(int day1, int month1, int year1, int day2, int month2, int year2) const
    {
        int sYear = creationDate.getYear();
        SalesAndCosts.reportOnsales(day1, month1, year1, day2, month2, year2, sYear);
    }

    void add_Sales_and_Costs(int year, int month, int day, float sA, float sS, float sC, float sI, float sE, float pub_Cost, float gen_Cost)
    {
        int sYear = creationDate.getYear();
        SalesAndCosts.Add_Sales_and_Costs(year, month, day, sA, sS, sC, sI, sE, pub_Cost, gen_Cost, sYear);
    }

    /*void displayRatio(int ID , Date date);
    void displayRatio(int ID, Date start, Date end);



    void displayRatio(vector<int> restaurants , Date date);
    void displayRatio(vector<int> restaurants, Date start, Date end);
    */
};
#endif