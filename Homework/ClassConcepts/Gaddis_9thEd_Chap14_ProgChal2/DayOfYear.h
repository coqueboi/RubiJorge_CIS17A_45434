/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DayOfYear.h
 * Author: Cokes PC
 *
 */
#include <string>

#ifndef DAYOFYEAR_H
#define DAYOFYEAR_H

class DayOfYear {
public:
    DayOfYear();
    DayOfYear(int);
    virtual ~DayOfYear();
    
    
    void setDay();
    void dayCalc();
    void print();
    
private:
    int day;
    
    //Month followed by day
    string md;
    
    //Holds month names
    static string month[12];
    
    //Holds number of days in month
    static int numDays[12];
};

#endif /* DAYOFYEAR_H */

