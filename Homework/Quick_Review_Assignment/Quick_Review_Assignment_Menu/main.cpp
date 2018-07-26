/* 
 * File:   main.cpp
 * Author: Jorge Rubi
 * Created on June 25, 2018
 * Purpose: Menu
 */
 
//System Libraries Here
#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <string>
using namespace std;
 
//User Libraries Here
 
//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions
const float YEN_PER_DOLLAR = 98.93f;
const float EUROS_PER_DOLLAR = 0.74f;
const float e = 2.718281f;
//Function Prototypes Here
void prog1(); //For programs to be launched
void prog2();
void prog3();
void prog4();
void prog5();
void prog6();
void prog7();
//For Program 5
float celsius(float);
//For Program 7
void selectionSort(string array[], int size);
int binarySearch(string names[],int NUM_NAMES,string input);

//Program Execution Begins Here
int main(int argc, char** argv) {
    int input=1;
    cout<<"Quick Review Assignment 1:"<<endl;
    cout<<"1. Chapter 3 Challenge 12 - Celsius to Fahrenheit"<<endl;
    cout<<"2. Chapter 3 Challenge 13 - Currency"<<endl;
    cout<<"3. Chapter 4 Challenge 10 - Days in a Month"<<endl;
    cout<<"4. Chapter 5 Challenge 11 - Population"<<endl;
    cout<<"5. Chapter 6 Challenge 7 - Celsius Temperature Table"<<endl;
    cout<<"6. Chapter 7 Challenge 6 - Rain or Shine"<<endl;
    cout<<"7. Chapter 8 Challenge 7 - Binary String Search"<<endl;
    cout<<endl<<"Please enter the number of the program you'd like to run: ";
    do{
        if(input<1||input>7)cout<<"Invalid entry. Please try again: ";
        cin>>input;
        cin.ignore();
    }while(input<1||input>7);
    switch(input){
        case 1: prog1();break;
        case 2: prog2();break;
        case 3: prog3();break;
        case 4: prog4();break;
        case 5: prog5();break;
        case 6: prog6();break;
        case 7: prog7();break;
    }
    //Exit
    return 0;
}
void prog1(){
    //Declare all Variables Here
    float input = 0, total = 0;
    //Input or initialize values Here
    cout<<"This program converts temperatures in Celsius to "
            "temperatures in Fahrenheit."<<endl;
    cout<<"To begin, please enter a valid measurement of temperature"
            " in Celsius: ";
    //Input Validation 
    do{
        cin>>input;
        if(input<-273.15f)cout<<"Invalid entry, try again: ";
    }while(input<-273.15f);
    //Process/Calculations Here
    total = ((1.8f)*input)+32;
    //Output Located Here
    cout<<endl;
    cout<<input<<" degrees Celsius equals "<<total<<" degrees Fahrenheit"<<endl;
}
void prog2(){
    //Declare all Variables Here
    float input = 0.0f;
    //Input or initialize values Here
    cout<<"This program converts U.S. Dollar amounts "
            "into Japanese Yen and Euros."<<endl;
    cout<<"To begin, please enter the value of U.S. Dollar "
            "you'd like to convert: ";
    cin>>input;
    //Process/Calculations Here
    cout<<"Your value of $ "<<input<<" equals:"<<endl;
    cout<<fixed<<showpoint<<setprecision(2)<<
            "¥ "<<input*YEN_PER_DOLLAR<<" Japanese Yen."<<endl<<
            "€ "<<input*EUROS_PER_DOLLAR<<" Euros."<<endl;
}
void prog3(){
    //Declare all Variables Here
    int month, year;
    month=1, year=0;
    const int SIZE = 12;
    string names[SIZE] = {"January","February","March","April","May","June",
        "July","August","September","October","November","December"};
    //Input or initialize values Here
    cout<<"This program calculates how many days there are in a month and year "
            "of your choosing."<<endl;
    cout<<"Additionally, this program will determine whether or not the year is"
            " a leap year."<<endl;
    cout<<"To begin, enter a month in the range of 1 through 12: ";
    do{
        if(month<=0||month>12){
            cout<<"Invalid value. Try again: ";
        }
        cin>>month;
    }while(month<=0||month>12);
    cout<<"Next, enter the year: ";
    do{
        if(year<0){
            cout<<"Invalid value. Try again: ";
        }
        cin>>year;
    }while(month<0);
    //Process/Calculations Here
    if(month==2){
        if(year%100 == 0 && year%400 == 0){
            cout<<"Because "<<year<<" is a leap year, "<<names[month-1]<<
                    " has 29 days."<<endl;
        }
        else if(year%4==0){
               cout<<"Because "<<year<<" is a leap year, "<<names[month-1]<<
                    " has 29 days."<<endl; 
            }
        else{
            cout<<"Because "<<year<<" is not a leap year, "<<names[month-1]<<
                    " has 28 days."<<endl;
        }
    }
    else if(month==1||month==3||month==5||month==7||month==8||month==10||month==12){
            cout<<"The month of "<<names[month-1]<<" has 31 days."<<endl;
    }
    else{
        cout<<"The month of "<<names[month-1]<<" has 30 days."<<endl;
    }
    if(year%100 == 0 && year%400 == 0){
        cout<<"The year"<<year<<" is a leap year."<<endl;
    }
    else if(year%4==0){
        cout<<"The year "<<year<<" is a leap year."<<endl; 
    }
    else{
        if(month!=2)
            cout<<year<<" is not a leap year."<<endl;
    }
}
void prog4(){
    //Declare all Variables Here
    int popSize=0, strtSize=2, days=1;
    float avg=0.0f, temp=0.0f;
    //Input or initialize values Here
    cout<<"This program predicts the size of a population of organisms."<<endl;
    cout<<"To begin, enter the starting number of organisms: ";
    do{
        if(strtSize<2)cout<<"Invalid Entry. Please enter a number no less than 2: ";
        cin>>strtSize;
    }while(strtSize<2);
    cout<<"Next, enter their average daily population increase as a percentage: ";
    do{
        if(avg<0)cout<<"Invalid Entry. Please enter a positive percentage: ";
        cin>>avg;
    }while(avg<0);
    cout<<"Finally, enter the number of days the population will multiply: ";
    do{
        if(days<1)cout<<"Invalid Entry. Please enter a number no less than 1: ";
        cin>>days;
    }while(days<1);
    //Process/Calculations Here
    avg=avg/100;
    for(short i=1;i<=days;i++){
        temp=avg*i;
        popSize=strtSize*pow(e,temp);
        cout<<"Day "<<i<<" population: "<<popSize<<"."<<endl;
    }
}
void prog5(){
    //Declare all Variables Here
    float f;
    //Input or initialize values Here
    cout<<"This program converts Fahrenheit temperatures to Celsius."<<endl;
    cout<<"To begin, enter a temperature in Fahrenheit: ";
    cin>>f;
    for(short i=0;i<=20;i++){
        cout<<"Fahrenheit: "<<f+i<<" Celsius: "<<celsius(f+i)<<endl;
    }
}
float celsius(float f){
    return ((f-32)/1.8f);
}
void prog6(){
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
}
void prog7(){
    //Declare all Variables Here
    const int NUM_NAMES=20;
    string names[NUM_NAMES]=
        {"Collins, Bill", "Smith, Bart", "Michalski, Joe", "Griffin, Jim",
	"Sanchez, Manny", "Rubin, Sarah", "Taylor, Tyrone", "Johnson, Jill",
	"Allison, Jeff", "Moreno, Juan", "Wolfe, Bill", "Whitman, Jean",
	"Moretti, Bella", "Wu, Hong", "Patel, Renee", "Harrison, Rose",
	"Smith, Cathy", "Conroy, Pat", "Kelly, Sean", "Holland, Beth"};
    string input;
    int loc=0; //Location of value in name array
    
    //Input or initialize values Here
    selectionSort(names,NUM_NAMES);
    cout<<"List of names: "<<endl<<endl;
    for(short i=0;i<NUM_NAMES;i++){
        cout<<names[i]<<" | ";
    }
    cout<<"\n\nThis program sorts a list of names and tells you the index at "
            "which it was stored."<<endl;
    cout<<"Enter any of the names listed above, including the comma: ";
    getline(cin,input);
    loc=binarySearch(names,NUM_NAMES,input);
    //Output Located Here
    if(loc==-1)cout<<"That name was not found in the list."<<endl;
    else{
        cout<<"That name was found at index #"<<loc<<endl;
    }
}
void selectionSort(string array[], int size){
    int minIndex;
    string minValue;
    for(int start=0;start<(size-1);start++){
        minIndex=start;
        minValue=array[start];
        for(int index=start+1;index<size;index++){
            minValue=array[index];
            minIndex=index;
        }
        array[minIndex]=array[start];
        array[start]=minValue;
    }
}
int binarySearch(string names[],int NUM_NAMES,string input){
    int first=0,last=NUM_NAMES-1,middle,position=-1;					
    bool found=false;

    while(!found&&first<=last){
        middle=(first+last)/2; 
        if(names[middle]==input){
            found=true;
            position=middle;
        }
        else if(names[middle]>input)last = middle - 1;
        else first = middle+1;
    }
    return position;	
}  