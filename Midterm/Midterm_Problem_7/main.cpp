/* 
 * File:   main.cpp
 * Author: Jorge Rubi
 * Created on July 16th, 2018
 * Purpose: Prime Factor
 */
 
//System Libraries Here
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <cmath>

using namespace std;
 
//User Libraries Here
#include "Primes.h" 
//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions
 
//Function Prototypes Here
int intInPrime(string type);
void printPrime(Primes *);
Primes *factor(int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    int num;
    Primes *temp;
    //Initialize variables
    num = intInPrime("number");
    //Calculations
    temp = factor(num);
    //Output
    printPrime(temp);
    //Exit
    return 0;
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