/**
 * DemoApp - Terrain Builder Test Suite.
 *
 * @author      Andy Liebke<coding@andysmiles4games.com>
 * @file        Src/Test/TerrainBuilderTest.cpp
 * @version     1.3.0 09-Jan-15
 * @copyright   Copyright (c) 2014-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */

#include <Test/TerrainBuilderTest.h>
#include <TerrainBuilder.h>
#include <ImageProcessorHeightMap.h>

namespace DemoAppTest
{
    void TerrainBuilderTest::createTerrainTest(void)
    {
        TerrainBuilder builder(TerrainBuilder::TypeVoxel, "./Resource/HeightMap_6.png");
        
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
        
        // setup image tansformer
        transformer->addProcessor(new ImageProcessorHeightMap(200.0f));

        TerrainAbstract* terrain = builder.build();
        
        CPPUNIT_ASSERT(terrain != NULL);

        // release memory
        if (terrain != NULL)
        {
            delete terrain;
            terrain = NULL;
        }
        
        builder.release();
    }
}