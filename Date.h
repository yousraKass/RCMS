// validate date/ year month day
#ifndef DATE_H
#define DATE_H
#include <iostream>
using namespace std;

class Date
{
private:
    int year;
    int month;
    int day;

public:
    Date(int y=1, int m = 1, int d = 1)
        
    {
        if(isValidDate(y,m,d)){
            year=y;
            month=m;
            day=d;
        }
    }
    
    bool isValidDate(int y, int m, int d) const
    {
        if (y < 0 || m < 1 || m > 12 || d < 1 )
        {
            return false;
        }

        // verifying days in each month
        if (d > daysInMonth(y, m))
        {
            return false;
        }

        return true;
    }

  
    int daysInMonth(int y, int m) const
    {
        static const int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        int daysInThisMonth = days[m];

        //  leap year in February
        if (m == 2 && isLeapYear(y))
        {
            daysInThisMonth = 29;
        }

        return daysInThisMonth;
    }
    
    bool isLeapYear(int year) const
    {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }


    void DisplayDate() const
    {
        cout << "Date: " << year << "-" << month << "-" << day << "\n";
    }
    int getYear() const
    {
        return year;
    }
    int getMonth() const
    {
        return month;
    }
    int getDay() const
    {
        return day;
    }
    bool operator==(const Date &date2)
    {
        if (this->getYear() == date2.getYear() && this->getMonth() == date2.getMonth() && this->getDay() == date2.getDay())
            return true;
        return false;
    }

    bool operator<(const Date &date2)
    {
        if (*this == date2)
            return false;
        if (this->getYear() < date2.getYear())
        {
            return true;
        }
        else if (this->getYear() > date2.getYear())
        {
            return false;
        }
        // year1= year2
        else
        {
            if (this->getMonth() < date2.getMonth())
            {
                return true;
            }
            if (this->getMonth() > date2.getMonth())
            {
                return false;
            }
            // same month
            else
            {
                if (this->getDay() < date2.getDay())
                {
                    return true;
                }
                return false;
            }
        }
    }
    bool operator>(const Date &date2)
    {
        return !(*this < date2 && *this == date2);
    }
};
#endif