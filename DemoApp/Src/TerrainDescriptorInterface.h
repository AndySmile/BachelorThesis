/**
 * DemoApp - Terrain Descriptor Interface.
 *
 * @author      Andy Liebke<coding@andysmiles4games.com>
 * @file        Src/TerrainDescriptorInterface.h
 * @version     1.0.0 03-Jan-15
 * @copyright   Copyright (c) 2014-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 * @ingroup     demoapp
 */
#ifndef __TERRAIN_DESCRIPTOR_INTERFACE_H__
#define __TERRAIN_DESCRIPTOR_INTERFACE_H__

#include <TerrainAbstract.h>
#include <OpenCV/cxcore.h>

struct TerrainDescriptorInterface
{
    virtual ~TerrainDescriptorInterface(void)
    {
    }
    
    virtual void process(TerrainAbstract* terrain, const cv::Mat& image) = 0;
};

#endif