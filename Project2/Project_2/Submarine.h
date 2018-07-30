/* 
 * File:   Submarine.h
 * Author: Cokes PC
 *
 * Created on July 26, 2018, 7:59 PM
 */
#include "Ship.h"

#ifndef SUBMARINE_H
#define SUBMARINE_H

class Submarine : public Ship {
    friend class Game;
public:
    Submarine();
    Submarine(const Submarine& orig);
    virtual ~Submarine();
    
    //Overloaded postfix -- operator
    Submarine operator--(int){
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

#endif /* SUBMARINE_H */

