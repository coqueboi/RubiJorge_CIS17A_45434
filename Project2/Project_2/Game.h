/* 
 * File:   Game.h
 * Author: Cokes PC
 *
 * Created on July 26, 2018, 7:55 PM
 */
#include <string>
using namespace std;
#include "Ship.h"
#include "AircraftCarrier.h"
#include "Battleship.h"
#include "Submarine.h"
#include "Cruiser.h"
#include "Destroyer.h"

#ifndef GAME_H
#define GAME_H

class Game {
    friend class Ship;
public:
    Game();
    Game(const Game& orig);
    virtual ~Game();
    
    //Executes and maintains game processes
    void play();
    
    //Outputs a player introduction and rules
    void intro();
    
    //Calls for ship and board initialization functions
    void init();
    
    //Generates & Initializes the playing board
    void bordGen();
    
    //Generates complete ship on the playing board
    //Warning: Absurdly redundant due to every ship having its own gen loop
    void shipGen(); 
    
    //Print the playing board in its current state
    void print();
    
    //Get user to input a guess
    char *input(string);
    
    //Update the board throughout play
    void update(char *);
    
    //Get user ID and store the number of moves it took for them to win the game
    void endGame(int);

private:
    //Store Board, Vars, and maybe player structs from proj 1 in here
    static string letters;
    //char **board; or board[10][10].
    char board[10][10];
    int hp = 17;
    
    //Ship members
    AircraftCarrier ship1;
    Battleship      ship2;
    Submarine       ship3;
    Cruiser         ship4;
    Destroyer       ship5;

};

#endif /* GAME_H */

