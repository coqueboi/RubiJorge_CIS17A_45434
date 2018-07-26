/* 
 * File:   main.cpp
 * Author: Jorge Rubi
 * Created on July 15th, 2018, 2:50 AM
 * Purpose: Gross Pay Application
 */
 
//System Libraries Here
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <stdlib.h>
#include <iomanip>

using namespace std;
 
//User Libraries Here
#include "Employee.h"

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions
const int HTHSND = 100000;
const int TTHSND = 10000;
const int THSND = 1000;
const int HNDRD = 100;
const int TEN = 10;
const int ONE = 1;

//Function Prototypes Here
int intIn(string);          //Integer input
float floatIn(string);      //Float input
string stringIn(string);    //String input
void employeeData(Employee *, int);        //Input employee data, find gross pay
void prntChk(string, string, Employee *, int); //Print employee checks
string engNum(Employee, float);       //Convert number to English for check

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Define Variables
    Employee *array;
    int size;
    //Output purpose
    cout << "This program determines the gross pay for any number of employees "
            "input. \n"
            "To begin,\n";
    //Create structure array        
    size = intIn("the number of employees");
    array = new Employee[size];
    
    //Get input and store data
    employeeData(array,size);
    
    //Exit
    return 0;
}

void employeeData(Employee *array, int size){
    float temp = 0.0f;
    cout<<"Next, \n";
    //Get company name
    string company = stringIn("company name");
    
    cout<<"Next, \n";
    //Get company address
    string address = stringIn("company address");
    
    //Get employee data
    cout<<"Next, \n";
    for(int i = 0; i < size; i++){
        
        cout<<"fill the following information for Employee #"<<i+1<<": \n";
        
        //Get employee's name
        array[i].name = stringIn("name");
        
        //Get employee's hours worked
        array[i].hours = floatIn("their number of hours worked");
        
        //Get the employee's pay rate
        array[i].rate = floatIn("their pay rate");
        
        //Calculate the employee's gross pay
        //If straight-time
        if(array[i].hours <= 30){ 
            temp += array[i].hours * array[i].rate;
            cout<<array[i].hours<<" hours "<<array[i].rate<<" rate"<<endl;
        }
        //If double-time
        else if(array[i].hours > 30 && array[i].hours < 50){ 
            //payrate * 2
            temp += array[i].rate * 30;
            temp += (array[i].hours - 30) * (array[i].rate * 2);
        }
        //If triple-time
        else if(array[i].hours >= 50){
            temp += (array[i].rate * 30);
            temp += array[i].rate * 2 * 20;
            temp += (array[i].hours - 50) * array[i].rate * 3;
        }
        //If error
        else{
            cout << "An error occurred." << endl;
            cout << "Program shutting down." << endl;
            exit (EXIT_FAILURE);
        }
        array[i].gross = temp;
        array[i].cents = temp - array[i].gross;
    }
    //When finished getting employee data, print their checks
    prntChk(company, address, array, size);
}

void prntChk(string comp, string addr, Employee *info, int size){
    float cent;
    for(int i = 0; i < size; i++){
        cent = info[i].cents;
        cout << "-------------------------------------------" << endl;
        cout << comp << endl;
        cout << addr << endl;
        cout << "Name: " << info[i].name;
        cout << setw(15) << right;
        cout << "Amount: " << info[i].gross << "." << (int)(cent * 100) << endl;
        cout << "Amount: " << engNum(info[i], cent) << endl; 
        cout << "Signature Line: " << endl;
        cout << "-------------------------------------------" << endl;
    }
}

