#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;

#include "generateSalesCosts.h"
#include "extractFromRestaurants.h"

int main()
{
    ifstream inputFile("../../Data/RESTAURANTS.csv");

    string line;
    getline(inputFile, line);
    
    
    while (getline(inputFile, line))
    {
        int startYear, startMonth, startDay, ID;
        extractTokens(line, ID, startYear, startMonth, startDay);
        generateSalesCosts(startYear, startMonth, startDay, ID);
    }

    return 0;
}