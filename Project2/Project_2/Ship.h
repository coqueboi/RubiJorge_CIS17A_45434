/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ship.h
 * Author: Cokes PC
 *
 * Created on July 26, 2018, 7:57 PM
 */
using namespace std;

#ifndef SHIP_H
#define SHIP_H

class Ship {
public:
    Ship();
    Ship(const Ship &orig);
    virtual ~Ship();
    
    //Ship generation function
    
    
private:

protected:
    //Holds the ship name/type
    string name;
    //Holds the length/size of the ship
    int length;
    //Holds the ship orientation (0 is horizontal, 1 is vertical)
    int orient; 
    //Holds the amount of hit points the ship can take
    int hp;
    //Holds X & Y Spawnpoint coordinates for the ship 
    int coords[2];
};

#endif /* SHIP_H */

