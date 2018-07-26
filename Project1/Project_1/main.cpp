/* 
 * File:   main.cpp
 * Author: Jorge Rubi
 * Purpose: Project 1 : Battleship, Revamped
 */
 
//System Libraries Here
#include <iostream>
#include <ctime>        //For pseudo-random number generation
#include <cctype>       //For input validation
#include <fstream>      //For file I/O
using namespace std;
 
//User Libraries Here
#include "GAME.h"

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions
 
//Function Prototypes Here
//Note: For Project 2 plan to create user-board and playability versus computer
Board run(Board &);          //Runs program and maintains processes 
Board init();         //Calls for board gen and ship gen
void print(Board &);   //Print the playing board (Executes throughout game for UI)
Board bordGen();     //Generate the playing board (Declare, Initialize, Pass)
Board shipGen(Board &); //Generate hidden ship positions on board (Occurs once)
Board update(char *, Board &);       //Update the playing board & check game conditions 
char *input(string);      //Get user input as string and convert to chars
void endGame(int);      //Get user ID and number of moves taken to win game
void intro();           //Outputs an introduction and tells player the rules

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Random number seed 
    srand(static_cast<unsigned int>(time(0)));
    
    Board arr;
    //Initialize game variables
    arr = init();
    
    //Output Prompt
    intro();
    
    //Run the game
    run(arr);      
   
    //Exit
    return 0;
}

Board init(){
    //Intialize the playing board once
    Board arr = bordGen();
    
    //Generate enemy battleship positions on the playing board once
    shipGen(arr);
    
    return arr;
}

Board run(Board &arr){
    //Play the game!
    int moves = 0; //Count the number of moves made by the user
    char *guess;  //Hold the user's guess for the enemy ship position
    do{
        print(arr);
        guess = input("a guess"); //Get user input
        arr = update(guess,arr);
        moves++;
    }while(arr.hp > 0); //will return false when all enemy ships have been sunk
    //Output final board state
    print(arr);
    //Record high score then end the game
    endGame(moves);
}

Board bordGen(){
    
    //Executes once to initialize the playing board
    Board array;
    int size = array.boardSize;
    
    //Loop initializes character array spaces to '+' as a placeholder 
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            array.board[i][j] = '+';
        }
    }
    
    return array;
}

