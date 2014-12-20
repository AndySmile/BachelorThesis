/**
 * @version 	1.0.0 13-Dec-14
 * @copyright	Copyright (c) 2014 by Andy Liebke. All rights reserved.
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
unsigned int ImageProcessor::getAmountOfWater(const cv::Mat& image)
{
	unsigned int amountWater = 0;
	
	if (!image.empty())
	{
		/*const int histogramSize = 256;
		const int numberOfChannels = 0;
		float channelRange[] = {0.0f, 256.0f};
		const float* histogramRange = {channelRange};
		
		cv::MatND histogram;
		std::vector<cv::Mat> listChannels;
		
		cv::split(image, listChannels);
		
		cv::calcHist(&listChannels[0], 1, &numberOfChannels, cv::Mat(), histogram, 1, &histogramSize, &histogramRange, true, false);
		
		unsigned int avgBlueColor = 0;
		
		for (int i=0; i < histogramSize; ++i)
		{
			//std::cout << histogram.at<float>(i) << std::endl;
			
			unsigned int currColor = cvRound(histogram.at<float>(i));
			
			// everything below color value 50 is to dark as that we want count
			// it to the average computation
			if (currColor > 50) {
				avgBlueColor += currColor;
			}
		}
		
		avgBlueColor /= histogramSize;
		
		std::cout << "average blue value: " << avgBlueColor << std::endl;*/
		
		unsigned int numberRows = image.rows;
		unsigned int numberCols = image.cols * image.channels();
		
		for (unsigned int y = 0; y < numberRows; ++y)
		{
			const uchar* currRowData = image.ptr<uchar>(y);
			
			for (unsigned int x = 0; x < numberCols; x += 3)
			{
				if (currRowData[x] > currRowData[x + 1] && currRowData[x] > currRowData[x + 2]) {
					std::cout << (int)currRowData[x] << std::endl;
				}
			}
		}
	}
	
	return amountWater;
}