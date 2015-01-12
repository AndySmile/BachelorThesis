/**
 * @author      Andy Liebke<coding@andysmiles4games.com>
 * @version     1.0.0 12-Jan-15
 * @copyright   Copyright (c) 2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#ifndef __IMAGE_PROCESSOR_BLURRING_H__
#define __IMAGE_PROCESSOR_BLURRING_H__

#include <ImageProcessorInterface.h>

class ImageProcessorBlurring : public ImageProcessorInterface
{
    public:
        ImageProcessorBlurring(void);
        virtual ~ImageProcessorBlurring(void);

        void process(HeightMap* map, cv::Mat* inputImage);
        void release(void);
};

#endif