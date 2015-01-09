/**
 * @version     1.1.0 09-Jan-15
 * @copyright   Copyright (c) 2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#ifndef __HEIGHT_MAP_TEST_H__
#define __HEIGHT_MAP_TEST_H__

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/TestCase.h>

/**
 * DemoApp UnitTest Namespace.
 *
 * This namespace includes all test cases.
 */
namespace DemoAppTest
{
    class HeightMapTest : public CppUnit::TestFixture
    {
        public:
            CPPUNIT_TEST_SUITE(HeightMapTest);
            CPPUNIT_TEST(undefinedMapTest);
            CPPUNIT_TEST(accessDataTest);
            CPPUNIT_TEST(resizeTest);
            CPPUNIT_TEST(initializeByConstructorTest);
            CPPUNIT_TEST_SUITE_END();

        public:

            void undefinedMapTest(void);
            void accessDataTest(void);
            void resizeTest(void);
            void initializeByConstructorTest(void);
    };
}

#endif