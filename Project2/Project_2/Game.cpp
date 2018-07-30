/* 
 * File:   Game.cpp
 * Author: Cokes PC
 * 
 * Created on July 26, 2018, 7:55 PM
 */
#include <iostream>
#include <cctype>
#include <fstream>
using namespace std;

#include "Game.h"

string Game::letters = "ABCDEFGHIJ";

Game::Game() {
}

Game::Game(const Game& orig) {
}

Game::~Game() {
}
void Game::play(){
    //Store the number of moves made in order to win 
    int moves = 0;
    //Store the user's guess to pass it to the update function
    char *guess;
    intro();
    init();                         //Generate the board and ships
    do{
        print();                    //Print the playing board 
        guess = input("a guess");   //Get user input
        update(guess);
        moves++;
    }while(hp > 0);
    //Output the board in it's final (winning) state.
    print();
    //Record the player's score and then end the game
    endGame(moves);
}
void Game::intro(){
    cout << "Welcome to battleship!" << endl <<endl;
    cout << "To play, you will need to enter the coordinate positions of where\n"
            "you suspect an enemy ship to reside. \n"
            "You can do so by following a LetterNumber order.\n\n"
            "That is, you must enter a letter followed by a number such that \n"
            "it reflects the following: B4 or b4 or any other combination \n"
            "of the numbers and letters displayed on the playing board.\n\n"
            "Note: \nAny unexplored locations will be marked with a + sign. \n"
            "If you guess the location of a ship it will be marked with an X.\n"
            "If you guess an empty location, however, it will count as a miss and will be marked with an *.\n\n\n"
            "Y O U R  M I S S I O N : \n\n"
            "Locate and destroy all enemy battleships. \n"
            "There are a total of 5 ships; their names are: \n\n"
            "Aircraft Carrier\n"
            "Battleship\n"
            "Cruiser\n"
            "Submarine\n"
            "Destroyer\n\n"
            "Try to sink all the enemy battleships in as few moves as possible!\n"
            "Good luck, Private." << endl << endl;    
}

void Game::init(){
    //Generate the playing board once
    bordGen();
    
    //Generate enemy battleship positions on the playing board once
    shipGen();
}

void Game::bordGen(){
    //Loop initializes character array spaces to '+' as a placeholder 
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            board[i][j] = '+';
        }
    }
}

