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
    //Holds the placement coordinates in a one dimensional array for easy access
    int *place;
};

#endif /* SHIP_H */

