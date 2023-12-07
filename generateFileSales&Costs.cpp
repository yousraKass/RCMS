#include <iostream>
#include <fstream>

using namespace std;

#include <iostream>
#include <sstream>
#include <string>

void extractTokens(const std::string &line, std::string &firstToken, int &year, int &month, int &day)
{
    // Create a stringstream to parse the line
    std::stringstream ss(line);

    string temp;
    // Use getline with ',' as the delimiter to extract tokens
    std::getline(ss, firstToken, ','); // 12345678
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
    while (getline(inputFile, line))
    {
        string ID;
        int startYear, startMonth, startDay;
        extractTokens(line, ID, startYear, startMonth, startDay);

        string filePath = ID + "salesCosts.csv";
        ofstream outputFile(filePath);
        outputFile << "year,month,day,sales1,sales2,sales3,sales4,sales5,publicity_costs,costs" << endl;

        for (int year = startYear; year <= 2023; ++year)
        {
            for (int month = (year == startYear) ? startMonth : 1; month <= 12; ++month)
            {
                for (int day = (year == startYear && month == startMonth) ? startDay : 1; day <= 31; ++day)
                {
                    // Generate random sales and costs data for each day (you can replace this with your own logic)
                    double sales[5];
                    for (int i = 0; i < 5; ++i)
                    {
                        sales[i] = rand() % 100000 + 1; // Random sales between 1 and 1000
                    }
                    double publicityCosts = rand() % 50000 + 1; // Random publicity costs between 1 and 100
                    double costs = rand() % 90000 + 1;          // Random costs between 1 and 500

                    // Write data to the CSV file
                    outputFile << year << "," << month << "," << day << ","
                               << sales[0] << "," << sales[1] << "," << sales[2] << "," << sales[3] << "," << sales[4] << ","
                               << publicityCosts << "," << costs << std::endl;
                }
            }
        }
    }

    return 0;
}
