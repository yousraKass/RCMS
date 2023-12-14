#ifndef PRIZE_WINNERS_H
#define PRIZE_WINNERS_H
#include "date.h"
#include "RESTAURANT.h"
#include "BSTRESTAURANT.h"
#include "AVLRESTAURANT.h"
#include <iostream>
#include <vector>
using namespace std;
enum cuisine{
    ALGERIAN,
    SYRIAN,
    CHINESE,
    INDIAN,
    EUROPIAN
};


class Prize_Winners
{
private:
    Date First_Creation_Date;
    vector<vector<Restaurant*>> winners;

public:
    void CalculateMonthlyPrizeWinner(Restaurant *root, int month, int year, Restaurant*& IdA, float &winnerA, Restaurant*& IdS, float &winnerS, Restaurant*& IdI, float &winnerI, Restaurant*& IdE, float &winnerE, Restaurant*& IdC, float &winnerC)
    {
        if (root == nullptr)
            return;
        CalculateMonthlyPrizeWinner(root->leftChild, month, year, IdA, winnerA, IdS, winnerS, IdI, winnerI, IdE, winnerE, IdC, winnerC);
        float aA, aS,aC,aI,aE;
        root->getPrize(month, year,aA, aS,aC,aI,aE);
        if (aA> winnerA)
        {   
            winnerA = aA;
            IdA = root;
        }
        if (aS >winnerS)
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
        Restaurant* IdA;
        Restaurant* IdS;
        Restaurant* IdI;
        Restaurant* IdC;
        Restaurant* IdE;
        while (year != 2024)
        {
            CalculateMonthlyPrizeWinner(rcms.root, month, year, IdA, winnerA, IdS, winnerS, IdI, winnerI, IdE, winnerE, IdC, winnerC);
            vector<Restaurant*> winnerIDS= {IdA,IdS,IdC,IdI,IdE};
            winners.push_back(winnerIDS);
            month++;
            if(month==13){
                month=1;
                year++;
            }
            
        }
    }
    vector<Restaurant*> get_winners(int month, int year)
    {
        int index=(year - First_Creation_Date.getYear() )*12+ month - First_Creation_Date.getMonth();
        return winners[index];
    }
};

#endif
