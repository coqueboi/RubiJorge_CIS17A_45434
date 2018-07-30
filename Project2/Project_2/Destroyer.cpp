#include "Destroyer.h"
using namespace std;

Destroyer::Destroyer() {
    name = "Destroyer";
    length = 2;
    orient = rand() % 2;
    hp = 2;
    coords[0] = 0;
    coords[1] = 0;
    //Initialize placement coordinate array
    place = new int[length * 2]; 
    for(int i = 0; i < (length*2); i++){
        place[i] = 0;
    }
}

Destroyer::Destroyer(const Destroyer& orig) {
    name = orig.name;
    length = orig.length;
    orient = orig.orient;
    hp = orig.hp;
    *coords = *orig.coords;
}

Destroyer::~Destroyer() {
}

///***Getters***///
void Destroyer::setCoords(){
    coords[0] = rand() % 10;
    coords[1] = rand() % 10;
}
string Destroyer::getName(){
    return name;
}
int Destroyer::getLength(){
    return length;
}
int Destroyer::getOrient(){
    return orient;
}
int Destroyer::getHp(){
    return hp;
}
int *Destroyer::getCoords(){
    return coords;
}