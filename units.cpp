/*****************************************************************************
 * 
 * File: units.cpp
 * Author : Amenyo K. Folitse 
 * Description: Implements units class and its basic arithmetic operations.
 * Build with: g++  -std=c++14 -Wall -Werror  -c -o units.o units.cpp
 * Modifications: 
 * 
 *****************************************************************************/

#include "units.h"
#include <string>
#include<iostream>
using namespace std;


UValue::UValue(double val, string unit){
            this->value = val;
            this->units = unit;
}

UValue:: ~UValue (){}

/* UValue convert_to function implementation.
 * To add a new conversions, add more if branches.
 * conversion are hard-coded.
 */
UValue convert_to(UValue input, string to_units){
    if ((input.get_units() == "lb") && (to_units == "kg")) {  
        return UValue (0.45 * input.get_value(), to_units);    
    } else if ((input.get_units() == "gal") && (to_units == "L")) {
        return UValue (3.79 * input.get_value(), to_units);   
    } else if ((input.get_units() == "mi") && (to_units == "km")){
        return UValue (1.6 * input.get_value(), to_units);
    } else {
        return UValue (input.get_value(),input.get_units());
    }
}

