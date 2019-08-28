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


/*
 * Initialization function.
 * This is called by main function to create/initialize
 * the collection of possible conversion type.
 */
UnitConverter converterUnit(){

    UnitConverter u;
    u.add_conversion("mi",1.6,"km");
    u.add_conversion ("mi",5280, "ft");

    u.add_conversion ( "ft", 12, "in");
    u.add_conversion ("in", 2.54, "cm");
    u.add_conversion("lb",0.45,"kg");
    u.add_conversion("stone",14,"lb");
    u.add_conversion("lb",1000,"g");
    u.add_conversion("gal", 3.79, "L");
    u.add_conversion("bushel",9.3,"gal");
    u.add_conversion("ft^3",7.5,"gal");
    u.add_conversion("L",1000,"ml");

    return u;
}


int main(int argc, char** argv) {

    string fromUnits,toUnits;
    double fromValue;
    cout << "Enter value with units: " << endl;
    cin >> fromValue;
    cin >> fromUnits;
  
    cout << "Convert to units: " << endl;
    cin >> toUnits;
  
    // Initialize the collection of known conversion.
    UnitConverter u = converterUnit();
    
    // Create an object Uvalue;
    UValue input = UValue(fromValue,fromUnits);
    
    try {
        UValue output = u.convert_to(input, toUnits);
        cout << "Converted to: " << output.get_value() << " " << output.get_units() << endl;
    } catch (invalid_argument e){
        cout << "Couldn't convert to " << toUnits << "!" <<endl;
        cout << e.what() << endl;
    }

    return 0;
}