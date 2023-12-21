#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

#include "extractFromRestaurants.h"
#include "generateRating.h"


int main()
{
    ifstream inputFile("../../Data/RESTAURANTS.csv");
    int ID;
    int startYear, startMonth, startDay;
    string line;
    int i = 0;
    getline(inputFile, line);
    while (getline(inputFile, line))
    {
        i++;
        extractTokens(line, ID, startYear, startMonth, startDay);
        generateRatings(ID, startYear, startMonth);
        if(i = 1) break;
    }

    return 0;
}