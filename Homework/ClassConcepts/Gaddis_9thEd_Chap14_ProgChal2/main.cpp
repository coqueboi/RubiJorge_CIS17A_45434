/* 
 * File:   main.cpp
 * Author: Jorge Rubi
 * Purpose: Day of the Year 
 */
 
//System Libraries Here
#include <iostream>
using namespace std;
 
//User Libraries Here
#include "DayOfYear.h"
//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions
 
//Function Prototypes Here
 
//Program Execution Begins Here
int main(int argc, char** argv) {
    
    DayOfYear year;
    year.setDay();
    year.dayCalc();
    year.print();
 
    //Exit
    return 0;
}