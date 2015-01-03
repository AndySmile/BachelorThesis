/**
 * @version     1.0.0 03-Jan-15
 * @copyright   Copyright (c) 2014-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#ifndef __TERRAIN_DESCRIPTOR_WATER_TEST_H__
#define __TERRAIN_DESCRIPTOR_WATER_TEST_H__

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/TestCase.h>

/**
 * DemoApp UnitTest Namespace.
 *
 * This namespace includes all test cases.
 */
namespace DemoAppTest
{
    class TerrainDescriptorWaterTest : public CppUnit::TestFixture
    {
        public:
            CPPUNIT_TEST_SUITE(TerrainDescriptorWaterTest);
            CPPUNIT_TEST(processTest);
            CPPUNIT_TEST_SUITE_END();
            
        public:
        
            void processTest(void);
    };
}

#endif