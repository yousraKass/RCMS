#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <string>
#include <iomanip>

using std::cin;
using std::getline;
using std::rand;
using std::srand;
using std::time;
using std::chrono::duration_cast;
using std::chrono::high_resolution_clock;
using std::chrono::microseconds;
using namespace std;

#include "BSTRESTAURANT.h"
#include "RESTAURANT.h"
#include "AVLRESTAURANT.h"
#include "Country.h"
#include "date.h"
#include "Prize_Winners.h"

void extractTokensRestaurant(const string &line, int &ID, string &name, string &type, int &year, int &month, int &day, int &employeeNum, string &wilaya, string &city, string &district);
void extractTokensSalesCosts(string &line, int &year, int &month, int &day, float &sales1, float &sales2, float &sales3, float &sales4, float &sales5, float &rent, float &employeePayment, float &electricity, float &gaz, float &vegetables, float &meats, float &otherIngredients, float &publicity);
void extractTokensRatings(string &lineRatings, float &r1, float &r2, float &r3, float &r4, float &r5, int &month_R, int &year_R);
void fillSalesCosts(int ID, Restaurant &r);
void fillRating(int ID, Restaurant &r);
void printWinners(vector<Restaurant *> v);
void toLower(string &str);

// chrono::duration<long long, std::micro> duration = std::chrono::microseconds(0);
// chrono::high_resolution_clock::time_point startTime;
// chrono::high_resolution_clock::time_point endTime;
// long long du = duration.count();
// long long du2 = duration.count();

