/* 
 * File:   AircraftCarrier.cpp
 * Author: Cokes PC
 * 
 * Created on July 26, 2018, 7:58 PM
 */
#include "AircraftCarrier.h"
#include "Ship.h"
using namespace std;

//Constructor
AircraftCarrier::AircraftCarrier() {
    name = "Aircraft Carrier";
    length = 5;
    orient = rand() % 2;
    hp = 5;
    coords[0] = rand() % 10;
    coords[1] = rand() % 10;
}
//Copy constructor
AircraftCarrier::AircraftCarrier(const AircraftCarrier& orig) {
    name = orig.name;
    length = orig.length;
    orient = orig.orient;
    hp = orig.hp;
    *coords = *orig.coords;
}
//Destructor
AircraftCarrier::~AircraftCarrier() {
}
///***Getters***///
void AircraftCarrier::setCoords(){
    coords[0] = rand() % 10;
    coords[1] = rand() % 10;
}
string AircraftCarrier::getName(){
    return name;
}
int AircraftCarrier::getLength(){
    return length;
}
int AircraftCarrier::getOrient(){
    return orient;
}
int AircraftCarrier::getHp(){
    return hp;
}
int *AircraftCarrier::getCoords(){
    return coords;
}
