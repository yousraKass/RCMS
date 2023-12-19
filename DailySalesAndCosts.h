#ifndef DAILY_SALESANDCOSTS_H
#define DAILY_SALESANDCOSTS_H
#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;

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
    void Add_SalesAndCosts(int year, int month, int day, float sA, float sS, float sC, float sI, float sE, float pub_Cost, float gen_Cost, int startYear);
    //
    void GetCumulativeSales(int month, int year, float &aA, float &aS, float &aC, float &aI, float &aE, int startYear) const;
    
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
        float publicity_costs;
        float general_costs;
        SalesCosts() : publicity_costs(0), general_costs(0)
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


// Implementation

void SalesAndCosts::reportOnsales(int day, int month, int year, int startYear) const
{
    if (year < startYear)
        return;
    if (month < 1 || month > 12)
        return;
    if((month == 4 || month == 6 || month == 9 || month == 11) && (day > 30 || day <1 ))
        return;
    else if(month == 2 && year%4 == 0 && (day > 29 || day <1 ))
        return;
    else if(month == 2 && (day > 28 || day <1 ))
        return;
    else if((day > 31 || day <1 ))
        return;

    cout<<"-----------------------Report on sales in : "<<day<<"/"<<month<<"/"<<year<<" : ------------------------------"<<endl;
    cout<<"------------------------------------------------------------------------------------------------"<<endl;
   
    cout << "-Sales of the Algerian cuisine : " << Years[year - startYear].months[month - 1].days[day - 1].sales[0] << " DA " << endl;
    cout << "-Sales of the Syrian cuisine : " << Years[year - startYear].months[month - 1].days[day - 1].sales[1] << " DA " << endl;
    cout << "-Sales of the Chinese cuisine : " << Years[year - startYear].months[month - 1].days[day - 1].sales[2] << " DA " << endl;
    cout << "-Sales of the Indian cuisine : " << Years[year - startYear].months[month - 1].days[day - 1].sales[3] << " DA " << endl;
    cout << "-Sales of the Europian cuisine : " << Years[year - startYear].months[month - 1].days[day - 1].sales[4] << " DA " << endl;
    cout << "Total : " << Years[year - startYear].months[month - 1].days[day - 1].sales[5] << " DA " << endl;
    cout <<"------------------------------------------------------------------------------------------------"<<endl<<endl;
}

void SalesAndCosts::reportOnsales(int month, int year, int startYear) const
{
    {
        if (year < startYear)
            return;
        if (month < 1 || month > 12)
            return;
        else
        {
            float A, S, C, I, E;
            GetMonthlySales(month, year, A, S, C, I, E, startYear);
            cout<<"-----------------------Report on sales on : "<<month<<"/"<<year<<" : ------------------------------"<<endl;
            cout<<"---------------------------------------------------------------------------------------------------"<<endl;
            cout << "-Monthly sales of the Algerian cuisine : " << A <<  " DA " << endl;
            cout << "-Monthly sales of the Syrian cuisine : " << S <<  " DA " << endl;
            cout << "-Monthly sales of the Chinese cuisine : " << C << " DA " <<  endl;
            cout << "-Monthly sales of the Indian cuisine : " << I <<  " DA " << endl;
            cout << "-Monthly sales of the Europian cuisine : " << E <<  " DA " << endl;
            cout << "-Total : " << Years[year - startYear].months[month - 1].MonthlySales[5] << " DA " <<  endl;
        }
    }
}

void SalesAndCosts::reportOnsales(int day1, int month1, int year1, int day2, int month2, int year2, int startYear) const
{
    {
        if (year1 < startYear || year2 < startYear)
            return;
        if (year1 > year2)
            return;
        if (year1 == year2 && month1>month2)
            return;
        if (year1 == year2 && month1 == month2 && day1>day2)
            return;
        if (year1 == year2 && month1 == month2 && day1 == day2)
            reportOnsales(day1, month1, year1, startYear);
        else
        {
            while (true)
            {
                if (year1 == year2 && month1 == month2 && day1 == day2)
                {
                    break;
                }

                else
                {
                    reportOnsales(day1, month1, year1, startYear);
                    day1++;
                    if (day1 == 32)
                    {
                        day1 = 1;
                        month1++;
                        if (month1 == 13)
                        {
                            month1 = 1;
                            year1++;
                        }
                    }
                }
            }
            reportOnsales(day1, month1, year1, startYear);
        }
    }
}