void Game::shipGen(){
//////////////////////////////////////////////////
//    ///***Extreme redundancy function***///   //
//     Due to abstract data type inheritance    //
//////////////////////////////////////////////////
    
    //Boolean to determine generation success
    bool gen = true;
    //Temporary variables for ship placement
    int sizeTemp, xVal, yVal, count, length, *coords;
    
//Generate Aircraft Carrier ship1
    do{
        //Get the spawn coords with every loop in case they are modified or reset
        ship1.setCoords();
        coords = ship1.getCoords();
        length = ship1.getLength();
        //Reset temporary variables for each ship loop
        sizeTemp = 0, xVal = 0, yVal = 0, count = 0;
        
        //Attempt horizontal generation
        if(ship1.getOrient() == 0 ){
            //Edge collision detection through sufficient space checking
            sizeTemp = 10 - coords[1] - length;
            //If there isn't enough space, move back the spawn point
            //by as many spaces as necessary and proceed
            if(sizeTemp < 0){
                coords[1] += sizeTemp;
            }
            //After potentially updating the coordinate values
            //due to space checking, define the temporary placement vars
            yVal = coords[0];
            xVal = coords[1];
            //Begin ship placement
            for(int x = 0; x < length; x++){
                //If an attempted overlap occurs, undo everything
                if(board[yVal][xVal + x] == '1'){
                    //Hold the position generation was at in order to undo
                    count = x;
                    //Set gen to false and break to attempt gen again
                    gen = false;
                    break;
                }
                else if(board[yVal][xVal + x] == '+'){
                    //Place a ship onto the board if there's space to do so
                    board[yVal][xVal + x] = '1';
                    
                    //Store placement coordinate
                    ship1.place[x + x] = yVal;
                    ship1.place[x + x + 1] = xVal + x;
                    
                    //Set gen to true to avoid undo loop
                    gen = true;
                }
            }
            //If generation was unsuccessful, undo the attempted generation actions
            if(!gen){
                for(int x = coords[1]; x < coords[1] + count; x++){
                    board[yVal][x] = '+';
                    //Undo storing of placement coordinate
                    ship1.place[x + x] = 0;
                    ship1.place[x + x + 1] = 0;
                }
            }
        }
        //Attempt vertical generation
        else if(ship1.getOrient() == 1){
            //Edge collision detection through sufficient space checking
            sizeTemp = 10 - coords[0] - length;
            //If there isn't enough space, move back the spawn point
            //by as many spaces as necessary and proceed
            if(sizeTemp < 0){
                coords[0] += sizeTemp;
            }
            //After potentially updating the coordinate values
            //due to space checking, define the temporary placement vars
            yVal = coords[0];
            xVal = coords[1];
            //Begin ship placement
            for(int y = 0; y < length; y++){
                //If an attempted overlap occurs, undo everything
                if(board[yVal + y][xVal] == '1'){
                    //Hold the position generation was at in order to undo
                    count = y;
                    //Set gen to false and break to attempt gen again
                    gen = false;
                    break;
                }
                else if(board[yVal + y][xVal] == '+'){
                    //Place a ship onto the board if there's space to do so
                    board[yVal + y][xVal] = '1';
                    
                    //Store placement coordinate
                    ship1.place[y + y] = yVal + y;
                    ship1.place[y + y + 1] = xVal;
                    
                    //Set gen to true to avoid undo loop
                    gen = true;
                }
            }
            //If generation was unsuccessful, undo the attempted generation actions
            if(!gen){
                for(int y = coords[0]; y < coords[0] + count; y++){
                    board[y][xVal] = '+';
                    //Undo storing of placement coordinate
                    ship1.place[y + y] = 0;
                    ship1.place[y + y + 1] = 0;
                }
            }
        }
        else{
            cout << "An error occurred" << endl;
            exit(EXIT_FAILURE);
        }
    }while(!gen);
    //Debugging    
    //    for(int i = 0; i < length; i++){
    //        cout << ship1.place[i + i] << ship1.place[i + i + 1] << endl;
    //    }
    
//Generate Battleship ship2
    do{
        //Get the spawn coords with every loop in case they are modified or reset
        ship2.setCoords();
        coords = ship2.getCoords();
        length = ship2.getLength();
        //Reset temporary variables for each ship loop
        sizeTemp = 0, xVal = 0, yVal = 0, count = 0;
        
        //Attempt horizontal generation
        if(ship2.getOrient() == 0 ){
            //Edge collision detection through sufficient space checking
            sizeTemp = 10 - coords[1] - length;
            //If there isn't enough space, move back the spawn point
            //by as many spaces as necessary and proceed
            if(sizeTemp < 0){
                coords[1] += sizeTemp;
            }
            //After potentially updating the coordinate values
            //due to space checking, define the temporary placement vars
            yVal = coords[0];
            xVal = coords[1];
            //Begin ship placement
            for(int x = 0; x < length; x++){
                //If an attempted overlap occurs, undo everything
                if(board[yVal][xVal + x] == '1'){
                    //Hold the position generation was at in order to undo
                    count = x;
                    //Set gen to false and break to attempt gen again
                    gen = false;
                    break;
                }
                else if(board[yVal][xVal + x] == '+'){
                    //Place a ship onto the board if there's space to do so
                    board[yVal][xVal + x] = '1';
                    
                    //Store placement coordinate
                    ship2.place[x + x] = yVal;
                    ship2.place[x + x + 1] = xVal + x;
                    
                    //Set gen to true to avoid undo loop
                    gen = true;
                }
            }
            //If generation was unsuccessful, undo the attempted generation actions
            if(!gen){
                for(int x = coords[1]; x < coords[1] + count; x++){
                    board[yVal][x] = '+';
                    
                    //Undo storing of placement coordinate
                    ship2.place[x + x] = 0;
                    ship2.place[x + x + 1] = 0;
                }
            }
        }
        //Attempt vertical generation
        else if(ship2.getOrient() == 1){
            //Edge collision detection through sufficient space checking
            sizeTemp = 10 - coords[0] - length;
            //If there isn't enough space, move back the spawn point
            //by as many spaces as necessary and proceed
            if(sizeTemp < 0){
                coords[0] += sizeTemp;
            }
            //After potentially updating the coordinate values
            //due to space checking, define the temporary placement vars
            yVal = coords[0];
            xVal = coords[1];
            //Begin ship placement
            for(int y = 0; y < length; y++){
                //If an attempted overlap occurs, undo everything
                if(board[yVal + y][xVal] == '1'){
                    //Hold the position generation was at in order to undo
                    count = y;
                    //Set gen to false and break to attempt gen again
                    gen = false;
                    break;
                }
                else if(board[yVal + y][xVal] == '+'){
                    //Place a ship onto the board if there's space to do so
                    board[yVal + y][xVal] = '1';
                    
                    //Store placement coordinate
                    ship2.place[y + y] = yVal + y;
                    ship2.place[y + y + 1] = xVal;
                    
                    //Set gen to true to avoid undo loop
                    gen = true;
                }
            }
            //If generation was unsuccessful, undo the attempted generation actions
            if(!gen){
                for(int y = coords[0]; y < coords[0] + count; y++){
                    board[y][xVal] = '+';
                    //Undo storing of placement coordinate
                    ship2.place[y + y] = 0;
                    ship2.place[y + y + 1] = 0;
                }
            }
        }
        else{
            cout << "An error occurred" << endl;
            exit(EXIT_FAILURE);
        }
    }while(!gen);
    //Debugging
    //    for(int i = 0; i < length; i++){
    //        cout << ship2.place[i + i] << ship2.place[i + i + 1] << endl;
    //    }
    
//Generate Submarine ship3
    do{
        //Get the spawn coords with every loop in case they are modified or reset
        ship3.setCoords();
        coords = ship3.getCoords();
        length = ship3.getLength();
        //Reset temporary variables for each ship loop
        sizeTemp = 0, xVal = 0, yVal = 0, count = 0;
        
        //Attempt horizontal generation
        if(ship3.getOrient() == 0 ){
            //Edge collision detection through sufficient space checking
            sizeTemp = 10 - coords[1] - length;
            //If there isn't enough space, move back the spawn point
            //by as many spaces as necessary and proceed
            if(sizeTemp < 0){
                coords[1] += sizeTemp;
            }
            //After potentially updating the coordinate values
            //due to space checking, define the temporary placement vars
            yVal = coords[0];
            xVal = coords[1];
            //Begin ship placement
            for(int x = 0; x < length; x++){
                //If an attempted overlap occurs, undo everything
                if(board[yVal][xVal + x] == '1'){
                    //Hold the position generation was at in order to undo
                    count = x;
                    //Set gen to false and break to attempt gen again
                    gen = false;
                    break;
                }
                else if(board[yVal][xVal + x] == '+'){
                    //Place a ship onto the board if there's space to do so
                    board[yVal][xVal + x] = '1';
                    
                    //Store placement coordinate
                    ship3.place[x + x] = yVal;
                    ship3.place[x + x + 1] = xVal + x;
                    
                    //Set gen to true to avoid undo loop
                    gen = true;
                }
            }
            //If generation was unsuccessful, undo the attempted generation actions
            if(!gen){
                for(int x = coords[1]; x < coords[1] + count; x++){
                    board[yVal][x] = '+';
                    
                    //Undo storing of placement coordinate
                    ship3.place[x + x] = 0;
                    ship3.place[x + x + 1] = 0;
                }
            }
        }
        //Attempt vertical generation
        else if(ship3.getOrient() == 1){
            //Edge collision detection through sufficient space checking
            sizeTemp = 10 - coords[0] - length;
            //If there isn't enough space, move back the spawn point
            //by as many spaces as necessary and proceed
            if(sizeTemp < 0){
                coords[0] += sizeTemp;
            }
            //After potentially updating the coordinate values
            //due to space checking, define the temporary placement vars
            yVal = coords[0];
            xVal = coords[1];
            //Begin ship placement
            for(int y = 0; y < length; y++){
                //If an attempted overlap occurs, undo everything
                if(board[yVal + y][xVal] == '1'){
                    //Hold the position generation was at in order to undo
                    count = y;
                    //Set gen to false and break to attempt gen again
                    gen = false;
                    break;
                }
                else if(board[yVal + y][xVal] == '+'){
                    //Place a ship onto the board if there's space to do so
                    board[yVal + y][xVal] = '1';
                    
                    //Store placement coordinate
                    ship3.place[y + y] = yVal + y;
                  
                    ship3.place[y + y + 1] = xVal;
                    
                    //Set gen to true to avoid undo loop
                    gen = true;
                }
            }
            //If generation was unsuccessful, undo the attempted generation actions
            if(!gen){
                for(int y = coords[0]; y < coords[0] + count; y++){
                    board[y][xVal] = '+';
                    //Undo storing of placement coordinate
                    ship3.place[y + y] = 0;
                    ship3.place[y + y + 1] = 0;
                }
            }
        }
        else{
            cout << "An error occurred" << endl;
            exit(EXIT_FAILURE);
        }
    }while(!gen);
    //Debugging
    //    for(int i = 0; i < length; i++){
    //        cout << ship3.place[i + i] << ship3.place[i + i + 1] << endl;
    //    }
    
//Generate Cruiser ship4
    do{
        //Get the spawn coords with every loop in case they are modified or reset
        ship4.setCoords();
        coords = ship4.getCoords();
        length = ship4.getLength();
        //Reset temporary variables for each ship loop
        sizeTemp = 0, xVal = 0, yVal = 0, count = 0;
        
        //Attempt horizontal generation
        if(ship4.getOrient() == 0 ){
            //Edge collision detection through sufficient space checking
            sizeTemp = 10 - coords[1] - length;
            //If there isn't enough space, move back the spawn point
            //by as many spaces as necessary and proceed
            if(sizeTemp < 0){
                coords[1] += sizeTemp;
            }
            //After potentially updating the coordinate values
            //due to space checking, define the temporary placement vars
            yVal = coords[0];
            xVal = coords[1];
            //Begin ship placement
            for(int x = 0; x < length; x++){
                //If an attempted overlap occurs, undo everything
                if(board[yVal][xVal + x] == '1'){
                    //Hold the position generation was at in order to undo
                    count = x;
                    //Set gen to false and break to attempt gen again
                    gen = false;
                    break;
                }
                else if(board[yVal][xVal + x] == '+'){
                    //Place a ship onto the board if there's space to do so
                    board[yVal][xVal + x] = '1';
                    
                    //Store placement coordinate
                    ship4.place[x + x] = yVal;
                    ship4.place[x + x + 1] = xVal + x;
                    
                    //Set gen to true to avoid undo loop
                    gen = true;
                }
            }
            //If generation was unsuccessful, undo the attempted generation actions
            if(!gen){
                for(int x = coords[1]; x < coords[1] + count; x++){
                    board[yVal][x] = '+';
                    
                    //Undo storing of placement coordinate
                    ship4.place[x + x] = 0;
                    ship4.place[x + x + 1] = 0;
                }
            }
        }
        //Attempt vertical generation
        else if(ship4.getOrient() == 1){
            //Edge collision detection through sufficient space checking
            sizeTemp = 10 - coords[0] - length;
            //If there isn't enough space, move back the spawn point
            //by as many spaces as necessary and proceed
            if(sizeTemp < 0){
                coords[0] += sizeTemp;
            }
            //After potentially updating the coordinate values
            //due to space checking, define the temporary placement vars
            yVal = coords[0];
            xVal = coords[1];
            //Begin ship placement
            for(int y = 0; y < length; y++){
                //If an attempted overlap occurs, undo everything
                if(board[yVal + y][xVal] == '1'){
                    //Hold the position generation was at in order to undo
                    count = y;
                    //Set gen to false and break to attempt gen again
                    gen = false;
                    break;
                }
                else if(board[yVal + y][xVal] == '+'){
                    //Place a ship onto the board if there's space to do so
                    board[yVal + y][xVal] = '1';
                    
                    //Store placement coordinate
                    ship4.place[y + y] = yVal + y;
                  
                    ship4.place[y + y + 1] = xVal;
                    
                    //Set gen to true to avoid undo loop
                    gen = true;
                }
            }
            //If generation was unsuccessful, undo the attempted generation actions
            if(!gen){
                for(int y = coords[0]; y < coords[0] + count; y++){
                    board[y][xVal] = '+';
                    //Undo storing of placement coordinate
                    ship4.place[y + y] = 0;
                    ship4.place[y + y + 1] = 0;
                }
            }
        }
        else{
            cout << "An error occurred" << endl;
            exit(EXIT_FAILURE);
        }
    }while(!gen);
    //Debugging
    //    for(int i = 0; i < length; i++){
    //        cout << ship4.place[i + i] << ship4.place[i + i + 1] << endl;
    //    }
    
//Generate Destroyer ship5
    do{
        //Get the spawn coords with every loop in case they are modified or reset
        ship5.setCoords();
        coords = ship5.getCoords();
        length = ship5.getLength();
        //Reset temporary variables for each ship loop
        sizeTemp = 0, xVal = 0, yVal = 0, count = 0;
        
        //Attempt horizontal generation
        if(ship5.getOrient() == 0 ){
            //Edge collision detection through sufficient space checking
            sizeTemp = 10 - coords[1] - length;
            //If there isn't enough space, move back the spawn point
            //by as many spaces as necessary and proceed
            if(sizeTemp < 0){
                coords[1] += sizeTemp;
            }
            //After potentially updating the coordinate values
            //due to space checking, define the temporary placement vars
            yVal = coords[0];
            xVal = coords[1];
            //Begin ship placement
            for(int x = 0; x < length; x++){
                //If an attempted overlap occurs, undo everything
                if(board[yVal][xVal + x] == '1'){
                    //Hold the position generation was at in order to undo
                    count = x;
                    //Set gen to false and break to attempt gen again
                    gen = false;
                    break;
                }
                else if(board[yVal][xVal + x] == '+'){
                    //Place a ship onto the board if there's space to do so
                    board[yVal][xVal + x] = '1';
                    
                    //Store placement coordinate
                    ship5.place[x + x] = yVal;
                    ship5.place[x + x + 1] = xVal + x;
                    
                    //Set gen to true to avoid undo loop
                    gen = true;
                }
            }
            //If generation was unsuccessful, undo the attempted generation actions
            if(!gen){
                for(int x = coords[1]; x < coords[1] + count; x++){
                    board[yVal][x] = '+';
                    
                    //Undo storing of placement coordinate
                    ship5.place[x + x] = 0;
                    ship5.place[x + x + 1] = 0;
                }
            }
        }
        //Attempt vertical generation
        else if(ship5.getOrient() == 1){
            //Edge collision detection through sufficient space checking
            sizeTemp = 10 - coords[0] - length;
            //If there isn't enough space, move back the spawn point
            //by as many spaces as necessary and proceed
            if(sizeTemp < 0){
                coords[0] += sizeTemp;
            }
            //After potentially updating the coordinate values
            //due to space checking, define the temporary placement vars
            yVal = coords[0];
            xVal = coords[1];
            //Begin ship placement
            for(int y = 0; y < length; y++){
                //If an attempted overlap occurs, undo everything
                if(board[yVal + y][xVal] == '1'){
                    //Hold the position generation was at in order to undo
                    count = y;
                    //Set gen to false and break to attempt gen again
                    gen = false;
                    break;
                }
                else if(board[yVal + y][xVal] == '+'){
                    //Place a ship onto the board if there's space to do so
                    board[yVal + y][xVal] = '1';
                    
                    //Store placement coordinate
                    ship5.place[y + y] = yVal + y;
                  
                    ship5.place[y + y + 1] = xVal;
                    
                    //Set gen to true to avoid undo loop
                    gen = true;
                }
            }
            //If generation was unsuccessful, undo the attempted generation actions
            if(!gen){
                for(int y = coords[0]; y < coords[0] + count; y++){
                    board[y][xVal] = '+';
                    //Undo storing of placement coordinate
                    ship5.place[y + y] = 0;
                    ship5.place[y + y + 1] = 0;
                }
            }
        }
        else{
            cout << "An error occurred" << endl;
            exit(EXIT_FAILURE);
        }
    }while(!gen);
    //Debugging
    //    for(int i = 0; i < length; i++){
    //        cout << ship5.place[i + i] << ship5.place[i + i + 1] << endl;
    //    }
}

