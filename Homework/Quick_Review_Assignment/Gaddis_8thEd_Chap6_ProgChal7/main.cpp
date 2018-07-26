/* 
 * File:   main.cpp
 * Author: Name
 * Created on June 25, 2018
 * Purpose: Celsius Temperature Table
 */
 
//System Libraries Here
#include <iostream>
#include <iomanip>
using namespace std;
 
//User Libraries Here
 
//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions
 
//Function Prototypes Here
float celsius(float);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    float f;
    //Input or initialize values Here
    cout<<"This program converts Fahrenheit temperatures to Celsius."<<endl;
    cout<<"To begin, enter a temperature in Fahrenheit: ";
    cin>>f;
    for(short i=0;i<=20;i++){
        cout<<"Fahrenheit: "<<f+i<<" Celsius: "<<celsius(f+i)<<endl;
    }
    //Exit
    return 0;
}

float celsius(float f){
    return ((f-32)/1.8f);
}