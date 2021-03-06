/* 
 * File:   main.cpp
 * Author: Jorge Rubi
 * Created on July 15th, 2018, 10:02PM
 * Purpose: Data Encryption 
 */
 
//System Libraries Here
#include <iostream>
#include <cstdlib>
using namespace std;
 
//User Libraries Here
 
//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
int encrypt(int);
bool validCrypt(int);
int intInCrypt(string);

//Program Execution Begins Here
int main(int argc, char** argv) {
    int temp = 0;
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
    //Exit
    return 0;
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