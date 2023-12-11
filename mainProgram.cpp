#include <iostream>
#include "RESTAURANT.h"
#include "BSTRESTAURANT.h"
#include "AVLRESTAURANT.h"
#include "Country.h"
#include "date.h"
#include <fstream>
#include <sstream>
#include <chrono>
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

void fillSalesCosts(int ID, Restaurant &r)
{
    // reading sales and costs of each restaurant
    // year,month,day,sales1,sales2,sales3,sales4,sales5,publicity_costs,costs
    // needed variables
    int year_SC, month_SC, day_SC;
    float sales1, sales2, sales3, sales4, sales5, publicity, costs;

    ifstream salesCostsInput("salesCosts/" + to_string(ID) + "salesCosts.csv");
    string lineSalesCosts;
    getline(salesCostsInput, lineSalesCosts);

    while (getline(salesCostsInput, lineSalesCosts))
    {
        extractTokensSalesCosts(lineSalesCosts, year_SC, month_SC, day_SC, sales1, sales2, sales3, sales4, sales5, publicity, costs);
        r.add_Sales_and_Costs(year_SC, month_SC, day_SC, sales1, sales2, sales3, sales4, sales5, publicity, costs);
    }
}

void fillRating(int ID, Restaurant &r)
{
    // variables needed
    string r1, r2, r3, r4, r5, month_R, year_R;
    // reading ratings
    // rating 1, 2, 3, 4, 5, month, year
    ifstream ratingsInput("Ratings/" + to_string(ID) + "ratings.csv");
    string lineRatings;
    getline(ratingsInput, lineRatings);
    while (getline(ratingsInput, lineRatings))
    {
        extractTokensRatings(lineRatings, r1, r2, r3, r4, r5, month_R, year_R);
        r.addRating(stof(month_R), stof(year_R), stof(r1), stof(r2), stof(r3), stof(r4), stof(r5));
    }
}

