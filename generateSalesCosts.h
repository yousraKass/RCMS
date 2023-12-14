#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int currentYear = 2023;
int currentMonth = 12;

void generateSalesCosts(int startYear, int startMonth, int startDay, int ID)
{
    string filePath = to_string(ID) + "salesCosts.csv";
    ofstream outputFile(filePath);
    outputFile << "year,month,day,sales1,sales2,sales3,sales4,sales5,publicity_costs,costs" << endl;

    for (int year = startYear; year <= currentYear; ++year)
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