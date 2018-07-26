/* 
 * File:   main.cpp
 * Author: Jorge Rubi
 * Purpose: Numbers Class
 */
 
//System Libraries Here
#include <iostream>

using namespace std;
 
//User Libraries Here
#include "Numbers.h"

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions
 
//Function Prototypes Here
void run();

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Run the program
    run();
    //Exit
    return 0;
}
void run(){
    Numbers num;
    num.setNum();
    num.getNum();
    num.engNum();
    num.print();
    
}