/* 
 * File:   main.cpp
 * Author: Jorge Rubi
 * Purpose: Sentence Filter
 */
 
//System Libraries Here
#include <iostream>
#include <cctype>
#include <fstream>

using namespace std;
 
//User Libraries Here
 
//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions
 
//Function Prototypes Here
bool names(string &, string &); //Read the file names to be used for input & output
void filter(string, &string);
//Program Execution Begins Here
int main(int argc, char** argv) {
    string in, out;
    
    cout << "This program reads the contents of a file and changes all the "
          "letters to lowercase except the first letter of each sentence, "
          "which will be made uppercase. The revised contents will be stored "
          "in a second file." << endl;
    if( !(names(in,out)) ) //If file names are not read properly, terminate.
        return 0; 
    else 
        cout << "Files were read properly" << endl;
    //Exit
    return 0;
}
//To check case use either cctype or ascii
//fstream for fileIn fileOut structs
//names function (Input/Output switch)
//Iterate through file using file I/O (and for loop?)
//Write to output file as you iterate
    //Check for upper at beginning of file
    //Check for upper behind every period and space
    //If upper anywhere else after first char after period and space
        //make lower
bool names(string &input, string &output){
    ifstream inFile;
    ofstream outFile;
    string temp;
    
    cout << "To begin, enter the name of the input file:";
    cin >> input;
    inFile.open(input);
    
    if(inFile){
        
        cout << "Next, enter the name of the output file you'd like to create "
              "and write to:";
        cin >> output;
        
        outFile.open(output);
        
        string paragraph,paragraph2;
        
        while(getline(inFile, temp)){
            cout << temp << endl;
            paragraph += temp;
            temp = "";
        }
        // process it
        string temp2;
        int last = 0;
        for(int i = 0; i < paragraph.length(); i++){
            if(paragraph[i] == '.'){
                for(int j = last; j < i; j++){
                    temp2 += paragraph[j];
                }
                filter(temp2,paragraph2);
                last = i + 1;
            }
        }
        // this is a sentence. this is another sentence. this is a third sentence.
        // when done ouput
        outFile << paragraph2;
        /////////////////
        
        inFile.close();
    }
    else{
        cout << "File could not be opened. Program stopping.";
        return false;
    }
//Remember to close the files when done reading them in or whatever 
//    inFile.close();
//    outFile.close();
    
}
void filter(string, &string){
    
}