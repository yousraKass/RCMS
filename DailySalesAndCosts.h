#ifndef DAILY_SALES_AND_COSTS_H
#define DAILY_SALES_AND_COSTS_H
#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;

class Sales_and_Costs
{
public:
    void GetMonthlySales(int month, int year, float &A, float &S, float &C, float &I, float &E, int startYear) const;
    float GetMonthlySalesOfRestaurant(int month, int year, int startYear)const;
    void Ratio(int month,int year,int startYear)const;
    void Ratio(int month1,int year1,int month2,int year2,int startYear)const;
    void reportOnsales(int day, int month, int year, int startYear) const;
    void reportOnsales(int month, int year, int startYear) const;
    void reportOnsales(int day1, int month1, int year1, int day2, int month2, int year2, int startYear) const;
    void Add_Sales_and_Costs(int year, int month, int day, float sA, float sS, float sC, float sI, float sE, float pub_Cost, float gen_Cost, int startYear);

private:
    bool isLeapYear(int year) { 
    // Leap years occur every 4 years, except for years divisible by 100 but not divisible by 400. 
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0); 
    } 
 
int daysInFebruary(int year) { 
    return isLeapYear(year) ? 29 : 28; 
}
    struct Sales_Costs
    {
        float sales[6];
        float publicity_costs;
        float general_costs;
        Sales_Costs():publicity_costs(0),general_costs(0){
            for(int i=0 ; i<6 ; i++)
            {
                sales[i] = 0;
            }
        }
    };

    struct Days
    {
        Sales_Costs days[31];
        float MonthlySales[6];
        Days(){
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
};

// Implementation

void Sales_and_Costs::reportOnsales(int day, int month, int year, int startYear)const
{
    cout <<"Sales of the Algerian cuisine in " << day << "/" << month << "/" << year << " : "<< Years[year - startYear].months[month - 1].days[day - 1].sales[0]<<endl;
    cout <<"Sales of the Syrian cuisine in " << day << "/" << month << "/" << year << " : " << Years[year - startYear].months[month - 1].days[day - 1].sales[1]<<endl;
    cout <<"Sales of the Chinese cuisine in " <<  day << "/" << month << "/" << year << " : " << Years[year - startYear].months[month - 1].days[day - 1].sales[2]<<endl;
    cout <<"Sales of the Indian cuisine in " <<  day << "/" << month << "/" << year << " : " << Years[year - startYear].months[month - 1].days[day - 1].sales[3]<<endl;
    cout <<"Sales of the Europian cuisine in " <<  day << "/" << month << "/" << year << " : " <<Years[year - startYear].months[month - 1].days[day - 1].sales[4]<<endl;
    cout <<"Sales of the Restaurant in " <<  day << "/" << month << "/" << year << " : " << Years[year - startYear].months[month - 1].days[day - 1].sales[5]<<endl;
}

void Sales_and_Costs::reportOnsales(int month, int year, int startYear) const
{
    {
        if (year < startYear)
            return;
        if(month <1 || month >12)
            return;
        
        else
        {
            float A, S, C, I, E;
            GetMonthlySales( month,  year, A, S, C, I,E,  startYear);  
            //we have to discuss it cuz the report may display detailed results like for everyday for now let it like this
            cout << "Monthly sales of the Algerian cuisine : " << A << endl;
            cout << "Monthly sales of the Syrian cuisine : " << S << endl;
            cout << "Monthly sales of the Chinese cuisine : " << C << endl;
            cout << "Monthly sales of the Indian cuisine : " << I << endl;
            cout << "Monthly sales of the Europian cuisine : " << E << endl;
            cout << "Monthly sales of the Restaurant : " <<Years[year - startYear].months[month - 1].MonthlySales[5]<< endl;
        }
    }
}

void Sales_and_Costs::reportOnsales(int day1, int month1, int year1, int day2, int month2, int year2, int startYear) const
{
    {
        if (year1 < startYear || year2 < startYear)
            return;
        if (year1 > year2)
            return;
        else
        {
            while (true)
            {
                if (year1 == year2 && month1 == month2 && day1 == day2){
                    break;
                }
                    
                else{
                    reportOnsales(day1,month1,year1,startYear);
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
                //please update it ; add a function reportonsales(day,month,year) so that you can call here
                //pls make sure of validations  
            }
        }
    }
}
}

void Sales_and_Costs::Ratio(int month,int year, int startYear)const
{
    int pubMcost = 0;
    for(int i = 0; i<31 ; i++)
    {
        pubMcost+=Years[year - startYear].months[month - 1].days[i].publicity_costs;
    }
    cout<<"The ratio of month "<<month<<" of the year "<<year<<" : "<<Years[year - startYear].months[month - 1].MonthlySales[5] / pubMcost<<endl;
}

void Sales_and_Costs::Ratio(int month1,int year1,int month2,int year2,int startYear)const
{
    while(true)
    {
        if (month1 == month2 && year1 == year2)
            break;
        Ratio(month1,year1,startYear);
        month1++;
        if(month1 == 13)
            {
                month1 = 1;
                year1++;
            }
    }
    
}

void Sales_and_Costs::GetMonthlySales(int month, int year, float &A, float &S, float &C, float &I, float &E, int startYear) const
{
    A = Years[year - startYear].months[month - 1].MonthlySales[0];
    S = Years[year - startYear].months[month - 1].MonthlySales[1];
    C = Years[year - startYear].months[month - 1].MonthlySales[2];
    I = Years[year - startYear].months[month - 1].MonthlySales[3];
    E = Years[year - startYear].months[month - 1].MonthlySales[4];
}

void Sales_and_Costs::Add_Sales_and_Costs(int year, int month, int day, float sA, float sS, float sC, float sI, float sE, float pub_Cost, float gen_Cost, int startYear)
{
    Years[year - startYear].months[month - 1].days[day - 1].sales[0] = sA;
    Years[year - startYear].months[month - 1].days[day - 1].sales[1] = sS;
    Years[year - startYear].months[month - 1].days[day - 1].sales[2] = sC;
    Years[year - startYear].months[month - 1].days[day - 1].sales[3] = sI;
    Years[year - startYear].months[month - 1].days[day - 1].sales[4] = sE;
    Years[year - startYear].months[month - 1].days[day - 1].sales[5] = sA + sS + sC + sI + sE;
    Years[year - startYear].months[month - 1].days[day - 1].publicity_costs = pub_Cost;
    Years[year - startYear].months[month - 1].days[day - 1].general_costs = gen_Cost;
    if( (month == 4 || month == 6 || month == 9 || month == 11 ) && day == 30)
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
    else if(month == 2 && daysInFebruary(year) == day)
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
}

float Sales_and_Costs::GetMonthlySalesOfRestaurant(int month, int year, int startYear) const
{
    return Years[year - startYear].months[month - 1].MonthlySales[5];
}

#endif
