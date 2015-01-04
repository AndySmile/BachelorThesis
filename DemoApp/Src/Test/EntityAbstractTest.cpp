/**
 * DemoApp - Abstract Entity Model Test Suite.
 *
 * Actually this is a test suite for EntityAbstract class.
 * like the name let it already assume that the class is abstract
 * so we need a particular implementation to actually test it.
 * that's why the EntityDummy class will be used for all tests
 * but only those methods will be tested which belongs to the
 * EntityAbstract class. The EntityDummy class is basically 
 * an empty implementation of the EntityAbstract class.
 *
 * @author      Andy Liebke<coding@andysmiles4games.com>
 * @file        Src/Test/EntityAbstractTest.cpp
 * @version     1.0.0 04-Jan-15
 * @copyright   Copyright (c) 2014-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */

#include <Test/EntityAbstractTest.h>
#include <Test/EntityDummy.h>

namespace DemoAppTest
{
    void EntityAbstractTest::assignDataTest(void)
    {
        EntityDummy entity;
        
        entity.setPosition(glm::vec3(0.0f, 10.0f, 0.0f));
        
        CPPUNIT_ASSERT(entity.getPosition() == glm::vec3(0.0f, 10.0f, 0.0f));
    }
}