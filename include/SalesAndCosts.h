#ifndef DAILYSALESANDCOSTS_H
#define DAILYSALESANDCOSTS_H
#include <vector>
#include <iostream>
#include <iomanip>
#include <sstream>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::setw;
using std::fixed;
using std::left;
using std::setprecision;
using std::ostringstream;

class SalesAndCosts
{
public:
    SalesAndCosts() : Years(25) {}
    // Returns values of sales of each cuisine of a restaurant in a given month of a given year
    void GetMonthlySales(int month, int year, float &A, float &S, float &C, float &I, float &E, int startYear) const;
    // Returns value of sales of the restaurant in a given month of a given year
    float GetMonthlySalesOfRestaurant(int month, int year, int startYear) const;
    // Display restaurant ratio (sales / publicity costs) in a given month of a given year
    void Ratio(int month, int year, int startYear) const;
    // Display restaurant ratio in a given period
    void Ratio(int month1, int year1, int month2, int year2, int startYear) const;
    // Display full report on sales of a restaurant in a given date
    void reportOnsales(int day, int month, int year, int startYear) const;
    // Display full report on sales of a restaurant in a given month of a given year
    void reportOnsales(int month, int year, int startYear) const;
    // Display full report on sales of a restaurant in a given period
    void reportOnsales(int day1, int month1, int year1, int day2, int month2, int year2, int startYear) const;
    // Add information about sales and costs of a restaurant to the system
    void Add_SalesAndCosts(int year, int month, int day, float sA, float sS, float sC, float sI, float sE, float rent_cost, float emp_salary_cost, float elec_cost, float gas_cost, float veg_cost, float meat_cost, float other_cost, float pub_cost, int startYear);
    //
    void GetCumulativeSales(int month, int year, float &aA, float &aS, float &aC, float &aI, float &aE, int startYear) const;
    float GetGeneralCosts(int day, int month, int year, int startYear) const;
    float GetGeneralCosts(int day1, int month1, int year1, int day2, int month2, int year2, int startYear) const;
    float GetPublicityCosts(int day, int month, int year, int startYear) const;
    float GetPublicityCosts(int day1, int month1, int year1, int day2, int month2, int year2, int startYear) const;
    float GetRentCosts(int day, int month, int year, int startYear) const;
    float GetRentCosts(int day1, int month1, int year1, int day2, int month2, int year2, int startYear) const;
    float GetEmployeesCosts(int day, int month, int year, int startYear) const;
    float GetEmployeesCosts(int day1, int month1, int year1, int day2, int month2, int year2, int startYear) const;
    float GetElectricityCosts(int day, int month, int year, int startYear) const;
    float GetElectricityCosts(int day1, int month1, int year1, int day2, int month2, int year2, int startYear) const;
    float GetGasCosts(int day, int month, int year, int startYear) const;
    float GetGasCosts(int day1, int month1, int year1, int day2, int month2, int year2, int startYear) const;
    float GetVegetablesCosts(int day, int month, int year, int startYear) const;
    float GetVegetablesCosts(int day1, int month1, int year1, int day2, int month2, int year2, int startYear) const;
    float GetMeatCosts(int day, int month, int year, int startYear) const;
    float GetMeatCosts(int day1, int month1, int year1, int day2, int month2, int year2, int startYear) const;
    float GetOtherCosts(int day, int month, int year, int startYear) const;
    float GetOtherCosts(int day1, int month1, int year1, int day2, int month2, int year2, int startYear) const;

private:
    bool isLeapYear(int year)
    {
        // Leap years occur every 4 years, except for years divisible by 100 but not divisible by 400.
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    int daysInFebruary(int year) // Returns the number of days in February of a given year
    {
        return isLeapYear(year) ? 29 : 28;
    }

    /*
    Struct contains an array of floats of size 6 to store the sales of each cuisine of the restaurant in the first five positions
    of a given date and the sixth position is the sum of sales of the five cuisines which is the same the sales of the restaurant.
    It contains also two float variables one of them to stores the publicity costs while the other stores the general costs of a
    restaurant in a given date.
    */
    struct SalesCosts
    {
        float sales[6];
        float Cost_on_rent;
        float Cost_on_employees_salary;
        float Cost_on_elec;
        float Cost_on_gas;
        float Cost_on_vegetables;
        float Cost_on_meat;
        float Cost_on_other_ingrediants;
        float publicity_costs;
        float general_costs;

        SalesCosts() : publicity_costs(0), general_costs(0), Cost_on_rent(0), Cost_on_employees_salary(0), Cost_on_elec(0), Cost_on_gas(0), Cost_on_vegetables(0), Cost_on_meat(0), Cost_on_other_ingrediants(0)
        {
            for (int i = 0; i < 6; i++)
            {
                sales[i] = 0;
            }
        }
    };

    struct Days
    {
        SalesCosts days[31];
        float MonthlySales[6];
        float CumulativeSales[5];
        Days()
        {
            for (int i = 0; i < 6; i++)
            {
                MonthlySales[i] = 0;
            }
        }
    };
    struct Months
    {
        Days months[12];
    };
    vector<Months> Years;
    // Private data member represnets a vector called years each year has an array of size 12 to represents months, this array (months) is an array of struct called Days contains array (Montly sales)
    // stores the values of monthly sales of each cuisine + monthly sales of the restaurant in the last position (the sum), also, it stores an array of size 31 of days, each day stores the information of the restaurant found in the struct up
};


#endif
