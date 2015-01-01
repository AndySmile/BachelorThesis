/**
 * @version     1.0.0 01-Jan-15
 * @copyright   Copyright (c) 2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */

#include <ImageProcessorHistogramHeightMap.h>
#include <OpenCV/cv.h>
#include <vector>
#include <algorithm>

#ifdef _DEBUG
    #include <SimpleLib/Logger.h>
#endif

ImageProcessorHistogramHeightMap::ImageProcessorHistogramHeightMap(void)
{
    
}

ImageProcessorHistogramHeightMap::~ImageProcessorHistogramHeightMap(void)
{
    
}

void ImageProcessorHistogramHeightMap::process(const cv::Mat& image, TerrainAbstract* terrain)
{
    const int histogramSize     = 256;
    const int numberOfChannels  = 0;
    float channelRange[]        = {0.0f, 256.0f};
    const float* histogramRange = {channelRange};
    std::vector<cv::Mat> listChannels;
    
    cv::split(image, listChannels);
    
    unsigned short numChannels  = listChannels.size();
    cv::MatND* listHistograms   = new cv::MatND[numChannels];
    
#ifdef _DEBUG
    SimpleLib::Logger::writeDebug("Histogram Height Map Processor: number of channels: %d", listChannels.size());
#endif
    for (unsigned short i=0; i < numChannels; ++i) {
        cv::calcHist(&listChannels[i], 1, &numberOfChannels, cv::Mat(), listHistograms[i], 1, &histogramSize, &histogramRange, true, false);
    }
    
    float* listHeights = new float[histogramSize];
    
    for (int x=0; x < histogramSize; ++x)
    {
        float currHistogramValueA = listHistograms[0].at<float>(x);
        
        for (int z=0; z < histogramSize; ++z)
        {
            float currAvgColor = currHistogramValueA;
            
            for (int i=1; i < numChannels; ++i) {
                currAvgColor += listHistograms[i].at<float>(z);
            }
            
            float currHeight = currAvgColor / numChannels;
            
            // don't cross max height border
            if (currHeight >= terrain->getHeight()) {
                currHeight /= (float)terrain->getHeight();
            }
            
            listHeights[z] = currHeight;
            
            // interpolate with previous height value
            if (z > 0)
            {
                float minValue = std::min(currHeight, listHeights[z - 1]);
                float maxValue = std::max(currHeight, listHeights[z - 1]);
                
                if (minValue > 0.0f && maxValue > 0.0f)
                {
                    float interpolationValue = minValue / maxValue;
                
                    currHeight = (listHeights[z - 1] * (1.0f - interpolationValue)) + (currHeight * interpolationValue);
                }
            }
            
            terrain->setGridNode(x, currHeight, z);
        }
    }

    delete[] listHeights;
    delete[] listHistograms;
}

void ImageProcessorHistogramHeightMap::release(void)
{
    
}