/**
 * @version     2.0.0 09-Jan-15
 * @copyright   Copyright (c) 2014-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#ifndef __TERRAIN_ENVIRONMENT_TEST_H__
#define __TERRAIN_ENVIRONMENT_TEST_H__

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/TestCase.h>

/**
 * DemoApp UnitTest Namespace.
 *
 * This namespace includes all test cases.
 */
namespace DemoAppTest
{
    class TerrainEnvironmentTest : public CppUnit::TestFixture
    {
        public:
            CPPUNIT_TEST_SUITE(TerrainEnvironmentTest);
            CPPUNIT_TEST(processTest);
            CPPUNIT_TEST_SUITE_END();
            
        public:
            
            void processTest(void);
    };
}

#endif