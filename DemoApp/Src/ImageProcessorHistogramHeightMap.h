/**
 * @version     1.2.0 12-Jan-15
 * @copyright   Copyright (c) 2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#ifndef __IMAGE_PROCESSOR_HISTOGRAM_HEIGHT_MAP_H__
#define __IMAGE_PROCESSOR_HISTOGRAM_HEIGHT_MAP_H__

#include <ImageProcessorInterface.h>

class ImageProcessorHistogramHeightMap : public ImageProcessorInterface
{
    public:
        ImageProcessorHistogramHeightMap(void);
        virtual ~ImageProcessorHistogramHeightMap(void);
    
        void process(HeightMap* map, cv::Mat* image);
        void release(void);
};

#endif