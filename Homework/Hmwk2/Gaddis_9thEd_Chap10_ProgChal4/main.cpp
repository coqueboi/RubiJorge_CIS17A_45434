/* 
 * File:   main.cpp
 * Author: Jorge Rubi
 * Created on July 3rd, 2018, 11:30 AM
 * Purpose: Average Number of Letters
 */
 
//System Libraries Here
#include <iostream>
#include <cstring>
using namespace std;
 
//User Libraries Here
 
//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions
 
//Function Prototypes Here
 
//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE=1000; //Maximum of 999 characters
    char *arr;
    //Input or initialize values Here
    arr=new char[SIZE]; 
    cin.getline(arr,SIZE);
    for(int i=0;i<SIZE;i++){
        cout<<arr[i];
    }
    //Process/Calculations Here
     
    //Output Located Here
    
    //Exit
    return 0;
}