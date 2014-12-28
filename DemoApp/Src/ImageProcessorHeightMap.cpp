/**
 * @version     2.1.0 28-Dec-14
 * @copyright   Copyright (c) 2014 by Andy Liebke. All rights reserved.
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
    SimpleLib::Logger::writeDebug("image channels: " + numberChannels);
    SimpleLib::Logger::writeDebug("image rows: " + numberRows);
    SimpleLib::Logger::writeDebug("image cols: " + numberCols);
    SimpleLib::Logger::writeDebug("terrain width: " + terrain->getWidth());
    SimpleLib::Logger::writeDebug("terrain height: " + terrain->getHeight());
    SimpleLib::Logger::writeDebug("terrain depth: " + terrain->getDepth());
#endif

    for (unsigned int x=0; x < numberCols; ++x)
    {
        for (unsigned int z=0; z < numberRows; ++z)
        {
            cv::Vec3b color = image.at<cv::Vec3b>(z, x);
            uchar currAvgColor = 0;
            
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