#include <iostream>
#include "RESTAURANT.h"
#include "BSTRESTAURANT.h"
#include <date.h>


using namespace std;

int main()
{
    // create an instance of the RCMS class
    RestaurantTree rcms;

    // display the menu
    int choice;
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
    } while (choice != 11);

    return 0;
}