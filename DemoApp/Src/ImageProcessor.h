/**
 * @version		1.0.0 14-Dec-14
 * @copyright	Copyright (c) 2014 by Andy Liebke. All rights reserved.
 */
#ifndef __IMAGE_PROCESSOR_H__
#define __IMAGE_PROCESSOR_H__

#include <OpenCV/cxcore.h>
#include <Terrain.h>
#include <string>

struct ImageProcessor
{
	virtual ~ImageProcessor(void)
    {
    }
    
    virtual void process(const cv::Mat& image, Terrain* terrain) = 0;
    virtual void release(void) = 0;
};

#endif