/**
 * @version		2.0.0 23-Dec-14
 * @copyright	Copyright (c) 2014 by Andy Liebke. All rights reserved.
 */
#include <ImageProcessorHeightMap.h>

#ifdef _DEBUG
	#include <iostream>
#endif

ImageProcessorHeightMap::ImageProcessorHeightMap(void)
{
    
}

ImageProcessorHeightMap::~ImageProcessorHeightMap(void)
{
    
}

void ImageProcessorHeightMap::process(const cv::Mat& image, TerrainAbstract* terrain)
{
	unsigned short numberChannels	= image.channels();
    unsigned int numberRows 		= image.rows;
    unsigned int numberCols 		= image.cols;
    
#ifdef _DEBUG
    std::cout << "image channels : " << numberChannels << std::endl;
    std::cout << "image rows: " << numberRows << std::endl;
    std::cout << "image cols: " << numberCols << std::endl;
    std::cout << "terrain width: " << terrain->getWidth() << std::endl;
    std::cout << "terrain height: " << terrain->getHeight() << std::endl;
    std::cout << "terrain depth: " << terrain->getDepth() << std::endl;
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