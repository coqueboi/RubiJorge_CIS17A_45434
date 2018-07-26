/* 
 * File:   main.cpp
 * Author: Jorge Rubi
 * Created on June 24th 2018, 3:31 PM
 * Purpose: Currency
 */
 
//System Libraries Here
#include <iostream>
#include <iomanip>
using namespace std;
 
//User Libraries Here
 
//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions
const float YEN_PER_DOLLAR = 98.93f;
const float EUROS_PER_DOLLAR = 0.74f;

//Function Prototypes Here
 
//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    float input = 0.0f;
    //Input or initialize values Here
    cout<<"This program converts U.S. Dollar amounts "
            "into Japanese Yen and Euros."<<endl;
    cout<<"To begin, please enter the value of U.S. Dollar "
            "you'd like to convert: ";
    cin>>input;
    //Process/Calculations Here
    cout<<"Your value of $ "<<input<<" equals:"<<endl;
    cout<<fixed<<showpoint<<setprecision(2)<<
            "¥ "<<input*YEN_PER_DOLLAR<<" Japanese Yen."<<endl<<
            "€ "<<input*EUROS_PER_DOLLAR<<" Euros."<<endl;
    //Exit
    return 0;
}