int main()
{
    // reading the files
    // the set of restaurants
    ifstream input("RESTAURANTS.csv");
    ofstream output("RESTAURANTS.csv", ios::app);

    // variable to store each line each time
    string line;
    RestaurantTree rcms;
    Country Algeria;
    int i = 0;

    // skipping the first line
    getline(input, line);
    string ID, name, type, year, month, day, employeeNum, wilaya, city, district;

    // reading lines until finishing with the file
    while (getline(input, line))
    {

        // reading the data in that line
        extractTokensRestaurant(line, ID, name, type, year, month, day, employeeNum, wilaya, city, district);

        // create the needed insttances
        Date d(stoi(year), stoi(month), stoi(day));
        Restaurant r(type, name, stoi(ID), d, stoi(employeeNum));

        fillSalesCosts(stoi(ID), r);
        fillRating(stoi(ID), r);

        // inserting the restaurants in our data structures
        // rcms.insert(r);
        // Algeria.addRestaurant(wilaya, city, district, stoi(ID));
    }

/*
    // display the menu
    int choice;
    do
    {
        cout << "Welcome to Koul Hani's  Restaurant Chain Management System!" << endl;
        cout << "Please select an option:" << endl;
        cout << "1. Add a restaurant" << endl;
        cout << "2. Display the list of restaurants" << endl;
        cout << "3. Display the monthly sales report for a specific restaurant " << endl;
        cout << "4. Display the monthly sales report for all restaurants in a specific district " << endl;
        cout << "5. Display the monthly sales report for all restaurants in a specific city " << endl;
        cout << "6. Display the monthly sales report for all restaurants in a specific wilaya " << endl;
        cout << "7. Display the monthly sales report for all restaurants in the country " << endl;
        cout << "8. Display the ratio of the monthly sales on the publicity cost for a specific restaurant " << endl;
        cout << "9. Display the ratio of the monthly sales on the publicity cost for all restaurants in a specific district " << endl;
        cout << "10. Display the ratio of the monthly sales on the publicity cost for all restaurants in a specific city " << endl;
        cout << "11. Display the ratio of the monthly sales on the publicity cost for all restaurants in a specific wilaya " << endl;
        cout << "12. Display the ratio of the monthly sales on the publicity cost for all restaurants in the country " << endl;
        cout << "13. Display the prize winners for each cuisine: " << endl;
        // for the graph display should be added in each case of the above cases
        cout << "14. Exit" << endl;
        cout << endl;
        cout << "Enter your choice: ";

        cin >> choice;

        switch (choice)
        {

        case 1:
        {
            // add a restaurant to the system add it to the ADT plus in the file
            // ID,Name,Type,Creation date,employee number,wilaya,city,district
            string name, wilaya, city, district;
            string type;
            int numEmployees, ID, day, month, year;

            cout << "enter the restaurant location: wilaya, city, district: ";
            cin >> wilaya >> city >> district;
            cout << "Enter the name of the restaurant: ";
            cin >> name;
            cout << "Enter the ID of the restaurant: ";
            cin >> ID;
            cout << "Enter the type of the restaurant (owned or franchised): ";
            cin >> type;
            cout << "Enter the number of employees: ";
            cin >> numEmployees;
            cout << "Enter the creation date: day, month, year: ";
            cin >> day >> month >> year;
            cout << "getting sales and costs..." << endl;
            cout << "getting ratings ..." << endl;
            Date d(year, month, day);

            auto start = chrono::high_resolution_clock::now();
            Restaurant newRestaurant(type, name, ID, d, numEmployees);
            if (!rcms.contains(ID))
            {
                fillRating(ID, newRestaurant);
                fillSalesCosts(ID, newRestaurant);
                rcms.insert(newRestaurant);
                Algeria.addRestaurant(wilaya, city, district, ID);
                // ID,Name,Type,Creation date,employee number,wilaya,city,district
                string date = to_string(year) + "-" + to_string(month) + "-" + to_string(day);
                output << ID << "," << name << "," << date << "," << numEmployees << "," << wilaya << "," << city << "," << district;
            }
            cout << "restaurant added successfuly" << endl;
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
            break;
        }
        case 2:
        {
            rcms.printRestaurantsData();
            break;
        }
        case 3:
        {
            // Display the monthly sales report for a specific restaurant
            cout << "enter the restaurant ID: ";
            int restaurant_ID;
            cin >> restaurant_ID;
            cout << endl;

            cout << "do you want it for a period or a specific month: ";
            cout << "1. specific month and year" << endl;
            cout << "2. specific period" << endl;
            int Case;
            cin >> Case;
            cout << endl;

            switch (Case)
            {
            case 1:
                cout << "enter the month and the year respectively: ";
                int month, year;
                cin >> month >> year;
                Date d(year, month);
                Restaurant *r = rcms.getRestaurant(restaurant_ID);
                if (!r)
                {
                    float amount = r->getMonthlySalesOfRestaurant(d.getMonth(), d.getYear());
                    if (amount == 0)
                        cout << "no sales in that month and year" << endl;
                    else
                    {
                        r->reportOnsales(d.getMonth(), d.getYear());
                    }
                }
                else
                {
                    cout << "this restaurant does not exist" << endl;
                }

                break;

            case 2:
                int day1, month1, year1;
                int day2, month2, year2;
                cout << "enter the starting date(day, month, year): ";
                cin >> day1 >> month1 >> year1;
                cout << "enter the ending date(day, month, year): ";
                cin >> day2 >> month2 >> year2;

                Date start(year1, month1, day1);
                Date end(year2, month2, day2);

                break;
            }
            string id, month, year;
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
            string id, month, year, day;
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
            rcms.getRestaurant(id)->repotOnsales(date1, date2);
            break;
        }
        // still not done
        case 5:
        {
            // display the prize winners for each cuisine on a specific month            string month;
            cout << "Enter the month (in the format MMMM YYYY): ";
            cin >> month;
            rcms.displayPrizeWinners(month);
            break;
        }
        case 11:
        {
            // exit the program            cout << "Exiting the program..." << endl;
            break;
        }
        default:
        {
            // invalid choice            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        }
    } while (choice != 11);*/

    return 0;
}