string engNum(Employee data, float cents){
    int temp = data.gross;
    int temp2 = 0;
    bool teenNum = false;
    bool teenTHSND = false;
    string amtWord;
    
    //Value of each place -- init to -1 to stop switch case
    int nHTHSND = -1;
    int nTTHSND = -1;
    int nTHSND = -1;
    int nHNDRD = -1;
    int nTEN = -1;
    int nONE = -1;
    
    //Check if gross pay is divisible by value, repeat until no remainder 
    ////////////////////////////////////////////////////////////////////////////
    if(temp >= HTHSND){
        nHTHSND = temp / HTHSND;
        temp %= HTHSND;
        
        nTTHSND = temp / TTHSND;
        temp %= TTHSND;
        
        nTHSND = temp / THSND;
        temp %= THSND;
        
        nHNDRD = temp / HNDRD;
        temp %= HNDRD;
        
        nTEN = temp / TEN;
        temp %= TEN;
        
        nONE = temp;
    }
    else if(temp >= TTHSND){
        nTTHSND = temp / TTHSND;
        temp %= TTHSND;
        
        nTHSND = temp / THSND;
        temp %= THSND;
        
        nHNDRD = temp / HNDRD;
        temp %= HNDRD;
        
        nTEN = temp / TEN;
        temp %= TEN;
        
        nONE = temp;
    }
    else if(temp >= THSND){
        nTHSND = temp / THSND;
        temp %= THSND;
        
        nHNDRD = temp / HNDRD;
        temp %= HNDRD;
        
        nTEN = temp / TEN;
        temp %= TEN;
        
        nONE = temp;
    }
    else if(temp >= HNDRD){
        nHNDRD = temp / HNDRD;
        temp %= HNDRD;
        
        nTEN = temp / TEN;
        temp %= TEN;
        
        nONE = temp;
    }
    else if(temp >= TEN){
        nTEN = temp / TEN;
        temp %= TEN;
        nONE = temp;
    }
    else nONE = temp;
    ////////////////////////////////////////////////////////////////////////////
    
    //Begin switch cases for appending to string amtWord
    ////////////////////////////////////////////////////////////////////////////
    switch(nHTHSND){
        case 9: amtWord += "Nine Hundred ";break;
        case 8: amtWord += "Eight Hundred ";break;
        case 7: amtWord += "Seven Hundred ";break;
        case 6: amtWord += "Six Hundred ";break;
        case 5: amtWord += "Five Hundred ";break;
        case 4: amtWord += "Four Hundred ";break;
        case 3: amtWord += "Three Hundred ";break;
        case 2: amtWord += "Two Hundred ";break;
        case 1: amtWord += "One Hundred ";break;
    }
    switch(nTTHSND){
        case 9: amtWord += "Ninety ";break;
        case 8: amtWord += "Eighty ";break;
        case 7: amtWord += "Seventy ";break;
        case 6: amtWord += "Sixty ";break;
        case 5: amtWord += "Fifty ";break;
        case 4: amtWord += "Forty ";break;
        case 3: amtWord += "Thirty ";break;
        case 2: amtWord += "Twenty ";break;
        case 1: teenTHSND = true;break;
    }
    switch(nTHSND){
        case 9: (teenTHSND)?(amtWord += "Nineteen Thousand "):(amtWord += "Nine Thousand ");break;
        case 8: (teenTHSND)?(amtWord += "Eighteen Thousand "):(amtWord += "Eight Thousand ");break;
        case 7: (teenTHSND)?(amtWord += "Seventeen Thousand "):(amtWord += "Seven Thousand ");break;
        case 6: (teenTHSND)?(amtWord += "Sixteen Thousand "):(amtWord += "Six Thousand ");break;
        case 5: (teenTHSND)?(amtWord += "Fifteen Thousand "):(amtWord += "Five Thousand ");break;
        case 4: (teenTHSND)?(amtWord += "Fourteen Thousand "):(amtWord += "Four Thousand ");break;
        case 3: (teenTHSND)?(amtWord += "Thirteen Thousand "):(amtWord += "Three Thousand ");break;
        case 2: (teenTHSND)?(amtWord += "Twelve Thousand "):(amtWord += "Two Thousand ");break;
        case 1: (teenTHSND)?(amtWord += "Eleven Thousand "):(amtWord += "One Thousand ");break;
        case 0: (teenTHSND)?(amtWord += "Ten Thousand "):(amtWord += "Thousand ");break;
    }
    switch(nHNDRD){
        case 9: amtWord += "Nine Hundred ";break;
        case 8: amtWord += "Eight Hundred ";break;
        case 7: amtWord += "Seven Hundred ";break;
        case 6: amtWord += "Six Hundred ";break;
        case 5: amtWord += "Five Hundred ";break;
        case 4: amtWord += "Four Hundred ";break;
        case 3: amtWord += "Three Hundred ";break;
        case 2: amtWord += "Two Hundred ";break;
        case 1: amtWord += "One Hundred ";break;
    }
    switch(nTEN){
        case 9: amtWord += "Ninety ";break;
        case 8: amtWord += "Eighty ";break;
        case 7: amtWord += "Seventy ";break;
        case 6: amtWord += "Sixty ";break;
        case 5: amtWord += "Fifty ";break;
        case 4: amtWord += "Forty ";break;
        case 3: amtWord += "Thirty ";break;
        case 2: amtWord += "Twenty ";break;
        case 1: teenNum = true;break;
    }
    switch(nONE){
        case 9:(teenNum)?(amtWord += "Nineteen "):(amtWord += "Nine ");break;
        case 8:(teenNum)?(amtWord += "Eighteen "):(amtWord += "Eight ");break;
        case 7:(teenNum)?(amtWord += "Seventeen "):(amtWord += "Seven ");break;
        case 6:(teenNum)?(amtWord += "Sixteen "):(amtWord += "Six ");break;
        case 5:(teenNum)?(amtWord += "Fifteen "):(amtWord += "Five ");break;
        case 4:(teenNum)?(amtWord += "Fourteen "):(amtWord += "Four ");break;
        case 3:(teenNum)?(amtWord += "Thirteen "):(amtWord += "Three ");break;
        case 2:(teenNum)?(amtWord += "Twelve "):(amtWord += "Two ");break;
        case 1:(teenNum)?(amtWord += "Eleven "):(amtWord += "One ");break;
        case 0:(teenNum)?(amtWord += "Ten "):(amtWord = amtWord);break;
    }
    ////////////////////////////////////////////////////////////////////////////
    
    amtWord += "dollars ";
    temp2 = cents * 100;
    if(temp2 == 0) amtWord += "and 00/100 cents.";
    else amtWord += " and " + to_string(temp2) + "/100 cents.";
    return amtWord;
}

