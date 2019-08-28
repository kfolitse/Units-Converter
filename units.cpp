 /* **************************************************************************
  * 
  * File: units.cpp
  * Author: Amenyo Folitse
  * Purpose: Implements units class and its basic arithmetic operations.
  * Build with: g++  -std=c++14 -Wall -Werror  -c -o units.o units.cpp
  * Modifications: 
  * 
  **************************************************************************/
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

/* add_conversion implementation */
void UnitConverter::add_conversion(string from_u, double mul, string to_u){

    vector<Conversion>::iterator it;
    for (it = this->conversion.begin(); it != this->conversion.end();++it) {
        if ((it->fromUnits == from_u) && (it->mutiplier == mul)
                && (it->toUnits == to_u)){
            string e = "Already have a conversion from" +  from_u +
                    " to " + to_u;
            /* Throw an exception if already conversion exists */
            throw invalid_argument (e); 
        }
    }
    this->conversion.push_back({from_u, mul, to_u});
    /* Also add the inverse of the conversion to the collection */
    this->conversion.push_back({to_u, 1 / mul, from_u});  
}

/* Convert_to implementation */
 UValue UnitConverter::convert_to(UValue input, string to_units){
     
     vector<Conversion>::iterator it;            
    for ( it = conversion.begin(); it != conversion.end();++it) {
        if ((it->fromUnits == input.get_units()) && (it->toUnits == to_units)){
            return UValue(it->mutiplier * input.get_value(),to_units);
        }  
    }
    string s =  "Don't know how to convert from " +  
            input.get_units() + " to " + to_units ;
    throw invalid_argument (s);
        
 }