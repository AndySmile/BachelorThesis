/**
 * @version     1.0.0 03-Jan-15
 * @copyright   Copyright (c) 2014-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#include <TerrainBuilder.h>
#include <TerrainMesh.h>
#include <TerrainVoxel.h>

TerrainBuilder::TerrainBuilder(const TerrainBuilder::TerrainType type, ImageTransformer* transformer) :
    _type(type),
    _terrain(NULL),
    _transformer(transformer),
    _descriptor(NULL),
    _decorator(NULL)
{
    switch (this->_type)
    {
        case TerrainBuilder::TypeMesh: {
            this->_terrain = new TerrainMesh();
        } break;
        
        case TerrainBuilder::TypeVoxel: {
            this->_terrain = new TerrainVoxel();
        } break;
    }
}

TerrainBuilder::~TerrainBuilder(void)
{
    
}

TerrainEnvironmentDescriptor* TerrainBuilder::getTerrainEnvironmentDescriptor(void)
{
    if (this->_descriptor == NULL) {
        this->_descriptor = new TerrainEnvironmentDescriptor(this->_terrain);
    }

    return this->_descriptor;
}