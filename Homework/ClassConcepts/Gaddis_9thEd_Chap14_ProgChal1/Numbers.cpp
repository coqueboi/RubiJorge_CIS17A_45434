/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Numbers.cpp
 * Author: Cokes PC
 * 
 * Created on July 24, 2018, 1:44 PM
 */
using namespace std;

#include <iostream>

#include "Numbers.h"

//Default Constructor
Numbers::Numbers() {
    this -> number = 0;
}
//Constructor
Numbers::Numbers(int number) {
    this -> number = number;
}
//Deconstructor
Numbers::~Numbers() { 
}

void Numbers::setNum(){
    
    int num = 0;
    string temp = "";
    int size;
    bool valid = true;
    cout << "This program translates a whole dollar amount in the range of "
            "0 and 9999 into an English description of the number." << endl;
    cout << "To begin, please enter a number : ";
    
    //Do not accept a value less than 0 
    do{
        if(!valid){
            cout << "Invalid input, please try again: ";
        }
        //Use cin instead of getline to avoid blank space characters
        cin >> temp;
        cin.ignore();
        size = temp.length();
        
        //Make sure input is no greater than 4 chars
        if(size > 4){
            valid = false;
            continue;
        }
        for(int i = 0; i < size; i++){
            if(isdigit(temp[i])){
                num = ((num * 10) + (temp[i] - '0'));
            }
            else{
                valid = false;
                break;
            }
        }
    }while(!valid);
    this -> number = num;
}

int Numbers::getNum(){
    return this -> number;
}
//Convert integer value into english
void Numbers::engNum(){
    const int HTHSND = 100000;
    const int TTHSND = 10000;
    const int THSND = 1000;
    const int HNDRD = 100;
    const int TEN = 10;
    const int ONE = 1;
    
    int temp = this -> number;
    bool teenNum = false;
    bool teenTHSND = false;
    string amtWord = "";
    
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
    
    this -> amtWord = amtWord;
}
//Print the integer's value in english
void Numbers::print(){
    cout << "Your value is: ";
    cout << this -> amtWord << endl;
}