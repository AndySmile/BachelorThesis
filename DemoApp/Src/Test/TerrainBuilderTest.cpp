/**
 * DemoApp - Terrain Builder Test Suite.
 *
 * @author      Andy Liebke<coding@andysmiles4games.com>
 * @file        Src/Test/TerrainBuilderTest.cpp
 * @version     1.1.0 04-Jan-15
 * @copyright   Copyright (c) 2014-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */

#include <Test/TerrainBuilderTest.h>
#include <TerrainBuilder.h>

namespace DemoAppTest
{
    void TerrainBuilderTest::createTerrainTest(void)
    {
        TerrainBuilder builder(TerrainBuilder::TypeVoxel, new ImageTransformer());
        
        ImageTransformer* transformer = builder.getImageTransformer();
        
        // test assigned values via constructor
        CPPUNIT_ASSERT(builder.getTerrainType() == TerrainBuilder::TypeVoxel);
        CPPUNIT_ASSERT(transformer != NULL);
        
        builder.setTerrainType(TerrainBuilder::TypeMesh);
        
        // test terrain type setter
        CPPUNIT_ASSERT(builder.getTerrainType() == TerrainBuilder::TypeMesh);
        
        TerrainEnvironmentDescriptor* environment   = builder.getTerrainEnvironmentDescriptor();
        TerrainDecorator* decorator                 = builder.getTerrainDecorator();
        
        // test default terrain builder components
        CPPUNIT_ASSERT(environment != NULL);
        CPPUNIT_ASSERT(decorator == NULL);
        
        // release memory
        builder.release();
        // setup image tansformer
        //transformer->addProcessor(new ImageProcessorHistogramHeightMap());
        
        // setup environment descriptor
        //descriptor = new TerrainEnvironmentDescriptor();
        //descriptor->addDescriptor(new TerrainDescriptorWater();

        
        //TerrainAbstract* terrain = builder.build(imageTransformer, terrainEnvironmentDescriptor, terrainDecorator);
    }
}