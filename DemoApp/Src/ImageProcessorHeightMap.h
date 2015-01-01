/**
 * @version     2.0.0 23-Dec-14
 * @copyright   Copyright (c) 2014-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#ifndef ___IMAGE_PROCESSOR_HEIGHT_MAP_H__
#define ___IMAGE_PROCESSOR_HEIGHT_MAP_H__

#include <ImageProcessorInterface.h>

class ImageProcessorHeightMap : public ImageProcessorInterface
{
    public:
        ImageProcessorHeightMap(void);
        virtual ~ImageProcessorHeightMap(void);
    
        void process(const cv::Mat& image, TerrainAbstract* terrain);
        void release(void);
};

#endif