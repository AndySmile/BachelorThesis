/**
 * DemoApp - Abstract Terrain Model Test Suite.
 *
 * Actually this is a test suite for TerrainAbstract class.
 * like the name let it already assume that the class is abstract
 * so we need a particular implementation to actually test it.
 * that's why the TerrainDummy class will be used for all tests
 * but only those methods will be tested which belongs to the
 * TerrainAbstract class. The TerrainAbstract class is basically
 * an empty implementation of the TerrainAbstract class.
 *
 * @author      Andy Liebke<coding@andysmiles4games.com>
 * @file        Src/Test/TerrainAbstractTest.cpp
 * @version     1.0.0 04-Jan-15
 * @copyright   Copyright (c) 2014-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */

#include <Test/TerrainAbstractTest.h>
#include <Test/TerrainDummy.h>
#include <Test/EntityDummy.h>

namespace DemoAppTest
{
    void TerrainAbstractTest::addEntitiesTest(void)
    {
        TerrainDummy terrain;
        
        CPPUNIT_ASSERT(terrain.getNumberOfEntities() == 0);
        
        terrain.addEntity(NULL);
        
        CPPUNIT_ASSERT(terrain.getNumberOfEntities() == 0);
        
        terrain.addEntity(new EntityDummy());
        
        CPPUNIT_ASSERT(terrain.getNumberOfEntities() == 1);
        
        terrain.release();
    }
}