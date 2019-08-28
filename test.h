/**************************************************************************
 * 
 * File: test.h
 * Author: Amenyo Folitse
 * Purpose: Test class that tests units.cpp
 *  
 ****************************************************************************/

#ifndef TEST_H
#define TEST_H
#include <cppunit/extensions/HelperMacros.h>

class Test: public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(Test);
    CPPUNIT_TEST(testConstructor);
    CPPUNIT_TEST(testAddConversion);
    CPPUNIT_TEST(testConvertTo);

    CPPUNIT_TEST_SUITE_END();

public:
    Test();
    virtual ~Test();
    void setUp();
    void tearDown();

private:
    void testConstructor();
    void testAddConversion();
    void testConvertTo ();
};

#endif /* TEST_H */

