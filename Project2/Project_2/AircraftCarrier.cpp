/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AircraftCarrier.cpp
 * Author: Cokes PC
 * 
 * Created on July 26, 2018, 7:58 PM
 */
#include "AircraftCarrier.h"
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
    coords = orig.coords;
}
//Destructor
AircraftCarrier::~AircraftCarrier() {
}