int main()
{

    cout << fixed << setprecision(2);

    RestaurantTree rcms;

    Country Algeria;

    ofstream runningTime("searchRestaurantBST.txt", ios::app);

    // reading the files
    // the set of restaurants
    ifstream input("Data/RESTAURANTS.csv");
    ofstream output("Data/RESTAURANTS.csv", ios::app);

    // variable to store each line each time
    string line;

    // skipping the first line
    getline(input, line);
    string name, type, wilaya, city, district;
    int ID, year, month, day, employeeNum;
    Date date(2024, 12, 31);
    int i = 0;

    // reading lines until finishing with the file
    // std::chrono::duration<long long, std::micro> duration = std::chrono::microseconds(0);
    // std::chrono::high_resolution_clock::time_point startTime;
    // std::chrono::high_resolution_clock::time_point endTime;
    // long long du = duration.count();
    while (getline(input, line))
    {
        i++;
        // reading the data in that line
        extractTokensRestaurant(line, ID, name, type, year, month, day, employeeNum, wilaya, city, district);

        // create the needed insttances
        Date d(year, month, day);
        if (d < date)
            date = d;
        toLower(wilaya);
        toLower(city);
        toLower(district);

        Restaurant restaurant(type, name, ID, d, employeeNum);

        fillSalesCosts(ID, restaurant);
        fillRating(ID, restaurant);

        // runningTime << "fillSalesCosts for 1 restaurant " << du2 << endl;
        // runningTime << "fillRating for 1 restaurant " << du << endl;

        // inserting the restaurants in our data structures

        rcms.insert(restaurant);

        Algeria.addRestaurant(wilaya, city, district, ID);
        if (i == 7000)
            break;
    }

    Prize_Winners winners(rcms, date);

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
        cout << "13. Display the prize winners for each cuisine " << endl;
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
            toLower(wilaya);
            toLower(city);
            toLower(district);

            cout << "Enter the name of the restaurant: ";
            cin >> name;
            toLower(name);

            cout << "Enter the ID of the restaurant: ";
            cin >> ID;

            cout << "Enter the type of the restaurant (owned or franchised): ";
            cin >> type;
            toLower(type);

            cout << "Enter the number of employees: ";
            cin >> numEmployees;
            cout << "Enter the creation date: day, month, year: ";
            cin >> day >> month >> year;
            cout << "getting sales and costs..." << endl;
            cout << "getting ratings ..." << endl;
            Date d(year, month, day);
            Restaurant newRestaurant(type, name, ID, d, numEmployees);
            if (!rcms.contains(ID))
            {

                // fillRating(ID, newRestaurant);
                fillSalesCosts(ID, newRestaurant);
                rcms.insert(newRestaurant);
                Algeria.addRestaurant(wilaya, city, district, ID);
                // ID,Name,Type,Creation date,employee number,wilaya,city,district
                string date = to_string(year) + "-" + to_string(month) + "-" + to_string(day);
                output << endl;
                output << ID << "," << name << "," << date << "," << numEmployees << "," << wilaya << "," << city << "," << district;
                cout << "restaurant added successfuly" << endl;
            }
            else
            {
                cout << "restaurant ID already excist" << endl;
            }
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

            cout << "do you want it for a period or a specific month: " << endl;
            cout << "1. specific month and year" << endl;
            cout << "2. specific period" << endl;
            int Case;
            cin >> Case;
            cout << endl;

            switch (Case)
            {
            case 1:
            {
                cout << "enter the month and the year respectively: ";
                int month, year;
                cin >> month >> year;
                Date d(year, month);
                if (r != nullptr)
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
            }

            case 2:
            {
                int day1, month1, year1;
                int day2, month2, year2;
                cout << "enter the starting date(day, month, year): ";
                cin >> day1 >> month1 >> year1;
                cout << "enter the ending date(day, month, year): ";
                cin >> day2 >> month2 >> year2;

                Date start(year1, month1, day1);
                Date end(year2, month2, day2);

                if (r != nullptr)
                {
                    r->reportOnsales(start.getDay(), start.getMonth(), start.getYear(), end.getDay(), end.getMonth(), end.getYear());
                }
                else
                {
                    cout << "this restaurant does not exist" << endl;
                }

                break;
            }
            }
            break;
        }

        case 4:
        {
            // Display the monthly sales report for all restaurants in a specific district
            cout << "enter the wilaya, city, district to get the report on sales of all restaurants in that district" << endl;
            string wilaya, city, district;
            cin >> wilaya >> city >> district;
            toLower(wilaya);
            toLower(city);
            toLower(district);
            cout << wilaya << endl;

            vector<int> restaurantIDs = Algeria.getRestaurantsDistrict(wilaya, city, district);

            cout << "do you want it for a period or a specific month: ";
            cout << "1. specific month and year" << endl;
            cout << "2. specific period" << endl;
            int Case;
            cin >> Case;
            cout << endl;

            switch (Case)
            {
            case 1:
            {
                cout << "enter the month and the year respectively: ";
                int month, year;
                cin >> month >> year;
                Date d(year, month);

                for (int i = 0; i < restaurantIDs.size(); i++)
                {
                    rcms.getRestaurant(restaurantIDs[i])->reportOnsales(d.getMonth(), d.getYear());
                    cout << "-------------------------------------------------" << endl;
                    cout << "-------------------------------------------------" << endl;
                }

                break;
            }

            case 2:
            {
                int day1, month1, year1;
                int day2, month2, year2;
                cout << "enter the starting date(day, month, year): ";
                cin >> day1 >> month1 >> year1;
                cout << "enter the ending date(day, month, year): ";
                cin >> day2 >> month2 >> year2;

                Date start(year1, month1, day1);
                Date end(year2, month2, day2);

                for (int i = 0; i < restaurantIDs.size(); i++)
                {
                    rcms.getRestaurant(restaurantIDs[i])->reportOnsales(start.getDay(), start.getMonth(), start.getYear(), end.getDay(), end.getMonth(), end.getYear());
                    cout << "-------------------------------------------------" << endl;
                    cout << "-------------------------------------------------" << endl;
                }
                break;
            }
            }
            break;
        }

        case 5:
        {
            // Display the monthly sales report for all restaurants in a specific city
            cout << "enter the wilaya, city to get the report on sales of all restaurants in that city" << endl;
            string wilaya, city;
            cin >> wilaya >> city;
            toLower(wilaya);
            toLower(city);

            vector<int> restaurantIDs = Algeria.getRestaurantsAllDistricts(wilaya, city);

            cout << "do you want it for a period or a specific month: ";
            cout << "1. specific month and year" << endl;
            cout << "2. specific period" << endl;
            int Case;
            cin >> Case;
            cout << endl;

            switch (Case)
            {
            case 1:
            {
                cout << "enter the month and the year respectively: ";
                int month, year;
                cin >> month >> year;
                Date d(year, month);
                for (int i = 0; i < restaurantIDs.size(); i++)
                {
                    rcms.getRestaurant(restaurantIDs[i])->reportOnsales(d.getMonth(), d.getYear());
                    cout << "-------------------------------------------------" << endl;
                    cout << "-------------------------------------------------" << endl;
                }

                break;
            }

            case 2:
            {
                int day1, month1, year1;
                int day2, month2, year2;
                cout << "enter the starting date(day, month, year): ";
                cin >> day1 >> month1 >> year1;
                cout << "enter the ending date(day, month, year): ";
                cin >> day2 >> month2 >> year2;

                Date start(year1, month1, day1);
                Date end(year2, month2, day2);

                for (int i = 0; i < restaurantIDs.size(); i++)
                {
                    rcms.getRestaurant(restaurantIDs[i])->reportOnsales(start.getDay(), start.getMonth(), start.getYear(), end.getDay(), end.getMonth(), end.getYear());
                    cout << "-------------------------------------------------" << endl;
                    cout << "-------------------------------------------------" << endl;
                }
                break;
            }
            }
            break;
        }

        case 6:
        {
            // Display the monthly sales report for all restaurants in a specific wilaya
            string wilaya;

            cout << "enter the wilaya to get the report on sales of all restaurants in that wilaya" << endl;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            getline(cin, wilaya, '\n');
            cout << wilaya;
            toLower(wilaya);

        

            vector<int> restaurantIDs = Algeria.getRestaurantsAllCities(wilaya);

            cout << "do you want it for a period or a specific month: ";
            cout << "1. specific month and year" << endl;
            cout << "2. specific period" << endl;
            int Case;
            cin >> Case;
            cout << endl;

            switch (Case)
            {
            case 1:
            {
                cout << "enter the month and the year respectively: ";
                int month, year;
                cin >> month >> year;
                Date d(year, month);
                for (int i = 0; i < restaurantIDs.size(); i++)
                {
                    rcms.getRestaurant(restaurantIDs[i])->reportOnsales(d.getMonth(), d.getYear());
                    cout << "-------------------------------------------------" << endl;
                    cout << "-------------------------------------------------" << endl;
                }

                break;
            }

            case 2:
            {
                int day1, month1, year1;
                int day2, month2, year2;
                cout << "enter the starting date(day, month, year): ";
                cin >> day1 >> month1 >> year1;
                cout << "enter the ending date(day, month, year): ";
                cin >> day2 >> month2 >> year2;

                Date start(year1, month1, day1);
                Date end(year2, month2, day2);

                for (int i = 0; i < restaurantIDs.size(); i++)
                {
                    rcms.getRestaurant(restaurantIDs[i])->reportOnsales(start.getDay(), start.getMonth(), start.getYear(), end.getDay(), end.getMonth(), end.getYear());
                    cout << "-------------------------------------------------" << endl;
                    cout << "-------------------------------------------------" << endl;
                }
                break;
            }
            }
            break;
        }

        case 7:
        {
            // Display the monthly sales report for all restaurants in the country

            vector<int> restaurantIDs = Algeria.getRestaurantsAllWilayas();

            cout << "do you want it for a period or a specific month: " << endl;
            cout << "1. specific month and year" << endl;
            cout << "2. specific period" << endl;
            int Case;
            cin >> Case;
            cout << endl;

            switch (Case)
            {
            case 1:
            {
                cout << "enter the month and the year respectively: ";
                int month, year;
                cin >> month >> year;
                Date d(year, month);
                for (int i = 0; i < restaurantIDs.size(); i++)
                {
                    rcms.getRestaurant(restaurantIDs[i])->reportOnsales(d.getMonth(), d.getYear());
                    cout << "-------------------------------------------------" << endl;
                    cout << "-------------------------------------------------" << endl;
                }

                break;
            }

            case 2:
            {
                int day1, month1, year1;
                int day2, month2, year2;
                cout << "enter the starting date(day, month, year): ";
                cin >> day1 >> month1 >> year1;
                cout << "enter the ending date(day, month, year): ";
                cin >> day2 >> month2 >> year2;

                Date start(year1, month1, day1);
                Date end(year2, month2, day2);

                for (int i = 0; i < restaurantIDs.size(); i++)
                {
                    rcms.getRestaurant(restaurantIDs[i])->reportOnsales(start.getDay(), start.getMonth(), start.getYear(), end.getDay(), end.getMonth(), end.getYear());
                    cout << "-------------------------------------------------" << endl;
                    cout << "-------------------------------------------------" << endl;
                }
                break;
            }
            }
            break;
        }

        case 8:
        {
            // Display the ratio of the monthly sales on the publicity cost for a specific restaurant
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
            {
                cout << "enter the month and the year respectively: " << endl;
                int month, year;
                cin >> month >> year;
                Date d(year, month);
                if (r != nullptr)
                {

                    r->getMonthlyRatio(d.getMonth(), d.getYear());
                }
                else
                {
                    cout << "this restaurant does not exist" << endl;
                }

                break;
            }

            case 2:
            {
                int month1, year1;
                int month2, year2;
                cout << "enter the starting date(month, year): ";
                cin >> month1 >> year1;
                cout << "enter the ending date(month, year): ";
                cin >> month2 >> year2;

                Date start(year1, month1);
                Date end(year2, month2);

                if (r != nullptr)
                {

                    r->getMonthlyRatioPeriod(start.getMonth(), start.getYear(), end.getMonth(), end.getYear());
                }
                else
                {
                    cout << "this restaurant does not exist" << endl;
                }

                break;
            }
            }

            break;
        }

        case 9:
        {
            // Display the ratio of the monthly sales on the publicity cost for all restaurants in a specific district
            cout << "enter the wilaya, city, district to get the ratio of the monthly sales on the publicity cost for all restaurants in that district" << endl;
            string wilaya, city, district;
            cin >> wilaya >> city >> district;
            toLower(wilaya);
            toLower(city);
            toLower(district);

            vector<int> restaurantIDs = Algeria.getRestaurantsDistrict(wilaya, city, district);

            cout << "do you want it for a period or a specific month: ";
            cout << "1. specific month and year" << endl;
            cout << "2. specific period" << endl;
            int Case;
            cin >> Case;
            cout << endl;

            switch (Case)
            {
            case 1:
            {
                cout << "enter the month and the year respectively: ";
                int month, year;
                cin >> month >> year;
                Date d(year, month);
                for (int i = 0; i < restaurantIDs.size(); i++)
                {
                    rcms.getRestaurant(restaurantIDs[i])->getMonthlyRatio(d.getMonth(), d.getYear());
                    cout << "-------------------------------------------------" << endl;
                    cout << "-------------------------------------------------" << endl;
                }

                break;
            }

            case 2:
            {
                int month1, year1;
                int month2, year2;
                cout << "enter the starting date(month, year): ";
                cin >> month1 >> year1;
                cout << "enter the ending date(month, year): ";
                cin >> month2 >> year2;

                Date start(year1, month1);
                Date end(year2, month2);

                for (int i = 0; i < restaurantIDs.size(); i++)
                {
                    rcms.getRestaurant(restaurantIDs[i])->getMonthlyRatioPeriod(start.getMonth(), start.getYear(), end.getMonth(), end.getYear());
                    cout << "-------------------------------------------------" << endl;
                    cout << "-------------------------------------------------" << endl;
                }
                break;
            }
            }

            break;
        }

        case 10:
        {
            // Display the ratio of the monthly sales on the publicity cost for all restaurants in a specific city
            cout << "enter the wilaya, city to get the ratio of the monthly sales on the publicity cost for all restaurants in that city" << endl;
            string wilaya, city;
            cin >> wilaya >> city;
            toLower(wilaya);
            toLower(city);

            vector<int> restaurantIDs = Algeria.getRestaurantsAllDistricts(wilaya, city);

            cout << "do you want it for a period or a specific month: ";
            cout << "1. specific month and year" << endl;
            cout << "2. specific period" << endl;
            int Case;
            cin >> Case;
            cout << endl;

            switch (Case)
            {
            case 1:
            {
                cout << "enter the month and the year respectively: ";
                int month, year;
                cin >> month >> year;
                Date d(year, month);
                for (int i = 0; i < restaurantIDs.size(); i++)
                {
                    rcms.getRestaurant(restaurantIDs[i])->getMonthlyRatio(d.getMonth(), d.getYear());
                    cout << "-------------------------------------------------" << endl;
                    cout << "-------------------------------------------------" << endl;
                }

                break;
            }

            case 2:
            {
                int month1, year1;
                int month2, year2;
                cout << "enter the starting date(month, year): ";
                cin >> month1 >> year1;
                cout << "enter the ending date(month, year): ";
                cin >> month2 >> year2;

                Date start(year1, month1);
                Date end(year2, month2);

                for (int i = 0; i < restaurantIDs.size(); i++)
                {
                    rcms.getRestaurant(restaurantIDs[i])->getMonthlyRatioPeriod(start.getMonth(), start.getYear(), end.getMonth(), end.getYear());
                    cout << "-------------------------------------------------" << endl;
                    cout << "-------------------------------------------------" << endl;
                }
                break;
            }
            }

            break;
        }

        case 11:
        {
            // Display the ratio of the monthly sales on the publicity cost for all restaurants in a specific wilaya
            cout << "enter the wilaya to get the ratio of the monthly sales on the publicity cost for all restaurants in that wilaya" << endl;
            string wilaya;
            cin >> wilaya;
            toLower(wilaya);

            vector<int> restaurantIDs = Algeria.getRestaurantsAllCities(wilaya);

            cout << "do you want it for a period or a specific month: ";
            cout << "1. specific month and year" << endl;
            cout << "2. specific period" << endl;
            int Case;
            cin >> Case;
            cout << endl;

            switch (Case)
            {
            case 1:
            {
                cout << "enter the month and the year respectively: ";
                int month, year;
                cin >> month >> year;
                Date d(year, month);
                for (int i = 0; i < restaurantIDs.size(); i++)
                {
                    rcms.getRestaurant(restaurantIDs[i])->getMonthlyRatio(d.getMonth(), d.getYear());
                    cout << "-------------------------------------------------" << endl;
                    cout << "-------------------------------------------------" << endl;
                }

                break;
            }

            case 2:
            {
                int month1, year1;
                int month2, year2;
                cout << "enter the starting date(month, year): ";
                cin >> month1 >> year1;
                cout << "enter the ending date(month, year): ";
                cin >> month2 >> year2;

                Date start(year1, month1);
                Date end(year2, month2);

                for (int i = 0; i < restaurantIDs.size(); i++)
                {
                    rcms.getRestaurant(restaurantIDs[i])->getMonthlyRatioPeriod(start.getMonth(), start.getYear(), end.getMonth(), end.getYear());
                    cout << "-------------------------------------------------" << endl;
                    cout << "-------------------------------------------------" << endl;
                }
                break;
            }
            }
            break;
        }

        case 12:
        {
            // Display the ratio of the monthly sales on the publicity cost for all restaurants in the country
            vector<int> restaurantIDs = Algeria.getRestaurantsAllWilayas();

            cout << "do you want it for a period or a specific month: ";
            cout << "1. specific month and year" << endl;
            cout << "2. specific period" << endl;
            int Case;
            cin >> Case;
            cout << endl;

            switch (Case)
            {
            case 1:
            {
                cout << "enter the month and the year respectively: ";
                int month, year;
                cin >> month >> year;
                Date d(year, month);
                for (int i = 0; i < restaurantIDs.size(); i++)
                {
                    rcms.getRestaurant(restaurantIDs[i])->getMonthlyRatio(d.getMonth(), d.getYear());
                    cout << "-------------------------------------------------" << endl;
                    cout << "-------------------------------------------------" << endl;
                }

                break;
            }

            case 2:
            {
                int month1, year1;
                int month2, year2;
                cout << "enter the starting date(month, year): ";
                cin >> month1 >> year1;
                cout << "enter the ending date(month, year): ";
                cin >> month2 >> year2;

                Date start(year1, month1);
                Date end(year2, month2);

                for (int i = 0; i < restaurantIDs.size(); i++)
                {
                    rcms.getRestaurant(restaurantIDs[i])->getMonthlyRatioPeriod(start.getMonth(), start.getYear(), end.getMonth(), end.getYear());
                    cout << "-------------------------------------------------" << endl;
                    cout << "-------------------------------------------------" << endl;
                }
                break;
            }
            }
            break;
        }

        case 13:
        {
            // Display the prize winners for each cuisine
            cout << "do you want the prize winners for: " << endl;
            cout << "1. specific month and year" << endl;
            cout << "2. specific period" << endl;

            int choice_p;
            cin >> choice_p;

            switch (choice_p)
            {
            case 1:
            {
                int month_p, year_p;
                cout << "enter the month and year respectively: ";
                cin >> month_p >> year_p;
                Date date_p(year_p, month_p);
                vector<Restaurant *> winner = winners.get_winners(date_p.getMonth(), date_p.getYear());
                printWinners(winner);

                break;
            }
            case 2:
            {
                int start_month_p, start_year_p;
                int end_month_p, end_year_p;

                cout << "enter the start month then year: ";
                cin >> start_month_p >> start_year_p;
                Date Sdate_p(start_year_p, start_month_p);

                cout << "enter the end month then year: ";
                cin >> end_month_p >> end_year_p;
                Date Edate_p(end_year_p, end_month_p);
                vector<vector<Restaurant *>> winner = winners.get_winners(Sdate_p.getMonth(), Sdate_p.getYear(), Edate_p.getMonth(), Edate_p.getYear());

                // this should be modified
                // our code is not consistent
                for (auto &item : winner)
                {
                    cout << "winners of " << start_month_p++ << "/" << start_year_p << endl;
                    printWinners(item);
                    if (start_month_p == 13)
                    {
                        start_month_p = 1;
                        start_year_p++;
                    }
                }
                break;
            }
            }

            break;
        }
        }

    } while (choice != 14);
}

