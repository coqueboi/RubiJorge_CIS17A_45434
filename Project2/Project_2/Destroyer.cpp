/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Destroyer.cpp
 * Author: Cokes PC
 * 
 * Created on July 26, 2018, 7:59 PM
 */
#include "Ship.h"
#include "Destroyer.h"
using namespace std;

Destroyer::Destroyer() {
    name = "Destroyer";
    length = 2;
    orient = rand() % 2;
    hp = 2;
    coords[0] = rand() % 10;
    coords[1] = rand() % 10;
}

Destroyer::Destroyer(const Destroyer& orig) {
    name = orig.name;
    length = orig.length;
    orient = orig.orient;
    hp = orig.hp;
    *coords = *orig.coords;
}

Destroyer::~Destroyer() {
}

///***Getters***///
void Destroyer::setCoords(){
    coords[0] = rand() % 10;
    coords[1] = rand() % 10;
}
string Destroyer::getName(){
    return name;
}
int Destroyer::getLength(){
    return length;
}
int Destroyer::getOrient(){
    return orient;
}
int Destroyer::getHp(){
    return hp;
}
int *Destroyer::getCoords(){
    return coords;
}