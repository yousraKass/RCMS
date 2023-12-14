#include <fstream>
using std::ifstream;
using std::ofstream;

#include <cstdlib>
#include <ctime>
using std::rand;
using std::srand;
using std::time;

#include <iostream>
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::to_string;

// we are generating 10000 restaurant
int restaurantNum = 7000;
int restaurantName = 400;
int restaurantLocation = 1541;

int main()
{
    // generate restaurant IDs

    srand(time(0));
    /*
    ofstream outputID("IDS.csv");

    for(int i = 0; i<7000; i++){
        unsigned id = rand() % 10000000000;
        // int k = rand() % 10 + 1;
        if(id < 1000000000){
            id = (id + 1000000000)% 10000000000;
        }
        outputID << id << endl;
    }
    */

    ifstream inputID("IDS.csv");
    ifstream inputLocation("algeria_cities.csv");
    ifstream inputname("restaurantNames.csv");
    int id, type;
    int day, month, year;
    string name;
    string wilaya ="", city ="", district = "";
    int currentRestaurantName = 1;
    int currentRestaurantID = 1;
    int currentRestaurantLocation = 1;
    int employeeNumber;
    ofstream output("RESTAURANTS.csv");

    // ID,Name,Type,Creation date,employee number,wilaya,city,district
    output << "ID,Name,Type,Creation date,employee number,wilaya,city,district" << endl;

    for (int i = 0; i < restaurantNum; i++)
    {
        inputID >> id;
        inputname >> name;
        getline(inputLocation, district, ',');
        getline(inputLocation, city, ',');
        getline(inputLocation, wilaya);
        string temp = wilaya + "," + city + "," + district;
        type = rand() % 2;
        string t = (type == 0) ? "owned" : "franchised";
        day = rand() % 28 + 1;
        month = rand() % 12 + 1;
        year = rand() % 20 + 2000;
        string date = to_string(year) + "-" + to_string(month) + "-" + to_string(day);
        employeeNumber = rand() % 200 + 20;

        output << id << "," << t << "," << date << "," << employeeNumber << "," << temp << endl;

        currentRestaurantName++;
        currentRestaurantLocation++;
        if (currentRestaurantName == restaurantName)
        {
            inputname.close();
            inputname.open("restaurantNames.csv");
            currentRestaurantName = 0;
        }

        if (currentRestaurantLocation == restaurantLocation)
        {
            inputLocation.close();
            inputLocation.open("algeria_cities.csv");
            currentRestaurantLocation = 0;
        }
    }

    return 0;
}