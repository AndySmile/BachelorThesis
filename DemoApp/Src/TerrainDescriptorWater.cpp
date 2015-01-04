/**
 * DemoApp - Water Terrain Descriptor Model.
 *
 * @author      Andy Liebke<coding@andysmiles4games.com>
 * @file        Src/TerrainDescriptorWater.cpp
 * @version     1.1.0 04-Jan-15
 * @copyright   Copyright (c) 2014-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 * @ingroup     demoapp
 */
#include <TerrainDescriptorWater.h>
#include <OpenCV/cv.h>
#include <vector>

#ifdef _DEBUG
    #include <SimpleLib/Logger.h>
#endif

TerrainDescriptorWater::TerrainDescriptorWater(void)
{
    
}

TerrainDescriptorWater::~TerrainDescriptorWater(void)
{
    
}

void TerrainDescriptorWater::process(TerrainAbstract* terrain, const cv::Mat& image)
{
    
}

float TerrainDescriptorWater::_determineWaterHeight(TerrainAbstract* terrain, const cv::Mat& image)
{
    float waterHeight = 0.0f;
    
    if (!image.empty())
    {
        cv::Size dimension          = image.size();
        const int histogramSize     = 256;
        const int numberOfChannels  = 0;
        float channelRange[]        = {0.0f, 256.0f};
        const float* histogramRange = {channelRange};
        
        cv::MatND histogramBlue;
        cv::MatND histogramGreen;
        cv::MatND histogramRed;
        std::vector<cv::Mat> listChannels;
        
        cv::split(image, listChannels);
        
        cv::calcHist(&listChannels[0], 1, &numberOfChannels, cv::Mat(), histogramBlue, 1, &histogramSize, &histogramRange, true, false);
        cv::calcHist(&listChannels[1], 1, &numberOfChannels, cv::Mat(), histogramGreen, 1, &histogramSize, &histogramRange, true, false);
        cv::calcHist(&listChannels[2], 1, &numberOfChannels, cv::Mat(), histogramRed, 1, &histogramSize, &histogramRange, true, false);
        
        unsigned int totalBlueColor     = 0;
        unsigned int totalGreenColor    = 0;
        unsigned int totalRedColor      = 0;
        
        for (int i=1; i < histogramSize; ++i)
        {
            unsigned int currColorBlue = cvRound(histogramBlue.at<float>(i));
            unsigned int currColorGreen = cvRound(histogramGreen.at<float>(i));
            unsigned int currColorRed = cvRound(histogramRed.at<float>(i));
            
            totalBlueColor += currColorBlue;
            totalGreenColor += currColorGreen;
            totalRedColor += currColorRed;
        }
        
        unsigned int totalPixels = dimension.width * dimension.height;

#ifdef _DEBUG
        SimpleLib::Logger::writeDebug("Has more blue color: %s", ((totalBlueColor > totalGreenColor && totalBlueColor > totalRedColor) ? "YES" : "NO"));
        SimpleLib::Logger::writeDebug("Blue color percentage: %f", ((float)totalBlueColor / (float)totalPixels));
#endif
        if (totalBlueColor > totalGreenColor && totalBlueColor > totalRedColor) {
            waterHeight = terrain->getHeight() * ((float)totalBlueColor / (float)totalPixels);
        }
    }
    
#ifdef _DEBUG
    SimpleLib::Logger::writeDebug("_determineWaterHeight: water height: %f", waterHeight);
#endif
    
    return waterHeight;
}