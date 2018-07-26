/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on July 11, 2018, 7:45 PM
 * Purpose:  Driver program to test out the statistics problem.
 */

//Libraries
#include <iostream>//I/O
using namespace std;

//User Libraries
#include "Array.h"
#include "Stats.h"

//No Global Constants

//Function Prototypes I supply
Array *fillAry(int,int);        //Fill an array and put into a structure
void prntAry(const Array *,int);//Print the array 
int *copy(const int *,int);     //Copy the array
void mrkSort(int *,int);        //Sort an array
void prtStat(const Stats *);    //Print the structure
void rcvrMem(Array *);          //Recover memory from the Array Structure
void rcvrMem(Stats *);          //Recover memory from Statistics Structure

//Functions you are to supply
Stats *stat(const Array *);      //Find & store mean, median, & modes in structure
float mean(int, int*);           //Calculate the mean
float median(int, int*);         //Calculate the median
int *mode(int, int*, int&, int&);//Calculate the mode 

//Execution begins here
int main(int argc, char*argv[]) {
    //Declare variables and fill
    int arySize=8; //Array Size
    int modNum=10; //Number to control the modes (digits 0 to 9 allowed)
    Array *array=fillAry(arySize,modNum);
    
    mrkSort(array ->data,arySize);
    
    //Print the initial array
    cout<<"Original Array"<<endl;
    prntAry(array,10);
    
    //Calculate some of the statistics
    Stats *stats=stat(array);
    
    //Print the statistics
    prtStat(stats);
    
    //Recover allocated memory
    rcvrMem(array);
    rcvrMem(stats);
    
    //Exit stage right
    return 0;
}

int *copy(const int *a,int n){
    //Declare and allocate an array
    //that is a c
    int *b=new int[n];
    //Fill
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
    //Return the copy
    return b;
}

void prtStat(const Stats *ary){
    cout<<endl;
    cout<<"The average of the array = "<<ary->avg<<endl;
    cout<<"The median of the array  = "<<ary->median<<endl;
    cout<<"The number of modes      = "<<
            ary->mode->size<<endl;
    cout<<"The max Frequency        = "<<
            ary->modFreq<<endl;
    if(ary->mode->size==0){
        cout<<"The mode set             = {null}"<<endl;
        return;
    }
    cout<<"The mode set             = {";
    for(int i=0;i<ary->mode->size-1;i++){
        cout<<ary->mode->data[i]<<",";
    }
    cout<<ary->mode->data[ary->mode->size-1]<<"}"<<endl;
}

void mrkSort(int *array,int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(array[j]<array[i]){
                int temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }
    }
}

void rcvrMem(Stats *stats){
    rcvrMem(stats->mode);
    delete stats;
}

void rcvrMem(Array *array){
    delete []array->data;
    delete array;
}

void prntAry(const Array *array,int perLine){
    //Output the array
    for(int i=0;i<array->size;i++){
        cout<<array->data[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

Array *fillAry(int n, int modNum){
    //Allocate memory
    Array *array=new Array;
    array->size=n;
    array->data=new int[array->size];
    
    //Fill the array with mod numbers
    for(int i=0;i<n;i++){
        array->data[i]=i%modNum;
    }
    //Exit function
    return array;
}

Stats *stat(const Array *array){
    //Non-working stub to be completed by the student
    cout<<endl<<"stat function to be completed by the student"<<endl;
    Stats *stats=new Stats;
    stats->mode=new Array;
    
    stats->mode->size=0;
    int nModes=0;
    
    stats->mode->data=new int[nModes];
    stats->modFreq=1;
    stats->mode->data = mode(array->size, array->data,
            stats->modFreq, stats->mode->size);
    stats->median = median(array->size, array->data);
    stats->avg = mean(array->size, array->data);
    return stats;
}

float mean(int size, int *arr){
    float sum = 0.0f;
    float num = 0.0f;
    for(int i = 0; i < size; i++){
        sum += arr[i];
    }
    num = sum / size;
    return num;
}

float median(int size, int *arr){
    float num = 0.0f;
    if(size % 2 == 0){
        num = arr[(size / 2)] + arr[((size / 2) - 1)];
        num /= 2.0f;
    }
    else{
        num = arr[size / 2];
    }
    return num;
}

int *mode(int size, int *arr, int &frequency, int &numModes){
    int *modes;
    int freq = 1;
    int nModes = 0;
    int count = 0;
    int frqncy = 1;
    int temp = 1;
    
    //Find Frequency
    for(int i = 1; i < size; i++){
        if(arr[i] == arr[i - 1]){
            frqncy++;
            if(frqncy == freq){
                nModes++;
            }
            if(frqncy > freq){
                freq = frqncy;
                nModes = 1;
            }
        }
        else frqncy = 1;
    }
    modes = new int[nModes];
    for(int i = 0; i < nModes; i++){
        modes[i] = -1;
    }
    //Insert modes into modes array
    for(int i = 1; i < size; i++){
        if(arr[i] == arr[i-1]){
            temp++;
            if(temp == freq){
                modes[count] = arr[i];
                count++;
            }
        }
        else temp = 1;
    }
    frequency = freq;
    numModes = nModes;
    return modes;
}