/* 
 * File:   main.cpp
 * Author: Jorge Rubi
 * Created on July 16th, 2018
 * Purpose: Midterm Menu
 */
 
//System Libraries Here
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <stdlib.h>
#include <iomanip>

using namespace std;
 
//User Libraries Here
#include "customer.h"
#include "Employee.h"
#include "Primes.h"

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions
const int HTHSND = 100000;
const int TTHSND = 10000;
const int THSND = 1000;
const int HNDRD = 100;
const int TEN = 10;
const int ONE = 1;

//Function Prototypes Here
void Menu();
void def(int inN);
int getN();
////////////////////////////////////////////////////////////////////////////////
void problem1();

void run(Customer *);
string sCheck(string);
float fCheck();
float loop(string);
////////////////////////////////////////////////////////////////////////////////
void problem2();

int intIn(string);          //Integer input
float floatIn(string);      //Float input
string stringIn(string);    //String input
void employeeData(Employee *, int);        //Input employee data, find gross pay
void prntChk(string, string, Employee *, int); //Print employee checks
string engNum(Employee, float);       //Convert number to English for check
////////////////////////////////////////////////////////////////////////////////
void problem3();

////////////////////////////////////////////////////////////////////////////////
void problem4();

int encrypt(int);
bool validCrypt(int);
int intInCrypt(string);

void decryptApp();

int decrypt(int);
bool validCrypt(int);
int intInCrypt(string);
////////////////////////////////////////////////////////////////////////////////
void problem5();

void factorial();
////////////////////////////////////////////////////////////////////////////////
void problem6();

////////////////////////////////////////////////////////////////////////////////
void problem7();

int intInPrime(string type);
void printPrime(Primes *);
Primes *factor(int);
////////////////////////////////////////////////////////////////////////////////


//Program Execution Begins Here
int main(int argc, char** argv) {
    Menu();
    //Exit
    return 0;
}
////////////////////////////////////////////////////////////////////////////////
void problem1(){
    //Dynamically create Customer structure
    Customer *lehr = nullptr; 
    lehr = new Customer;
    
    //Output prompt and run input dialog function
    cout<<"This program takes in a user's banking information and determines "
          "whether or not they have exceeded their checking account balance. ";
    run(lehr);
    
    //Return to Menu
    Menu();
}

