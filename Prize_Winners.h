#ifndef PRIZE_WINNERS_H
#define PRIZE_WINNERS_H
#include "date.h"
#include "RESTAURANT.h"
#include "BSTRESTAURANT.h"
#include "AVLRESTAURANT.h"
#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class Prize_Winners
{
private:
    Date First_Creation_Date;
    vector<vector<Restaurant *>> winnersID;

public:
    void CalculateMonthlyPrizeWinner(Restaurant *root, int month, int year, Restaurant * &IdA, float &winnerA, Restaurant * &IdS, float &winnerS, Restaurant * &IdI, float &winnerI, Restaurant * &IdE, float &winnerE, Restaurant * &IdC, float &winnerC)
    {
        if (root == nullptr)
            return;
        CalculateMonthlyPrizeWinner(root->leftChild, month, year, IdA, winnerA, IdS, winnerS, IdI, winnerI, IdE, winnerE, IdC, winnerC);
        float aA, aS, aC, aI, aE;
        root->getPrize(month, year, aA, aS, aC, aI, aE);
        if (aA > winnerA)
        {
            winnerA = aA;
            IdA = root;
        }
        if (aS > winnerS)
        {
            winnerS = aS;
            IdS = root;
        }
        if (aI > winnerI)
        {
            winnerI = aI;
            IdI = root;
        }
        if (aE > winnerE)
        {
            winnerE = aE;
            IdE = root;
        }
        if (aC > winnerC)
        {
            winnerC = aC;
            IdC = root;
        }
        CalculateMonthlyPrizeWinner(root->rightChild, month, year, IdA, winnerA, IdS, winnerS, IdI, winnerI, IdE, winnerE, IdC, winnerC);
    }

    Prize_Winners(const RestaurantTree &rcms, const Date &firstDate)
    {
        First_Creation_Date = firstDate;

        int year = First_Creation_Date.getYear();
        int month = First_Creation_Date.getMonth();
        float winnerA = 0, winnerS = 0, winnerC = 0, winnerI = 0, winnerE = 0;
        Restaurant * IdA;
        Restaurant * IdS;
        Restaurant * IdI;
        Restaurant * IdC;
        Restaurant * IdE;
        while (year != 2024)
        {
            CalculateMonthlyPrizeWinner(rcms.root, month, year, IdA, winnerA, IdS, winnerS, IdI, winnerI, IdE, winnerE, IdC, winnerC);
            vector<Restaurant *> winnerIDS = {IdA, IdS, IdC, IdI, IdE};
            winnersID.push_back(winnerIDS);
            month++;
            if (month == 13)
            {
                month = 1;
                year++;
            }
        }
    }

    // we have to test if the index is valid
    // and throw an exception if there is an error
    vector<Restaurant *> get_winners(int month, int year)
    {
        int index = (year - First_Creation_Date.getYear()) * 12 + month - First_Creation_Date.getMonth();
        if (index < 0 || index >= winnersID.size())
           throw out_of_range{"out of range index"};
        return winnersID[index];
    }
    Prize_Winners(const AVLRestaurantTree &rcms, const Date &firstDate)
    {
        First_Creation_Date = firstDate;

        int year = First_Creation_Date.getYear();
        int month = First_Creation_Date.getMonth();
        float winnerA = 0, winnerS = 0, winnerC = 0, winnerI = 0, winnerE = 0;
        Restaurant * IdA;
        Restaurant * IdS;
        Restaurant * IdI;
        Restaurant * IdC;
        Restaurant * IdE;
        while (year != 2024)
        {
            CalculateMonthlyPrizeWinner(rcms.root, month, year, IdA, winnerA, IdS, winnerS, IdI, winnerI, IdE, winnerE, IdC, winnerC);
            vector<Restaurant *> winnerIDS = {IdA, IdS, IdC, IdI, IdE};
            winnersID.push_back(winnerIDS);
            month++;
            if (month == 13)
            {
                month = 1;
                year++;
            }
        }
    }

    

    vector<vector<Restaurant *>> get_winners(int startMonth, int startYear, int endMonth, int endYear)
    {
        int startIndex = (startYear - First_Creation_Date.getYear()) * 12 + startMonth - First_Creation_Date.getMonth();
        int endIndex = (endYear - First_Creation_Date.getYear()) * 12 + endMonth - First_Creation_Date.getMonth();
        vector<vector<Restaurant *>> result;

        if (startIndex > endIndex)
            swap(startIndex, endIndex);

        if (startIndex < 0 || endIndex > winnersID.size())
            throw out_of_range{"out of range index"};

        for (; startIndex <= endIndex; startIndex++)
            result.push_back(winnersID[startIndex]);

        return result;
    }
};

#endif
