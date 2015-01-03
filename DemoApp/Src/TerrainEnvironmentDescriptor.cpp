/**
 * @version     1.0.0 03-Jan-15
 * @copyright   Copyright (c) 2014-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#include <TerrainEnvironmentDescriptor.h>

TerrainEnvironmentDescriptor::TerrainEnvironmentDescriptor(TerrainAbstract* terrain) :
    _terrain(terrain),
    _listDescriptors()
{
    
}

TerrainEnvironmentDescriptor::~TerrainEnvironmentDescriptor(void)
{
    
}

unsigned int TerrainEnvironmentDescriptor::getCountDescriptors(void)
{
    return this->_listDescriptors.size();
}

void TerrainEnvironmentDescriptor::addDescriptor(TerrainDescriptorInterface* descriptor)
{
    if (descriptor != NULL) {
        this->_listDescriptors.push_back(descriptor);
    }
}

void TerrainEnvironmentDescriptor::process(void)
{
    
}

void TerrainEnvironmentDescriptor::release(void)
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