/* 
 * File:   main.cpp
 * Author: Jorge Rubi
 * Created on Month Day Year Time
 * Purpose:
 */

//System Libraries
#include <iostream> //I/O Library -> cout,endl
#include <cstring>
#include <cctype>
#include <cstdlib>

using namespace std; //namespace I/O stream library created

enum req {
    tooShrt,// Less that 6 characters
    noUppr,// No uppercase character
    noLwer,// No lowercase character
    noDigit,// No number
    pass// Passed
};

enum req passChk(const char*);

int main(int argc, char** argv) {
    int size = 100;
    char *arr = new char[size];
    cout<<"Please enter your password: "<<endl;
    cout<<"Your password must "<<endl;
    cout<<" - be at least six characters long."<<endl;
    cout<<" - contain at least one uppercase and one lowercase letter."<<endl;
    cout<<" - have at least one digit."<<endl;
    cout<<"Please enter your password: ";
    cin>>arr;
    req errors=passChk(arr);
    switch(errors){
        case tooShrt: 
            std::cout<<"Your password is too short, try again.";break;
        case noUppr: 
            std::cout<<"Your password contains no uppercase character";break;
        case noLwer: 
            std::cout<<"Your password contains no lowercase character.";break;
        case noDigit: 
            std::cout<<"Your password contains no number.";break;
        case pass: 
            std::cout<<"Your password passes all requirements!.";break;
        default: 
            std::cout<<"Unknown error, try again.";
     }
    return 0;
}

enum req passChk(const char *arr){
    req temp;
    bool length = false;
    bool upper = false;
    bool lower = false;
    bool digit = false;
    
    int size = strlen(arr);
    if(size < 6){
        temp = tooShrt;
        return temp;
    }
    
    for(int i = 0; i < size; i++){
        if(isupper(arr[i])){
         upper = true;   
        }
        if(islower(arr[i])){
            lower = true;
        }
        if(isdigit(arr[i])){
            digit = true;
        }
    }
    
    if(!upper){
        temp = noUppr;
    }
    else if(!lower){
        temp = noLwer;
    }
    else if(!digit){
        temp = noDigit;
    }
    else{
        temp = pass;
    }
    
    return temp;
}