Board shipGen(Board &bArr){
    
    //Generate ships and their properties
    ////////////////////////////////////////////////////////////////////////////
    //Create ships variable
    Vars ships;     
    //Dynamic allocation of ship quantity (create array of ship structures)
    ships.array = new Ship[ships.size];
    //Boolean to determine generation success
    bool gen = true;
    //Temporary variables for ship placement
    int sizeTemp, xVal, yVal, count;
    
    //Create coordinate array as such to store the ship's starting point 
    /*   0|1 |2 
     *  s0|y0|x0 
     *  s1|y1|x1
     *  s2|y2|x2
     *  s3 ...
     *  s4 ...
     */  
    ships.array->coords[ships.size][3];
    
    //Loop until all ships are created
    for(int i = 0; i <= ships.size - 1; i++){
        //If the ship orientation is 0: horizontal gen. if 1: vertical gen.
        ships.array[i].orient = rand() % 2;
        //Set the length of the ship, independent of orientation
        ships.array[i].length = ships.lngthArr[i];
        //Reset temporary variables for each ship loop
        sizeTemp = 0, xVal = 0, yVal = 0, count = 0;
        
        //Loop until valid ship placement
        do{
            //"Spawnpoint" generation
            ////////////////////////////////////////////////////////////////////
            //Generate random y value & store the y coordinate
            ships.array[i].coords[i][1] = rand() % 10;
            
            //Generate random x value & store the x coordinate
            ships.array[i].coords[i][2] = rand() % 10;
            ////////////////////////////////////////////////////////////////////
            
            
            //Attempt horizontal generation
            ////////////////////////////////////////////////////////////////////
            if(ships.array[i].orient == 0){
                //Edge collision detection through sufficient space checking
                sizeTemp = bArr.boardSize - ships.array[i].coords[i][2] - ships.array[i].length;
                
                //If there isn't enough space, move back the spawn point
                //by as many spaces as necessary and proceed
                if(sizeTemp < 0){
                    ships.array[i].coords[i][2] += sizeTemp;
                }
                
                //After potentially updating the coordinate values
                //due to space checking, define the temporary placement vars
                yVal = ships.array[i].coords[i][1];
                xVal = ships.array[i].coords[i][2];
                        
                //Begin ship placement
                for(int x = 0; x < ships.array[i].length; x++){
                    
                    //if bArr == '1', undo everything, gen = false, break
                    if(bArr.board[yVal][xVal + x] == '1'){
                        //Count what position generation was at in order to undo
                        count = x;
                        //Set gen to false so the function may try again
                        gen = false;
                        break;
                    }
                    //If there is a free '+' space, place a ship marker
                    else if(bArr.board[yVal][xVal + x] == '+'){
                        bArr.board[yVal][xVal + x] = '1';
                        //Set gen to true to avoid undo loop
                        gen = true;
                    }
                }
                //if generation unsuccessful (gen == false) undo ship placement
                if(!gen){
                    for(int x = count; x > ships.array[i].coords[i][2]; x--){
                        bArr.board[yVal][xVal + x] = '+';
                    }
                }
            }
            ////////////////////////////////////////////////////////////////////
            
            
            //Attempt vertical generation
            ////////////////////////////////////////////////////////////////////
            if(ships.array[i].orient == 1){
                //Edge collision detection through sufficient space checking
                sizeTemp = bArr.boardSize - ships.array[i].coords[i][1] - ships.array[i].length;
                
                //If there isn't enough space, move back the spawn point
                //by as many spaces as necessary and proceed
                if(sizeTemp < 0){
                    ships.array[i].coords[i][1] += sizeTemp;
                }
                
                //After potentially updating the coordinate values
                //due to space checking, define the temporary placement vars
                yVal = ships.array[i].coords[i][1];
                xVal = ships.array[i].coords[i][2];
                        
                //Begin ship placement
                for(int y = 0; y < ships.array[i].length; y++){
                    
                    //Overlap detection
                    if(bArr.board[yVal + y][xVal] == '1'){
                        //Count what position generation was at in order to undo
                        count = y;
                        //Set gen to false so the function may try again
                        gen = false;
                        break;
                    }
                    //If there is a free '+' space, place a ship marker
                    else if(bArr.board[yVal + y][xVal] == '+'){
                        bArr.board[yVal + y][xVal] = '1';
                        //Set gen to true to avoid undo loop
                        gen = true;
                    }
                }
                //if generation unsuccessful (gen == false) undo ship placement
                if(!gen){
                    for(int y = count; y > ships.array[i].coords[i][1]; y--){
                        bArr.board[yVal + y][xVal] = '+';
                    }
                }
            }
            ////////////////////////////////////////////////////////////////////    
        }while(!gen);
    ////////////////////////////////////////////////////////////////////////////
        //Debugging line reveals ship generation coordinates
        //cout<<ships.array[i].coords[i][1]<<ships.array[i].coords[i][2]<<endl;
    }
    return bArr;
}

void print(Board &array){
    
    string letters = "ABCDEFGHIJ";
    
    //Output Nums on top of board
    ////////////////////////////////////////////////////////////////////////////
    for(int i = 0; i < 10; i++){
        if(i == 0 ) cout << " ";
        cout << " " << i;
        if(i == 9 ) cout << endl;
    }
    ////////////////////////////////////////////////////////////////////////////
    
    //Output the playing board in its current state
    ////////////////////////////////////////////////////////////////////////////
    int size = array.boardSize;
    
    for(int y = 0; y < size; y++){
        
        //Output letters on left side of board
        cout << letters[y] << " ";        
        
        //Output board characters
        for(int x = 0; x < size; x++){
            if(array.board[y][x] == '1'){   
                cout << "+" << " ";         //"Hide" the ship positions to user
            }
            else{
                cout << array.board[y][x] << " "; //Output the char ie: +,*,X
            }
        }
        cout << endl;       
    } 
    ////////////////////////////////////////////////////////////////////////////
}

