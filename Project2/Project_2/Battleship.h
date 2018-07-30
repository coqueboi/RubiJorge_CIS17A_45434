/* 
 * File:   Battleship.h
 * Author: Cokes PC
 *
 * Created on July 26, 2018, 7:58 PM
 */
#include "Ship.h"

#ifndef BATTLESHIP_H
#define BATTLESHIP_H

class Battleship : public Ship {
public:
    friend class Game;
    Battleship();
    Battleship(const Battleship& orig);
    virtual ~Battleship();
    
    //Overloaded postfix -- operator
    Battleship operator--(int){
        hp--;                       //Updates the Hp value by subtracting one 
        return *this;
    }
    //Setters for modifying values
    virtual void setCoords();               //Creates a new spawnpoint
    //Getters for returning the data in the member
    string getName();
    int getLength();
    int getOrient();
    int getHp();
    virtual int *getCoords();
private:

};

#endif /* BATTLESHIP_H */

