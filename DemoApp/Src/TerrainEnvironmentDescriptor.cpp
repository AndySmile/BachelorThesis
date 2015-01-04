/**
 * DemoApp - Terrain Environment Descriptor Model.
 *
 * @author      Andy Liebke<coding@andysmiles4games.com>
 * @file        Src/TerrainEnvironmentDescriptor.cpp
 * @version     1.1.0 04-Jan-15
 * @copyright   Copyright (c) 2014-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 * @ingroup     demoapp
 */
#include <TerrainEnvironmentDescriptor.h>

TerrainEnvironmentDescriptor::TerrainEnvironmentDescriptor(TerrainAbstract* terrain) :
    _terrain(terrain),
    _listDescriptors()
{
    
}

TerrainEnvironmentDescriptor::TerrainEnvironmentDescriptor(const TerrainEnvironmentDescriptor& src) :
    _terrain(NULL),
    _listDescriptors()
{
    
}

TerrainEnvironmentDescriptor::~TerrainEnvironmentDescriptor(void)
{
    
}

TerrainEnvironmentDescriptor& TerrainEnvironmentDescriptor::operator = (const TerrainEnvironmentDescriptor& src)
{
    this->_terrain = NULL;
    
    return *this;
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