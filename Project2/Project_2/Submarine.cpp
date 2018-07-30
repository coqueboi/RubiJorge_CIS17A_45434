#include "Submarine.h"
using namespace std;

Submarine::Submarine() {
    name = "Submarine";
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

Submarine::Submarine(const Submarine& orig) {
    name = orig.name;
    length = orig.length;
    orient = orig.orient;
    hp = orig.hp;
    *coords = *orig.coords;
}

Submarine::~Submarine() {
}
///***Getters***///
void Submarine::setCoords(){
    coords[0] = rand() % 10;
    coords[1] = rand() % 10;
}
string Submarine::getName(){
    return name;
}
int Submarine::getLength(){
    return length;
}
int Submarine::getOrient(){
    return orient;
}
int Submarine::getHp(){
    return hp;
}
int *Submarine::getCoords(){
    return coords;
}