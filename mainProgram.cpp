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
    AVLRestaurantTree rcms;
    Country Algeria;
    int i = 0;
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

        
        // reading sales and costs of each restaurant
        // year,month,day,sales1,sales2,sales3,sales4,sales5,publicity_costs,costs
        /*
        ifstream salesCostsInput(ID + "salesCosts.csv");
        string lineSalesCosts;
        getline(salesCostsInput, lineSalesCosts);

        while (getline(salesCostsInput, lineSalesCosts))
        {
            extractTokensSalesCosts(lineSalesCosts, year_SC, month_SC, day_SC, sales1, sales2, sales3, sales4, sales5, publicity, costs);
            r.add_Sales_and_Costs(stoi(year_SC), stoi(month_SC), stoi(day_SC), stof(sales1), stof(sales2), stof(sales3), stof(sales4), stof(sales5), stof(publicity), stof(costs));
        }*/

        // reading ratings
        // rating 1, 2, 3, 4, 5, month, year
        ifstream ratingsInput(ID + "ratings.csv");
        string lineRatings;
        getline(ratingsInput, lineRatings);

        while (getline(ratingsInput, lineRatings))
        {
            extractTokensRatings(lineRatings, r1, r2, r3, r4, r5, month_R, year_R);
            r.addRating(stof(month_R), stof(year_R), stof(r1), stof(r2), stof(r3), stof(r4), stof(r5));
            
        }

        cout << r.getRestaurantRating(4,2018);
        i++;
        // inserting the restaurants in our data structures
        //rcms.insert(r);
        Algeria.addRestaurant(wilaya, city, district, stoi(ID));
        if(i== 2)break;
    }
    
    

    // display the menu
    /*int choice;
    do
    {
        cout << "Welcome to Koul Hani's  Restaurant Chain Management System!" << endl;
        cout << "Please select an option:" << endl;
        cout << "1. Add a restaurant" << endl;
        cout << "2. Display the list of restaurants" << endl;
        cout << "3. Display the monthly sales report for a specific restaurant " << endl;
        cout << "4. Display the sales report for a specific restaurant in a specific period " << endl;
        cout << "5. Display the sales report for all restaurants (the whole country)  in a specific period " << endl;

        cout << "6. Display the sales report for  restaurants in a city in a specific period " << endl;
        cout << "7. Display the sales report for  restaurants in a district  in a specific period " << endl;

        cout << "8. Display the sales report for a specific restaurant in a specific period " << endl;
        cout << "9. Display the sales report for a specific restaurant in a specific period " << endl;

        cout << "10. Display the prize winners for each cuisine on a specific month" << endl;

        cout << "11. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {

        // case 1:
        // {
        //     // add a restaurant to the system add it to the ADT plus in the file
        //     string name, id, location, type;
        //     int numEmployees;

        //     cout << "Enter the type of the restaurant (owned or franchised): ";
        //     cin >> type;
        //     cout << "Enter the name of the restaurant: ";
        //     cin >> name;
        //     cout << "Enter the ID of the restaurant: ";
        //     cin >> id;

        //     // creation date is today
        //     //  Get the current time point
        //     //std::chrono::system_clock::time_point now = std::chrono::system_clock::now();

        //     // Convert the time point to a time since epoch (std::time_t)
        //     std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

        //     // Convert the time since epoch to a struct tm
        //     struct std::tm *timeInfo = std::localtime(&currentTime);

        //     // Extract year, month, and day
        //     int year = timeInfo->tm_year + 1900; // Years since 1900
        //     int month = timeInfo->tm_mon + 1;    // Months are zero-based
        //     int day = timeInfo->tm_mday;
        //     Date creationDate(year, month, date);

        //     cout << "Enter the number of employees: ";
        //     cin >> numEmployees;
        //     cout << "Enter the location of the restaurant (it should be detailed and separated by , (country,city,district)): ";
        //     getline(cin, location);
        //     // add to file ID,Name,Type,Creation date,employee number,country,city,districtf

        //     Restaurant newRestaurant(type, name, id, creationDate, numEmployees);
        //     rcms.insert(newRestaurant);

        //     break;
        // }
        case 2:
        {
            // display the list of restaurants
            rcms.printRestaurantsData();
            break;
        }

        case 3:
        {
            // display the monthly sales report for a specific restaurant
            int id, month, year;
            cout << "Enter the ID of the restaurant: ";
            cin >> id;
            cout << "Enter the month (a number): ";
            cin >> month;
            cout << "Enter the year: ";
            cin >> year;
            rcms.getRestaurant(id)->reportOnsales(month, year);
            break;
        }
        case 4:
        {
            // display the monthly sales report for a specific restaurant
            int id, month, year, day;
            cout << "Enter the ID of the restaurant: ";
            cin >> id;
            cout << "enter the first date " << endl;
            cout << "Enter the day (a number): ";
            cin >> day;
            cout << "Enter the month (a number): ";
            cin >> month;
            cout << "Enter the year: ";
            cin >> year;
            Date date1(year, month, day);

            cout << "enter the second date " << endl;
            cout << "Enter the day (a number): ";
            cin >> day;
            cout << "Enter the month (a number): ";
            cin >> month;
            cout << "Enter the year: ";
            cin >> year;
            Date date2(year, month, day);

            rcms.getRestaurant(id)->reportOnsales(date1, date2);
            break;
        }

        // still not done
        /*case 5:
        {
            // display the prize winners for each cuisine on a specific month
            string month;
            cout << "Enter the month (in the format MMMM YYYY): ";
            cin >> month;
            rcms.displayPrizeWinners(month);
            break;
        }
        case 11:
        {
            // exit the program
            cout << "Exiting the program..." << endl;
            break;
        }
        default:
        {
            // invalid choice
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        }
    } while (choice != 11);*/

    return 0;
}