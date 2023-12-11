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

void extractTokensSalesCosts(string &line, string &year, string &month, string &day, string &sales1, string &sales2, string &sales3, string &sales4, string &sales5, string &publicity, string &costs)
{
    // year,month,day,sales1,sales2,sales3,sales4,sales5,publicity_costs,costs

    // Create a stringstream to parse the line
    stringstream ss(line);

    // Use getline with ',' as the delimiter to extract tokens
    getline(ss, year, ',');
    getline(ss, month, ',');
    getline(ss, day, ',');
    getline(ss, sales1, ',');
    getline(ss, sales2, ',');
    getline(ss, sales3, ',');
    getline(ss, sales4, ',');
    getline(ss, sales5, ',');
    getline(ss, publicity, ',');
    getline(ss, costs);
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
    RestaurantTree rcms;
    Country Algeria;

    // skipping the first line
    getline(input, line);
    string ID, name, type, year, month, day, employeeNum, wilaya, city, district;
    string lineSalesCosts, year_SC, month_SC, day_SC, sales1, sales2, sales3, sales4, sales5, publicity, costs;
    string r1, r2, r3, r4, r5, month_R, year_R;

    // reading lines until finishing with the file
    while (getline(input, line))
    {
        // reading the data in that line
        extractTokensRestaurant(line, ID, name, type, year, month, day, employeeNum, wilaya, city, district);

        // create the needed insttances
        Date d(stoi(year), stoi(month), stoi(day));
        Restaurant r(type, name, stoi(ID), d, stoi(employeeNum));

        // inserting the restaurants in our data structures

        // reading sales and costs of each restaurant
        /* year,month,day,sales1,sales2,sales3,sales4,sales5,publicity_costs,costs
        ifstream salesCostsInput(ID + "salesCosts.csv");
        string lineSalesCosts;
        getline(salesCostsInput, lineSalesCosts);

        while (getline(salesCostsInput, lineSalesCosts))
        {
            extractTokensSalesCosts(lineSalesCosts, year_SC, month_SC, day_SC, sales1, sales2, sales3, sales4, sales5, publicity, costs);
            r.add_Sales_and_Costs(stoi(year_SC), stoi(month_SC), stoi(day_SC), stof(sales1), stof(sales2), stof(sales3), stof(sales4), stof(sales5), stof(publicity), stof(costs));
        }

        // reading ratings
        /*rating 1, 2, 3, 4, 5, month, year
        ifstream ratingsInput(ID + "ratings.csv");
        string lineRatings;
        getline(ratingsInput, lineRatings);

       /* while (getline(ratingsInput, lineRatings))
        {
            extractTokensRatings(lineRatings, r1, r2, r3, r4, r5, month_R, year_R);
            r.addRating(stof(month_R), stof(year_R), stof(r1), stof(r2), stof(r3), stof(r4), stof(r5));
        }
*/
        rcms.insert(r);
       cout<<"total number of restaurants "<< rcms.getTotalRestaurants()<<endl;
       rcms.printRestaurantsData();
        Algeria.addRestaurant(wilaya, city, district, stoi(ID));
    }

    

    return 0;
}