/**
 * DemoApp - Height Map Image Processor Model.
 *
 * @author      Andy Liebke\<coding@andysmiles4games.com\>
 * @file        Src/ImageProcessorHeightMap.cpp
 * @version     2.1.1 02-Jan-15
 * @copyright   Copyright (c) 2014-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 * @ingroup     demoapp
 */
#include <ImageProcessorHeightMap.h>

#ifdef _DEBUG
    #include <SimpleLib/Logger.h>
#endif

ImageProcessorHeightMap::ImageProcessorHeightMap(void)
{
    
}

ImageProcessorHeightMap::~ImageProcessorHeightMap(void)
{
    
}

void ImageProcessorHeightMap::process(const cv::Mat& image, TerrainAbstract* terrain)
{
    unsigned short numberChannels   = image.channels();
    unsigned int numberRows         = image.rows;
    unsigned int numberCols         = image.cols;
    
#ifdef _DEBUG
    SimpleLib::Logger::writeDebug("image channels: %d", numberChannels);
    SimpleLib::Logger::writeDebug("image rows: %d", numberRows);
    SimpleLib::Logger::writeDebug("image cols: %d", numberCols);
    SimpleLib::Logger::writeDebug("terrain width: %d", terrain->getWidth());
    SimpleLib::Logger::writeDebug("terrain height: %d", terrain->getHeight());
    SimpleLib::Logger::writeDebug("terrain depth: %d", terrain->getDepth());
#endif

    for (unsigned int x=0; x < numberCols; ++x)
    {
        for (unsigned int z=0; z < numberRows; ++z)
        {
            cv::Vec3b color = image.at<cv::Vec3b>(z, x);
            float currAvgColor = 0.0f;
            
            for (unsigned short n=0; n < numberChannels; ++n) {
                currAvgColor += color.val[n];
            }
            
            currAvgColor /= numberChannels;
            
            if (currAvgColor >= terrain->getHeight()) {
                currAvgColor /= terrain->getHeight();
            }
            
            terrain->setGridNode(x, currAvgColor, z);
        }
    }
}

void ImageProcessorHeightMap::release(void)
{
    
}