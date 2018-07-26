/* 
 * File:   main.cpp
 * Author: Jorge Rubi
 * Created on July 14th, 2018, 6:21 PM
 * Purpose: Customer Checking Account
 */
 
//System Libraries Here
#include <iostream>
#include <cctype>
#include "customer.h"

using namespace std;
 
//User Libraries Here
 
//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions
 
//Function Prototypes Here
void run(Customer *);
string sCheck(string);
float fCheck();
float loop(string);

//Program Execution Begins Here
int main(int argc, char** argv) {
    
    //Dynamically create Customer structure
    Customer *lehr = nullptr; 
    lehr = new Customer;
    
    //Output prompt and run input dialog function
    cout<<"This program takes in a user's banking information and determines "
          "whether or not they have exceeded their checking account balance. ";
    run(lehr);
    
    
    //Exit
    return 0;
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