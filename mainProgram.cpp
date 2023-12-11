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
        r.reportOnsales(10,2023);
        // rcms.insert(r);
        // Algeria.addRestaurant(wilaya, city, district, stoi(ID));
        break;
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
            Restaurant *r = rcms.getRestaurant(restaurant_ID);
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

                if (!r)
                {
                    r->reportOnsales(start.getDay(), start.getMonth(), start.getYear(), end.getDay(), end.getMonth(), end.getYear());
                }
                else
                {
                    cout << "this restaurant does not exist" << endl;
                }

                break;
            }
            break;
        }
        case 4:
        {
            // Display the monthly sales report for all restaurants in a specific district
            
            break;
        }
        // still not done
        case 5:
        {
            
        }
        case 11:
        {
        }
        default:
        {
            
        }
        }
    } while ();*/

    return 0;
}


/*

8.49534e+06
7.52052e+06
7.69615e+06
0
7.8634e+06
7.71604e+06
7.97874e+06
7.80434e+06
7.76131e+06
7.94022e+06
7.764e+06
8.5523e+06
7.80956e+06
7.66228e+06
7.66315e+06
7.77564e+06
8.07638e+06
8.25934e+06
7.51848e+06
7.91691e+06
7.10204e+06
7.73141e+06
7.53395e+06
7.61077e+06
7.46321e+06
8.36894e+06
7.30923e+06
7.90141e+06
7.63913e+06
7.40383e+06
8.03814e+06
8.11017e+06
8.06579e+06
7.80088e+06
7.46703e+06
7.59032e+06
7.67292e+06
7.74755e+06
7.54756e+06
7.83904e+06
6.96119e+06
7.84783e+06
7.44523e+06
7.31329e+06
7.58359e+06
7.96386e+06
7.98076e+06
7.67292e+06
8.01825e+06
8.22076e+06
7.15508e+06
8.00745e+06
8.31572e+06
7.98547e+06
8.50514e+06
7.30713e+06
7.01916e+06
8.25698e+06
7.84247e+06
7.9765e+06
8.21801e+06
7.87157e+06
8.17033e+06
7.84612e+06
8.04514e+06
8.13764e+06
7.86498e+06
7.57528e+06
6.9265e+06
8.20558e+06
7.98785e+06
7.06998e+06
8.0713e+06
7.34224e+06
7.74089e+06
7.62389e+06
7.45116e+06
7.79206e+06
7.57462e+06
7.89184e+06
7.46618e+06
7.98307e+06
7.23553e+06
7.35808e+06
7.36239e+06
7.49123e+06
8.09295e+06
7.95738e+06
7.83957e+06
7.46968e+06
7.74521e+06
7.64941e+06
7.84761e+06
7.42135e+06
7.93066e+06
7.53985e+06
8.12138e+06
7.70504e+06
7.75294e+06
7.48082e+06
7.93088e+06
7.56916e+06
7.95867e+06
6.82374e+06
7.52007e+06
7.24938e+06
7.30849e+06
7.91216e+06
7.59964e+06
7.53976e+06
7.74254e+06
7.25405e+06
7.85195e+06
7.92597e+06
7.61306e+06
7.44527e+06
8.17901e+06
7.95738e+06
7.83957e+06
7.46968e+06
7.74521e+06
7.64941e+06
7.84761e+06
7.42135e+06
7.93066e+06
7.53985e+06
8.12138e+06
7.70504e+06
7.75294e+06
7.48082e+06
7.93088e+06
7.56916e+06
7.95867e+06
6.82374e+06
7.52007e+06
7.24938e+06
7.30849e+06
7.91216e+06
7.59964e+06
7.53976e+06
7.74254e+06
7.25405e+06
7.39454e+06
7.38496e+06
7.66055e+06
7.59738e+06
7.90975e+06
8.05586e+06
7.99133e+06
7.27981e+06
7.73444e+06
8.22979e+06
8.03317e+06
7.95126e+06
7.85306e+06
8.74578e+06
7.63418e+06
7.98488e+06
7.8148e+06
7.91396e+06
7.99871e+06
7.94223e+06
8.04182e+06
7.25818e+06
8.35279e+06
8.01304e+06
7.56534e+06
7.54791e+06
7.07749e+06
7.67354e+06
7.38541e+06
7.5341e+06
7.82027e+06
8.50787e+06
7.58951e+06
7.8728e+06
7.66856e+06
8.05586e+06
7.99133e+06
7.27981e+06
7.73444e+06
8.22979e+06
8.03317e+06
7.95126e+06
7.85306e+06
8.74578e+06
7.63418e+06
7.98488e+06
7.8148e+06
7.91396e+06
7.99871e+06
7.94223e+06
8.04182e+06
7.25818e+06
8.35279e+06
8.01304e+06
7.62306e+06
7.42424e+06
7.22624e+06
7.4389e+06
7.20388e+06
7.52236e+06
7.52434e+06
8.3931e+06
7.22512e+06
7.71794e+06
7.64238e+06
8.05586e+06
7.99133e+06
7.27981e+06
7.73444e+06
8.22979e+06
8.03317e+06
7.95126e+06
7.85306e+06
8.74578e+06
7.63418e+06
7.98488e+06
7.8148e+06
7.91396e+06
7.99871e+06
7.94223e+06
8.04182e+06
7.25818e+06
8.35279e+06
8.01304e+06
7.62306e+06
7.42424e+06
7.22624e+06
7.4389e+06
7.20388e+06
7.52236e+06
7.52434e+06
8.3931e+06
7.22512e+06
7.71794e+06
7.64238e+06
8.05586e+06
7.99133e+06
7.27981e+06
7.73444e+06
8.22979e+06
8.03317e+06
7.95126e+06
7.85306e+06
8.74578e+06
7.63418e+06
7.98488e+06
7.8148e+06
7.91396e+06
7.99871e+06
7.94223e+06
8.04182e+06
7.25818e+06
8.35279e+06
8.01304e+06
7.62306e+06
7.42424e+06
7.22624e+06
7.4389e+06
7.20388e+06
7.52236e+06
8.07528e+06
8.15166e+06
8.23394e+06
7.34907e+06
7.7975e+06
7.81956e+06
8.0673e+06
0
*/