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
    DayOfYear(string month, int day);
    virtual ~DayOfYear();
    
    //Day # to date functions
    void setDay();
    void dayCalc();
    void print();
    
    //Date to day # functions
    void setDate();
    void getDate(string, int);
    void printDay();
    
    //Overloaded postfix operators
    DayOfYear operator++(int);
    DayOfYear operator--(int);
private:
    int day;
    
    //Month name
    string m;
    
    //Month followed by day
    string md;
    
    //Holds month names
    static string month[12];
    
    //Holds number of days in month
    static int numDays[12];
};

#endif /* DAYOFYEAR_H */

