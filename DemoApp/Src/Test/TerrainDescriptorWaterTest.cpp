/**
 * @version     1.1.0 04-Jan-15
 * @copyright   Copyright (c) 2014-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */

#include <Test/TerrainDescriptorWaterTest.h>
#include <TerrainDescriptorWater.h>
#include <TerrainMesh.h>

#include <OpenCV/cxcore.h>
#include <OpenCV/highgui.h>

namespace DemoAppTest
{
    void TerrainDescriptorWaterTest::processTest(void)
    {
        TerrainMesh terrain(100, 10, 200);
        TerrainDescriptorWater waterDescriptor;
        cv::Mat testImage(10, 10, CV_8UC3, cv::Scalar(255, 255, 255));
        
        // fill half of the image with blue color
        cv::rectangle(testImage, cv::Point(0, 5), cv::Point(10, 10), cv::Scalar(255, 0, 0), CV_FILLED);
        
        // test water detection method with an image half filled with blue color
        // that test might lead to be 100 percent full of water => waterHeight == terrainHeight
        float waterHeight = waterDescriptor._determineWaterHeight(&terrain, testImage);
        
        // actually you shouldn't compare two floating point numbers with each other,
        // but in this case we know what actually has to be the result so we do it here,
        // nevertheless, it isn't a garantee that it'll works all the time on all platforms or
        // with all compiles. So, it's definitely necessary to replace it with a proper floating
        // point comparism function!
        CPPUNIT_ASSERT(waterHeight == 10.0f);
    }
}