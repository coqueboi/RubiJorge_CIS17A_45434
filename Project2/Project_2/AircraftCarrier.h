/* 
 * File:   AircraftCarrier.h
 * Author: Cokes PC
 *
 * Created on July 26, 2018, 7:58 PM
 */
#include "Ship.h"

#ifndef AIRCRAFTCARRIER_H
#define AIRCRAFTCARRIER_H

class AircraftCarrier : public Ship {
public:
    AircraftCarrier();
    AircraftCarrier(const AircraftCarrier& orig);
    virtual ~AircraftCarrier();
    
    //Overloaded postfix -- operator
    AircraftCarrier operator--(int){
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

#endif /* AIRCRAFTCARRIER_H */

