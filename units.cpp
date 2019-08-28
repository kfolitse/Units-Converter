 /* **************************************************************************
  * 
  * File: units.cpp
  * Author: Amenyo Folitse
  * Purpose: Implements units class and its basic arithmetic operations.
  * Build with: g++  -std=c++14 -Wall -Werror  -c -o units.o units.cpp
  * Modifications: 
  * 
  *****************************************************************************/

#include "units.h"
#include <stdexcept>
#include <vector>
#include <algorithm> 
#include <string>
#include <iostream>

using namespace std;


UValue::UValue (double val, string uni) : value(val),units(uni) {
    this->value = val;
    this->units = uni;
}

UValue::~UValue (){}

UnitConverter::UnitConverter (){}

UnitConverter::~UnitConverter (){} 

/* Add conversion implementation. */
void UnitConverter::add_conversion(const string & from_u, const double mul,
        const string & to_u){
    
    vector<Conversion>::iterator it;
    for (it = this->conversion.begin(); it != this->conversion.end();++it) {
        if ((it->fromUnits == from_u) && (it->mutiplier == mul) 
                && (it->toUnits == to_u)){
            string e = "Already have a conversion from " +
                    from_u + " to " + to_u;
            throw invalid_argument (e); 
        }
    }
    this->conversion.push_back({from_u, mul, to_u});
    /* dd the inverse of the conversion {from_units,multiplier,to_units} */
    this->conversion.push_back({to_u, 1 / mul, from_u});  
}

 /* Recursive Convert_to implementation */
 UValue UnitConverter::convert_to(UValue  input, const string & to_units, 
         set<string>  seen){
     
     seen.insert(input.get_units());          
    for (vector<Conversion>::iterator it = this->conversion.begin(); 
            it != this->conversion.end();++it) {
        if ((input.get_units() == it->fromUnits) && (to_units == it->toUnits)){
            return UValue(it->mutiplier * input.get_value(),to_units);  
        } else if ((input.get_units() == it->fromUnits) &&
                seen.count(it->toUnits) == 0) {
            try {
                return convert_to(UValue(it->mutiplier * input.get_value(),
                        it->toUnits),to_units, seen);
            } catch (invalid_argument e) {}
             
        }    
    }
    string s =  "Don't know how to convert from " + 
            input.get_units() + " to " + to_units ;
    throw invalid_argument (s);
 }
 
/* Two-arguments UnitConverter Interface */
 UValue UnitConverter::convert_to(UValue  input, const string & to_units) {
     return convert_to(input, to_units,{});
 }