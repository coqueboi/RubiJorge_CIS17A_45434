/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Game.cpp
 * Author: Cokes PC
 * 
 * Created on July 26, 2018, 7:55 PM
 */
#include <iostream>
#include "Game.h"
#include "Ship.h"
#include "AircraftCarrier.h"
#include "Battleship.h"
#include "Submarine.h"
#include "Cruiser.h"
#include "Destroyer.h"

using namespace std;

Game::Game() {
}

Game::Game(const Game& orig) {
}

Game::~Game() {
}

void Game::print(){
    AircraftCarrier ship1;
    int *temp;
    temp = new int[2];
    
    Battleship ship2;
    int *temp2;
    temp2 = new int[2];
    
    cout << ship1.getName() << endl;
    cout << ship1.getLength() << endl;
    cout << ship1.getOrient() << endl;
    cout << ship1.getHp() << endl;
    ship1--;
    cout << ship1.getHp() << endl;
    temp = ship1.getCoords();
    cout << temp[0] << temp[1] << endl;
    //Reset coords in case it matches with anyone else's? 
    ship1.setCoords();
    temp = ship1.getCoords();
    cout << temp[0] << temp[1] << endl;
    
    cout<<endl<<endl;
    
    
    cout << ship2.getName() << endl;
    cout << ship2.getLength() << endl;
    cout << ship2.getOrient() << endl;
    cout << ship2.getHp() << endl;
    ship2--;
    cout << ship2.getHp() << endl;
    temp2 = ship2.getCoords();
    cout << temp2[0] << temp2[1] << endl;
    
    //Reset coords in case it matches with anyone else's? 
    ship2.setCoords();
    
    temp2 = ship2.getCoords();
    cout << temp2[0] << temp2[1] << endl;
}
