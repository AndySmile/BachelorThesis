/**
 * @version 	1.0.0 14-Dec-14
 * @copyright	Copyright (c) 2014 by Andy Liebke. All rights reserved.
 */
#ifndef __WATER_PROCESSOR_h__
#define __WATER_PROCESSOR_h__

#include <ImageProcessor.h>

class WaterProcessor : public ImageProcessor
{
	public:
    	WaterProcessor(void);
    	virtual ~WaterProcessor(void);
    
    	void process(const cv::Mat& image, Terrain* terrain);
    	void release(void);
};

#endif