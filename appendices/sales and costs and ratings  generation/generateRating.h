#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

void generateRatings(int & ID, int startYear, int startMonth)
{
    string fileName = to_string(ID) + "ratings.csv";
    ofstream csvFile(fileName);

    // Write header
    csvFile << "rating1,rating2,rating3,rating4,rating5,month,year" << std::endl;

    srand(time(0));

    for (; startYear < 2024;)

    {
        for (int i = 0; i < 5; i++)
        {
            csvFile << rand() % 6 << ","; // Generate random ratings between 0 and 5
        }

        csvFile << startMonth << "," << startYear << endl;
        startMonth++;
        if (startMonth == 13)
        {
            startMonth = 1;
            startYear++;
        }
    }
}