string stringIn(string member){
    string temp = "";
    bool valid = true;
    int size = 1;
    if(member == "company name" || member == "company address"){
        cout << "please enter the " << member <<": ";
    }
    else{
        cout << "Enter the employee's "<< member <<": ";
    }
    //Input validation
    ////////////////////////////////////////////////////////////////////////////
    if(member == "name"){ 
        do{ 
            if(!valid){
                cout << "Invalid " << member << ". Please try again: ";
            }
            getline(cin, temp);
            size = temp.length();
            valid = true;
            
            //Check Input
            if((!size>0)||temp[0]==' '){
                valid = false;
            }
            else{
                //Check if input is alphabetical
                for(int i = 0; i < size; i++){
                    if(temp[i]!=' '){
                        if(!isalpha(temp[i])){
                            valid = false;
                            break;
                        }
                    }
                }
            }
        }while(!valid);
    }
    if(member == "company address" || member == "company name"){
        do{
            if(!valid){
                cout << "Invalid " << member << ". Please try again: ";
            }
            getline(cin, temp);
            size = temp.length();
            valid = true;
            
            //Check Input
            if(size<=0){
                valid = false;
            }
            else{
                //Check if input is alphanumerical
                for(int i = 0; i < size; i++){
                    if(!(isspace(temp[i]) || ispunct(temp[i]) || isalnum(temp[i]))){
                        valid = false;
                        break;
                    }
                }
            }
        }while(!valid);
    }
    ////////////////////////////////////////////////////////////////////////////
    
    cout << endl;
    return temp;
}

float floatIn(string action){
    string str = "";
    bool valid = true;
    bool floating = false;
    int dPlace = 0;
    int f = 1;
    int size;
    float result = 0;
    
    cout << "Enter " << action << ": ";
    //Input validation
    ////////////////////////////////////////////////////////////////////////////
    do{
        //Get user input
        getline(cin, str);
        size = str.length();
        //Reset conditional vars
        valid = true;
        floating = false;
        dPlace = 0;
        
        //Check Input validity
        if(size <= 0){
            valid = false;
        }
        //String to Float conversion
        for(int i = 0; i < size; i++){
            //Check if the value entered was a float
            if(floating)dPlace++;
            
            //Break function loop if condition is encountered
            if(str[i] != '.' && str[i] < '0' || str[i] > '9'){
                valid = false;
                cout << "Invalid entry. Please try again: " << endl;
                break;
            }
            if(str[i] != '.'){
                result = (result * 10) + (str[i] - '0');
            }
            else{
                floating = true;
            }
        }

    }while(!valid);
    ////////////////////////////////////////////////////////////////////////////
    for(int i = 0; i < dPlace; i++){
        f *= 10;
    }
    return result / f;
}

int intIn(string action){
    bool valid = true;
    string str = "";
    int temp = 0;
    int size;
    
    //Input validation
    ///////////////////////////////////////////////////////////////////////////
    cout << "Please enter " << action << ": ";
    do{
        if(!valid){
            cout << "Invalid value. Please try again: ";
        }
        cin >> str;
        cin.ignore();
        size = str.length();
        valid = true;
        
        for(int i = 0; i < size; i++ ){
            //Break function loop
            if(isdigit(str[i])){
                temp = temp * 10 + (str[i] - '0');
            }
            else{
                valid = false;
                break;
            }
        }
    }while(!valid);
    ///////////////////////////////////////////////////////////////////////////
    
    cout << endl;
    return temp;
}