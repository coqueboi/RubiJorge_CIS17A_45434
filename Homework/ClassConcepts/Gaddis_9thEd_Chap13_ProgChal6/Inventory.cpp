/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Inventory.cpp
 * Author: Cokes PC
 * 
 */

#include "Inventory.h"
//Default constructor
Inventory::Inventory() {
    int itemNum = 0;      
    int quant = 0;   
    float cost = 0.0f;     
    float total = 0.0f;
}
//Constructor
Inventory::Inventory(int itemNum, float cost, int quant) {
    this -> itemNum = itemNum;
    this -> cost = cost;
    this -> quant = quant;
    setTotal();
}

//Deconstructor
Inventory::~Inventory() {
}

//Setters
void Inventory::setItemNum(int arg){
    this -> itemNum = arg;
}
void Inventory::setQuant(int arg){
    this -> quant = arg;
}
void Inventory::setCost(float arg){
    this -> cost = arg;
}
void Inventory::setTotal(){
    this->total = this->quant * this->cost;
}

//Getters
int Inventory::getItemNum(){
    return this -> itemNum;
}
int Inventory::getQuant(){
    return this -> quant;
}
float Inventory::getCost(){
    return this -> cost;
}
float Inventory::getTotal(){
    return this -> total;
}