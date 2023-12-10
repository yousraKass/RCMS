#include <iostream>
#include "RESTAURANT.h"
#include "BSTRESTAURANT.h"
#include"AVLRESTAURANT.h"
#include "Country.h"
#include "date.h"
#include <fstream>
#include <sstream>
using namespace std;

void extractTokensRestaurant(const string &line, string &ID, string &name, string &type, string &year, string &month, string &day, string &employeeNum, string &wilaya, string &city, string &district)
{
    // ID,Name,Type,Creation date,employee number,wilaya,city,district

    // Create a stringstream to parse the line
    stringstream ss(line);

    // Use getline with ',' as the delimiter to extract tokens
    getline(ss, ID, ',');
    getline(ss, name, ',');
    getline(ss, type, ',');

    // Extract the date and parse it
    string dateToken;
    getline(ss, dateToken, ',');
    stringstream dateSS(dateToken);

    getline(dateSS, year, '-');
    getline(dateSS, month, '-');
    getline(dateSS, day, '-');

    getline(ss, employeeNum, ',');
    getline(ss, wilaya, ',');
    getline(ss, city, ',');
    getline(ss, district);
}

void extractTokensSalesCosts(string &line, int &year, int &month, int &day, float &sales1, float &sales2, float &sales3, float &sales4, float &sales5, float &publicity, float &costs)
{
    // year,month,day,sales1,sales2,sales3,sales4,sales5,publicity_costs,costs

    // Create a stringstream to parse the line
    stringstream ss(line);

    // Use getline with ',' as the delimiter to extract tokens
    ss >> year;
    ss.ignore();
    ss >> month;
    ss.ignore();  
    ss >> day;
    ss.ignore(); 
    ss >> sales1;
    ss.ignore();
    ss >> sales2;
    ss.ignore();
    ss >> sales3;
    ss.ignore();
    ss >> sales4;
    ss.ignore();
    ss >> sales5;
    ss.ignore();
    ss >> costs;
    ss.ignore();
    ss >> publicity;
}



void extractTokensRatings(string &lineRatings, string &r1, string &r2, string &r3, string &r4, string &r5, string &month_R, string &year_R)
{
    // rating 1, 2, 3, 4, 5, month, year

    // Create a stringstream to parse the line
    stringstream ss(lineRatings);

    // Use getline with ',' as the delimiter to extract tokens
    getline(ss, r1, ',');
    getline(ss, r2, ',');
    getline(ss, r3, ',');
    getline(ss, r4, ',');
    getline(ss, r5, ',');
    getline(ss, month_R, ',');
    getline(ss, year_R);
}




int main()
{
    // reading the files
    // the set of restaurants
    ifstream input("RESTAURANTS.csv");

    // variable to store each line each time
    string line;
    //RestaurantTree rcms;
    Country Algeria;
    int i = 0;

    // skipping the first line
    getline(input, line);
    string ID, name, type, year, month, day, employeeNum, wilaya, city, district;
    string lineSalesCosts;
    int year_SC, month_SC, day_SC; 
    float sales1, sales2, sales3, sales4, sales5, publicity, costs;
    string r1, r2, r3, r4, r5, month_R, year_R;

    // reading lines until finishing with the file
    while (getline(input, line))
    {
        
        // reading the data in that line
        extractTokensRestaurant(line, ID, name, type, year, month, day, employeeNum, wilaya, city, district);

        // create the needed insttances
        Date d(stoi(year), stoi(month), stoi(day));
        Restaurant r(type, name, stoi(ID), d, stoi(employeeNum));

        
        // reading sales and costs of each restaurant
        // year,month,day,sales1,sales2,sales3,sales4,sales5,publicity_costs,costs
        
        ifstream salesCostsInput("salesCosts/" + ID + "salesCosts.csv");
        string lineSalesCosts;
        getline(salesCostsInput, lineSalesCosts);

        while (getline(salesCostsInput, lineSalesCosts))
        {
            extractTokensSalesCosts(lineSalesCosts, year_SC, month_SC, day_SC, sales1, sales2, sales3, sales4, sales5, publicity, costs);
            r.add_Sales_and_Costs(year_SC,month_SC, day_SC, sales1, sales2, sales3, sales4, sales5, publicity, costs);
        }

        // reading ratings
        // rating 1, 2, 3, 4, 5, month, year
        ifstream ratingsInput("Ratings/" + ID + "ratings.csv");
        string lineRatings;
        i++;
        getline(ratingsInput, lineRatings);

        while (getline(ratingsInput, lineRatings))
        {
            extractTokensRatings(lineRatings, r1, r2, r3, r4, r5, month_R, year_R);
            r.addRating(stof(month_R), stof(year_R), stof(r1), stof(r2), stof(r3), stof(r4), stof(r5));
        }
        
        // inserting the restaurants in our data structures
        //rcms.insert(r);
        r.reportOnsales(11,2023);
        Algeria.addRestaurant(wilaya, city, district, stoi(ID));
    }
    

    return 0;
}