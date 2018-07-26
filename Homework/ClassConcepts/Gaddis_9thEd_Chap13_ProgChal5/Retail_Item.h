#include <string>
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Retail_Item.h
 * Author: Cokes PC
 *
 */
using namespace std;

#ifndef RETAIL_ITEM_H
#define RETAIL_ITEM_H

class Retail_Item {
public:
    //Constructor
    Retail_Item();
    Retail_Item(string, int, float);
    virtual ~Retail_Item();
    
    //Mutator functions
    void setDesc(string);
    void setUnits(int);
    void setPrice(float);
    
    //Accessor functions
    string getDesc();
    int getUnits();
    float getPrice();
    
private:
    string desc;         //Brief description of item
    int units;           //Holds the number of units in inventory
    float price;         //Holds the item's retail price
};



#endif /* RETAIL_ITEM_H */

