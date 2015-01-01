/**
 * @version     2.0.0 23-Dec-14
 * @copyright   Copyright (c) 2014-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#ifndef __IMAGE_PROCESSOR_INTERFACE_H__
#define __IMAGE_PROCESSOR_INTERFACE_H__

#include <OpenCV/cxcore.h>
#include <TerrainAbstract.h>
#include <string>

struct ImageProcessorInterface
{
    virtual ~ImageProcessorInterface(void)
    {
    }
    
    virtual void process(const cv::Mat& image, TerrainAbstract* terrain) = 0;
    virtual void release(void) = 0;
};

#endif