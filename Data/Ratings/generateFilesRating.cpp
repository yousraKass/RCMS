#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

void extractTokens(const string &line, string &firstToken, int &year, int &month)
{
    stringstream ss(line);

    std::getline(ss, firstToken, ',');
    std::string temp;
    std::getline(ss, temp, ',');
    std::getline(ss, temp, ',');

    std::string dateToken;
    std::getline(ss, dateToken, ',');

    // Parse the full date "yyyy-mm-dd"
    istringstream dateSS(dateToken);
    string yearStr, monthStr, dayStr;
   
    getline(dateSS, yearStr, '-');
    getline(dateSS, monthStr, '-');
    getline(dateSS, dayStr, '-');

    year = stoi(yearStr);
    month = stoi(monthStr);
}

void generateRandomRatings(const std::string &fileName, int startYear, int startMonth)
{
    std::ofstream csvFile(fileName);

    // Write header
    csvFile << "rating1,rating2,rating3,rating4,rating5,month,year" << std::endl;

    srand(static_cast<unsigned>(std::time(0)));

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

int main()
{
    ifstream inputFile("./RESTAURANT1.csv");
    string ID;
    int startYear, startMonth;
    std::string line;
    while (getline(inputFile, line))
    {
        extractTokens(line, ID, startYear, startMonth);

        string filePath = ID + "ratings.csv";

        // Generate random ratings for each month
        generateRandomRatings(filePath, startYear, startMonth);
    }

    return 0;
}
