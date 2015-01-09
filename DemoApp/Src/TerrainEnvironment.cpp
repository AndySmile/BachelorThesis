/**
 * DemoApp - Terrain Environment Descriptor Model.
 *
 * @author      Andy Liebke<coding@andysmiles4games.com>
 * @file        Src/TerrainEnvironmentDescriptor.cpp
 * @version     2.0.0 09-Jan-15
 * @copyright   Copyright (c) 2014-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 * @ingroup     demoapp
 */
#include <TerrainEnvironment.h>
#include <OpenCV/highgui.h>

#ifdef _DEBUG
    #include <SimpleLib/Logger.h>
#endif

TerrainEnvironment::TerrainEnvironment(const std::string pathInputImage) :
    _listDescriptors(),
    _pathInputImage(pathInputImage)
{
    
}

TerrainEnvironment::TerrainEnvironment(const TerrainEnvironment& src) :
    _listDescriptors(),
    _pathInputImage(src._pathInputImage)
{
    
}

TerrainEnvironment::~TerrainEnvironment(void)
{
    
}

TerrainEnvironment& TerrainEnvironment::operator = (const TerrainEnvironment& src)
{
    this->_pathInputImage = src._pathInputImage;

    return *this;
}

unsigned int TerrainEnvironment::getCountDescriptors(void)
{
    return this->_listDescriptors.size();
}

void TerrainEnvironment::addDescriptor(TerrainDescriptorInterface* descriptor)
{
    if (descriptor != NULL) {
        this->_listDescriptors.push_back(descriptor);
    }
}

void TerrainEnvironment::process(TerrainAbstract* terrain)
{
#ifdef _DEBUG
    SimpleLib::Logger::writeDebug("Start to processing environment descriptors!");
#endif

    if (!this->_pathInputImage.empty())
    {
        cv::Mat image = cv::imread(this->_pathInputImage);

        if (image.data == 0)
        {
#ifdef _DEBUG
            SimpleLib::Logger::writeDebug("TerrainEnvironmentDescriptor::process Failure: image '%s' wasn't loaded!", this->_pathInputImage.c_str());
#endif
        }
        else if (!this->_listDescriptors.empty())
        {
#ifdef _DEBUG
            SimpleLib::Logger::writeDebug("Run through each environment descriptor!");
#endif

            for (ListTerrainDescriptorsIterator it = this->_listDescriptors.begin(); it != this->_listDescriptors.end(); ++it) {
                (*it)->process(terrain, image);
            }
        }
    }
}

void TerrainEnvironment::release(void)
{
    if (!this->_listDescriptors.empty())
    {
        while (!this->_listDescriptors.empty())
        {
            TerrainDescriptorInterface* currDescriptor = this->_listDescriptors.back();
            
            if (currDescriptor != NULL)
            {
                delete currDescriptor;
                currDescriptor = NULL;
            }
            
            this->_listDescriptors.pop_back();
        }
    }
}