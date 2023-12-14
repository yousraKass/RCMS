#include <fstream>
using std::ifstream;
using std::ofstream;

#include <cstdlib>
#include <ctime>
using std::srand;
using std::rand;
using std::time;

#include <iostream>
using std::endl;
using std::getline;
using std::cout;

// we are generating 10000 restaurant
int restaurantNum = 7000;
int restaurantName = 400;

int main()
{
    // generate restaurant IDs
    /*
    srand(time(0));
    ofstream outputID("IDS.csv");
    
    for(int i = 0; i<7000; i++){
        unsigned id = rand() % 10000000000;
        // int k = rand() % 10 + 1;
        if(id < 1000000000){
            id = (id + 1000000000)% 10000000000;
        }
        outputID << id << endl;
    }
    */

    ifstream inputID("IDS.csv");
    int id;
    int currentRestaurantName = 1;
    int currentRestauran = 1;
    int currentRestaurantLocation = 1;
    ofstream output("RESTAURANTS.csv");

    // ID,Name,Type,Creation date,employee number,country,city,district
    for(int i = 0; i<restaurantNum; i++){
        inputID >> id;
        

        output < id << "," << 
    }


    return 0;
}