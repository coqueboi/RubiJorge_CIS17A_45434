/* 
 * File:   Ship.h
 * Author: Cokes PC
 *
 * Created on July 26, 2018, 7:57 PM
 */
using namespace std;
#include <string>

#ifndef SHIP_H
#define SHIP_H

class Ship {
public:
    Ship();
    Ship(const Ship &orig);
    virtual ~Ship();
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
    
    ///***Might be a good idea to store XY for **every** position***///
    //Or considering using the spawn, orient, and length to try and cheese it
    //Might have to store the positions in an array regardless 
    //Otherwise how are you going to check 
    //You could loop through an array that holds all these "place" values
    //if the guess matches one of them, it means you hit a ship
    //then hp--, set that coordinate to 00? (Otherwise you could farm the spot xD)
};

#endif /* SHIP_H */

