/* 
 * File:   main.cpp
 * Author: Jorge Rubi
 * Created on June 25, 2018
 * Purpose: Rain or Shine
 */
 
//System Libraries Here
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
 
//User Libraries Here
 
//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions
 
//Function Prototypes Here
 
//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const short MONTHS=3;
    const short DAYS=30;
    char array[MONTHS][DAYS];
    short sCount=0,rCount=0,cCount=0; //Count for Sunny, Rainy, and Cloudy days
    short max=0; //Determines which month had the most rain
    string most; //Names the month with most rain
    string names[MONTHS]={"June","July","August"};
    ifstream inFile;
    
    //Initialize array
    for(int y=0;y<3;y++){
        for(int x=0;x<30;x++){
            array[y][x]='X';
            //cout<<array[y][x];
        }
        //cout<<endl;
    }
    cout<<"Weather conditions during the summer season:"<<endl<<endl;
    //Fill array
    inFile.open("RainOrShine.txt");
    for(int y=0;y<3;y++){
        cout<<setw(7)<<names[y]<<": ";
        for(int x=0;x<30;x++){
            inFile>>array[y][x];
            cout<<array[y][x];
        }
        cout<<endl;
    }
    cout<<endl<<"--------------------------Report--------------------------"<<endl<<endl;
    for(int y=0;y<3;y++){
        sCount=0,rCount=0,cCount=0;
        cout<<setw(6)<<names[y]<<" had ";
        for(int x=0;x<30;x++){
            if(array[y][x]=='S')sCount++;
            else if(array[y][x]=='R'){
                rCount++;
                if(rCount>max){ //Determines which month has the most rain count
                    max=rCount;
                    most=names[y];
                }
            }
            else if(array[y][x]=='C')cCount++;
        }
        cout<<sCount<<" sunny days, "<<rCount<<" rainy days, and "
            <<cCount<<" cloudy days."<<endl;
        cout<<endl;
    }
    cout<<"The month with the most rainy days was "<<most<<" with a total of "
        <<max<<" rainy days."<<endl;
    //Exit
    return 0;
}