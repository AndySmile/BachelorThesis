/**
 * @author      Andy Liebke<coding@andysmiles4games.com>
 * @version     1.0.0 12-Jan-15
 * @copyright   Copyright (c) 2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#include <ImageProcessorBlurring.h>
#include <OpenCV/cv.h>

ImageProcessorBlurring::ImageProcessorBlurring(void)
{
}

ImageProcessorBlurring::~ImageProcessorBlurring(void)
{

}

void ImageProcessorBlurring::process(HeightMap* map, cv::Mat* inputImage)
{
    cv::blur(*inputImage, *inputImage, cv::Size(5, 5));
}

void ImageProcessorBlurring::release(void)
{
    
}