/* 
 * File:   main.cpp
 * Author: Jorge Rubi
 * Created on July 2nd, 2018, 5:00 PM
 * Purpose: Lab Statistics
 */
 
//System Libraries Here
#include <iostream>
#include <cstdlib>
using namespace std;
 
//User Libraries Here
 
//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions
 
//Function Prototypes Here
float mean(int *,int);      //Calculate the mean
float median(int *,int);    //Calculate the median
int *mode(int *,int);       //Calculate the mode
void selectSort(int *,int); //Sort the array

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    int *array, size=1, choice=1;
    const int SIZE=3;
    string names[SIZE]={"mean","median","mode"};
    cout<<"------------------------Lab Statistics Program------------------------"<<endl;
    cout<<"1. Mean \n2. Median \n3. Mode"<<endl;
    cout<<"Select what you would like to calculate by entering the option number: ";
    //Input Validation
    do{
        
        if(choice<=0||choice>3)cout<<"Invalid entry. Please try again: ";
        cin>>choice;
        cin.ignore();
    }while(choice<=0||choice>3);
    cout<<"Enter the number of entries you'd like to calculate: ";
    //Input validation
    do{
        if(size==0){
            cout<<"Zero entries were computed."<<endl;
            return 0;
        }
        else if(size<0)cout<<"Invalid entry. Please try again: ";
        cin>>size;
        cin.ignore();
    }while(size<=0);
    //Dynamic allocation and initialization
    array=new int[size];
    for(int i=0;i<size;i++)array[i]=0;
    cout<<"Enter the set of numbers to calculate the "<<names[choice-1]<<": "<<endl;
    for(int i=0;i<size;i++){
        cout<<"Index #"<<i+1<<": ";
        cin>>array[i];
    }
    //Sort the array of numbers
    selectSort(array,size);
    //Execute function according to choice
    switch(choice){
        case 1: cout<<"The mean = "<<mean(array,size)<<endl;break;
        case 2: cout<<"The median = "<<median(array,size)<<endl;break;
        case 3:{array=mode(array,size);
                for(int i=0;i<size;i++){
                    cout<<array[i]<<" ";
                }
                break;
        }
    }
    //Exit
    return 0;
}
void selectSort(int *arr, int size){
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
float mean(int *array,int size){
    int sum=0;
    for(int i=0;i<size;i++)sum+=array[i];
    return (sum/(float)(size));
}
float median(int *arr,int size){
    if((size%2)==0){ //If even
        return (((arr[((size/2)-1)]+arr[(size/2)])/2.0f)); //Avg of the 2 center points
    }
    else{ //If odd
        return arr[(size/2)];
    }
}
//int *mode(int *arr,int size){
//    int same=0, maxCount, mode, results[];
//    for(int i=0;i<size;i++){
//        if(arr[i+1]==arr[i]){
//            same++;
//            maxCount=same;
//        }
//        else same=0;
//    }
//    for(int i=0;i<size;i++){
//        for(int j=0;j<maxCount;j++){
//            if(arr[i+j]==arr[i+1]){
//                mode+=1;
//                
//            }
//        }
//    }
//}
int *mode(int *arr,int size){
    int *modes,freqCount=1,freq=1,count=0,numMode=0,modeSize=0;
    for(int i=1;i<size;i++){
        if(arr[i]==arr[i-1]){
            freqCount++;
            if(freqCount==freq)numMode++;
            if(freqCount>freq){
                freq=freqCount;
                numMode=1;
            }
        }
        else freqCount=1;
    }
    //Initialize modes array
    modeSize=2+numMode;
    modes=new int[modeSize];
    for(int i=0;i<modeSize;i++)modes[i]=-1;
    modes[count]=numMode;count++;
    modes[count]=freq;count++;
    int temp=1;
    for(int i=1;i<size;i++){
        if(arr[i]==arr[i-1]){
            temp++;
            if(temp==freq){
                modes[count]=arr[i];
                count++;
            }
        }
        else temp=1;
    }
    return modes;
}














