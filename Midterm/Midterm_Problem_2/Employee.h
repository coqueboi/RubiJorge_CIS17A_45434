/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Employee.h
 * Author: Cokes PC
 *
 * Created on July 15, 2018, 3:04 AM
 */
using namespace std;
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

struct Employee{
    string name;//Employee's name
    
    float
        hours,  //Hours worked
        rate,   //Rate of pay
        cents;
    int
        gross;  //Gross pay 
};

#endif /* EMPLOYEE_H */