void extractTokensRestaurant(const string &line, int &ID, string &name, string &type, int &year, int &month, int &day, int &employeeNum, string &wilaya, string &city, string &district)
{
    // ID,Name,Type,Creation date,employee number,wilaya,city,district

    // Create a stringstream to parse the line
    stringstream ss(line);

    // Use getline with ',' as the delimiter to extract tokens
    ss >> ID;
    ss.ignore();
    getline(ss, name, ',');
    getline(ss, type, ',');

    // Extract the date and parse it
    string dateToken;
    getline(ss, dateToken, ',');
    stringstream dateSS(dateToken);

    dateSS >> year;
    dateSS.ignore();
    dateSS >> month;
    dateSS.ignore();
    dateSS >> day;
    dateSS.ignore();

    ss >> employeeNum;
    ss.ignore();
    getline(ss, wilaya, ',');
    getline(ss, city, ',');
    getline(ss, district);
}

void extractTokensSalesCosts(string &line, int &year, int &month, int &day, float &sales1, float &sales2, float &sales3, float &sales4, float &sales5, float &rent, float &employeePayment, float &electricity, float &gaz, float &vegetables, float &meats, float &otherIngredients, float &publicity)
{
    // year,month,day,sales1,sales2,sales3,sales4,sales5,rent, employeePayment, electricity, gaz, vegetables, meats, otherIngredients, publicity

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
    ss >> rent;
    ss.ignore();
    ss >> employeePayment;
    ss.ignore();
    ss >> electricity;
    ss.ignore();
    ss >> gaz;
    ss.ignore();
    ss >> vegetables;
    ss.ignore();
    ss >> meats;
    ss.ignore();
    ss >> otherIngredients;
    ss.ignore();
    ss >> publicity;
}

