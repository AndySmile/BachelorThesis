/**
 * @version     1.0.0 04-Jan-15
 * @copyright   Copyright (c) 2014-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#ifndef __TERRAIN_ABSTRACT_TEST_H__
#define __TERRAIN_ABSTRACT_TEST_H__

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/TestCase.h>

/**
 * DemoApp UnitTest Namespace.
 *
 * This namespace includes all test cases.
 */
namespace DemoAppTest
{
    class TerrainAbstractTest : public CppUnit::TestFixture
    {
        public:
            CPPUNIT_TEST_SUITE(TerrainAbstractTest);
            CPPUNIT_TEST(addEntitiesTest);
            CPPUNIT_TEST_SUITE_END();
            
        public:
            
            void addEntitiesTest(void);
    };
}

#endif