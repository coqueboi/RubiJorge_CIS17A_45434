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
//////////////////////////////////
//  Program 14.2 function calls //
//    year.setDay();            //
//    year.dayCalc();           //
//    year.print();             //
//////////////////////////////////
    
    //Get user input to set the date, then output after calculating
    year.setDate();
    cout << "The day before was ";
    year--;
    year.printDay();
    cout << endl;
    cout << "This date is ";
    year++;
    year.printDay();
    cout << endl;
    year++;
    cout << "The day after is ";
    year.printDay();
    cout << endl;
    
    
    //Exit
    return 0;
}