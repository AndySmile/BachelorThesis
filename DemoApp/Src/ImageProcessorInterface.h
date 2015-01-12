/**
 * DemoApp - Image Processor Interface Header.
 *
 * @author      Andy Liebke\<coding@andysmiles4games.com\>
 * @file        Src/ImageProcessorInterface.h
 * @version     2.3.0 12-Jan-15
 * @copyright   Copyright (c) 2014-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#ifndef __IMAGE_PROCESSOR_INTERFACE_H__
#define __IMAGE_PROCESSOR_INTERFACE_H__

#include <OpenCV/cxcore.h>
#include <TerrainAbstract.h>
#include <HeightMap.h>
#include <string>

struct ImageProcessorInterface
{
    virtual ~ImageProcessorInterface(void)
    {
    }
    
    virtual void process(HeightMap* map, cv::Mat* inputImage) = 0;
    virtual void release(void) = 0;
};

#endif