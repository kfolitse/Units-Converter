/**************************************************************************
 * 
 * File: converter.cpp
 * Author: Amenyo Folitse
 * Purpose: Entry point of units.cpp .
 * Compilation:
 * g++  -std=c++14 -Wall -Werror  matrix.cpp converter.cpp -o matrix  
 *
 * Conversion are declared in a text file. The file name is passed to the
 * program by command line.
 * 
 ****************************************************************************/


#include <cstdlib>
#include <iostream>
#include <string>
#include "units.h"
#include <iostream>
#include <fstream>
#include <set>


using namespace std;

/*
 * Initialization function.
 * This is called by main function to create/initialize
 * the collection/vector of possible conversion type.
 */
UnitConverter converterUnit(){

    UnitConverter u;
    
    string file, fromUnits, toUnits;
    double multiplier;
    cout << "Enter file name: " << endl;
    cin >> file;
    
   ifstream ifile(file);    
   if (!ifile.is_open()) {
       string s =  "File does not exist ";
       throw invalid_argument (s);
   }
   
    while (ifile >> fromUnits >> multiplier >> toUnits){
        u.add_conversion (fromUnits ,multiplier, toUnits);
   }
   ifile.close();
   
   return u;
}

int main(int argc, char** argv) {

    string fromUnits,toUnits;
    double fromValue;
    std::cout << "Enter value with units: " << endl;
    std::cin >> fromValue;
    std::cin >> fromUnits;
  
    std::cout << "Convert to units: " << endl;
    std::cin >> toUnits;
  
    // Initialize the collection of known conversion.
    UnitConverter u;
    set<string> s;
    try {
        u = converterUnit();
            // Create an object Uvalue;
        UValue input = UValue(fromValue,fromUnits);
        UValue output = u.convert_to(input, toUnits,s);
        std::cout << "Converted to: " << output.get_value() << " " << output.get_units() << endl;
    
    } catch (invalid_argument e){
        std::cout << "Couldn't convert to " << toUnits << "!" <<endl;
        std::cout << e.what() << endl;
     
    }
    
    return 0;
}

