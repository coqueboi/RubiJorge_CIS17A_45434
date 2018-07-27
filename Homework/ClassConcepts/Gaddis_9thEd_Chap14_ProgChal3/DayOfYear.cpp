/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DayOfYear.cpp
 * Author: Cokes PC
 * 
 * Created on July 24, 2018, 6:37 PM
 */
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

#include "DayOfYear.h"

string DayOfYear::month[12] = {
        "January","February","March","April","May","June","July","August",
        "September","October","November","December"};
int DayOfYear::numDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

//Default Constructor
DayOfYear::DayOfYear() {
    this->day = 0;
}

//Constructor
DayOfYear::DayOfYear(string month, int day) {
    this->m = month;
    this->day = day;
}
//Deconstructor
DayOfYear::~DayOfYear() {
}

//Overloading postfix ++ operator
DayOfYear DayOfYear::operator++(int){
    if(this->day == 365){
        day = 1;
    }
    else{
        day++;
    }
    return *this;
}

//Overloading postfix -- operator
DayOfYear DayOfYear::operator--(int){
    if(this->day == 1){
        day = 365;
    }
    else{
        day--;
    }
    return *this;
}

void DayOfYear::setDate(){
    string month = "";
    int day = 0, temp = 0;
    bool valid = true;
    
    cout << "This program takes a date in the form of Month & Date and tells "
            "you what day of the year the date happens to be.\n\n"
            "To begin, please enter a month: ";
    do{
        cin >> month;
        cin.ignore();
        valid = true;
        month[0] = toupper(month[0]);
        
        for(int i = 0; i < 12 ; i++){
            if(month == this->month[i]){
                valid = true;
                temp = i;
                break;
            }
            else if(i == 11 ){
                cout << "You did not enter a valid month. Please try again: ";
                valid = false;
            }
        }
    }while(!valid);
    
    cout << "Next, enter a day: ";
    do{
        cin >> day;
        cin.ignore();
        if(day < 1 || day > this->numDays[temp]){
            cout << "An invalid day for this month was entered. Please try again: ";
        }
        else{
            valid = true;
        }
    }while(!valid);
    
    this->getDate(month, day);
}

void DayOfYear::getDate(string month, int day){
    int temp = 0;
    for(int i = 0; i < 12; i++){
        if(this->month[i] != month){
            temp += this->numDays[i];
        }
        else{
            //If the number entered is outside the range of days for the month
            if(day < 1 || day > this->numDays[i]){
                cout << "An invalid day for this month was entered." << endl;
                exit(EXIT_FAILURE);
            }
            else{
                this->day = temp + day;
                break;
            }
        }
    }
}

void DayOfYear::printDay(){
    cout << "day number " << this->day <<endl;
}



//Set day -- Input validation, set day var
void DayOfYear::setDay(){
    int num = 0;
    string input = "";
    int size;
    bool valid = true;
    cout << "This program takes any integer day in the year (1-365) and "
            "outputs the month and day it falls in.\n"
            "To begin, please enter any day of the year: ";
    
    //Do not accept a value less than 1 or greater than 365
    do{
        if(!valid){
            cout << "Invalid entry, please try again: ";
        }
        //Use cin instead of getline to avoid blank space characters
        cin >> input;
        cin.ignore();
        size = input.length();
        
        //Make sure input is no greater than 3 chars
        if(size > 3){
            valid = false;
            continue;
        }
        //Make sure there are no invalid characters in the input string
        for(int i = 0; i < size; i++){
            if(isdigit(input[i])){
                num = ((num * 10) + (input[i] - '0'));
            }
            else{
                valid = false;
                break;
            }
        }
        //Make sure value is between 1 and 365
        if(num <= 0 || num > 365){
            valid = false;
        }
    }while(!valid);
    this -> day = num;
}

//Day calc -- Do all the calculations, set month var
void DayOfYear::dayCalc(){
    //Initialize variables
    int num = this->day;
    int i = 0;
    bool finish = false;
    
    //Find which month and day the number is
    do{
        
        if(num > this->numDays[i]){
            num -= this->numDays[i];
            i++;
        }
        else if(num < this->numDays[i]){
            this->md += this->month[i];
            this->md += " ";
            this->md += to_string(num);
            finish = true;
        }
        else if(num == this->numDays[i]){
            //Last day of the month
            this->md += this->month[i];
            this->md += " ";
            this->md += to_string(this->numDays[i]);
            finish = true;
        }   
    }while(!finish);
}

//Print -- Output the month string 
void DayOfYear::print(){
    cout << "Day " << this->day <<" lies on " << this->md << endl;
}