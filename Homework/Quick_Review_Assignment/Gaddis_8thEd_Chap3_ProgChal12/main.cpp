/* 
 * File:   main.cpp
 * Author: Jorge Rubi
 * Created on June 19, 2018, 11:32 PM
 * Purpose: Celsius to Fahrenheit
 */
 
//System Libraries Here
#include <iostream>
using namespace std;
 
//User Libraries Here
 
//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions
 
//Function Prototypes Here
 
//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    float input = 0, total = 0;
    
    //Input or initialize values Here
    cout<<"This program converts temperatures in Celsius to "
            "temperatures in Fahrenheit."<<endl;
    cout<<"To begin, please enter a valid measurement of temperature"
            " in Celsius: ";
    //Input Validation 
    do{
        cin>>input;
        if(input<-273.15f)cout<<"Invalid entry, try again: ";
    }while(input<-273.15f);
    
    //Process/Calculations Here
    total = ((1.8f)*input)+32;
    //Output Located Here
    cout<<endl;
    cout<<input<<" degrees Celsius equals "<<total<<" degrees Fahrenheit"<<endl;
    //Exit
    return 0;
}