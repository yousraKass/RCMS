#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;

#include "generateSalesCosts.h"

void extractTokens(const string &line, int &ID, int &year, int &month, int &day)
{
    // Create a stringstream to parse the line
    stringstream ss(line);

    string temp;
    
    ss >> ID;
    ss.ignore();
    getline(ss, temp, ',');       
    getline(ss, temp, ','); 

    string dateToken;
    getline(ss, dateToken, ','); 
    stringstream dateSS(dateToken);
    dateSS >> year;
    dateSS.ignore(); 
    dateSS >> month;
    dateSS.ignore();
    dateSS >> day;
}


int main()
{
    ifstream inputFile("RESTAURANTS.csv");

    string line;
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