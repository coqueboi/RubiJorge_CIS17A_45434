/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Inventory.h
 * Author: Cokes PC
 *
 * Created on July 23, 2018, 11:43 PM
 */

#ifndef INVENTORY_H
#define INVENTORY_H

class Inventory {
public:
    //Default constructor sets all the member vars to 0
    Inventory();
    //Constructor #2
    Inventory(int itemNum, float cost, int quant);
    virtual ~Inventory();
    
    void setItemNum(int);
    void setQuant(int);
    void setCost(float);
    void setTotal();
    
    int getItemNum();
    int getQuant();
    float getCost();
    float getTotal();
    
    
private:
    int itemNum;        //Holds the item's item number
    int quant;          //Holds the quantity of items on hand
    float cost;         //Holds the per-unit cost of the item
    float total;        //Holds the total inventory cost of the item
    //total = quant * cost
};

#endif /* INVENTORY_H */

