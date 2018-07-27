/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NumDays.cpp
 * Author: Cokes PC
 * 
 */
using namespace std;
#include <iostream>
#include "NumDays.h"


NumDays::NumDays() {
    hours = 0;
    days = 0;
}

NumDays::NumDays(int hours) {
    this->hours = hours;
}
NumDays::Numdays(float days) {
    this->days = days;
}

NumDays::~NumDays() {
}
//Calculate the number of workdays
void NumDays::convert(){

    days = hours / 8.0f;
}
//Output the conversions
void NumDays::print(){
    cout << "The number of workdays is " << days << endl;
}