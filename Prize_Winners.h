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
}
class Prize_Winners
{
private:
    Date First_Creation_Date;
    vector<vector<int>> winnersID;

public:
    void CalculateMonthlyPrizeWinner(const Restaurant *root, int month, int year, int IdA, float &winnerA, int IdS, float &winnerS, int IdI, float &winnerI, int IdE, float &winnerE, int IdC, float &winnerC)
    {
        if (root == nullptr)
            return;
        CalculateMonthlyPrizeWinner(root->leftChild, month, year, IdA, winnerA, IdS, winnerS, IdI, winnerI, IdE, winnerE, IdC, winnerC);
        if (root->getPrize(month, year, 0) > winnerA)
        {
            winnerA = root->getPrize(month, year, 0);
            IdA = root->getId();
        }
        if (root->getPrize(month, year, 1) > winnerS)
        {
            winnerS = root->getPrize(month, year, 1);
            IdS = root->getId();
        }
        if (root->getPrize(month, year, 2) > winnerI)
        {
            winnerI = root->getPrize(month, year, 2);
            IdI = root->getId();
        }
        if (root->getPrize(month, year, 3) > winnerE)
        {
            winnerE = root->getPrize(month, year, 3);
            IdE = root->getId();
        }
        if (root->getPrize(month, year, 4) > winnerC)
        {
            winnerC = root->getPrize(month, year, 4);
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
}

#endif;
