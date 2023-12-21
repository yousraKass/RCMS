#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

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