void Game::print(){
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
    int size = 10;
    
    for(int y = 0; y < size; y++){
        
        //Output letters on left side of board
        cout << letters[y] << " ";        
        //Output board characters
        for(int x = 0; x < size; x++){
            if(board[y][x] == '1'){   
                cout << "+" << " ";         //"Hide" the ship positions to user
            }
            else{
                cout << board[y][x] << " "; //Output the char ie: +,*,X
            }
        }
        cout << endl;       
    } 
    ////////////////////////////////////////////////////////////////////////////
}

char *Game::input(string action){
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

void Game::update(char* guess){
    //Convert chars into ints and set them equal to temp variables
    int y = guess[0] - '0'; 
    int x = guess[1] - '0';
    //If hit
    if(board[y][x] == '1'){
        board[y][x] = 'X';
        hp--;
        
        //Check all ship coordinates to determine which ship type was hit
        ////////////////////////////////////////////////////////////////////////
        for(int i = 0; i < (ship1.length * 2); i++){
            if(ship1.place[i + i] == y && ship1.place[i + i + 1] == x){
                ship1--;
            }
        }
        for(int i = 0; i < (ship2.length * 2); i++){
            if(ship2.place[i + i] == y && ship2.place[i + i + 1] == x){
                ship2--;
            }
        }
        for(int i = 0; i < (ship3.length * 2); i++){
            if(ship3.place[i + i] == y && ship3.place[i + i + 1] == x){
                ship3--;
            }
        }
        for(int i = 0; i < (ship4.length * 2); i++){
            if(ship4.place[i + i] == y && ship4.place[i + i + 1] == x){
                ship4--;
            }
        }
        for(int i = 0; i < (ship5.length * 2); i++){
            if(ship5.place[i + i] == y && ship5.place[i + i + 1] == x){
                ship5--;
            }
        }
        ////////////////////////////////////////////////////////////////////////
    }
    //If miss
    if(board[y][x] == '+'){
        board[y][x] = '*';
    }
    //Note: If already hit ('X') or a miss ('*'), do nothing.
    
    //Output when a ship has been sunk!
    if(ship1.hp == 0){
        //Turn value negative to avoid outputting with every update
        ship1--;
        cout << "#########################################" << endl << endl;
        cout << "You sunk my " << ship1.getName() << "!" << endl << endl;
        cout << "#########################################" << endl << endl;
    }
    if(ship2.hp == 0){
        //Turn value negative to avoid outputting with every update
        ship2--;
        cout << "#########################################" << endl << endl;
        cout << "You sunk my " << ship2.getName() << "!" << endl << endl;
        cout << "#########################################" << endl << endl;
    }
    if(ship3.hp == 0){
        //Turn value negative to avoid outputting with every update
        ship3--;
        cout << "#########################################" << endl << endl;
        cout << "You sunk my " << ship3.getName() << "!" << endl << endl;
        cout << "#########################################" << endl << endl;
    }
    if(ship4.hp == 0){
        //Turn value negative to avoid outputting with every update
        ship4--;
        cout << "#########################################" << endl << endl;
        cout << "You sunk my " << ship4.getName() << "!" << endl << endl;
        cout << "#########################################" << endl << endl;
    }
    if(ship5.hp == 0){
        //Turn value negative to avoid outputting with every update
        ship5--;
        cout << "#########################################" << endl << endl;
        cout << "You sunk my " << ship5.getName() << "!" << endl << endl;
        cout << "#########################################" << endl << endl;
    }
}

void Game::endGame(int moves){
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
    file << " with " << moves << " moves! "<< '\r' << '\n' << endl;
    file.close();
}