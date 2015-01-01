/**
 * @version     2.0.0 23-Dec-14
 * @copyright   Copyright (c) 2014-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#ifndef __IMAGE_PROCESSOR_WATER_H__
#define __IMAGE_PROCESSOR_WATER_H__

#include <ImageProcessorInterface.h>

class ImageProcessorWater : public ImageProcessorInterface
{
    public:
        ImageProcessorWater(void);
        virtual ~ImageProcessorWater(void);
    
        void process(const cv::Mat& image, TerrainAbstract* terrain);
        void release(void);
};

#endif