#include "SalesAndCosts.h"

// Implementation

void SalesAndCosts::reportOnsales(int day, int month, int year, int startYear) const
{
    if (year < startYear)
        return;
    if (month < 1 || month > 12)
        return;
    if ((month == 4 || month == 6 || month == 9 || month == 11) && (day > 30 || day < 1))
        return;
    else if (month == 2 && year % 4 == 0 && (day > 29 || day < 1))
        return;
    else if (month == 2 && (day > 28 || day < 1))
        return;
    else if ((day > 31 || day < 1))
        return;

    cout << "------------------------------- Report on sales and costs in : " << day << "/" << month << "/" << year << " : -------------------------------------" << endl;
    cout << "---------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "Sales : " << endl;
    cout << "-------" << endl;
    ostringstream stream1, stream2, stream3, stream4, stream5, stream6;
    stream1 << fixed << setprecision(2) << Years[year - startYear].months[month - 1].days[day - 1].sales[0];
    string s1 = stream1.str();
    stream2 << fixed << setprecision(2) << Years[year - startYear].months[month - 1].days[day - 1].sales[1];
    string s2 = stream2.str();
    stream3 << fixed << setprecision(2) << Years[year - startYear].months[month - 1].days[day - 1].sales[2];
    string s3 = stream3.str();
    stream4 << fixed << setprecision(2) << Years[year - startYear].months[month - 1].days[day - 1].sales[3];
    string s4 = stream4.str();
    stream5 << fixed << setprecision(2) << Years[year - startYear].months[month - 1].days[day - 1].sales[4];
    string s5 = stream5.str();
    stream6 << fixed << setprecision(2) << Years[year - startYear].months[month - 1].days[day - 1].sales[5];
    string s6 = stream6.str();
    cout << setw(20) << left << "Algerian"
         << setw(20) << left << "Syrian"
         << setw(20) << left << "Chinese"
         << setw(20) << left << "Indian"
         << setw(20) << left << "Europian"
         << setw(20) << left << "Total" << endl;

    cout << setw(20) << left << s1 + " DA "
         << setw(20) << left << s2 + " DA "
         << setw(20) << left << s3 + " DA "
         << setw(20) << left << s4 + " DA "
         << setw(20) << left << s5 + " DA "
         << setw(20) << left << s6 + " DA " << endl;
    cout << endl;
    cout << "Costs : " << endl;
    cout << "-------" << endl;
    ostringstream Stream1, Stream2, Stream3, Stream4, Stream5, Stream6, Stream7, Stream8, Stream9;
    Stream1 << fixed << setprecision(2) << Years[year - startYear].months[month - 1].days[day - 1].Cost_on_rent;
    string S1 = Stream1.str();
    Stream2 << fixed << setprecision(2) << Years[year - startYear].months[month - 1].days[day - 1].Cost_on_employees_salary;
    string S2 = Stream2.str();
    Stream3 << fixed << setprecision(2) << Years[year - startYear].months[month - 1].days[day - 1].Cost_on_elec;
    string S3 = Stream3.str();
    Stream4 << fixed << setprecision(2) << Years[year - startYear].months[month - 1].days[day - 1].Cost_on_gas;
    string S4 = Stream4.str();
    Stream5 << fixed << setprecision(2) << Years[year - startYear].months[month - 1].days[day - 1].Cost_on_vegetables;
    string S5 = Stream5.str();
    Stream6 << fixed << setprecision(2) << Years[year - startYear].months[month - 1].days[day - 1].Cost_on_meat;
    string S6 = Stream6.str();
    Stream7 << fixed << setprecision(2) << Years[year - startYear].months[month - 1].days[day - 1].Cost_on_other_ingrediants;
    string S7 = Stream7.str();
    Stream8 << fixed << setprecision(2) << Years[year - startYear].months[month - 1].days[day - 1].publicity_costs;
    string S8 = Stream8.str();
    Stream9 << fixed << setprecision(2) << Years[year - startYear].months[month - 1].days[day - 1].general_costs;
    string S9 = Stream9.str();
    cout << setw(18) << left << "Rent"
         << setw(23) << left << "Employees salary"
         << setw(23) << left << "Electricity"
         << setw(18) << left << "Gas" << endl;

    cout << setw(18) << left << S1 + " DA "
         << setw(23) << left << S2 + " DA "
         << setw(23) << left << S3 + " DA "
         << setw(18) << left << S4 + " DA " << endl;
    cout << endl;
    cout << setw(18) << left << "Vegetables"
         << setw(23) << left << "Meat"
         << setw(23) << left << "Other ingrediants"
         << setw(18) << left << "Publicity"
         << setw(20) << left << "Total" << endl;

    cout << setw(18) << left << S5 + " DA "
         << setw(23) << left << S6 + " DA "
         << setw(23) << left << S7 + " DA "
         << setw(18) << left << S8 + " DA "
         << setw(20) << left << S9 + " DA " << endl;
    cout << endl;
    float difference = Years[year - startYear].months[month - 1].days[day - 1].sales[5] - GetGeneralCosts(day, month, year, startYear);
    cout << "-The difference between sales and costs : " << difference << " DA " << endl;
}

