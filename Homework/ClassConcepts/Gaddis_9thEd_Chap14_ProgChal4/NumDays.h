/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NumDays.h
 * Author: Cokes PC
 *
 */

#ifndef NUMDAYS_H
#define NUMDAYS_H

class NumDays {
public:
    NumDays();
    NumDays(int);
    Numdays(float);
    virtual ~NumDays();
    
    //Convert number of work hours to number of work days
    void convert();
    //Print conversions
    void print();
    
    //Inline functions for practice
    
    //Overload + operator
    NumDays operator+(const NumDays &right){
        NumDays temp;
        temp.hours = hours + right.hours;
        return temp;
    }
    //Overload - operator
    NumDays operator-(const NumDays &right){
        NumDays temp;
        temp.hours = hours - right.hours;
        return temp;
    }
    //Overload prefix and postfix ++ operators
    NumDays operator++(){
        //Prefix
        ++hours;
        //Automatically recalculate number of days
        convert();
        return *this;
    }
    NumDays operator++(int){
        //Postfix
        NumDays temp(hours);
        hours++;
        //Automatically recalculate number of days
        convert();
        return temp;
    }
    NumDays operator--(){
        //Prefix
        --hours;
        //Automatically recalculate number of days
        convert();
        return *this;
    }
    NumDays operator--(int){
        //Postfix
        NumDays temp(hours);
        hours--;
        //Automatically recalculate number of days
        convert();
        return temp;
    }
    
    
private:
    //Hold the number of work hours
    int hours;
    //Hold the number of work days
    float days;
    
    
};

#endif /* NUMDAYS_H */