void SalesAndCosts::Ratio(int month, int year, int startYear) const
{
    if (year < startYear)
        return;
    if (month < 1 || month > 12)
        return;
    int pubMcost = 0;
    for (int i = 0; i < 31; i++)
    {
        pubMcost += Years[year - startYear].months[month - 1].days[i].publicity_costs;
    }
    cout <<" The  monthly ratio on "<< month << "/" << year  << " is  : " << Years[year - startYear].months[month - 1].MonthlySales[5] / pubMcost << endl;
}

void SalesAndCosts::Ratio(int month1, int year1, int month2, int year2, int startYear) const
{
    if (year1 < startYear || year2 < startYear)
            return;
        if (year1 > year2)
            return;
        if (year1 == year2 && month1>month2)
            return;
        if (year1 == year2 && month1 == month2)
            Ratio(month1,year1,startYear);
        else{
            while (month1<=month2 && year1<=year2)
        {
            Ratio(month1, year1, startYear);
            month1++;
            if (month1 == 13)
                {
                    month1 = 1;
                    year1++;
                }
        }
        }
    
}

void SalesAndCosts::GetMonthlySales(int month, int year, float &A, float &S, float &C, float &I, float &E, int startYear) const
{
    if (year < startYear)
        return;
    if (month < 1 || month > 12)
        return;
    A = Years[year - startYear].months[month - 1].MonthlySales[0];
    S = Years[year - startYear].months[month - 1].MonthlySales[1];
    C = Years[year - startYear].months[month - 1].MonthlySales[2];
    I = Years[year - startYear].months[month - 1].MonthlySales[3];
    E = Years[year - startYear].months[month - 1].MonthlySales[4];
}

