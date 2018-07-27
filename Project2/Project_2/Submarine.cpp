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

#include "Submarine.h"

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
    coords = orig.coords;
}

Submarine::~Submarine() {
}

