/* 
 * File:   main.cpp
 * Author: Jorge Rubi
 * Purpose: Retail Item Class
 */
 
//System Libraries Here
#include <iostream>

#include "Retail_Item.h"
using namespace std;
 
//User Libraries Here
 
//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions
 
//Function Prototypes Here
 
//Program Execution Begins Here
int main(int argc, char** argv) {
    
    //Using constructor which accepts 3 args
    //////////////////////////////////////////////////
    Retail_Item item1("Jacket",12,59.95);           //
    Retail_Item item2("Designer Jeans",40,34.95);   //
    //////////////////////////////////////////////////
    
    //Use of single-argument constructors
    //////////////////////////////////////////////////
    Retail_Item item3;                              //
    item3.setDesc("Shirt");                         //
    item3.setUnits(20);                             //
    item3.setPrice(24.95);                          //
    //////////////////////////////////////////////////
 
    //Output
    cout << item1.getDesc()  << " ";
    cout << item1.getUnits() << " ";
    cout << item1.getPrice() << " " << endl;
    
    cout << item2.getDesc()  << " ";
    cout << item2.getUnits() << " ";
    cout << item2.getPrice() << " " << endl;
    
    cout << item3.getDesc()  << " ";
    cout << item3.getUnits() << " ";
    cout << item3.getPrice() << " " << endl;
    
    //Exit
    return 0;
}