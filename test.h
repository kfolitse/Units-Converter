/**************************************************************************
 * 
 * File: test.h
 * Author: Amenyo Folitse
 * Purpose: Test class declaration that tests units.cpp
 *  
 ****************************************************************************/
#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <set>
#include <string>
#include <cmath>

using namespace std;

#include <cppunit/extensions/HelperMacros.h>

class TestContext : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(TestContext);
    CPPUNIT_TEST(testConstructor);
    CPPUNIT_TEST(testConvert_to);
    CPPUNIT_TEST_SUITE_END();

public:
    TestContext();
    virtual ~TestContext();
    void setUp();
    void tearDown();
    
private:
    void testConstructor();
    void testConvert_to();
    
};


#endif /* TEST_H */


