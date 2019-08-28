/**************************************************************************
 * 
 * File: converter.cpp
 * Author: Amenyo Folitse
 * Purpose: Entry point of units.cpp .
 * Compilation: : 
 * g++  -std=c++14 -Wall -Werror  matrix.cpp converter.cpp -o matrix  
 *
 * 
 ****************************************************************************/

#include <cstdlib>
#include <iostream>
#include <string>
#include "units.h"
using namespace std;


int main(int argc, char** argv) {

    string fromUnits,toUnits;
    double fromValue;
    cout << "Enter value with units: " << endl;
    cin >> fromValue;
    cin >> fromUnits;
    
    UValue input(fromValue,fromUnits);
    
    // Enter the unit to convert to
    cout << "Convert to units: " << endl;
    cin >> toUnits;
    
    UValue output = convert_to(input,toUnits);
    
    // Check results
    if (output.get_units() == toUnits) {
        cout << "Converted to: " << output.get_value() << " " << output.get_units() << endl;
    
    } else {
        cout << "Couldn't convert to " << toUnits <<"!"<< endl;
    }
    
    return 0;
}


