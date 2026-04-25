#ifndef PRIZEWINNERS_H
#define PRIZEWINNERS_H
#include "Date.h"
#include "Restaurant.h"
#include "BSTRestaurant.h"
#include "AVLRestaurant.h"

#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class PrizeWinners
{
private:
    Date FirstCreationDate;
    vector<vector<Restaurant *>> winnersID;

public:
    void CalculateMonthlyPrizeWinner(Restaurant *root, int month, int year, Restaurant *&IdA, float &winnerA, Restaurant *&IdS, float &winnerS, Restaurant *&IdI, float &winnerI, Restaurant *&IdE, float &winnerE, Restaurant *&IdC, float &winnerC);

    PrizeWinners(const BSTRestaurantTree &rcms, const Date &firstDate);

    vector<Restaurant *> getWinners(int month, int year);
    PrizeWinners(const AVLRestaurantTree &rcms, const Date &firstDate);

    vector<vector<Restaurant *>> getWinners(int startMonth, int startYear, int endMonth, int endYear);
};

#endif
