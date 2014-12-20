/**
 * @version 	1.0.0 13-Dec-14
 * @copyright	Copyright (c) 2014 by Andy Liebke. All rights reserved.
 */

#ifndef __IMAGE_PROCESSOR_H__
#define __IMAGE_PROCESSOR_H__

#include <OpenCV/cxcore.h>

enum ImageFormat
{
	ImageFormat_Landscape = 0,
	ImageFormat_Portrait = 1,
	ImageFormat_Square = 2
};

enum ProcessorFlags
{
	ProcessorFlags_None = 0,
	ProcessorFlags_Width = 1,
	ProcessorFlags_Height = 2
};

class ImageProcessor
{
	public:
		ImageProcessor(void);
		~ImageProcessor(void);
		
		ImageFormat getImageFormat(const cv::Mat& image);
		void splitImage(ProcessorFlags flag, const cv::Mat& image, cv::Mat* imagePart1, cv::Mat* imagePart2);
		unsigned int getAmountOfWater(const cv::Mat& image);
};

#endif