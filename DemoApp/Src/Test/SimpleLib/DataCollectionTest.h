/**
 * @version     1.0.0 26-Dec-14
 * @copyright   Copyright (c) 2014-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#ifndef __SIMPLE_LIB_DATA_COLLECTION_TEST_H__
#define __SIMPLE_LIB_DATA_COLLECTION_TEST_H__

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/TestCase.h>

/**
 * DemoApp UnitTest Namespace.
 *
 * This namespace includes all test cases.
 */
namespace DemoAppTest
{
    class DataCollectionTest : public CppUnit::TestFixture
    {
        public:
            CPPUNIT_TEST_SUITE(DataCollectionTest);
            CPPUNIT_TEST(loadDataFromFileTest);
            CPPUNIT_TEST(accessDataTest);
            CPPUNIT_TEST_SUITE_END();
            
        public:
            void loadDataFromFileTest(void);
            void accessDataTest(void);
    };
}

#endif