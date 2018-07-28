/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Destroyer.h
 * Author: Cokes PC
 *
 * Created on July 26, 2018, 7:59 PM
 */
#include "Ship.h"
#ifndef DESTROYER_H
#define DESTROYER_H

class Destroyer : public Ship {
public:
    Destroyer();
    Destroyer(const Destroyer& orig);
    virtual ~Destroyer();
    
    //Overloaded postfix -- operator
    Destroyer operator--(int){
        hp--;                       //Updates the Hp value by subtracting one 
        return *this;
    }
    //Setters for modifying values
    void setCoords();               //Creates a new spawnpoint
    //Getters for returning the data in the member
    string getName();
    int getLength();
    int getOrient();
    int getHp();
    int *getCoords();
private:

};

#endif /* DESTROYER_H */

