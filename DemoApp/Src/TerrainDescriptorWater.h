/**
 * @version     1.1.0 04-Jan-15
 * @copyright   Copyright (c) 2014-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#ifndef __TERRAIN_DESCRIPTOR_WATER_H__
#define __TERRAIN_DESCRIPTOR_WATER_H__

#include <TerrainDescriptorInterface.h>

#ifdef _UNITTEST
    #include <Test/TerrainDescriptorWaterTest.h>
#endif

class TerrainDescriptorWater : public TerrainDescriptorInterface
{
#ifdef _UNITTEST
    public:
        friend class DemoAppTest::TerrainDescriptorWaterTest;
#endif

    public:
        TerrainDescriptorWater(void);
        virtual ~TerrainDescriptorWater(void);
    
        void process(TerrainAbstract* terrain, const cv::Mat& image);
    
    private:
        float _determineWaterHeight(TerrainAbstract* terrain, const cv::Mat& image);
};

#endif