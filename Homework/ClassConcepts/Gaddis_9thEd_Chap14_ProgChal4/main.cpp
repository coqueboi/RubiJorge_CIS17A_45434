/* 
 * File:   main.cpp
 * Author: Jorge Rubi
 * Purpose: NumDays Class
 */
 
//System Libraries Here
#include <iostream>

#include "NumDays.h"
using namespace std;
 
//User Libraries Here
 
//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions
 
//Function Prototypes Here
 
//Program Execution Begins Here
int main(int argc, char** argv) {
    //Test driver
    NumDays test(16);               //Start the work hours at 16
    test.convert();                 //Convert the hours into workdays
    test.print();                   //Output the results
    ++test;                         //Add 1 to the amount of hours
    test.print();                   //Output the results
    test--;                         //Substract 1 to the amount of hours
    test.print();                   //Output the results
    
    NumDays test2(24);              //Start the work hours at 24
    test2.convert();                //Convert the hours into workdays
    test2.print();                  //Output the results
    test = test.operator+(test2);   //Add the work hours of the two objects
    test.convert();                 //Convert those work hours into work days
    test.print();                   //Output those results
    
    //Exit
    return 0;
}