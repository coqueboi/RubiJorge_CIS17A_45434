/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Primes.h
 * Author: Cokes PC
 *
 * Created on July 16, 2018
 */

#ifndef PRIMES_H
#define PRIMES_H

struct Prime{
    unsigned char prime = 0;
    unsigned char power = 0;
};

struct Primes{
    Prime *primes;
    unsigned char nPrimes;
};


#endif /* PRIMES_H */

