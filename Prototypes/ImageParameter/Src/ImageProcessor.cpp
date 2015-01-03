/**
 * @version     1.1.0 03-Jan-15
 * @copyright   Copyright (c) 2014-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */

#include <ImageProcessor.h>
#include <vector>
#include <OpenCV/cv.h>

#ifdef _DEBUG
    #include <iostream>
#endif

ImageProcessor::ImageProcessor(void)
{
    
}

ImageProcessor::~ImageProcessor(void)
{
    
}

ImageFormat ImageProcessor::getImageFormat(const cv::Mat& image)
{
    ImageFormat format = ImageFormat_Square;
    cv::Size dimension = image.size();
    
    if (dimension.width > dimension.height) {
        format = ImageFormat_Landscape;
    }
    else if (dimension.width < dimension.height) {
        format = ImageFormat_Portrait;
    }
    
    return format;
}

void ImageProcessor::splitImage(ProcessorFlags flag, const cv::Mat& image, cv::Mat* imagePartTop, cv::Mat* imagePartBottom)
{
    cv::Size dimension = image.size();
    
    if (imagePartTop != NULL)
    {
        imagePartTop->create(dimension.height / 2, dimension.width, image.type());
        
        *imagePartTop = image(cv::Rect(0, 0, dimension.width, dimension.height / 2)).clone();
    }
    
    if (imagePartBottom != NULL)
    {
        imagePartBottom->create(dimension.height / 2, dimension.width, image.type());
    
        *imagePartBottom = image(cv::Rect(0, dimension.height / 2, dimension.width, dimension.height / 2)).clone();
    }
}

/**
 * Determines amount of water within a picture.
 *
 * This method is pretty simple. It isn't capabable to detect real water.
 * It only determines how many of those pixels have a big amount of blue
 * in it. In case there is much blue within that picture, it assumes that
 * it's water but it will deliver the same result in the case there is a 
 * huge blue car on the image.
 *
 * @return integer - amount of water within the given picture in procent
 */
float ImageProcessor::getAmountOfWater(const cv::Mat& image)
{
    unsigned int amountWater = 0;
    
    if (!image.empty())
    {
        cv::Size dimension = image.size();
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
        unsigned int totalOthers        = 0;
        
        unsigned int avgColorBlue = 0;
        unsigned int avgColorGreen = 0;
        unsigned int avgColorRed = 0;
        
        for (int i=1; i < histogramSize; ++i)
        {
            unsigned int currColorBlue = cvRound(histogramBlue.at<float>(i));
            unsigned int currColorGreen = cvRound(histogramGreen.at<float>(i));
            unsigned int currColorRed = cvRound(histogramRed.at<float>(i));
            
            std::cout << (int)i << " Blue: " << (int)currColorBlue << std::endl;
            std::cout << (int)i << " Green: " << (int)currColorGreen << std::endl;
            std::cout << (int)i << " Red: " << (int)currColorRed << std::endl;
            
            totalBlueColor += currColorBlue;
            totalGreenColor += currColorGreen;
            totalRedColor += currColorRed;
            totalOthers += currColorRed + currColorGreen;
            
            if (currColorBlue > 0) {
                avgColorBlue += i;
            }
        
            if (currColorGreen > 0) {
                avgColorGreen += i;
            }
            
            if (currColorRed > 0) {
                avgColorRed += i;
            }
        }
        
        unsigned int totalPixels = dimension.width * dimension.height;
        
        std::cout << "number of pixels: " << (int)totalPixels << std::endl;
        std::cout << "total amount of blue pixels: " << (int)totalBlueColor << std::endl;
        std::cout << "total amount of green pixels: " << (int)totalGreenColor << std::endl;
        std::cout << "total amount of red pixels: " << (int)totalRedColor << std::endl;
        std::cout << "total amount of other pixels: " << (int)totalOthers << std::endl;
        std::cout << "\naverage amount of color blue: " << (float)((float)totalBlueColor / (float)totalPixels) << std::endl;
        std::cout << "average amount of color green: " << (float)((float)totalGreenColor / (float)totalPixels) << std::endl;
        std::cout << "average amount of color red: " << (float)((float)totalRedColor / (float)totalPixels) << std::endl;
        std::cout << "average amount of color other: " << (float)((float)totalOthers / (float)totalPixels) << std::endl;
        
        std::cout << "\nAverage color blue: " << (float)((float)avgColorBlue / 255.0f) << std::endl;
        std::cout << "Average color green: " << (float)((float)avgColorGreen / 255.0f) << std::endl;
        std::cout << "Average color red: " << (float)((float)avgColorRed / 255.0f) << std::endl;
        
        std::cout << "\nhas more blue color: " << ((totalBlueColor > totalGreenColor && totalBlueColor > totalRedColor) ? "YES" : "NO") << std::endl;
        
        amountWater = (totalBlueColor > totalGreenColor && totalBlueColor > totalRedColor) ? ((float)totalBlueColor / (float)totalPixels) : 0.0f;
    }
    
    return amountWater;
}