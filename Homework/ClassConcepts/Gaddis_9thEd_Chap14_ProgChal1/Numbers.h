/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Numbers.h
 * Author: Cokes PC
 *
 * Created on July 24, 2018, 1:44 PM
 */

#include <string>

using namespace std;

#ifndef NUMBERS_H
#define NUMBERS_H

class Numbers {
public:
    Numbers();
    Numbers(int);
    virtual ~Numbers();
    
    void setNum();
    int getNum();
    void engNum();
    void print();
    
private:
    int number;
    string amtWord;
};

#endif /* NUMBERS_H */

