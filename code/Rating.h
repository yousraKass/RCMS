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

    Rating() : Years(25)
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



#endif