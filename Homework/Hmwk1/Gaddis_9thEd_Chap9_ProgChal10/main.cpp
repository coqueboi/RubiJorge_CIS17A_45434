/* 
 * File:   main.cpp
 * Author: Jorge Rubi
 * Created on June 24th, 2018, 7:36 PM
 * Purpose: Reverse Array
 */
 
//System Libraries Here
#include <iostream>
using namespace std;
 
//User Libraries Here
 
//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions
 
//Function Prototypes Here
int *copy(int array[],int size);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    int *array, size=1, *arrCopy;
    //Input validation
    cout<<"This program fills an integer array with values then reverses "
          "their order.\nTo begin, please enter the number of indices you "
          "would like to fill: ";
    do{
        if(size==0){
            cout<<"Zero entries were computed."<<endl;
            return 0;
        }
        else if(size<0)cout<<"Invalid entry. Please try again: ";
        cin>>size;
        cin.ignore();
    }while(size<=0);
    //Dynamic Allocation
    array=new int[size];
    //Array Initialization
    for(int i=0;i<size;i++)array[i]=0;
    cout<<"Next, please fill the array with integers."<<endl;
    for(int i=0;i<size;i++){
        cout<<"Index #"<<i+1<<": ";
        cin>>array[i];
    }
    arrCopy=new int[size];
    arrCopy=copy(array,size);
    //Output
    cout<<"The original array was: "<<endl;
    for(int i=0;i<size;i++){
        if(i==size-1)cout<<array[i];
        else cout<<array[i]<<", ";
    }
    cout<<endl<<"The reversed array is: "<<endl;
    for(int i=0;i<size;i++){
        if(i==size-1)cout<<arrCopy[i];
        else cout<<arrCopy[i]<<", ";
        
    }
    //Exit
    return 0;
}
int *copy(int array[],int size){
    //Declare array
    int *arrCopy=new int[size];
    //Initialize array in reverse
    for(int i=size-1,j=0;i>=0;i--,j++){
        arrCopy[i]=array[j];
    }
    return arrCopy;
}