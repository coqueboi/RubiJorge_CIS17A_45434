/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Game.h
 * Author: Cokes PC
 *
 * Created on July 26, 2018, 7:55 PM
 */

#ifndef GAME_H
#define GAME_H

class Game {
    friend class Ship;
public:
    Game();
    Game(const Game& orig);
    virtual ~Game();
    
    //Outputs a player introduction and rules
    void intro();
    
    //Executes and maintains game processes
    void play();
    
    //Calls for ship and board initialization functions
    void init();
    
    //Initializes ship values
    void shipInit();
    
    //Generates & Initializes the playing board
    void bordInit();
    
    //Generates complete ship on the playing board
    void shipGen();
    
    //Print the playing board in its current state
    void print();
    
    
    ///***Don't forget to overload operators***/// 
    
private:
    
    
};

#endif /* GAME_H */

