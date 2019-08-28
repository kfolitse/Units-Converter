/*****************************************************************************
 * File: test.cpp
 * Author : Amenyo K. Folitse
 * Description: Tests UValue class and its basic arithmetic operations.
 * 
 *****************************************************************************/
#include "test.h"
#include "units.h"
CPPUNIT_TEST_SUITE_REGISTRATION(TestContext);

TestContext::TestContext() {}

TestContext::~TestContext() {}

void TestContext::setUp() {}

void TestContext::tearDown() {}

/* Test the constructor */
void TestContext::testConstructor() {
    UValue input(12 , "mi");
    CPPUNIT_ASSERT(input.get_value() == 12);
    string fromUnit = input.get_units();
    CPPUNIT_ASSERT(fromUnit == "mi");
}

/* Tests conversion between different units */
void TestContext::testConvert_to(){
    
    // Create UValue object
    UValue input1(34,"gal");
    UValue input2(15,"mi");
    UValue input3(4,"lb");

    // do few conversion
    UValue out1 = convert_to(input1,"L");
    UValue out2 = convert_to(input2,"km");
    UValue out3 = convert_to(input3,"kg");

    /* Check the expected value and units */
    CPPUNIT_ASSERT_EQUAL(128.86,out1.get_value());
    CPPUNIT_ASSERT("L" == out1.get_units());

    CPPUNIT_ASSERT_EQUAL(24.0,out2.get_value());
    CPPUNIT_ASSERT("km" == out2.get_units());

    CPPUNIT_ASSERT_EQUAL(1.8,out3.get_value());
    CPPUNIT_ASSERT("kg" == out3.get_units());
    
    // Attempt a conversion that does not exist
    UValue input4(10,"ft");
    UValue out4 = convert_to(input4,"L");
    CPPUNIT_ASSERT_EQUAL (10.0, out4.get_value());
    CPPUNIT_ASSERT("ft" == out4.get_units());
    
}

