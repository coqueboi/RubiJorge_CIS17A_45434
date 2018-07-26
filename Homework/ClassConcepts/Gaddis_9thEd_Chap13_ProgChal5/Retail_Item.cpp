/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Retail_Item.cpp
 * Author: Cokes PC
 * 
 */

#include "Retail_Item.h"
//Constructor
Retail_Item::Retail_Item() {
    //Initialize Vars
    string desc = "";
    int units = 0;     
    float price = 0.0f;
}
//Constructor
Retail_Item::Retail_Item(string desc, int units, float price) {
    //Note: Due to name conflict, use "this ->" to point at the proper member
    this -> desc  = desc;
    this -> units = units;
    this -> price = price;
}

//Deconstructor (not used in this program)
Retail_Item::~Retail_Item() {
}

//Mutator Functions
void Retail_Item::setDesc(string arg){
    this -> desc = arg;
}
void Retail_Item::setUnits(int arg){
    this -> units = arg;
}
void Retail_Item::setPrice(float arg){
    this -> price = arg;
}

//Accessor Functions
string Retail_Item::getDesc(){
    return this -> desc;
}
int Retail_Item::getUnits(){
    return this -> units;
}
float Retail_Item::getPrice(){
    return this -> price;
}