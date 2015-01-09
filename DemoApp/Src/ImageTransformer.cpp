/**
 * @version     1.4.0 09-Jan-15
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

TerrainAbstract* ImageTransformer::generateTerrain(TerrainType type)
{
    TerrainAbstract* terrain    = NULL;
    
    if (!this->_imageFilePath.empty())
    {
        cv::Mat image = cv::imread(this->_imageFilePath);
        
        if (image.data == 0)
        {
#ifdef _DEBUG
            SimpleLib::Logger::writeDebug("image '%s' wasn't loaded!", this->_imageFilePath.c_str());
#endif
        }
        else
        {
            cv::Size dimension = image.size();
            
            if (type == MeshTerrain) {
                terrain = new TerrainMesh(dimension.width, 40, dimension.height);
            }
            else if (type == VoxelTerrain) {
                terrain = new TerrainVoxel(dimension.width, 10, dimension.height);
            }
            
            /*if (terrain != NULL)
            {
                for (ImageProcessorsIterator it = this->_listProcessors.begin(); it != this->_listProcessors.end(); ++it) {
                    (*it)->process(image, terrain);
                }
            }*/
        }
    }
    
    return terrain;
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
            // initial size of the height map. It's possible that'll change by one of those image processors
            //map.create(image.cols, image.rows, CV_8UC3);

            /*map = new float[image.cols * image.rows];

            for (unsigned int y=0; y < image.rows; ++y)
            {
                for (unsigned int x=0; x < image.cols; ++x) {
                    map[(image.rows * y) + x] = 0.0f;
                }
            }*/

            map = new HeightMap(image.cols, image.rows);

            for (ImageProcessorsIterator it = this->_listProcessors.begin(); it != this->_listProcessors.end(); ++it) {
                (*it)->process(map, image);
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