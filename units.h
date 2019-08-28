/*****************************************************************************
 * 
 * File: units.h
 * Author: Amenyo Folitse
 *  
 * Purpose: Converts between different units. It contains 
 * two classes : the class UValue is used for input abstraction and the 
 * class UnitConverter for unit conversion.
 * 
 * Description: User enters, on two separate command lines, the value with unit
 * to be converted and the unit to converted into. If the conversion is 
 * successful The program outputs the result in the given unit, otherwise, 
 * an error message is display.
 *  
 ****************************************************************************/

#ifndef UNITS_H
#define UNITS_H

#include <string>
#include <vector>
#include <set>

using namespace std;

class UValue {
    public:
        /* 
         * @param input value to be converted,
         * @param unit of the value to be converted
         */
        UValue(double value, string units);
        ~UValue (); 
        
        /* Returns the input value */
        double get_value () const {
            return value;
        }  
        
        /* Returns the unit in which the input value is expressed  */
        string get_units () const {
            return units;
        };  
        
                                                                 
    private:
        double value; /* value to be converted */
        string units; /* unit in which value is expressed  */  
};


class UnitConverter{   
    /* Structure to stores a conversion type */
    struct Conversion {
        string fromUnits;
        double mutiplier;
        string toUnits;
    };
    /* Vector of known conversion */
    vector<Conversion> conversion;  
    
    public: 
        UnitConverter();
        ~UnitConverter();

       /* 
        * Records a new conversion and its its inverse to the collection
        * Throws an invalid_argument exception if the conversion type is known.
        * @param input unit
        * @param input value
        * @param unit to convert into
        */
        void add_conversion(const string & from_units, const double multiplier, 
                        const string &to_units); 

        /*
         * Converts value with unit into a given unit.
         * Throws an invalid argument exception when the conversion type does 
         * not exist in the collection.
         * @param  input UValue.
         * @param  unit to convert into.
         * @return UValue object.
         */
         UValue convert_to(UValue input,const  string & to_units,
                        set<string>  seen_Units); 

         /* Two argument convert_to function. */
         UValue convert_to(UValue input, const string & to_units);
};
#endif /* UNITS_H */

