/**
 * @version		1.0.1 18-Dec-14
 * @copyright	Copyright (c) 2014 by Andy Liebke. All rights reserved.
 */
#include <HeightMapProcessor.h>

#ifdef _DEBUG
	#include <iostream>
#endif

HeightMapProcessor::HeightMapProcessor(void)
{
    
}

HeightMapProcessor::~HeightMapProcessor(void)
{
    
}

void HeightMapProcessor::process(const cv::Mat& image, Terrain* terrain)
{
	unsigned short numberChannels	= image.channels();
    unsigned int numberRows 		= image.rows;
    unsigned int numberCols 		= image.cols;// * numberChannels;
    
    std::cout << "image channels : " << numberChannels << std::endl;
    std::cout << "image rows: " << numberRows << std::endl;
    std::cout << "image cols: " << numberCols << std::endl;
    std::cout << "terrain width: " << terrain->getWidth() << std::endl;
    std::cout << "terrain height: " << terrain->getHeight() << std::endl;
    std::cout << "terrain depth: " << terrain->getDepth() << std::endl;
    
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
            
            for (unsigned short y = 0; y < currAvgColor; ++y) {
				terrain->setVoxelState(1, x, y, z);
			}
        }
    }
    
    /*if (image.isContinuous())
    {
        numberCols *= numberRows;
        numberRows = 1;
    }
    
    for (unsigned int z = 0; z < numberRows; ++z)
    {
        const uchar* currRowData = image.ptr<uchar>(z);
        
        for (unsigned int x = 0; x < numberCols; x += numberChannels)
		{
			uchar currAvgColor = 0;
            
            for (unsigned short n=0; n < numberChannels; ++n) {
                currAvgColor += currRowData[x + n];
            }
            
            currAvgColor /= numberChannels;
            
            if (currAvgColor >= terrain->getHeight()) {
                currAvgColor = terrain->getHeight() - 1;
            }
            
			for (unsigned short y = 0; y < currAvgColor; ++y) {
				terrain->setVoxelState(1, x / numberChannels, y, z);
			}
		}
	}*/
}

void HeightMapProcessor::release(void)
{
    
}