void extractTokensRatings(string &lineRatings, float &r1, float &r2, float &r3, float &r4, float &r5, int &month_R, int &year_R)
{
    // rating 1, 2, 3, 4, 5, month, year

    // Create a stringstream to parse the line
    stringstream ss(lineRatings);

    // Use getline with ',' as the delimiter to extract tokens
    ss >> r1;
    ss.ignore();
    ss >> r2;
    ss.ignore();
    ss >> r3;
    ss.ignore();
    ss >> r4;
    ss.ignore();
    ss >> r5;
    ss.ignore();
    ss >> month_R;
    ss.ignore();
    ss >> year_R;
}

void fillSalesCosts(int ID, Restaurant &restaurant)
{
    // reading sales and costs of each restaurant
    // year,month,day,sales1,sales2,sales3,sales4,sales5,rent, employeePayment, electricity, gaz, vegetables, meats, otherIngredients, publicity
    // needed variables
    int year_SC, month_SC, day_SC;
    float sales1, sales2, sales3, sales4, sales5, rent, employeePayment, electricity, gaz, vegetables, meats, otherIngredients, publicity;

    ifstream salesCostsInput("Data/salesCosts/" + to_string(ID) + "salesCosts.csv");
    string lineSalesCosts;
    getline(salesCostsInput, lineSalesCosts);

    while (getline(salesCostsInput, lineSalesCosts))
    {
        extractTokensSalesCosts(lineSalesCosts, year_SC, month_SC, day_SC, sales1, sales2, sales3, sales4, sales5, rent, employeePayment, electricity, gaz, vegetables, meats, otherIngredients, publicity);
        restaurant.add_Sales_and_Costs(year_SC, month_SC, day_SC, sales1, sales2, sales3, sales4, sales5, rent, employeePayment, electricity, gaz, vegetables, meats, otherIngredients, publicity);
    }
}

