/**************************************************************************
 * 
 * File: units.h
 * Author: Amenyo Folitse
 * Purpose : Conversion between different units.
 * 
 * Description: User enters, on two separate command line, the value with unit
 * and the unit in which the value will be converted into. 
 * The program outputs the result in the given unit if the conversion is
 * successful and an error message otherwise.
 * 
 ******************************************************************************/

#ifndef UNITS_H
#define UNITS_H
#include <string>
using namespace std;

/* 
 * Models an input value with unit 
 * Example: 23 km is models as UValue in(23,"km").
 * 
 */
class UValue {
    public:
        /* 
         * @param value to be converted
         * @param unit of the value to be converted
         */
        UValue(double v, string u);
        ~UValue ();
        
        /* Return the value to be converted */
        double get_value () const {
            return value;
        };
        
        /* Returns the unit of the value to be converted */
        string get_units () const {
            return units;
        };
                                                         
    private:
        double value; /* value to be converted */
        string units; /*  the unit of the value to be converted */
    
};

/*
 * Converts value with unit into a given unit.
 * Throws an invalid argument exception when the conversion type does 
 * not exist in the collection.
 * @param  input UValue.
 * @param  unit to convert into.
 * @return UValue object.
 */
 UValue convert_to(UValue input, string to_units); 

#endif /* UNITS_H */

