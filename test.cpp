 /* ***********************************************************************
  * 
  * File: units.cpp
  * Author: Amenyo Folitse
  * Created on: 
  * Purpose: Test suite implementation. This file tests units.cpp
  * 
  * Build with: g++ -std=c++14 -Wall -Werror  -c -o units.o test.cpp
  * 
  **************************************************************************/
#include "units.h"
#include "test.h"
CPPUNIT_TEST_SUITE_REGISTRATION(Test);

Test::Test() {}
Test::~Test() {}
void Test::setUp() {}
void Test::tearDown() {}

/* Tests the UValue constructor.*/
void Test::testConstructor(){
    UValue input(12 , "mi");
    CPPUNIT_ASSERT_DOUBLES_EQUAL(12,input.get_value(),1e-10);
    CPPUNIT_ASSERT(input.get_units() == "mi");
}
/* Tests the add_conversion */
void Test::testAddConversion(){
    UnitConverter u;
    u.add_conversion("mi", 1.6, "km");
    u.add_conversion("lb", 1000, "gal");
       
    try {
        /* 1 km = 1000 m already recorded. */ 
        /* Expected exception of type invalid_argument.*/
        CPPUNIT_ASSERT_THROW(u.add_conversion("mi", 1.6, "km"),
                std::invalid_argument); 
    } catch (...) {
        CPPUNIT_ASSERT(false);
    }
}

/* Tests the convert_to function  */
void Test::testConvertTo (){
    
    /* Test conversion operations  */
    UnitConverter u;
    u.add_conversion("mi", 1.6, "km"); // 1 mi = 1.6 km
    UValue out(0, "invalid");

    out = u.convert_to(UValue(3,"mi"),"km");
    CPPUNIT_ASSERT_DOUBLES_EQUAL(4.8,out.get_value(),1e-10);
    CPPUNIT_ASSERT("km" == out.get_units());

    out = u.convert_to(UValue(15,"km"),"mi");
    CPPUNIT_ASSERT_DOUBLES_EQUAL(9.375,out.get_value(),1e-10);
    CPPUNIT_ASSERT("mi" == out.get_units());
    
    /* Doesn't recognize a conversion type.*/
    try {
        /* Should not be able to convert from gal to L.*/ 
        /* Expected exception of type invalid_argument */
       CPPUNIT_ASSERT_THROW(u.convert_to(UValue(2,"gal"),"L"),
               std::invalid_argument ); 
    }
    catch (...) {
        CPPUNIT_ASSERT(false); // Wrong Exception type.
    } 
}


