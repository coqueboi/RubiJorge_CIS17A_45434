/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Battleship.cpp
 * Author: Cokes PC
 * 
 * Created on July 26, 2018, 7:58 PM
 */

#include <iostream>
#include <cstdlib>

#include "Battleship.h"
#include "Ship.h"
using namespace std;

Battleship::Battleship() {
    name = "Battleship";
    length = 4;
    orient = rand() % 2;
    hp = 4;
    coords[0] = rand() % 10;
    coords[1] = rand() % 10;
}

Battleship::Battleship(const Battleship& orig) {
    name = orig.name;
    length = orig.length;
    orient = orig.orient;
    hp = orig.hp;
    *coords = *orig.coords;
}

Battleship::~Battleship() {
}
///***Getters***///
void Battleship::setCoords(){
    coords[0] = rand() % 10;
    coords[1] = rand() % 10;
}
string Battleship::getName(){
    return name;
}
int Battleship::getLength(){
    return length;
}
int Battleship::getOrient(){
    return orient;
}
int Battleship::getHp(){
    return hp;
}
int *Battleship::getCoords(){
    return coords;
}