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

#include "test.h"
#include "units.h"
#include <string>
CPPUNIT_TEST_SUITE_REGISTRATION(Test);

Test::Test() {}
Test::~Test() {}
void Test::setUp() {}
void Test::tearDown() {}
/* Test UValue constructor.*/
void Test::testConstructor(){
    UValue input(12 , "mi");
    CPPUNIT_ASSERT_DOUBLES_EQUAL(12,input.get_value(),1e-10);
    CPPUNIT_ASSERT(input.get_units() == "mi");
}

/* Test add_conversion function */
void Test::testAddConversion(){
    UnitConverter u;
    try {
        //  1 km = 1000 m. New record. This should not throw any exception. 
       CPPUNIT_ASSERT_NO_THROW(u.add_conversion("km", 1000, "m"));
    } catch (...) {
        CPPUNIT_ASSERT(false);
    }
    
    /* Test UnitConverter doesn't allow a conversion more than once */
    try {
        /*1 km = 1000 m already recorded. 
         * Expect exception of type invalid_argument. */
        CPPUNIT_ASSERT_THROW(u.add_conversion("km", 1000, "m"),std::invalid_argument); 
    } catch (...) {
        CPPUNIT_ASSERT(false);
    }

    try {
        /* 1 m = 1 /1000 km already recorded. 
         * Expect exception of type invalid_argument. */
        CPPUNIT_ASSERT_THROW(u.add_conversion("m", 1.0 / 1000, "km"),std::invalid_argument); 

    } catch (...) {
        CPPUNIT_ASSERT(false); 
    }
}

/* Test convert_to */
void Test::testConvertTo (){

    // Test UniConverter allows conversion operations 
    UnitConverter u;
    u.add_conversion("mi", 1.6, "km"); // 1 mi = 1.6 km
    UValue out(0, "invalid");

    out = u.convert_to(UValue(3,"mi"),"km");
    CPPUNIT_ASSERT_DOUBLES_EQUAL(4.8,out.get_value(),1e-10);
    CPPUNIT_ASSERT("km" == out.get_units());

    out = u.convert_to(UValue(15,"km"),"mi");
    CPPUNIT_ASSERT_DOUBLES_EQUAL(9.375,out.get_value(),1e-10);
    CPPUNIT_ASSERT("mi" == out.get_units());

   /* UnitConverter allows multiple conversions for a type */
    u.add_conversion("km", 1000, "m");  // 1km = 1000m

    out = u.convert_to(UValue(2, "km"), "m");
    CPPUNIT_ASSERT_DOUBLES_EQUAL(2000, out.get_value(),1e-10);
    CPPUNIT_ASSERT(out.get_units() == "m");

    out = u.convert_to(UValue(20000, "m"), "km");
    CPPUNIT_ASSERT_DOUBLES_EQUAL(20, out.get_value(),1e-10);
    CPPUNIT_ASSERT(out.get_units() == "km");

   /* UnitConverter throws on unrecognized conversion */
    try {
        /* Should not be able to convert from gal to L.
         * Expected exception. No exception means failure 
         */
       CPPUNIT_ASSERT_THROW(u.convert_to(UValue(2,"gal"),"L"),
               std::invalid_argument ); 
    }
    catch (...) {
        CPPUNIT_ASSERT(false); 
    }

    /* Test Multi-step conversion operations that are possible */
    UnitConverter v;
    v.add_conversion("A", 2, "B");  // 1 A = 2 B
    v.add_conversion("B", 3, "C");  // 1 B = 3 C
    v.add_conversion("A", 5, "D");  // 1 A = 5 D
    v.add_conversion("E", 10, "F"); // 1 E = 10 F

    UValue out3(0, "invalid");
    
    try{
        /* should be able de convert from A to C, through B */
        out3 = v.convert_to(UValue(1,"A"),"C");
        CPPUNIT_ASSERT_DOUBLES_EQUAL(6,out3.get_value(),1e-10);
        CPPUNIT_ASSERT("C" == out3.get_units());
    } catch (...) {
        CPPUNIT_ASSERT(false); // catch unexpected exception
    }

    try {
        /* Should be able de convert from C to A, through B. */
        out3 = v.convert_to(UValue(18,"C"),"A");
        CPPUNIT_ASSERT_DOUBLES_EQUAL(3,out3.get_value(),1e-10);
        CPPUNIT_ASSERT("A" == out3.get_units());
    } catch (...) {
        CPPUNIT_ASSERT(false); // catch unexpected exception

    }

   /* Test Multi-step conversions that are impossible should throw */
    try {
        /* Should not be able to convert from B to F.
         * Expected exception.
         */
        CPPUNIT_ASSERT_THROW(u.convert_to(UValue(20,"B"),"F"),
                std::invalid_argument );
    } catch (...) {
        CPPUNIT_ASSERT(false); 
    }

}
