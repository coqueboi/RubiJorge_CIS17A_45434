/* 
 * File:   Cruiser.h
 * Author: Cokes PC
 *
 * Created on July 26, 2018, 7:59 PM
 */
#include "Ship.h"

#ifndef CRUISER_H
#define CRUISER_H

class Cruiser : public Ship {
    friend class Game;
public:
    Cruiser();
    Cruiser(const Cruiser& orig);
    virtual ~Cruiser();
    
    //Overloaded postfix -- operator
    Cruiser operator--(int){
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

#endif /* CRUISER_H */

