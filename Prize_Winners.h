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
    vector<vector<int>> winnersID;

public:
    void CalculateMonthlyPrizeWinner(Restaurant *root, int month, int year, int &IdA, float &winnerA, int& IdS, float &winnerS, int &IdI, float &winnerI, int &IdE, float &winnerE, int &IdC, float &winnerC)
    {
        if (root == nullptr)
            return;
        CalculateMonthlyPrizeWinner(root->leftChild, month, year, IdA, winnerA, IdS, winnerS, IdI, winnerI, IdE, winnerE, IdC, winnerC);
        float aA, aS,aC,aI,aE;
        root->getPrize(month, year,aA, aS,aC,aI,aE);
        if (aA> winnerA)
        {   
            winnerA = aA;
            IdA = root->getId();
        }
        if (aS >winnerS)
        {
            winnerS = aS;
            IdS = root->getId();
        }
        if (aI > winnerI)
        {
            winnerI = aI;
            IdI = root->getId();
        }
        if (aE > winnerE)
        {
            winnerE = aE;
            IdE = root->getId();
        }
        if (aC > winnerC)
        {
            winnerC = aC;
            IdC = root->getId();
        }
        CalculateMonthlyPrizeWinner(root->rightChild, month, year, IdA, winnerA, IdS, winnerS, IdI, winnerI, IdE, winnerE, IdC, winnerC);
    }
    Prize_Winners(const RestaurantTree &rcms, const Date &firstDate)
    {
        First_Creation_Date = firstDate;

        int year = First_Creation_Date.getYear();
        int month = First_Creation_Date.getMonth();
        float winnerA = 0, winnerS = 0, winnerC = 0, winnerI = 0, winnerE = 0;
        int IdA, IdS, IdI, IdC, IdE;
        while (year != 2024)
        {
            CalculateMonthlyPrizeWinner(rcms.root, month, year, IdA, winnerA, IdS, winnerS, IdI, winnerI, IdE, winnerE, IdC, winnerC);
            vector<int> winnerIDS= {IdA,IdS,IdC,IdI,IdE};
            winnersID.push_back(winnerIDS);
            month++;
            if(month==13){
                month=1;
                year++;
            }
            
        }
    }
    vector<int> get_winners(int month, int year)
    {
        int index=(year - First_Creation_Date.getYear() )*12+ month - First_Creation_Date.getMonth();
        return winnersID[index];
    }
};

#endif