void fillRating(int ID, Restaurant &r)
{
    // variables needed
    float r1, r2, r3, r4, r5;
    int month_R, year_R;
    // reading ratings
    // rating 1, 2, 3, 4, 5, month, year
    ifstream ratingsInput("Data/Ratings/" + to_string(ID) + "ratings.csv");
    string lineRatings;
    getline(ratingsInput, lineRatings);
    while (getline(ratingsInput, lineRatings))
    {
        extractTokensRatings(lineRatings, r1, r2, r3, r4, r5, month_R, year_R);
        auto startTime = chrono::high_resolution_clock::now();
        r.addRating(month_R, year_R, r1, r2, r3, r4, r5);
    }
}

void printWinners(vector<Restaurant *> v)
{
    cout << "The winner of the Algerian cuisine is: ";
    cout << v[ALGERIAN]->getName() << " restaurant";
    cout << "\tID:" << v[ALGERIAN]->getId() << endl;

    cout << "The winner of the Syrian cuisine is: ";
    cout << v[SYRIAN]->getName() << " restaurant";
    cout << "\tID:" << v[SYRIAN]->getId() << endl;

    cout << "The winner of the Chinese cuisine is: ";
    cout << v[CHINESE]->getName() << " restaurant";
    cout << "\tID:" << v[CHINESE]->getId() << endl;

    cout << "The winner of the Indian cuisine is: ";
    cout << v[INDIAN]->getName() << " restaurant";
    cout << "\tID:" << v[INDIAN]->getId() << endl;

    cout << "The winner of the Europian cuisine is: ";
    cout << v[EUROPIAN]->getName() << " restaurant";
    cout << "\tID:" << v[EUROPIAN]->getId() << endl;
}

void toLower(string &str)
{
    for (int i = 0; i < str.size(); i++)
        str[i] = tolower(str[i]);
}