void run(Customer *lehr){
    
    //Input dialog
    cout << "To begin,\n";
    lehr -> name = sCheck("name");

    cout << "Next,\n";
    lehr -> address = sCheck("address");

    cout << "Next,\n";
    cout << "Please enter your balance at the beginning of the month: ";
    lehr -> balance = fCheck();

    cout << "Next,\n";
    cout << "Please enter all checks written this month. "<<endl;
    cout << "When you are finished, enter -1."<<endl;
    lehr -> checks = loop("check");

    cout << "Finally,\n";
    cout << "Please enter all deposits credited this month. ";
    cout << "When you are finished, enter -1."<<endl;
    lehr -> deposits = loop("deposit");
    
    //Final Calculations
    cout << "Here is your report: "<<endl;
    cout << lehr -> name << endl;
    cout << lehr -> address << endl;
    cout << "Balance: " << lehr -> balance << endl;
    cout << "Monthly Checking Total: " << lehr -> checks << endl;
    cout << "Monthly Deposit Total: "  << lehr -> deposits << endl;
    cout << "___________________________________" << endl;
    lehr -> newBal = (lehr->balance + lehr->deposits - lehr->checks);
    cout << endl;
    cout << "Your net account balance is: " << lehr -> newBal << endl;
    if(lehr -> newBal < 0){
        cout << "Due to your account being overdrawn this month an additional "
                "$15 fee has been applied to your account." << endl;
        cout << "Your new account balance is: " << lehr -> newBal - 15 << endl;
    }
    
}
float loop(string type){
    float 
        total = 0.0f,
        input = 0.0f;
    do{
        cout << "Enter your " << type << "'s value: ";
        input = fCheck();
        if(input == -1){
            break;
        }
        else{
            total += input;
        }
        input = 0;
    }while(input != -1);
    cout<<endl;
    return total;
}
string sCheck(string member){
    string temp = "";
    bool valid = true;
    int size = 1;
    cout << "Please enter your "<< member <<": ";
    
    //Input validation
    ///////////////////////////////////////////////////////////////////////////
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
    if(member == "address"){
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
    ///////////////////////////////////////////////////////////////////////////
    
    cout << endl;
    return temp;
}
float fCheck(){
    float temp = 0.0f;
    string str = "";
    bool valid = true;
    bool floating = false;
    int size = 1;
    //Input validation
    ///////////////////////////////////////////////////////////////////////////
    //Check if input is a float
    do{
        if(!valid){
            cout << "Invalid entry. Please try again: ";
        }
        cin >> str;
        size = str.length();
        valid = true;
        
        //String to Float conversion
        for(int i = 0; i < size; i++){
            
            //Break function loop
            if(str[i] == '-'){
                return -1;
            }
            if(str[i] != '.'){
                temp = temp * 10 + (str[i] - '0');
                if(!isdigit(str[i])){
                    valid = false;
                    break;
                }
            }
        }
    }while(!valid);
    ///////////////////////////////////////////////////////////////////////////
    
    cout << endl;
    //Check if the value entered was a float
    for(int i = 0; i < size; i++){
        if(str[i] == '.'){
            floating = true;
        }
    }
    if(floating){
       return temp / 100;
    }
    else{
       return temp; 
    }
}
////////////////////////////////////////////////////////////////////////////////
void problem2(){
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
    
    Menu();
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
////////////////////////////////////////////////////////////////////////////////
void problem3(){
    cout << "This program is included in another project" << endl << endl;
    Menu();
}

////////////////////////////////////////////////////////////////////////////////
void problem4(){
    int temp = 0;
    char input;
    //Output program purpose
    cout << "This program allows you to encrypt numbers based on "
            "a company's telephone data encryption standard." << endl;
    cout << "This program only encrypts four-digit integers and only accepts ";
    cout << "the values 0, 1, 2, 3, 4, 5, 6, and 7. " << endl;
    cout << "An error will appear if you exceed these limits. " << endl << endl;
    cout << "To begin, "; 
    
    //Get user input
    temp = intInCrypt("number");
    if(validCrypt(temp)){
        cout << "The encrypted value is: " << encrypt(temp) << endl;
    }
    else{
        cout << "An error occurred. "<< temp <<" could not be encrypted." <<endl;
        cout << "Program shutting down. " << endl;
    }
    cout << endl << "Would you like to try decrypting a number? (y/n): ";
    cin >> input;
    if(input == 'y') decryptApp();
    Menu();
}

int encrypt(int temp){
    int swap;
    int digiOne = 0;
    int digiTwo = 0;
    int digiThree = 0;
    int digiFour = 0;
    //Find Digit values
    digiOne = temp / 1000;
    temp %= 1000;
    digiTwo = temp / 100;
    temp %= 100;
    digiThree = temp / 10;
    temp %= 10;
    digiFour = temp;
    //Encryption algorithm
    digiOne = (digiOne + 5) % 8;
    digiTwo = (digiTwo + 5) % 8;
    digiThree = (digiThree + 5) % 8;
    digiFour = (digiFour + 5) % 8;
    //Swap value positions
    ////////////////////////////////////////////////////////////////////////////
    swap = digiOne;
    digiOne = digiThree;
    digiThree = swap;
    swap = digiTwo;
    digiTwo = digiFour;
    digiFour = swap;
    ////////////////////////////////////////////////////////////////////////////
    
    //Complete encryption algorithm
    temp = (digiOne * 1000) + (digiTwo * 100) + (digiThree * 10) + digiFour;
    return temp;
}
bool validCrypt(int input){
    int temp = input;
    //ValidCryptate four digit number value & limit numbers
    ////////////////////////////////////////////////////////////////////////////
    int nThsnd = 0;
    int nHndrd = 0;
    int nTen = 0;
    int nOne = 0;
    
    nThsnd = temp / 1000;
    if(nThsnd > 7){
        return false;
    }
    temp %= 1000;
    
    nHndrd = temp / 100;
    if(nHndrd > 7){
        return false;
    }
    temp %= 100;
    
    nTen = temp / 10;
    if(nTen > 7){
        return false;
    }
    temp %= 10;
    
    nOne = temp;
    if(nOne > 7){
        return false;
    }
    ////////////////////////////////////////////////////////////////////////////
    return true;
}
int intInCrypt(string type){
    string temp = "";
    bool validCrypt = true;
    int size;
    int result = 0;
    
    cout << "please enter the " << type << " you would like to encrypt: ";
    //Input ValidCryptation
    ////////////////////////////////////////////////////////////////////////////
    do{
        validCrypt = true;
        getline(cin, temp);
        size = temp.length();
        
        if(size <= 0){
            validCrypt = false;
        }
        if(size != 4){
            validCrypt = false;
            cout << "Invalid entry. Please try again: ";
        }
        result = 0;
        for(int i = 0; i < size; i++){
            if(isdigit(temp[i])){
                result = (result * 10) + (temp[i] - '0');
            }
            else{
                cout << "Invalid entry. Please try again: ";
                validCrypt = false;
                break;
            }
        }
    }while(!validCrypt);
    ////////////////////////////////////////////////////////////////////////////
    return result;
}

void decryptApp(){
    int temp = 0;
    //Output program purpose
    cout << "This program allows you to decrypt numbers based on "
            "a company's telephone data decryption standard." << endl;
    cout << "This program only decrypts four-digit integers and only accepts ";
    cout << "the values 0, 1, 2, 3, 4, 5, 6, and 7. " << endl;
    cout << "An error will appear if you exceed these limits. " << endl << endl;
    cout << "To begin, "; 
    
    //Get user input
    temp = intInCrypt("number");
    if(validCrypt(temp)){
        cout << "The decrypted value is: " << decrypt(temp) << endl;
    }
    else{
        cout << "An error occurred. "<< temp <<" could not be decrypted." <<endl;
        cout << "Program shutting down. " << endl;
    }
}
int decrypt(int temp){
    int swap;
    int digiOne = 0;
    int digiTwo = 0;
    int digiThree = 0;
    int digiFour = 0;
    //Find Digit Values
    digiOne = temp / 1000;
    temp %= 1000;
    digiTwo = temp / 100;
    temp %= 100;
    digiThree = temp / 10;
    temp %= 10;
    digiFour = temp;
    //Decryption Algorithm
    if(digiOne == 0) digiOne = 3;
    else{
        digiOne -= 5;
        if(digiOne < 0) digiOne += 8;
    }
    if(digiTwo == 0) digiTwo = 3;
    else{
        digiTwo -= 5;
        if(digiTwo < 0) digiTwo += 8;
    }
    if(digiThree == 0) digiThree = 3;
    else{
        digiThree -= 5;
        if(digiThree < 0) digiThree += 8;
    }
    if(digiFour == 0) digiFour = 3;
    else{
        digiFour -= 5;
        if(digiFour < 0) digiFour += 8;
    }
    //Swap value positions
    ////////////////////////////////////////////////////////////////////////////
    swap = digiOne;
    digiOne = digiThree;
    digiThree = swap;
    swap = digiTwo;
    digiTwo = digiFour;
    digiFour = swap;
    ////////////////////////////////////////////////////////////////////////////
    
    //Complete encryption algorithm
    temp = (digiOne * 1000) + (digiTwo * 100) + (digiThree * 10) + digiFour;
    return temp;
}
////////////////////////////////////////////////////////////////////////////////
void problem5(){
    factorial();
    Menu();
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
////////////////////////////////////////////////////////////////////////////////
void problem6(){
    cout << "Here are the conversions for the following numbers:" << endl<<endl;
    
    cout << "2.875" << endl;
    cout << "in binary: 0000 0010.1110 0000" << endl;
    cout << "in octal : 2.7" << endl;
    cout << "in hex   : 2.E" << endl;
    cout << "float representation: " << endl;
    cout << "   0101 1100|0000 0000|0000 0000|0000 0010 " << endl;
    cout << "   or" << endl;
    cout << "   5C000002 base 16 " << endl <<endl;
    
    cout << "0.1796875" << endl;
    cout << "in binary: 0000 0000.0010 1110" << endl;
    cout << "in octal : 0.134" << endl;
    cout << "in hex   : 0.2E " << endl;
    cout << "float representation: " << endl;
    cout << "   0101 1100|0000 0000|0000 0000|1111 1110 " << endl;
    cout << "   or" << endl;
    cout << "   5C0000FE base 16 " << endl;
    
    cout << "---------------------------------------------------" << endl<<endl;
    
    cout << "Here are the conversions for the negative versions of the "
            "previous numbers: " << endl<<endl;
    
    cout << "-2.875" << endl;
    cout << "in binary: 1111 1101.0010 0000" << endl;
    cout << "in octal : -2.7" << endl;
    cout << "in hex   : -2.E" << endl;
    cout << "float representation: " << endl;
    cout << "   1110 1001|0000 0000|0000 0000|0000 0100 " << endl;
    cout << "   or" << endl;
    cout << "   E9000004 base 16 " << endl << endl;
    
    cout << "-0.1796875" << endl;
    cout << "in binary: 1111 1111.1101 0010" << endl;
    cout << "in octal : -0.134" << endl;
    cout << "in hex   : -0.2E " << endl;
    cout << "float representation: " << endl;
    cout << "   1110 1001|0000 0000|0000 0000|0000 0000" << endl;
    cout << "   or" << endl;
    cout << "   E9000000 base 16 " << endl;
    
    cout << "---------------------------------------------------" << endl<<endl;
    
    cout << "Here are the conversions for the following numbers:" << endl<<endl;
    cout << "Note: '...' after a number indicates a repeating decimal." << endl;
    cout << "Note: the following conversions follow the conversion "
            "standard given in class." << endl << endl;
    
    cout << "59999901 is equal to 1.06..." << endl << endl;
    
    cout << "59999902 is equal to 2.12121212128" << endl << endl;
    
    cout << "A66667FE is equal to -2.666676" << endl << endl;
    
    Menu();
}

////////////////////////////////////////////////////////////////////////////////
void problem7(){
    //Declare variables
    int num;
    Primes *temp;
    //Initialize variables
    num = intInPrime("number");
    //Calculations
    temp = factor(num);
    //Output
    printPrime(temp);
    Menu();
}

void printPrime(Primes *primes){
    int size = primes->nPrimes;
    if(size > 0){
        cout << endl << "The factors for this number are: ";
        for(int i = 0; i < size; i++){
            cout << static_cast<int> (primes->primes[i].prime) << "^"
                 << static_cast<int> (primes->primes[i].power);
            if(i != size - 1){
                cout<<", ";
            }
        }
    }
    else cout << "This number is prime." << endl;
}
Primes *factor(int num){
    int size = 25;
    int count = 0;
    Primes *factors = new Primes;
    int primes[size] = { 2,3,5,7,11,
                        13,17,19,23,29,
                        31,37,41,43,47,
                        53,59,61,67,71,
                        73,79,83,89,97};
    factors->primes = new Prime[num];
    //Prime factor algorithm
    for(int i = 0; i < size; i++){
        while(num % primes[i] == 0){
            if(factors->primes[count].power == 0){
                factors->primes[count].power++;
                factors->primes[count].prime = primes[i];
            }
            else{
                factors->primes[count].power++;
            }
            num /= primes[i];
            if(num < 2){break;}
        }
        if(factors->primes[count].power != 0){
            count++;
        }
    }
    if(num > 2 && count != 0){
        factors->primes[count].power++;
        factors->primes[count].prime = num;
        count++;
    }
    else if(num > 100) factors->nPrimes = -1;
    factors->nPrimes = count;
    return factors;
}
int intInPrime(string type){
    string temp = "";
    bool valid = true;
    int size;
    int result = 0;
    cout << "This program factors an input integer into it's prime numbers.";
    cout << endl;
    cout << "Any number between [2,10000] where n is not a prime > 100 will be";
    cout << " a valid number to check for prime factors." << endl << endl;
    cout << "To begin, " << endl; 
    cout << "   please enter the " << type << " you would like to factor: ";
    //Input validation
    ////////////////////////////////////////////////////////////////////////////
    do{
        valid = true;
        getline(cin, temp);
        size = temp.length();
        
        if(size <= 0){
            valid = false;
        }
        result = 0;
        for(int i = 0; i < size; i++){
            if(isdigit(temp[i])){
                result = (result * 10) + (temp[i] - '0');
            }
            else{
                cout << "Invalid entry. Please try again: ";
                valid = false;
                break;
            }
        }
    }while(!valid);
    ////////////////////////////////////////////////////////////////////////////
    return result;
}
////////////////////////////////////////////////////////////////////////////////


void Menu(){
    
    //Output statements go here
    cout << endl << endl;
    cout << "--------Program list--------" << endl;
    cout << "1. Checking Account Balance" << endl;
    cout << "2. Employee Paycheck" << endl;
    cout << "3. Stat Stub" << endl;
    cout << "4. Data Encryption/Decryption" << endl;
    cout << "5. Largest Factorial of Primitive Data types" << endl;
    cout << "6. Scaled Binary - 4 Byte/32bit Representation" << endl;
    cout << "7. Prime Factor" << endl << endl;
    int inN;
    do{
        inN=getN();
        switch(inN){
           case 1:    problem1();break;
           case 2:    problem2();break;
           case 3:    problem3();break;
           case 4:    problem4();break;
           case 5:    problem5();break;
           case 6:    problem6();break;
           case 7:    problem7();break;
           default:   def(inN);}
    }while(inN<8);
}
void def(int inN){
    cout << "Your input was invalid." << endl;
    cout << "The program is now stopping." << endl;
    exit(EXIT_FAILURE);
}
int getN(){
    int temp = 0;
    cout << "Please enter the number of the program you would like to run: ";
    cin >> temp;
    cin.ignore();
    cout << endl;
    return temp;
}
////////////////////////////////////////////////////////////////////////////////