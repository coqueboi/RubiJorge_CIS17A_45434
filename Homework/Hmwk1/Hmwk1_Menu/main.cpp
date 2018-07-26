/* 
 * File:   main.cpp
 * Author: Jorge Rubi
 * Created on June 28th, 2018
 * Purpose: Hmwk1 Menu
 */
 
//System Libraries Here
#include <iostream>
using namespace std;
 
//User Libraries Here
 
//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions
 
//Function Prototypes Here
int prog1(); //For programs to be launched
int prog2();
int prog3();
int prog4();
int prog5();
//For program 1
int *copy(int array[],int size);
//For program 2
int *expand(int *arr,int size);
//For program 3
void order(float *tests,int size); //Sorts array of scores in ascending order
float avg(float total,int size); //Calculates the average score
//For program 4
void arrSelectSort(int [], int);
void showArray(const int[], int);
//For program 5
void arrSort(int [], int);
void show(const int[], int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    int input=1;
    cout<<"Quick Review Assignment 1:"<<endl;
    cout<<"1. Chapter 9 Challenge 10 - Reverse Array"<<endl;
    cout<<"2. Chapter 9 Challenge 11 - Array Expander"<<endl;
    cout<<"3. Chapter 9 Challenge 2 - Test Scores #1"<<endl;
    cout<<"4. Chapter 9 Challenge 6 - Case Study Modification #1"<<endl;
    cout<<"5. Chapter 9 Challenge 7 - Case Study Modification #2"<<endl;
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
    }
    //Exit
    return 0;
}
int prog1(){
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
int prog2(){
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
int prog3(){
    //Declare all Variables Here
    float *tests,total;
    int size=1;
    //Input or initialize values Here
    cout<<"This program takes in a number of test scores, sorts them, then "
            "calculates the test average."<<endl;
    cout<<"To begin, please enter the number of tests you'd like to calculate: ";
    do{
        if(size==0){
            cout<<"Zero tests were calculated."<<endl;
            return 0;
        }
        else if(size<0)cout<<"Invalid entry. Please try again: ";
        cin>>size;
        cin.ignore();
    }while(size<=0);
    tests = new float[size]; //Dynamic allocation
    for(int i=0;i<size;i++)*(tests+i)=0.0f; //Initialize array 
    cout<<"Thank you. Next, please enter the score of each test."<<endl;
    for(int i=0;i<size;i++){
        do{
            if(*(tests+i)<0.0f)cout<<"Invalid Entry. Please enter a positive score value: ";
            else cout<<"Enter test score "<<i+1<<": ";
            cin>>*(tests+i);
        }while(*(tests+i)<0.0f);
        total+=*(tests+i);
    }
    order(tests,size);
    //Output
    cout<<"The list of scores in ascending order is:"<<endl;
    for(int i=0;i<size;i++){
        cout<<*(tests+i)<<endl;
    }
    cout<<"The average test score was: "<<avg(total,size)<<endl;
    //Exit
    return 0;
}
void order(float *tests,int size){
    int minIndex,minVal; //Minimum index and value variables for sorting
    float temp;
    for(int x=0;x<size;x++){ //Iteration through indexes comparing them to min
        minIndex=x;
        minVal=*(tests+x);
        for(int i=x+1;i<size;i++){
            if(*(tests+i)<minVal){
                minVal=*(tests+i);
                minIndex=i;
            }
        }
        //Memory swap
        temp=*(tests+minIndex);
        *(tests+minIndex)=*(tests+x);
        *(tests+x)=temp;
    }
}
float avg(float total,int size){
    return total/=size;
}
int prog4(){
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
int prog5(){
    //Declare all Variables Here
    int *arrPtr,*donations;
    int size=1;
    //Input or initialize values Here
    cout<<"This program takes in the donations made to the United Cause by the "
        "employees of CK Graphics, Inc. It organizes the donations in "
        "order from highest to lowest and in the original order they were "
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
    arrSort(arrPtr, size);
    //Display the donations using the array of pointers
    cout<<"The donations, sorted in descending order, are: \n";
    show(arrPtr, size);
    //Display the donations in their original order
    cout<<"The donations, in their original order, are: \n";
    show(donations, size);
    //Exit
    return 0;
}
void arrSort(int arr[], int size){
    int startScan, maxIndex;
    int maxElem;
    for(startScan=0;startScan<(size-1);startScan++){
        maxIndex=startScan;
        maxElem=arr[startScan];
        for(int index=startScan+1;index<size;index++){
            if(arr[index]>maxElem){
                maxElem=arr[index];
                maxIndex=index;
            }
        }
        arr[maxIndex]=arr[startScan];
        arr[startScan]=maxElem;
    }
}
void show(const int arr[], int size){
    for(int count=0;count<size;count++)
        cout<<arr[count]<<" ";
    cout<<endl;
}