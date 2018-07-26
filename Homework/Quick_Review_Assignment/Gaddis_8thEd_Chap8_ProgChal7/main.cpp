/* 
 * File:   main.cpp
 * Author: Jorge Rubi
 * Created on June 25, 2018
 * Purpose: Binary String Search
 */
 
//System Libraries Here
#include <iostream>
#include <string>
using namespace std;
 
//User Libraries Here
 
//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions
 
//Function Prototypes Here
void selectionSort(string array[], int size);
int binarySearch(string names[],int NUM_NAMES,string input);

//Program Execution Begins Here
int main(int argc, char** argv) {
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
    //Exit
    return 0;
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
