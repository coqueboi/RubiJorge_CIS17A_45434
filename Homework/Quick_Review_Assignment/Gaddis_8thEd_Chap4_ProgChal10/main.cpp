/* 
 * File:   main.cpp
 * Author: Jorge Rubi
 * Created on June 24th, 2018, 4:56 PM
 * Purpose: Days in a Month
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
    int month, year;
    month=1, year=0;
    const int SIZE = 12;
    string names[SIZE] = {"January","February","March","April","May","June",
        "July","August","September","October","November","December"};
    //Input or initialize values Here
    cout<<"This program calculates how many days there are in a month and year "
            "of your choosing."<<endl;
    cout<<"Additionally, this program will determine whether or not the year is"
            " a leap year."<<endl;
    cout<<"To begin, enter a month in the range of 1 through 12: ";
    do{
        if(month<=0||month>12){
            cout<<"Invalid value. Try again: ";
        }
        cin>>month;
    }while(month<=0||month>12);
    cout<<"Next, enter the year: ";
    do{
        if(year<0){
            cout<<"Invalid value. Try again: ";
        }
        cin>>year;
    }while(month<0);
    
    //Process/Calculations Here
    if(month==2){
        if(year%100 == 0 && year%400 == 0){
            cout<<"Because "<<year<<" is a leap year, "<<names[month-1]<<
                    " has 29 days."<<endl;
        }
        else if(year%4==0){
               cout<<"Because "<<year<<" is a leap year, "<<names[month-1]<<
                    " has 29 days."<<endl; 
            }
        else{
            cout<<"Because "<<year<<" is not a leap year, "<<names[month-1]<<
                    " has 28 days."<<endl;
        }
    }
    else if(month==1||month==3||month==5||month==7||month==8||month==10||month==12){
            cout<<"The month of "<<names[month-1]<<" has 31 days."<<endl;
    }
    else{
        cout<<"The month of "<<names[month-1]<<" has 30 days."<<endl;
    }
    if(year%100 == 0 && year%400 == 0){
        cout<<"The year "<<year<<" is a leap year."<<endl;
    }
    else if(year%4==0){
        cout<<"The year "<<year<<" is a leap year."<<endl; 
    }
    else{
        if(month!=2)
            cout<<year<<" is not a leap year."<<endl;
    }
 
    //Exit
    return 0;
}