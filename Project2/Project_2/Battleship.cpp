#include "Battleship.h"
using namespace std;

Battleship::Battleship() {
    name = "Battleship";
    length = 4;
    orient = rand() % 2;
    hp = 4;
    coords[0] = 0;
    coords[1] = 0;
    //Initialize placement coordinate array
    place = new int[length * 2]; 
    for(int i = 0; i < (length*2); i++){
        place[i] = 0;
    }
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