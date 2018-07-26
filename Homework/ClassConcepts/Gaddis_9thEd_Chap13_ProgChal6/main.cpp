/* 
 * File:   main.cpp
 * Author: Jorge Rubi
 * Purpose: Inventory Class
 */
 
//System Libraries Here
#include <iostream>

#include "Inventory.h"
using namespace std;
 
//User Libraries Here
 
//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions
 
//Function Prototypes Here
void run();

//Program Execution Begins Here
int main(int argc, char** argv) {
    
    run();
 
    //Exit
    return 0;
}

void run(){
    bool valid = true;
    int numIn, quantIn;
    float costIn;
    
    //Output prompt
    cout << "This program calculates data for a retail store's inventory." << endl;
    cout << "By following the prompts below you will be able to calculate the\n"
            "total cost of various items based on their cost and quantity.\n"
            "To begin, first ";
    
    //Input validation
    do{
        if(!valid){
            cout << "Negative values are invalid. \n"
                    "Please re-enter the item's properties." << endl << endl;
        }
        cout << "enter the item's item number: ";
        cin >> numIn;
        if(numIn < 0){
            valid = false;
            continue;
        }
        cout << "Next, enter the quantity of items: ";
        cin >> quantIn;
        if(quantIn < 0){
            valid = false;
            continue;
        }
        cout << "Finally, enter the per-unit cost of the item: ";
        cin >> costIn;
        if(costIn < 0){
            valid = false;
            continue;
        }
    }while(!valid);
    
    //Perform calculations
    Inventory item(numIn, costIn, quantIn);
    
    //Output results
    cout << endl << endl;
    cout << "Item #" << item.getItemNum() << ", ";
    cout << "at a per-unit cost of $" << item.getCost() << " ";
    cout << "would cost $" << item.getTotal() <<" for ";
    cout << item.getQuant() << " units." << endl;
}