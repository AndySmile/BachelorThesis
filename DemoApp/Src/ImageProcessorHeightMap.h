/**
 * @version     2.2.0 09-Jan-15
 * @copyright   Copyright (c) 2014-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#ifndef ___IMAGE_PROCESSOR_HEIGHT_MAP_H__
#define ___IMAGE_PROCESSOR_HEIGHT_MAP_H__

#include <ImageProcessorInterface.h>

class ImageProcessorHeightMap : public ImageProcessorInterface
{
    public:
        ImageProcessorHeightMap(const float maxHeight);
        virtual ~ImageProcessorHeightMap(void);
    
        void process(HeightMap* map, const cv::Mat& inputImage);
        void release(void);

    private:
        float _maxHeight;
};

#endif