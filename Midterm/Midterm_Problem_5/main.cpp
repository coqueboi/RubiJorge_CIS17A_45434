/* 
 * File:   main.cpp
 * Author: Jorge Rubi
 * Created on July 16th, 2018
 * Purpose: Largest Factorial
 */
 
//System Libraries Here
#include <iostream>
using namespace std;
 
//User Libraries Here
 
//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions
 
//Function Prototypes Here
void factorial();

//Program Execution Begins Here
int main(int argc, char** argv) {
    factorial();
 
    //Exit
    return 0;
}
void factorial(){
    cout << "The largest factorial for each primitive data type is as follows:";
    cout << endl;
    cout << "   signed char: 5" << endl;
    cout << " unsigned char: 5" << endl;
    cout << "  signed short: 7" << endl;
    cout << "unsigned short: 8" << endl;
    cout << "         float: 12" << endl;
    cout << "        double: 20" << endl;
    cout << "   signed  int: 12" << endl;
    cout << " unsigned  int: 12" << endl;
    cout << "   signed long: 20" << endl;
    cout << " unsigned long: 22" << endl;
    cout << "" << endl;
}