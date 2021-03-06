/**
 * @version     1.5.0 12-Jan-15
 * @copyright   Copyright (c) 2014-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#include <ImageTransformer.h>
#include <TerrainVoxel.h>
#include <TerrainMesh.h>
#include <OpenCV/highgui.h>

#ifdef _DEBUG
    #include <SimpleLib/Logger.h>
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

void ImageTransformer::addProcessor(ImageProcessorInterface* processor)
{
    this->_listProcessors.push_back(processor);
}

HeightMap* ImageTransformer::generateHeightMap(void)
{
    HeightMap* map = NULL;
    
    if (!this->_imageFilePath.empty())
    {
        cv::Mat image = cv::imread(this->_imageFilePath);

        if (image.data == 0)
        {
#ifdef _DEBUG
            SimpleLib::Logger::writeDebug("ImageTransformer::generateHeightMap Failure: image '%s' wasn't loaded!", this->_imageFilePath.c_str());
#endif
        }
        else if (!this->_listProcessors.empty())
        {
            map = new HeightMap(image.cols, image.rows);

            for (ImageProcessorsIterator it = this->_listProcessors.begin(); it != this->_listProcessors.end(); ++it) {
                (*it)->process(map, &image);
            }
        }
    }

    return map;
}

void ImageTransformer::release()
{
    if (!this->_listProcessors.empty())
    {
        while (!this->_listProcessors.empty())
        {
            ImageProcessorInterface* currProcessor = this->_listProcessors.back();
            
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