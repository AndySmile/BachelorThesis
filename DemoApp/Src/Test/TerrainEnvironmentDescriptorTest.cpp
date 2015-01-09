/**
 * @version     1.1.0 09-Jan-15
 * @copyright   Copyright (c) 2014-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */

#include <Test/TerrainEnvironmentDescriptorTest.h>
#include <TerrainEnvironmentDescriptor.h>
#include <TerrainDescriptorWater.h>
#include <TerrainMesh.h>

namespace DemoAppTest
{
    void TerrainEnvironmentDescriptorTest::processTest(void)
    {
        // create dummy terrain
        TerrainMesh terrain;

        // create test image
        cv::Mat testImage(10, 10, CV_8UC3, cv::Scalar(255, 255, 255));

        // fill half of the image with blue color
        cv::rectangle(testImage, cv::Point(0, 5), cv::Point(10, 10), cv::Scalar(255, 0, 0), CV_FILLED);
        
        TerrainEnvironmentDescriptor environment;
        
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
        environment.process(testImage, &terrain);
        
        // test releasing memory
        environment.release();
        
        CPPUNIT_ASSERT(environment.getCountDescriptors() == 0);
    }
}