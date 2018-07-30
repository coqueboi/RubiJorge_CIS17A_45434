#include "Cruiser.h"
using namespace std;

Cruiser::Cruiser() {
    name = "Cruiser";
    length = 3;
    orient = rand() % 2;
    hp = 3;
    coords[0] = 0;
    coords[1] = 0;
    //Initialize placement coordinate array
    place = new int[length * 2]; 
    for(int i = 0; i < (length*2); i++){
        place[i] = 0;
    }
}

Cruiser::Cruiser(const Cruiser& orig) {
    name = orig.name;
    length = orig.length;
    orient = orig.orient;
    hp = orig.hp;
    *coords = *orig.coords;
}

Cruiser::~Cruiser() {
}

///***Getters***///
void Cruiser::setCoords(){
    coords[0] = rand() % 10;
    coords[1] = rand() % 10;
}
string Cruiser::getName(){
    return name;
}
int Cruiser::getLength(){
    return length;
}
int Cruiser::getOrient(){
    return orient;
}
int Cruiser::getHp(){
    return hp;
}
int *Cruiser::getCoords(){
    return coords;
}