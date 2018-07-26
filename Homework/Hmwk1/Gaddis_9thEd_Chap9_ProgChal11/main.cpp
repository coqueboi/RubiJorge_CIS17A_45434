/* 
 * File:   main.cpp
 * Author: Jorge Rubi
 * Created on June 27th, 2018, 9:40 PM
 * Purpose: Array Expander
 */
 
//System Libraries Here
#include <iostream>
using namespace std;
 
//User Libraries Here
 
//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions
 
//Function Prototypes Here
int *expand(int *arr,int size);
//Program Execution Begins Here
int main(int argc, char** argv){
    //Declare all Variables Here
    int *array, size=1, *newArr;
    //Input validation
    cout<<"This program allows you to fill an array the size of your choosing "
          "and creates an array twice the size while filling the gaps with "
          "zeroes."<<endl;
    cout<<"To begin, enter the size of the array you'd like to fill: ";
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
    newArr=new int[size];
    newArr=expand(array,size);
    //Output
    cout<<"The original array was: "<<endl;
    for(int i=0;i<size;i++){
        if(i==size-1)cout<<array[i];
        else cout<<array[i]<<", ";
    }
    cout<<endl<<"The expanded array is: "<<endl;
    for(int i=0;i<(size*2);i++){
        if(i==(size*2)-1)cout<<newArr[i];
        else cout<<newArr[i]<<", ";
        
    }
    //Exit
    return 0;
}
int *expand(int *arr,int size){
    int temp=size*2;
    int *wideArr=new int[temp];
    for(int i=0;i<temp;i++){
        if(i>=size)wideArr[i]=0;
        else wideArr[i]=arr[i];
    }
    return wideArr;
}