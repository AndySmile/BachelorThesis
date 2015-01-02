/**
 * @version     1.1.0 02-Jan-15
 * @copyright   Copyright (c) 2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */

#include <ImageProcessorHistogramHeightMap.h>
#include <OpenCV/cv.h>
#include <vector>
#include <algorithm>

#ifdef _DEBUG
    #include <SimpleLib/Logger.h>

    #include <OpenCV/cxcore.h>
    #include <OpenCV/highgui.h>
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
    
    // create a debug window to display the histogram values
    cv::Size dimension = image.size();
    cv::Mat debugHistogram(400, 256, CV_8UC3, cv::Scalar(0, 0, 0));
    cv::namedWindow("Histogram Debug Output", CV_WINDOW_AUTOSIZE);
#endif
    for (unsigned short i=0; i < numChannels; ++i) {
        cv::calcHist(&listChannels[i], 1, &numberOfChannels, cv::Mat(), listHistograms[i], 1, &histogramSize, &histogramRange, true, false);
    
        //cv::normalize(listHistograms[i], listHistograms[i], 0, 400, cv::NORM_MINMAX, -1, cv::MatND());
    }
    
    float* listHeights = new float[histogramSize];
    
    //cv::line(debugHistogram, cv::Point(50, 0), cv::Point(50, dimension.height * dimension.width), cv::Scalar(255, 0, 0), 2);
    
    for (int x=0; x < histogramSize; ++x)
    {
        for (int i=0; i < numChannels; ++i) {
            cv::line(debugHistogram, cv::Point(x, 0), cv::Point(x, listHistograms[i].at<float>(x)), cv::Scalar((i == 0) ? 255 : 0, (i == 1) ? 255 : 0, (i == 2) ? 255 : 0));
        }
    }
    
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

    imshow("Histogram Debug Output", debugHistogram);

    delete[] listHeights;
    delete[] listHistograms;
}

void ImageProcessorHistogramHeightMap::release(void)
{
    
}