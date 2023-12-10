#ifndef DAILY_SALES_AND_COSTS_H
#define DAILY_SALES_AND_COSTS_H
#include <vector>
#include <iostream>
using std::vector;
using std::cout;
using std::endl;


class Sales_and_Costs{
    public:

    void GetMonthlySales(int month,int year,float &A, float &S, float &C, float &I, float &E,int startYear) const;
    float GetMonthlySalesOfRestaurant(int month,int year,int startYear)const;
    void reportOnsales(int month,int year,int startYear) const;
    void reportOnsales(int day1,int month1,int year1,int day2,int month2,int year2,int startYear) const;
    void Add_Sales_and_Costs(int year,int month,int day,float sA,float sS,float sC,float sI,float sE,float pub_Cost,float gen_Cost,int startYear);
    private:
    struct Sales_Costs
        {
            float sales[6];
            float publicity_costs;
            float general_costs;
        };

    struct Days
        {
            Sales_Costs* days[31];
            float MonthlySales[5];
        };
    struct Months
        {
            Days* months[12];
        };
    vector<Months*> Years;

}
;



// Implementation

void Sales_and_Costs::reportOnsales(int month,int year,int startYear) const{
    {
        if(year < startYear)
            return;
        else
        {
            float sum1 = 0, sum2 = 0 , sum3 = 0, sum4 = 0, sum5 = 0;
            for (int i = 0; i < 31; i++)
            {
                sum1+= Years[year-startYear]->months[month-1]->days[i]->sales[0];
                sum2+= Years[year-startYear]->months[month-1]->days[i]->sales[1];
                sum3+= Years[year-startYear]->months[month-1]->days[i]->sales[2];
                sum4+= Years[year-startYear]->months[month-1]->days[i]->sales[3];
                sum5+= Years[year-startYear]->months[month-1]->days[i]->sales[4];
            }
            cout<<"Monthly sales of the Algerian cuisine : "<<sum1<<endl;
            cout<<"Monthly sales of the Syrian cuisine : "<<sum2<<endl;
            cout<<"Monthly sales of the Chinese cuisine : "<<sum3<<endl;
            cout<<"Monthly sales of the Indian cuisine : "<<sum4<<endl;
            cout<<"Monthly sales of the Europian cuisine : "<<sum5<<endl;  
        }
    }
}

void Sales_and_Costs::reportOnsales(int day1,int month1,int year1,int day2,int month2,int year2,int startYear) const{
    {
        if(year1<startYear || year2<startYear)
            return;
        if(year1>year2)
            return;
        else
        {
            float sum1 = 0, sum2 = 0 , sum3 = 0, sum4 = 0, sum5 = 0;
            while(true)
            {
                if(year1 == year2 && month1 == month2 && day1 == day2)
                    break;
                else
                {
                    sum1+= Years[year1-startYear]->months[month1-1]->days[day1-1]->sales[0];
                    sum2+= Years[year1-startYear]->months[month1-1]->days[day1-1]->sales[1];
                    sum3+= Years[year1-startYear]->months[month1-1]->days[day1-1]->sales[2];
                    sum4+= Years[year1-startYear]->months[month1-1]->days[day1-1]->sales[3];
                    sum5+= Years[year1-startYear]->months[month1-1]->days[day1-1]->sales[4];
                }
                day1++;
                if(day1 == 32)
                    {
                        day1 = 1;
                        month1++;
                        if(month1 == 13)
                        {
                            month1 = 1;
                            year1++;
                        }
                    }
            }

            cout<<"Sales of the Algerian cuisine over the given period : "<<sum1<<endl;
            cout<<"Sales of the Syrian cuisine over the given period : "<<sum2<<endl;
            cout<<"Sales of the Chinese cuisine over the given period : "<<sum3<<endl;
            cout<<"Sales of the Indian cuisine over the given period : "<<sum4<<endl;
            cout<<"Sales of the Europian cuisine over the given period : "<<sum5<<endl; 
        }
    }
}

void Sales_and_Costs::GetMonthlySales(int month,int year,float &A, float &S, float &C, float &I, float &E,int startYear) const{
    A = Years[year-startYear]->months[month-1]->MonthlySales[0];
    S = Years[year-startYear]->months[month-1]->MonthlySales[1];
    C = Years[year-startYear]->months[month-1]->MonthlySales[2];
    I = Years[year-startYear]->months[month-1]->MonthlySales[3];
    E = Years[year-startYear]->months[month-1]->MonthlySales[4];
}


void Sales_and_Costs::Add_Sales_and_Costs(int year,int month,int day,float sA,float sS,float sC,float sI,float sE,float pub_Cost,float gen_Cost,int startYear)
{
    Years[year-startYear]->months[month-1]->days[day-1]->sales[0] = sA;
    Years[year-startYear]->months[month-1]->days[day-1]->sales[1] = sS;
    Years[year-startYear]->months[month-1]->days[day-1]->sales[2] = sC;
    Years[year-startYear]->months[month-1]->days[day-1]->sales[3] = sI;
    Years[year-startYear]->months[month-1]->days[day-1]->sales[4] = sE;
    Years[year-startYear]->months[month-1]->days[day-1]->publicity_costs = pub_Cost;
    Years[year-startYear]->months[month-1]->days[day-1]->general_costs = gen_Cost;
}


float Sales_and_Costs::GetMonthlySalesOfRestaurant(int month,int year,int startYear)const{
    return Years[year-startYear]->months[month-1]->MonthlySales[0]  +  Years[year-startYear]->months[month-1]->MonthlySales[1]  +  Years[year-startYear]->months[month-1]->MonthlySales[2]  +  Years[year-startYear]->months[month-1]->MonthlySales[3]  +  Years[year-startYear]->months[month-1]->MonthlySales[4];
}



#endif