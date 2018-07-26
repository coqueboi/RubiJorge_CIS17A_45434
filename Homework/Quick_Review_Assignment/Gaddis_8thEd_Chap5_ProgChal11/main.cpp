/* 
 * File:   main.cpp
 * Author: Jorge Rubi
 * Created on June 24th, 2018, 6:39 PM
 * Purpose: Population
 */
 
//System Libraries Here
#include <iostream>
#include <cmath>
using namespace std;
 
//User Libraries Here
 
//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions
const float e = 2.718281f;
//Function Prototypes Here
 
//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    int popSize=0, strtSize=2, days=1;
    float avg=0.0f, temp=0.0f;
    
    //Input or initialize values Here
    cout<<"This program predicts the size of a population of organisms."<<endl;
    cout<<"To begin, enter the starting number of organisms: ";
    do{
        if(strtSize<2)cout<<"Invalid Entry. Please enter a number no less than 2: ";
        cin>>strtSize;
    }while(strtSize<2);
    cout<<"Next, enter their average daily population increase as a percentage: ";
    do{
        if(avg<0)cout<<"Invalid Entry. Please enter a positive percentage: ";
        cin>>avg;
    }while(avg<0);
    cout<<"Finally, enter the number of days the population will multiply: ";
    do{
        if(days<1)cout<<"Invalid Entry. Please enter a number no less than 1: ";
        cin>>days;
    }while(days<1);
    //Process/Calculations Here
    avg=avg/100;
    
    for(short i=1;i<=days;i++){
        temp=avg*i;
        popSize=strtSize*pow(e,temp);
        cout<<"Day "<<i<<" population: "<<popSize<<"."<<endl;
    }
    
    //Exit
    return 0;
}