/**
 * DemoApp - Terrain Builder Model.
 *
 * @author      Andy Liebke<coding@andysmiles4games.com>
 * @file        Src/TerrainBuilder.cpp
 * @version     1.1.0 04-Jan-15
 * @copyright   Copyright (c) 2014-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 * @ingroup     demoapp
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
    this->_initTerrain();
}

TerrainBuilder::TerrainBuilder(const TerrainBuilder& src) :
    _type(src._type),
    _terrain(NULL),
    _transformer(NULL),
    _descriptor(NULL),
    _decorator(NULL)
{
    this->_initTerrain();
}

TerrainBuilder::~TerrainBuilder(void)
{
    
}

TerrainBuilder& TerrainBuilder::operator = (const TerrainBuilder& src)
{
    this->_type         = src._type;
    this->_transformer  = NULL;
    this->_descriptor   = NULL;
    this->_decorator    = NULL;
    
    this->_initTerrain();
    
    return *this;
}

void TerrainBuilder::_initTerrain(void)
{
    switch (this->_type)
    {
        case TerrainBuilder::TypeMesh: {
            this->_terrain = new TerrainMesh();
        } break;
            
        case TerrainBuilder::TypeVoxel: {
            this->_terrain = new TerrainVoxel();
        } break;
        
        default: {
            this->_terrain = NULL;
        } break;
    }
}

TerrainEnvironmentDescriptor* TerrainBuilder::getTerrainEnvironmentDescriptor(void)
{
    if (this->_descriptor == NULL) {
        this->_descriptor = new TerrainEnvironmentDescriptor(this->_terrain);
    }

    return this->_descriptor;
}