void SalesAndCosts::reportOnsales(int month, int year, int startYear) const
{
  
    if (year < startYear)
    {
        
      
        return;
    }
    if (month < 1 || month > 12)
    {
        
        return;
    }
    else
    {
          
        cout << "--------------------------- Monthly report on sales and costs in : " << month << "/" << year << " : -----------------------------------------" << endl;
        cout << "------------------------------------------------------------------------------" << endl;
        cout << endl;
        cout << "Sales : " << endl;
        cout << "-------" << endl;
        ostringstream stream1, stream2, stream3, stream4, stream5, stream6;
        stream1 << fixed << setprecision(2) << Years[year - startYear].months[month - 1].MonthlySales[0];
        string s1 = stream1.str();
        stream2 << fixed << setprecision(2) << Years[year - startYear].months[month - 1].MonthlySales[1];
        string s2 = stream2.str();
        stream3 << fixed << setprecision(2) << Years[year - startYear].months[month - 1].MonthlySales[2];
        string s3 = stream3.str();
        stream4 << fixed << setprecision(2) << Years[year - startYear].months[month - 1].MonthlySales[3];
        string s4 = stream4.str();
        stream5 << fixed << setprecision(2) << Years[year - startYear].months[month - 1].MonthlySales[4];
        string s5 = stream5.str();
        stream6 << fixed << setprecision(2) << Years[year - startYear].months[month - 1].MonthlySales[5];
        string s6 = stream6.str();

        cout << setw(20) << left << "Algerian"
             << setw(20) << left << "Syrian"
             << setw(20) << left << "Chinese"
             << setw(20) << left << "Indian"
             << setw(20) << left << "Europian"
             << setw(20) << left << "Total" << endl;

        cout << setw(20) << left << s1 + " DA "
             << setw(20) << left << s2 + " DA "
             << setw(20) << left << s3 + " DA "
             << setw(20) << left << s4 + " DA "
             << setw(20) << left << s5 + " DA "
             << setw(20) << left << s6 + " DA " << endl;
        cout << endl;
        cout << "Costs : " << endl;
        cout << "-------" << endl;
        if (month + 1 < 13)
        {
            ostringstream Stream1, Stream2, Stream3, Stream4, Stream5, Stream6, Stream7, Stream8, Stream9;
            Stream1 << fixed << setprecision(2) << GetRentCosts(1, month, year, 1, month + 1, year, startYear) - GetRentCosts(1, month + 1, year, startYear);
            string S1 = Stream1.str();
            Stream2 << fixed << setprecision(2) << GetEmployeesCosts(1, month, year, 1, month + 1, year, startYear) - GetEmployeesCosts(1, month + 1, year, startYear);
            string S2 = Stream2.str();
            Stream3 << fixed << setprecision(2) << GetElectricityCosts(1, month, year, 1, month + 1, year, startYear) - GetElectricityCosts(1, month + 1, year, startYear);
            string S3 = Stream3.str();
            Stream4 << fixed << setprecision(2) << GetGasCosts(1, month, year, 1, month + 1, year, startYear) - GetGasCosts(1, month + 1, year, startYear);
            string S4 = Stream4.str();
            Stream5 << fixed << setprecision(2) << GetVegetablesCosts(1, month, year, 1, month + 1, year, startYear) - GetVegetablesCosts(1, month + 1, year, startYear);
            string S5 = Stream5.str();
            Stream6 << fixed << setprecision(2) << GetMeatCosts(1, month, year, 1, month + 1, year, startYear) - GetMeatCosts(1, month + 1, year, startYear);
            string S6 = Stream6.str();
            Stream7 << fixed << setprecision(2) << GetOtherCosts(1, month, year, 1, month + 1, year, startYear) - GetOtherCosts(1, month + 1, year, startYear);
            string S7 = Stream7.str();
            Stream8 << fixed << setprecision(2) << GetPublicityCosts(1, month, year, 1, month + 1, year, startYear) - GetPublicityCosts(1, month + 1, year, startYear);
            string S8 = Stream8.str();
            Stream9 << fixed << setprecision(2) << GetGeneralCosts(1, month, year, 1, month + 1, year, startYear) - GetGeneralCosts(1, month + 1, year, startYear);
            string S9 = Stream9.str();
            cout << setw(18) << left << "Rent"
                 << setw(23) << left << "Employees salary"
                 << setw(23) << left << "Electricity"
                 << setw(18) << left << "Gas" << endl;

            cout << setw(18) << left << S1 + " DA "
                 << setw(23) << left << S2 + " DA "
                 << setw(23) << left << S3 + " DA "
                 << setw(18) << left << S4 + " DA " << endl;
            cout << endl;
            cout << setw(18) << left << "Vegetables"
                 << setw(23) << left << "Meat"
                 << setw(23) << left << "Other ingrediants"
                 << setw(18) << left << "Publicity"
                 << setw(20) << left << "Total" << endl;

            cout << setw(18) << left << S5 + " DA "
                 << setw(23) << left << S6 + " DA "
                 << setw(23) << left << S7 + " DA "
                 << setw(18) << left << S8 + " DA "
                 << setw(20) << left << S9 + " DA " << endl;
            cout << endl;

            float difference = Years[year - startYear].months[month - 1].MonthlySales[5] - (GetGeneralCosts(1, month, year, 1, month + 1, year, startYear) - GetGeneralCosts(1, month + 1, year, startYear));
            cout << "-The difference between sales and costs : " << difference << " DA " << endl;
        }
        else if (month + 1 == 13)
        {
            ostringstream Stream1, Stream2, Stream3, Stream4, Stream5, Stream6, Stream7, Stream8, Stream9;
            Stream1 << fixed << setprecision(2) << GetRentCosts(1, month, year, 1, 1, year + 1, startYear) - GetRentCosts(1, 1, year + 1, startYear);
            string S1 = Stream1.str();
            Stream2 << fixed << setprecision(2) << GetEmployeesCosts(1, month, year, 1, 1, year + 1, startYear) - GetEmployeesCosts(1, 1, year + 1, startYear);
            string S2 = Stream2.str();
            Stream3 << fixed << setprecision(2) << GetElectricityCosts(1, month, year, 1, 1, year + 1, startYear) - GetElectricityCosts(1, 1, year + 1, startYear);
            string S3 = Stream3.str();
            Stream4 << fixed << setprecision(2) << GetGasCosts(1, month, year, 1, 1, year + 1, startYear) - GetGasCosts(1, 1, year + 1, startYear);
            string S4 = Stream4.str();
            Stream5 << fixed << setprecision(2) << GetVegetablesCosts(1, month, year, 1, 1, year + 1, startYear) - GetVegetablesCosts(1, 1, year + 1, startYear);
            string S5 = Stream5.str();
            Stream6 << fixed << setprecision(2) << GetMeatCosts(1, month, year, 1, 1, year + 1, startYear) - GetMeatCosts(1, 1, year + 1, startYear);
            string S6 = Stream6.str();
            Stream7 << fixed << setprecision(2) << GetOtherCosts(1, month, year, 1, 1, year + 1, startYear) - GetOtherCosts(1, 1, year + 1, startYear);
            string S7 = Stream7.str();
            Stream8 << fixed << setprecision(2) << GetPublicityCosts(1, month, year, 1, 1, year + 1, startYear) - GetPublicityCosts(1, 1, year + 1, startYear);
            string S8 = Stream8.str();
            Stream9 << fixed << setprecision(2) << GetGeneralCosts(1, month, year, 1, 1, year + 1, startYear) - GetGeneralCosts(1, 1, year + 1, startYear);
            string S9 = Stream9.str();

            cout << setw(18) << left << "Rent"
                 << setw(23) << left << "Employees salary"
                 << setw(23) << left << "Electricity"
                 << setw(18) << left << "Gas" << endl;

            cout << setw(18) << left << S1 + " DA "
                 << setw(23) << left << S2 + " DA "
                 << setw(23) << left << S3 + " DA "
                 << setw(18) << left << S4 + " DA " << endl;
            cout << endl;
            cout << setw(18) << left << "Vegetables"
                 << setw(23) << left << "Meat"
                 << setw(23) << left << "Other ingrediants"
                 << setw(18) << left << "Publicity"
                 << setw(20) << left << "Total" << endl;

            cout << setw(18) << left << S5 + " DA "
                 << setw(23) << left << S6 + " DA "
                 << setw(23) << left << S7 + " DA "
                 << setw(18) << left << S8 + " DA "
                 << setw(20) << left << S9 + " DA " << endl;
            cout << endl;

            float difference = Years[year - startYear].months[month - 1].MonthlySales[5] - (GetGeneralCosts(1, month, year, 1, 1, year + 1, startYear) - GetGeneralCosts(1, 1, year + 1, startYear));
            cout << "-The difference between sales and costs : " << difference << " DA " << endl;
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
        if (year1 == year2 && month1 > month2)
            return;
        if (year1 == year2 && month1 == month2 && day1 > day2)
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
    cout << " The  monthly ratio on " << month << "/" << year << " is  : " << Years[year - startYear].months[month - 1].MonthlySales[5] / pubMcost << endl;
}

void SalesAndCosts::Ratio(int month1, int year1, int month2, int year2, int startYear) const
{
    if (year1 < startYear || year2 < startYear)
        return;
    if (year1 > year2)
        return;
    if (year1 == year2 && month1 > month2)
        return;
    if (year1 == year2 && month1 == month2)
        Ratio(month1, year1, startYear);
    else
    {
        while (true)
        {
            if (month1 == month2 && year1 == year2)
                break;
            Ratio(month1, year1, startYear);
            month1++;
            if (month1 == 13)
            {
                month1 = 1;
                year1++;
            }
        }
        Ratio(month1, year1, startYear);
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

void SalesAndCosts::Add_SalesAndCosts(int year, int month, int day, float sA, float sS, float sC, float sI, float sE, float rent_cost, float emp_salary_cost, float elec_cost, float gas_cost, float veg_cost, float meat_cost, float other_cost, float pub_cost, int startYear)
{
    if (year - startYear >= Years.size())
        Years.resize(Years.size() * 2);

    if (sA < 0 || sS < 0 || sC < 0 || sI < 0 || sE < 0 || pub_cost < 0 || rent_cost < 0 || emp_salary_cost < 0 || elec_cost < 0 || gas_cost < 0 || veg_cost < 0 || meat_cost < 0 || other_cost < 0)
    {
        cout << "Invalid input." << endl;
        return;
    }
    Years[year - startYear].months[month - 1].days[day - 1].sales[0] = sA;
    Years[year - startYear].months[month - 1].days[day - 1].sales[1] = sS;
    Years[year - startYear].months[month - 1].days[day - 1].sales[2] = sC;
    Years[year - startYear].months[month - 1].days[day - 1].sales[3] = sI;
    Years[year - startYear].months[month - 1].days[day - 1].sales[4] = sE;
    Years[year - startYear].months[month - 1].days[day - 1].sales[5] = sA + sS + sC + sI + sE;
    Years[year - startYear].months[month - 1].days[day - 1].publicity_costs = pub_cost;
    Years[year - startYear].months[month - 1].days[day - 1].Cost_on_rent = rent_cost;
    Years[year - startYear].months[month - 1].days[day - 1].Cost_on_employees_salary = emp_salary_cost;
    Years[year - startYear].months[month - 1].days[day - 1].Cost_on_elec = elec_cost;
    Years[year - startYear].months[month - 1].days[day - 1].Cost_on_gas = gas_cost;
    Years[year - startYear].months[month - 1].days[day - 1].Cost_on_vegetables = veg_cost;
    Years[year - startYear].months[month - 1].days[day - 1].Cost_on_meat = meat_cost;
    Years[year - startYear].months[month - 1].days[day - 1].Cost_on_other_ingrediants = other_cost;
    Years[year - startYear].months[month - 1].days[day - 1].general_costs = pub_cost + rent_cost + emp_salary_cost + elec_cost + gas_cost + veg_cost + meat_cost + other_cost;
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

float SalesAndCosts::GetGeneralCosts(int day, int month, int year, int startYear) const
{
    return Years[year - startYear].months[month - 1].days[day - 1].general_costs;
}

float SalesAndCosts::GetGeneralCosts(int day1, int month1, int year1, int day2, int month2, int year2, int startYear) const
{
    int g_costs = 0;
    while (true)
    {
        if (year1 == year2 && month1 == month2 && day1 == day2)
        {
            break;
        }

        else
        {
            g_costs += Years[year1 - startYear].months[month1 - 1].days[day1 - 1].general_costs;
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
    g_costs += Years[year1 - startYear].months[month1 - 1].days[day1 - 1].general_costs;
    return g_costs;
}

float SalesAndCosts::GetPublicityCosts(int day, int month, int year, int startYear) const
{
    return Years[year - startYear].months[month - 1].days[day - 1].publicity_costs;
}

float SalesAndCosts::GetPublicityCosts(int day1, int month1, int year1, int day2, int month2, int year2, int startYear) const
{
    int p_costs = 0;
    while (true)
    {
        if (year1 == year2 && month1 == month2 && day1 == day2)
        {
            break;
        }

        else
        {
            p_costs += Years[year1 - startYear].months[month1 - 1].days[day1 - 1].publicity_costs;
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
    p_costs += Years[year1 - startYear].months[month1 - 1].days[day1 - 1].publicity_costs;
    return p_costs;
}

float SalesAndCosts::GetRentCosts(int day, int month, int year, int startYear) const
{
    return Years[year - startYear].months[month - 1].days[day - 1].Cost_on_rent;
}

float SalesAndCosts::GetRentCosts(int day1, int month1, int year1, int day2, int month2, int year2, int startYear) const
{
    int r_costs = 0;
    while (true)
    {
        if (year1 == year2 && month1 == month2 && day1 == day2)
        {
            break;
        }

        else
        {
            r_costs += Years[year1 - startYear].months[month1 - 1].days[day1 - 1].Cost_on_rent;
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
    r_costs += Years[year1 - startYear].months[month1 - 1].days[day1 - 1].Cost_on_rent;
    return r_costs;
}

float SalesAndCosts::GetEmployeesCosts(int day, int month, int year, int startYear) const
{
    return Years[year - startYear].months[month - 1].days[day - 1].Cost_on_employees_salary;
}

float SalesAndCosts::GetEmployeesCosts(int day1, int month1, int year1, int day2, int month2, int year2, int startYear) const
{
    int em_costs = 0;
    while (true)
    {
        if (year1 == year2 && month1 == month2 && day1 == day2)
        {
            break;
        }

        else
        {
            em_costs += Years[year1 - startYear].months[month1 - 1].days[day1 - 1].Cost_on_employees_salary;
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
    em_costs += Years[year1 - startYear].months[month1 - 1].days[day1 - 1].Cost_on_employees_salary;
    return em_costs;
}

float SalesAndCosts::GetElectricityCosts(int day, int month, int year, int startYear) const
{
    return Years[year - startYear].months[month - 1].days[day - 1].Cost_on_elec;
}

float SalesAndCosts::GetElectricityCosts(int day1, int month1, int year1, int day2, int month2, int year2, int startYear) const
{
    int e_costs = 0;
    while (true)
    {
        if (year1 == year2 && month1 == month2 && day1 == day2)
        {
            break;
        }

        else
        {
            e_costs += Years[year1 - startYear].months[month1 - 1].days[day1 - 1].Cost_on_elec;
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
    e_costs += Years[year1 - startYear].months[month1 - 1].days[day1 - 1].Cost_on_elec;
    return e_costs;
}

float SalesAndCosts::GetGasCosts(int day, int month, int year, int startYear) const
{
    return Years[year - startYear].months[month - 1].days[day - 1].Cost_on_gas;
}

float SalesAndCosts::GetGasCosts(int day1, int month1, int year1, int day2, int month2, int year2, int startYear) const
{
    int g_costs = 0;
    while (true)
    {
        if (year1 == year2 && month1 == month2 && day1 == day2)
        {
            break;
        }

        else
        {
            g_costs += Years[year1 - startYear].months[month1 - 1].days[day1 - 1].Cost_on_gas;
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
    g_costs += Years[year1 - startYear].months[month1 - 1].days[day1 - 1].Cost_on_gas;
    return g_costs;
}

float SalesAndCosts::GetVegetablesCosts(int day, int month, int year, int startYear) const
{
    return Years[year - startYear].months[month - 1].days[day - 1].Cost_on_vegetables;
}

float SalesAndCosts::GetVegetablesCosts(int day1, int month1, int year1, int day2, int month2, int year2, int startYear) const
{
    int v_costs = 0;
    while (true)
    {
        if (year1 == year2 && month1 == month2 && day1 == day2)
        {
            break;
        }

        else
        {
            v_costs += Years[year1 - startYear].months[month1 - 1].days[day1 - 1].Cost_on_vegetables;
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
    v_costs += Years[year1 - startYear].months[month1 - 1].days[day1 - 1].Cost_on_vegetables;
    return v_costs;
}

float SalesAndCosts::GetMeatCosts(int day, int month, int year, int startYear) const
{
    return Years[year - startYear].months[month - 1].days[day - 1].Cost_on_meat;
}

float SalesAndCosts::GetMeatCosts(int day1, int month1, int year1, int day2, int month2, int year2, int startYear) const
{
    int m_costs = 0;
    while (true)
    {
        if (year1 == year2 && month1 == month2 && day1 == day2)
        {
            break;
        }

        else
        {
            m_costs += Years[year1 - startYear].months[month1 - 1].days[day1 - 1].Cost_on_meat;
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
    m_costs += Years[year1 - startYear].months[month1 - 1].days[day1 - 1].Cost_on_meat;
    return m_costs;
}

float SalesAndCosts::GetOtherCosts(int day, int month, int year, int startYear) const
{
    return Years[year - startYear].months[month - 1].days[day - 1].Cost_on_other_ingrediants;
}

float SalesAndCosts::GetOtherCosts(int day1, int month1, int year1, int day2, int month2, int year2, int startYear) const
{
    int o_costs = 0;
    while (true)
    {
        if (year1 == year2 && month1 == month2 && day1 == day2)
        {
            break;
        }

        else
        {
            o_costs += Years[year1 - startYear].months[month1 - 1].days[day1 - 1].Cost_on_other_ingrediants;
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
    o_costs += Years[year1 - startYear].months[month1 - 1].days[day1 - 1].Cost_on_other_ingrediants;
    return o_costs;
}
