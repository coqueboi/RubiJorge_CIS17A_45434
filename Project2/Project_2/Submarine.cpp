/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Submarine.cpp
 * Author: Cokes PC
 * 
 * Created on July 26, 2018, 7:59 PM
 */
#include "Ship.h"
#include "Submarine.h"
using namespace std;

Submarine::Submarine() {
    name = "Submarine";
    length = 3;
    orient = rand() % 2;
    hp = 3;
    coords[0] = rand() % 10;
    coords[1] = rand() % 10;
}

Submarine::Submarine(const Submarine& orig) {
    name = orig.name;
    length = orig.length;
    orient = orig.orient;
    hp = orig.hp;
    *coords = *orig.coords;
}

Submarine::~Submarine() {
}
///***Getters***///
void Submarine::setCoords(){
    coords[0] = rand() % 10;
    coords[1] = rand() % 10;
}
string Submarine::getName(){
    return name;
}
int Submarine::getLength(){
    return length;
}
int Submarine::getOrient(){
    return orient;
}
int Submarine::getHp(){
    return hp;
}
int *Submarine::getCoords(){
    return coords;
}