char *input(string action){
    bool valid = true;
    string str = "";
    char *temp = new char[2];   //For C-string
    int size;
    
    //Input validation
    ///////////////////////////////////////////////////////////////////////////
    cout << "Please enter " << action << ": ";
    do{
        if(!valid){
            cout << "Invalid entry. Please try again: ";
        }
        cin >> str;
        cin.ignore();
        size = str.length();
        valid = true;
        
        if(size > 2){
            valid = false;
            continue;
        }
        
        //Check if values entered are alphanumeric
        if(isalnum(str[0]) || isalnum(str[1])){
            
            //Check if the first character is alphabetical and do changes 
            if(isalpha(str[0])){
                str[0] = tolower(str[0]);
                if(str[0]>'j'){
                    valid = false;
                    continue;
                }
                else{
                    str[0] -= 49;
                }
            }
            else{
                cout << endl;
                cout << "The first character must be alphabetical (A-J). " << endl;
                valid = false;
                continue;
            }
            
            //Check if second character is a number and if it's <= 9
            if(!(isdigit(str[1]) && (str[1] > 9))){
                cout << endl;
                cout << "The second character must be numerical and in the";
                cout << " range of 0 to 9. " << endl;
                valid = false;
                continue;
            }
            for(int j = 0; j < size; j++){
                temp[j] = str[j];
            }
        }
        else{
            valid = false;
        } 
    }while(!valid);
    ///////////////////////////////////////////////////////////////////////////
    
    return temp;
}

Board update(char *guess, Board &arr){
    //Convert chars into ints and set them equal to temp variables
    int y = guess[0] - '0'; 
    int x = guess[1] - '0';
    //If hit
    if(arr.board[y][x] == '1'){
        arr.board[y][x] = 'X';
        arr.hp--;
    }
    //If miss
    if(arr.board[y][x] == '+'){
        arr.board[y][x] = '*';
    }
    //Note: If already hit ('X') or a miss ('*'), do nothing.
    
    return arr;
}

void endGame(int moves){
    string name = "";
    bool valid = true;
    int size;
    fstream file;
    
    cout << "Congratulations, you sunk my battleships!" << endl;
    cout << "Your total moves were: " << moves << endl;
    cout << "Enter your initials to add yourself to the leaderboard. " << endl;
    cout << "(Note: Your initials must be 3 characters) : ";
    
    do{
        if(!valid){
            cout << "Invalid entry. Please try again: ";
        }
        valid = true;
        getline(cin, name);
        size = name.length();
        //Ensure initials are 3 characters long
        if(!(size==3)){
            valid = false;
            continue;
        }
        //Ensure characters are alphabetical
        for(int i = 0; i < size; i++){
            if(!(isalpha(name[i]))){
                valid = false;
                continue;
            }
        }
    }while(!valid);
    cout << "Your highscore has been saved. Thanks for playing! \n" << endl;
    //Open or create highscores file
    file.open("highscores.txt", fstream::in|fstream::out|fstream::app);
    file << "High scores: ";
    //Add initials to the file
    for(int i = 0; i < size; i++){
        file << name[i];
    }
    file << " with " << moves << " moves! " << endl;
    file.close();
}

void intro(){
    cout << "Welcome to battleship!" << endl <<endl;
    cout << "The goal of the game is simple; locate and destroy the enemy \n"
            "ships in order to emerge victorious. \n\n"
            "To play, you will need to enter the coordinate positions of where\n"
            "you suspect an enemy ship to reside. \n"
            "You can do so by following a LetterNumber order.\n\n"
            "That is, you must enter a letter followed by a number such that \n"
            "it reflects the following: B4 or b4 or any other combination \n"
            "of the numbers and letters displayed on the playing board.\n\n"
            "Note: \nAny unexplored locations will be marked with a + sign. \n"
            "If you guess the location of a ship it will be marked with an X.\n"
            "If you guess an empty location, however, it will count as a miss and will be marked with an *.\n\n"
            "Try to sink all the enemy battleships in as few moves as possible!\n"
            "Good luck!" << endl << endl;    
}