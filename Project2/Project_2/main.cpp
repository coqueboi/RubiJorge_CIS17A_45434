/* 
 * File:   main.cpp
 * Author: Jorge Rubi
 * Purpose: Project 2 - Battleship Revamped x 2
 */
 
//System Libraries Here
#include <iostream>
#include "Game.h"

using namespace std;
 
//User Libraries Here
 
//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions
 
//Function Prototypes Here
 
//Program Execution Begins Here
int main(int argc, char** argv) {
    //Seed random number
    srand(static_cast<unsigned int>(time(0)));
    Game run;
    run.print();
    //Exit
    return 0;
}