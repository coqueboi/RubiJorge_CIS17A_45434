/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GAME.h
 * Author: Cokes PC
 *
 */

using namespace std;

#ifndef GAME_H
#define GAME_H

struct Board{
    static const int boardSize = 10; //Holds the board size to be used in the array definition
    char board[boardSize][boardSize];//Game board
    int hp = 17;
};

struct Player{
    string name;        //Stores player name for leaderboard/highscore output
    int score;          //Stores player's score 
};

struct Ship{
    int orient;         //Stores ship value for horizontal or vertical generation
    int length;         //Stores ship length for generation
    int coords[][3];    //Stores ship coords for generation
};

struct Vars{
    Ship *array;        //Hold array of ships and their values from Ship struct
    int size = 5;       //Hold size of ships array aka the number of ships
    int lngthArr[5] = {2,3,3,4,5};     //Length array to be used in ship generation
};

#endif /* GAME_H */

    