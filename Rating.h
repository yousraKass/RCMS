#ifndef RATING_H
#define RATING_H

#include<iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;


class Rating
{
public:
    void AddRating(int month, int year, float rA, float rS, float rC, float rI, float rE, int startYear, int startMonth);
    float GetRestaurantRating(int month, int year, int startYear) const;
    void GetAmountOfPrize(int month, int year, float &aA, float &aS, float &aC, float &aI, float &aE, int startYear) const;

    Rating() : Years(20)
    {
    }

private:
struct Rating_and_AOP
    {
        float Rating[6];
        float Amount_of_Prize[5];
    };

    struct Months
    {
        Rating_and_AOP months[12];
    };
    
    std::vector<Months> Years;
};

// Implementation

void Rating::AddRating(int month, int year, float rA, float rS, float rC, float rI, float rE, int startYear, int startMonth)
{
    cout << "added 1" << endl;

    Years[year - startYear].months[month - 1].Rating[0] = rA;
    Years[year - startYear].months[month - 1].Rating[1] = rS;
    Years[year - startYear].months[month - 1].Rating[2] = rC;
    Years[year - startYear].months[month - 1].Rating[3] = rI;
    Years[year - startYear].months[month - 1].Rating[4] = rE;
    Years[year - startYear].months[month - 1].Rating[5] = (rA + rS + rC + rI + rE) / 5;

    if (year == startYear && month == startMonth)
    {
        Years[0].months[startMonth - 1].Amount_of_Prize[0] = rA / 100;
        Years[0].months[startMonth - 1].Amount_of_Prize[1] = rS / 100;
        Years[0].months[startMonth - 1].Amount_of_Prize[2] = rC / 100;
        Years[0].months[startMonth - 1].Amount_of_Prize[3] = rI / 100;
        Years[0].months[startMonth - 1].Amount_of_Prize[4] = rE / 100;
    }

    else if (month == 1)
    {
        Years[year - startYear].months[month - 1].Amount_of_Prize[0] = Years[year - startYear - 1].months[11].Amount_of_Prize[0] + (rA / 100);
        Years[year - startYear].months[month - 1].Amount_of_Prize[1] = Years[year - startYear - 1].months[11].Amount_of_Prize[1] + (rS / 100);
        Years[year - startYear].months[month - 1].Amount_of_Prize[2] = Years[year - startYear - 1].months[11].Amount_of_Prize[2] + (rC / 100);
        Years[year - startYear].months[month - 1].Amount_of_Prize[3] = Years[year - startYear - 1].months[11].Amount_of_Prize[3] + (rI / 100);
        Years[year - startYear].months[month - 1].Amount_of_Prize[4] = Years[year - startYear - 1].months[11].Amount_of_Prize[4] + (rE / 100);
    }
    else
    {
        Years[year - startYear].months[month - 1].Amount_of_Prize[0] = Years[year - startYear].months[month - 2].Amount_of_Prize[0] + (rA / 100);
        Years[year - startYear].months[month - 1].Amount_of_Prize[1] = Years[year - startYear].months[month - 2].Amount_of_Prize[1] + (rS / 100);
        Years[year - startYear].months[month - 1].Amount_of_Prize[2] = Years[year - startYear].months[month - 2].Amount_of_Prize[2] + (rC / 100);
        Years[year - startYear].months[month - 1].Amount_of_Prize[3] = Years[year - startYear].months[month - 2].Amount_of_Prize[3] + (rI / 100);
        Years[year - startYear].months[month - 1].Amount_of_Prize[4] = Years[year - startYear].months[month - 2].Amount_of_Prize[4] + (rE / 100);
    }
    cout << "added 2" << endl;
}

float Rating::GetRestaurantRating(int month, int year, int startYear) const
{
    return Years[year - startYear].months[month - 1].Rating[5];
}

void Rating::GetAmountOfPrize(int month, int year, float &aA, float &aS, float &aC, float &aI, float &aE, int startYear) const
{
    aA = Years[year - startYear].months[month - 1].Amount_of_Prize[0];
    aS = Years[year - startYear].months[month - 1].Amount_of_Prize[1];
    aC = Years[year - startYear].months[month - 1].Amount_of_Prize[2];
    aI = Years[year - startYear].months[month - 1].Amount_of_Prize[3];
    aE = Years[year - startYear].months[month - 1].Amount_of_Prize[4];
}

#endif