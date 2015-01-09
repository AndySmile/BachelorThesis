/**
 * DemoApp - Height Map Test Suite
 *
 * @author      Andy Liebke<coding@andysmiles4games.com>
 * @file        Src/Test/HeightMapTest.cpp
 * @version     1.1.0 09-Jan-15
 * @copyright   Copyright (c) 2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#include <Test/HeightMapTest.h>
#include <HeightMap.h>

#include <SimpleLib/Logger.h>

namespace DemoAppTest
{
    void HeightMapTest::undefinedMapTest(void)
    {
        HeightMap map;

        // because there is no size defined there isn't any value at that position
        // but because there's no data at all it has to return 0.0f instead of crashing
        float height = map.getHeight(10, 10);

        CPPUNIT_ASSERT(height == 0.0f);

        // even after setting a value it has to return 0.0f because there is no data map defined yet
        map.setHeight(25.5f, 10, 10);

        height = map.getHeight(10, 10);

        CPPUNIT_ASSERT(height == 0.0f);

        // clean up memory
        map.release();
    }

    void HeightMapTest::accessDataTest(void)
    {
        HeightMap map(6, 4);
        unsigned int counter = 0;

        // fill map with demo data
        for (unsigned int y=0; y < 4; ++y)
        {
            for (unsigned int x=0; x < 6; ++x) {
                map.setHeight(++counter, x, y);
            }
        }

        // check several values for correctness
        float height = map.getHeight(1, 1);

        CPPUNIT_ASSERT(height == 8.0f);

        height = map.getHeight(0, 0);
        CPPUNIT_ASSERT(height == 1.0f);

        height = map.getHeight(5, 2);
        CPPUNIT_ASSERT(height == 18.0f);

        height = map.getHeight(4, 3);
        CPPUNIT_ASSERT(height == 23.0f);

        height = map.getHeight(5, 3);
        CPPUNIT_ASSERT(height == 24.0f);

        // clean up memory
        map.release();
    }

    void HeightMapTest::resizeTest(void)
    {
        HeightMap map;

        map.resize(6, 4);

        map.setHeight(1.0f, 5, 3);

        float height = map.getHeight(5, 3);

        CPPUNIT_ASSERT(height == 1.0f);

        // in case the position is out of range it returns 0.0f
        height = map.getHeight(100, 100);

        CPPUNIT_ASSERT_MESSAGE("Position was out of the map boundaries, so the result has to be 0.0f", height == 0.0f);

        //after resizing the map it should be possible to get that height
        map.resize(5, 5);
        map.setHeight(4.0f, 10, 10);

        height = map.getHeight(10, 10);

        SimpleLib::Logger::writeDebug("height: %f", height);

        CPPUNIT_ASSERT_MESSAGE("Height has to be 0.0f after resizing the map and trying to access a height value out of boundaries!", height == 0.0f);

        // but within its boundaries it has to work
        map.setHeight(2.0f, 2, 2);

        height = map.getHeight(2, 2);

        CPPUNIT_ASSERT(height == 2.0f);

        // clean up memory
        map.release();
    }

    void HeightMapTest::initializeByConstructorTest(void)
    {
        // now test map which map initialization via constructor
        HeightMap map(50, 50);

        // the entire map is set to 0, so the result has to be 0.0f
        float height = map.getHeight(20, 20);

        CPPUNIT_ASSERT(height == 0.0f);

        /**
         * now the setting test again
         */
        map.setHeight(1.0f, 10, 10);

        height = map.getHeight(10, 10);

        CPPUNIT_ASSERT(height == 1.0f);

        // clean up memory
        map.release();
    }
}