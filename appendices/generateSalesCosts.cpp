#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;

#include "generateSalesCosts.h"

void extractTokens(const std::string &line, int &ID, int &year, int &month, int &day)
{
    // Create a stringstream to parse the line
    std::stringstream ss(line);

    string temp;
    // 1010043555,owned,2008-3-4,142,Chlef,Beni Haoua,Oued Goussine

    // Use getline with ',' as the delimiter to extract tokens
    ss >> ID;
    ss.ignore();
    std::getline(ss, temp, ',');       // Chez Omar (skipping the second token)
    std::getline(ss, temp, ',');       // owned (skipping the third token)

    // Extract the date and parse it
    std::string dateToken;
    std::getline(ss, dateToken, ','); // 2023-10-04

    // Create another stringstream to parse the date
    std::stringstream dateSS(dateToken);

    // Extract year, month, and day directly into variables
    dateSS >> year;
    dateSS.ignore(); // Ignore the '-'
    dateSS >> month;
    dateSS.ignore(); // Ignore the '-'
    dateSS >> day;
}

int main()
{
    ifstream inputFile("RESTAURANTS.csv");

    std::string line;
    getline(inputFile, line);
    int i = 0;
    while (getline(inputFile, line))
    {
        int startYear, startMonth, startDay, ID;
        extractTokens(line, ID, startYear, startMonth, startDay);
        i++;

        generateSalesCosts(startYear, startMonth, startDay, ID);

        
    }

    return 0;
}