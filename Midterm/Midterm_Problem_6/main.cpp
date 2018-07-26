/* 
 * File:   main.cpp
 * Author: Jorge Rubi
 * Created on July 16th, 2018, 12:02PM
 * Purpose: Float Representation
 *          Scaled Binary - 4 Byte/32bit representation
 */
 
//System Libraries Here
#include <iostream>
using namespace std;
 
//User Libraries Here
 
//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions
 
//Function Prototypes Here
//void conversions();

//Program Execution Begins Here
int main(int argc, char** argv) {
    cout << "Here are the conversions for the following numbers:" << endl<<endl;
    
    cout << "2.875" << endl;
    cout << "in binary: 0000 0010.1110 0000" << endl;
    cout << "in octal : 2.7" << endl;
    cout << "in hex   : 2.E" << endl;
    cout << "float representation: " << endl;
    cout << "   0101 1100|0000 0000|0000 0000|0000 0010 " << endl;
    cout << "   or" << endl;
    cout << "   5C000002 base 16 " << endl <<endl;
    
    cout << "0.1796875" << endl;
    cout << "in binary: 0000 0000.0010 1110" << endl;
    cout << "in octal : 0.134" << endl;
    cout << "in hex   : 0.2E " << endl;
    cout << "float representation: " << endl;
    cout << "   0101 1100|0000 0000|0000 0000|1111 1110 " << endl;
    cout << "   or" << endl;
    cout << "   5C0000FE base 16 " << endl;
    
    cout << "---------------------------------------------------" << endl<<endl;
    
    cout << "Here are the conversions for the negative versions of the "
            "previous numbers: " << endl<<endl;
    
    cout << "-2.875" << endl;
    cout << "in binary: 1111 1101.0010 0000" << endl;
    cout << "in octal : -2.7" << endl;
    cout << "in hex   : -2.E" << endl;
    cout << "float representation: " << endl;
    cout << "   1110 1001|0000 0000|0000 0000|0000 0100 " << endl;
    cout << "   or" << endl;
    cout << "   E9000004 base 16 " << endl << endl;
    
    cout << "-0.1796875" << endl;
    cout << "in binary: 1111 1111.1101 0010" << endl;
    cout << "in octal : -0.134" << endl;
    cout << "in hex   : -0.2E " << endl;
    cout << "float representation: " << endl;
    cout << "   1110 1001|0000 0000|0000 0000|0000 0000" << endl;
    cout << "   or" << endl;
    cout << "   E9000000 base 16 " << endl;
    
    cout << "---------------------------------------------------" << endl<<endl;
    
    cout << "Here are the conversions for the following numbers:" << endl<<endl;
    cout << "Note: '...' after a number indicates a repeating decimal." << endl;
    cout << "Note: the following conversions follow the conversion "
            "standard given in class." << endl << endl;
    
    cout << "59999901 is equal to 1.06..." << endl << endl;
    
    cout << "59999902 is equal to 2.12121212128" << endl << endl;
    
    cout << "A66667FE is equal to -2.666676" << endl << endl;
    
    //Exit
    return 0;
}