void SalesAndCosts::Add_SalesAndCosts(int year, int month, int day, float sA, float sS, float sC, float sI, float sE, float pub_Cost, float gen_Cost, int startYear)
{
    if(year -startYear >= Years.size())
        Years.resize(Years.size()*2);
    
    if( sA < 0 || sS < 0 || sC < 0 || sI < 0 || sE < 0 || pub_Cost < 0 || gen_Cost < 0)
    {
        cout<<"Invalid input."<<endl;
        return;
    }
    Years[year - startYear].months[month - 1].days[day - 1].sales[0] = sA;
    Years[year - startYear].months[month - 1].days[day - 1].sales[1] = sS;
    Years[year - startYear].months[month - 1].days[day - 1].sales[2] = sC;
    Years[year - startYear].months[month - 1].days[day - 1].sales[3] = sI;
    Years[year - startYear].months[month - 1].days[day - 1].sales[4] = sE;
    Years[year - startYear].months[month - 1].days[day - 1].sales[5] = sA + sS + sC + sI + sE;
    Years[year - startYear].months[month - 1].days[day - 1].publicity_costs = pub_Cost;
    Years[year - startYear].months[month - 1].days[day - 1].general_costs = gen_Cost;
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day == 30)
    {
        float sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0;

        for (int i = 0; i < day; i++)
        {
            sum1 += Years[year - startYear].months[month - 1].days[i].sales[0];
            sum2 += Years[year - startYear].months[month - 1].days[i].sales[1];
            sum3 += Years[year - startYear].months[month - 1].days[i].sales[2];
            sum4 += Years[year - startYear].months[month - 1].days[i].sales[3];
            sum5 += Years[year - startYear].months[month - 1].days[i].sales[4];
        }
        Years[year - startYear].months[month - 1].MonthlySales[0] = sum1;
        Years[year - startYear].months[month - 1].MonthlySales[1] = sum2;
        Years[year - startYear].months[month - 1].MonthlySales[2] = sum3;
        Years[year - startYear].months[month - 1].MonthlySales[3] = sum4;
        Years[year - startYear].months[month - 1].MonthlySales[4] = sum5;
        Years[year - startYear].months[month - 1].MonthlySales[5] = sum1 + sum2 + sum3 + sum4 + sum5;
    }
    else if (month == 2 && daysInFebruary(year) == day)
    {
        float sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0;

        for (int i = 0; i < day; i++)
        {
            sum1 += Years[year - startYear].months[month - 1].days[i].sales[0];
            sum2 += Years[year - startYear].months[month - 1].days[i].sales[1];
            sum3 += Years[year - startYear].months[month - 1].days[i].sales[2];
            sum4 += Years[year - startYear].months[month - 1].days[i].sales[3];
            sum5 += Years[year - startYear].months[month - 1].days[i].sales[4];
        }
        Years[year - startYear].months[month - 1].MonthlySales[0] = sum1;
        Years[year - startYear].months[month - 1].MonthlySales[1] = sum2;
        Years[year - startYear].months[month - 1].MonthlySales[2] = sum3;
        Years[year - startYear].months[month - 1].MonthlySales[3] = sum4;
        Years[year - startYear].months[month - 1].MonthlySales[4] = sum5;
        Years[year - startYear].months[month - 1].MonthlySales[5] = sum1 + sum2 + sum3 + sum4 + sum5;
    }
    else if (day == 31)
    {
        float sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0;

        for (int i = 0; i < 31; i++)
        {
            sum1 += Years[year - startYear].months[month - 1].days[i].sales[0];
            sum2 += Years[year - startYear].months[month - 1].days[i].sales[1];
            sum3 += Years[year - startYear].months[month - 1].days[i].sales[2];
            sum4 += Years[year - startYear].months[month - 1].days[i].sales[3];
            sum5 += Years[year - startYear].months[month - 1].days[i].sales[4];
        }
        Years[year - startYear].months[month - 1].MonthlySales[0] = sum1;
        Years[year - startYear].months[month - 1].MonthlySales[1] = sum2;
        Years[year - startYear].months[month - 1].MonthlySales[2] = sum3;
        Years[year - startYear].months[month - 1].MonthlySales[3] = sum4;
        Years[year - startYear].months[month - 1].MonthlySales[4] = sum5;
        Years[year - startYear].months[month - 1].MonthlySales[5] = sum1 + sum2 + sum3 + sum4 + sum5;
    }

    if (year == startYear && month == 1)
    {
        Years[0].months[month - 1].CumulativeSales[0] = Years[year - startYear].months[month - 1].MonthlySales[0];
        Years[0].months[month - 1].CumulativeSales[1] = Years[year - startYear].months[month - 1].MonthlySales[1];
        Years[0].months[month - 1].CumulativeSales[2] = Years[year - startYear].months[month - 1].MonthlySales[2];
        Years[0].months[month - 1].CumulativeSales[3] = Years[year - startYear].months[month - 1].MonthlySales[3];
        Years[0].months[month - 1].CumulativeSales[4] = Years[year - startYear].months[month - 1].MonthlySales[4];
    }

    else if (month == 1)
    {
        Years[year - startYear].months[month - 1].CumulativeSales[0] = Years[year - startYear].months[month - 1].MonthlySales[0];
        Years[year - startYear].months[month - 1].CumulativeSales[1] = Years[year - startYear].months[month - 1].MonthlySales[1];
        Years[year - startYear].months[month - 1].CumulativeSales[2] = Years[year - startYear].months[month - 1].MonthlySales[2];
        Years[year - startYear].months[month - 1].CumulativeSales[3] = Years[year - startYear].months[month - 1].MonthlySales[3];
        Years[year - startYear].months[month - 1].CumulativeSales[4] = Years[year - startYear].months[month - 1].MonthlySales[4];
    }
    else
    {
        Years[year - startYear].months[month - 1].CumulativeSales[0] = Years[year - startYear].months[month - 2].CumulativeSales[0] + Years[year - startYear].months[month - 1].MonthlySales[0];
        Years[year - startYear].months[month - 1].CumulativeSales[1] = Years[year - startYear].months[month - 2].CumulativeSales[1] + Years[year - startYear].months[month - 1].MonthlySales[1];
        Years[year - startYear].months[month - 1].CumulativeSales[2] = Years[year - startYear].months[month - 2].CumulativeSales[2] + Years[year - startYear].months[month - 1].MonthlySales[2];
        Years[year - startYear].months[month - 1].CumulativeSales[3] = Years[year - startYear].months[month - 2].CumulativeSales[3] + Years[year - startYear].months[month - 1].MonthlySales[3];
        Years[year - startYear].months[month - 1].CumulativeSales[4] = Years[year - startYear].months[month - 2].CumulativeSales[4] + Years[year - startYear].months[month - 1].MonthlySales[4];
    }
}

float SalesAndCosts::GetMonthlySalesOfRestaurant(int month, int year, int startYear) const
{
    if (year < startYear)
        return -1;
    if (month < 1 || month > 12)
        return -1;
    return Years[year - startYear].months[month - 1].MonthlySales[5];
}

void SalesAndCosts::GetCumulativeSales(int month, int year, float &aA, float &aS, float &aC, float &aI, float &aE, int startYear) const
{
    if (year < startYear)
        return;
    aA = Years[year - startYear].months[month - 1].CumulativeSales[0];
    aS = Years[year - startYear].months[month - 1].CumulativeSales[1];
    aC = Years[year - startYear].months[month - 1].CumulativeSales[2];
    aI = Years[year - startYear].months[month - 1].CumulativeSales[3];
    aE = Years[year - startYear].months[month - 1].CumulativeSales[4];
}


#endif
