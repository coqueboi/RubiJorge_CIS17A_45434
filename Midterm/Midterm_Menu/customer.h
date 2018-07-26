/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   customer.h
 * Author: Cokes PC
 *
 * Created on July 14, 2018, 6:33 PM
 */
using namespace std;

#ifndef CUSTOMER_H
#define CUSTOMER_H

struct Customer{
    string 
        name,
        address;
    
    float 
        balance, //Balance at beginning of month
        checks,  //Total of all checks written by customer
        deposits,//Total of all deposits credited to customer
        newBal;  //New balance
    
};

#endif /* CUSTOMER_H */

