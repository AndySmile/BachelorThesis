/**
 * @version		1.0.0 14-Dec-14
 * @copyright	Copyright (c) 2014 by Andy Liebke. All rights reserved.
 */
#ifndef __HEIGHT_MAP_PROCESSOR_H__
#define __HEIGHT_MAP_PROCESSOR_H__

#include <ImageProcessor.h>

class HeightMapProcessor : public ImageProcessor
{
	public:
    	HeightMapProcessor(void);
    	virtual ~HeightMapProcessor(void);
    
		void process(const cv::Mat& image, Terrain* terrain);
    	void release(void);
};

#endif