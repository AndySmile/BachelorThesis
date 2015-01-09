/**
 * DempApp - Abstract Grid Terrain Model.
 *
 * @author      Andy Liebke\<coding@andysmiles4games.com\>
 * @file        Src/AbstractTerrain.cpp
 * @version     1.2.0 09-Jan-15
 * @copyright   Copyright (c) 2014-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 * @ingroup     demoapp
 */
#include <TerrainAbstract.h>

TerrainAbstract::TerrainAbstract(const unsigned short width, const unsigned short height, const unsigned short depth, const float unitLength) :
    _width(width),
    _height(height),
    _depth(depth),
    _unitLength(unitLength),
    _listEntities()
{
    
}

TerrainAbstract::~TerrainAbstract(void)
{
    this->_width        = 0;
    this->_height       = 0;
    this->_depth        = 0;
    this->_unitLength   = 0.0f;
}

void TerrainAbstract::addEntity(EntityAbstract* entity)
{
    if (entity != NULL) {
        this->_listEntities.push_back(entity);
    }
}

unsigned int TerrainAbstract::getNumberOfEntities(void)
{
    return this->_listEntities.size();
}

void TerrainAbstract::render(void)
{
    this->_renderEntities();
}

void TerrainAbstract::release(void)
{
    if (!this->_listEntities.empty())
    {
        while (!this->_listEntities.empty())
        {
            EntityAbstract *currEntity = this->_listEntities.back();
            
            if (currEntity != NULL)
            {
                currEntity->release();
            
                delete currEntity;
                currEntity = NULL;
            }
            
            this->_listEntities.pop_back();
        }
    }
}

void TerrainAbstract::_renderEntities(void)
{
    for (ListEntitiesIterator it=this->_listEntities.begin(); it != this->_listEntities.end(); ++it) {
        (*it)->render();
    }
}