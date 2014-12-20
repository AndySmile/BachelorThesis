/**
 * @version		1.0.0 14-Dec-14
 * @copyright	Copyright (c) 2014 by Andy Liebke. All rights reserved.
 */
#ifndef __IMAGE_TRANSFORMER_H__
#define __IMAGE_TRANSFORMER_H__

#include <ImageProcessor.h>
#include <Terrain.h>
#include <vector>
#include <string>

class ImageTransformer
{
    public:
    	ImageTransformer(const std::string imageFilePath);
    	ImageTransformer(void);
    	virtual ~ImageTransformer(void);
    
    	void addProcessor(ImageProcessor* processor);
    	Terrain* generateTerrain(void);
    	void release(void);
    
    public:
    	void setImageFilePath(const std::string imageFilePath)
        {
            this->_imageFilePath = imageFilePath;
        }
    
    private:
    	typedef std::vector<ImageProcessor*>::iterator ImageProcessorsIterator;
    
	private:
		std::vector<ImageProcessor*> _listProcessors;
    	std::string _imageFilePath;
};

#endif