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
    void CalculateMonthlyPrizeWinner(Restaurant *root, int month, int year, Restaurant *&IdA, float &winnerA, Restaurant *&IdS, float &winnerS, Restaurant *&IdI, float &winnerI, Restaurant *&IdE, float &winnerE, Restaurant *&IdC, float &winnerC)
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

    PrizeWinners(const BSTRestaurantTree &rcms, const Date &firstDate)
    {
        FirstCreationDate = firstDate;

        int year = FirstCreationDate.getYear();
        int month = FirstCreationDate.getMonth();
        float winnerA = 0, winnerS = 0, winnerC = 0, winnerI = 0, winnerE = 0;
        Restaurant *IdA;
        Restaurant *IdS;
        Restaurant *IdI;
        Restaurant *IdC;
        Restaurant *IdE;
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

    vector<Restaurant *> getWinners(int month, int year)
    {
        int index = (year - FirstCreationDate.getYear()) * 12 + month - FirstCreationDate.getMonth();
        if (index < 0 || index >= winnersID.size())
        {
            {
                cout << "invalid date" << endl;
                exit(1);
            }
        }
        return winnersID[index];
    }
    PrizeWinners(const AVLRestaurantTree &rcms, const Date &firstDate)
    {
        FirstCreationDate = firstDate;

        int year = FirstCreationDate.getYear();
        int month = FirstCreationDate.getMonth();
        float winnerA = 0, winnerS = 0, winnerC = 0, winnerI = 0, winnerE = 0;
        Restaurant *IdA;
        Restaurant *IdS;
        Restaurant *IdI;
        Restaurant *IdC;
        Restaurant *IdE;
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

    vector<vector<Restaurant *>> getWinners(int startMonth, int startYear, int endMonth, int endYear)
    {
        int startIndex = (startYear - FirstCreationDate.getYear()) * 12 + startMonth - FirstCreationDate.getMonth();
        int endIndex = (endYear - FirstCreationDate.getYear()) * 12 + endMonth - FirstCreationDate.getMonth();
        vector<vector<Restaurant *>> result;

        if (startIndex > endIndex)
        {
            cout << "invalid period" << endl;
            exit(1);
        }

        if (startIndex < 0 || endIndex > winnersID.size())
        {
            cout << "invalid period" << endl;
            exit(1);
        }

        for (; startIndex <= endIndex; startIndex++)
            result.push_back(winnersID[startIndex]);

        return result;
    }
};

#endif
