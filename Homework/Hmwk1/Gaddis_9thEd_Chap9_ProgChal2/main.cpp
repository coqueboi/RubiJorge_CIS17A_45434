/* 
 * File:   main.cpp
 * Author: Jorge Rubi
 * Created on June 26, 2018, 10:08PM
 * Purpose: Test Scores #1
 */
 
//System Libraries Here
#include <iostream>
using namespace std;
 
//User Libraries Here
 
//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions
 
//Function Prototypes Here
void order(float *tests,int size); //Sorts array of scores in ascending order
float avg(float total,int size); //Calculates the average score

//Program Execution Begins Here
int main(int argc, char** argv) {
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