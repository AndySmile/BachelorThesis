/**
 * @version     2.0.0 09-Jan-15
 * @copyright   Copyright (c) 2014-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */

#include <Test/TerrainEnvironmentTest.h>
#include <TerrainEnvironment.h>
#include <TerrainDescriptorWater.h>
#include <TerrainMesh.h>

namespace DemoAppTest
{
    void TerrainEnvironmentTest::processTest(void)
    {
        // create dummy terrain
        TerrainMesh terrain;
        TerrainEnvironment environment("Resource/HeightMap_10.png");
        
        // test default values
        CPPUNIT_ASSERT(environment.getCountDescriptors() == 0);
        
        // test adding descriptor that it doesn't do anything in case of
        // an invalid parameter
        environment.addDescriptor(NULL);
        
        CPPUNIT_ASSERT(environment.getCountDescriptors() == 0);
        
        // test adding descriptors with a real descriptor object
        environment.addDescriptor(new TerrainDescriptorWater());
        
        CPPUNIT_ASSERT(environment.getCountDescriptors() == 1);
        
        // test processing
        environment.process(&terrain);
        
        // test releasing memory
        environment.release();
        
        CPPUNIT_ASSERT(environment.getCountDescriptors() == 0);
    }
}