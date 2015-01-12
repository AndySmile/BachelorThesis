/**
 * DemoApp - Height Map Image Processor Model.
 *
 * @author      Andy Liebke\<coding@andysmiles4games.com\>
 * @file        Src/ImageProcessorHeightMap.cpp
 * @version     2.4.0 12-Jan-15
 * @copyright   Copyright (c) 2014-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 * @ingroup     demoapp
 */
#include <ImageProcessorHeightMap.h>

#ifdef _DEBUG
    #include <SimpleLib/Logger.h>
#endif

ImageProcessorHeightMap::ImageProcessorHeightMap(const float maxHeight) :
    _maxHeight(maxHeight)
{
}

ImageProcessorHeightMap::~ImageProcessorHeightMap(void)
{
    this->_maxHeight = 0;
}

void ImageProcessorHeightMap::process(HeightMap* map, cv::Mat* inputImage)
{
    unsigned short numberChannels   = inputImage->channels();
    unsigned int numberRows         = inputImage->rows;
    unsigned int numberCols         = inputImage->cols;
    
#ifdef _DEBUG
    SimpleLib::Logger::writeDebug("image channels: %d", numberChannels);
    SimpleLib::Logger::writeDebug("image rows: %d", numberRows);
    SimpleLib::Logger::writeDebug("image cols: %d", numberCols);
    SimpleLib::Logger::writeDebug("Max height: %f", this->_maxHeight);
#endif

    for (unsigned int x=0; x < numberCols; ++x)
    {
        for (unsigned int z=0; z < numberRows; ++z)
        {
            cv::Vec3b color = inputImage->at<cv::Vec3b>(z, x);
            float currAvgColor = 0.0f;
            
            for (unsigned short n=0; n < numberChannels; ++n) {
                currAvgColor += color.val[n];
            }
            
            currAvgColor /= numberChannels;
            
            if (currAvgColor >= this->_maxHeight) {
                currAvgColor /= this->_maxHeight;
            }

            map->setHeight(currAvgColor, x, z);
        }
    }
}

void ImageProcessorHeightMap::release(void)
{
    
}