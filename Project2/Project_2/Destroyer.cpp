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

#include "Destroyer.h"

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
    coords = orig.coords;
}

Destroyer::~Destroyer() {
}

