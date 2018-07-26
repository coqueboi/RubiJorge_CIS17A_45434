/* 
 * File:   main.cpp
 * Author: Jorge Rubi
 * Created on June 27th, 2018, 2:09 PM
 * Purpose: Case Study Modification #1
 */
 
//System Libraries Here
#include <iostream>
using namespace std;
 
//User Libraries Here
 
//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions
 
//Function Prototypes Here
void arrSelectSort(int [], int);
void showArray(const int[], int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    int *arrPtr,*donations;
    int size=1;
    //Input or initialize values Here
    cout<<"This program takes in the donations made to the United Cause by the"
        "by the employees of CK Graphics, Inc. It organizes the donations in "
        "order from lowest to highest and in the original order they were "
        "received."<<endl;
    cout<<"To begin, please enter the number of donations you'd like to enter: ";
    //Input validation loop
    do{
        if(size==0){
            cout<<"Zero donations were sorted."<<endl;
            return 0;
        }
        else if(size<0)cout<<"Invalid entry. Please try again: ";
        cin>>size;
        cin.ignore();
    }while(size<=0);
    //Dynamic allocation
    donations=new int[size]; 
    arrPtr=new int[size];
    //Array Initialization
    for(int i=0;i<size;i++){
        donations[i]=0;
        arrPtr[i]=NULL;
    }
    cout<<"Thank you. Next, please enter the donation amounts."<<endl;
    for(int i=0;i<size;i++){
        do{
            if(donations[i]<0)cout<<"Invalid Entry. Please enter a positive score value: ";
            else cout<<"Enter donation amount #"<<i+1<<": ";
            cin>>donations[i];
        }while(donations[i]<0);
    }
    //Make each element point to an element in the donations array
    for(int i=0;i<size;i++)
        arrPtr[i]=donations[i];
    //Sort the elements of the array of pointers.
    arrSelectSort(arrPtr, size);
    //Display the donations using the array of pointers
    cout<<"The donations, sorted in ascending order, are: \n";
    showArray(arrPtr, size);
    //Display the donations in their original order
    cout<<"The donations, in their original order, are: \n";
    showArray(donations, size);
    //Exit
    return 0;
}
void arrSelectSort(int arr[], int size){
    int startScan, minIndex;
    int minElem;
    for(startScan=0;startScan<(size-1);startScan++){
        minIndex=startScan;
        minElem=arr[startScan];
        for(int index=startScan+1;index<size;index++){
            if(arr[index]<minElem){
                minElem=arr[index];
                minIndex=index;
            }
        }
        arr[minIndex]=arr[startScan];
        arr[startScan]=minElem;
    }
}
void showArray(const int arr[], int size){
    for(int count=0;count<size;count++)
        cout<<arr[count]<<" ";
    cout<<endl;
}