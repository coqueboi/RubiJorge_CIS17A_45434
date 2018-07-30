#include "AircraftCarrier.h"
using namespace std;

//Constructor
AircraftCarrier::AircraftCarrier() {
    name = "Aircraft Carrier";
    length = 5;
    orient = rand() % 2;
    hp = 5;
    coords[0] = 0;
    coords[1] = 0;
    //Initialize placement coordinate array
    place = new int[length * 2]; 
    for(int i = 0; i < (length*2); i++){
        place[i] = 0;
    }
}
//Copy constructor
AircraftCarrier::AircraftCarrier(const AircraftCarrier& orig) {
    name = orig.name;
    length = orig.length;
    orient = orig.orient;
    hp = orig.hp;
    *coords = *orig.coords;
}
//Destructor
AircraftCarrier::~AircraftCarrier() {
}
///***Getters***///
void AircraftCarrier::setCoords(){
    coords[0] = rand() % 10;
    coords[1] = rand() % 10;
}
string AircraftCarrier::getName(){
    return name;
}
int AircraftCarrier::getLength(){
    return length;
}
int AircraftCarrier::getOrient(){
    return orient;
}
int AircraftCarrier::getHp(){
    return hp;
}
int *AircraftCarrier::getCoords(){
    return coords;
}
