/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cruiser.cpp
 * Author: Cokes PC
 * 
 * Created on July 26, 2018, 7:59 PM
 */
#include "Ship.h"
#include "Cruiser.h"
using namespace std;

Cruiser::Cruiser() {
    name = "Cruiser";
    length = 3;
    orient = rand() % 2;
    hp = 3;
    coords[0] = rand() % 10;
    coords[1] = rand() % 10;
}

Cruiser::Cruiser(const Cruiser& orig) {
    name = orig.name;
    length = orig.length;
    orient = orig.orient;
    hp = orig.hp;
    *coords = *orig.coords;
}

Cruiser::~Cruiser() {
}

///***Getters***///
void Cruiser::setCoords(){
    coords[0] = rand() % 10;
    coords[1] = rand() % 10;
}
string Cruiser::getName(){
    return name;
}
int Cruiser::getLength(){
    return length;
}
int Cruiser::getOrient(){
    return orient;
}
int Cruiser::getHp(){
    return hp;
}
int *Cruiser::getCoords(){
    return coords;
}