/**
 * @version		1.0.1 18-Dec-14
 * @copyright	Copyright (c) 2014 by Andy Liebke. All rights reserved.
 */
#include <ImageTransformer.h>
#include <OpenCV/highgui.h>

#ifdef _DEBUG
	#include <iostream>
#endif

ImageTransformer::ImageTransformer(const std::string imagePath) :
	_listProcessors(0),
	_imageFilePath(imagePath)
{
}

ImageTransformer::ImageTransformer(void) :
	_listProcessors(0),
	_imageFilePath("")
{
    
}

ImageTransformer::~ImageTransformer(void)
{
    
}

void ImageTransformer::addProcessor(ImageProcessor* processor)
{
	this->_listProcessors.push_back(processor);
}

Terrain* ImageTransformer::generateTerrain(void)
{
	Terrain* terrain 	= NULL;
	cv::Mat image 		= cv::imread(this->_imageFilePath);
    
    if (image.data == 0) {
        std::cout << "image wasn't loaded!" << std::endl;
    }
    else
    {
        cv::Size dimension = image.size();
        
        terrain = new Terrain(dimension.width, 10, dimension.height);
        
        for (ImageProcessorsIterator it = this->_listProcessors.begin(); it != this->_listProcessors.end(); ++it) {
            (*it)->process(image, terrain);
        }
    }
    
    return terrain;
}

void ImageTransformer::release()
{
    if (!this->_listProcessors.empty())
    {
        while (!this->_listProcessors.empty())
        {
            ImageProcessor* currProcessor = this->_listProcessors.back();
            
            if (currProcessor != NULL)
            {
            	currProcessor->release();
            	delete currProcessor;
            	currProcessor = NULL;
            }
            
        	this->_listProcessors.pop_back();
        }
    }
}