/**
 * DemoApp - Terrain Builder Model.
 *
 * @author      Andy Liebke<coding@andysmiles4games.com>
 * @file        Src/TerrainBuilder.cpp
 * @version     1.2.0 08-Jan-15
 * @copyright   Copyright (c) 2014-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 * @ingroup     demoapp
 */
#include <TerrainBuilder.h>
#include <TerrainMesh.h>
#include <TerrainVoxel.h>

TerrainBuilder::TerrainBuilder(const TerrainBuilder::TerrainType type, const std::string pathInputImage) :
    _type(type),
    //_terrain(NULL),
    _transformer(NULL),
    _descriptor(NULL),
    _decorator(NULL),
    _pathInputImage(pathInputImage)
{
    //this->_initTerrain();
}

TerrainBuilder::TerrainBuilder(const TerrainBuilder& src) :
    _type(src._type),
    //_terrain(NULL),
    _transformer(NULL),
    _descriptor(NULL),
    _decorator(NULL),
    _pathInputImage(src._pathInputImage)
{
    //this->_initTerrain();
}

TerrainBuilder::~TerrainBuilder(void)
{
    
}

TerrainBuilder& TerrainBuilder::operator = (const TerrainBuilder& src)
{
    this->_type             = src._type;
    this->_pathInputImage   = src._pathInputImage;
    this->_transformer      = NULL;
    this->_descriptor       = NULL;
    this->_decorator        = NULL;
    
    //this->_initTerrain();
    
    return *this;
}

void TerrainBuilder::release(void)
{
    if (this->_transformer != NULL)
    {
        delete this->_transformer;
        this->_transformer = NULL;
    }
    
    if (this->_descriptor != NULL)
    {
        delete this->_descriptor;
        this->_descriptor = NULL;
    }
    
    if (this->_decorator != NULL)
    {
        delete this->_decorator;
        this->_decorator = NULL;
    }
}

/*void TerrainBuilder::_initTerrain(void)
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
}*/

TerrainEnvironmentDescriptor* TerrainBuilder::getTerrainEnvironmentDescriptor(void)
{
    if (this->_descriptor == NULL) {
        this->_descriptor = new TerrainEnvironmentDescriptor();
    }
    
    return this->_descriptor;
}

ImageTransformer* TerrainBuilder::getImageTransformer(void)
{
    if (this->_transformer == NULL) {
        this->_transformer = new ImageTransformer(this->_pathInputImage);
    }

    return this->_transformer;
}

TerrainDecorator* TerrainBuilder::getTerrainDecorator(void)
{
    return NULL;
}

TerrainAbstract* TerrainBuilder::build(void)
{
    /*TerrainAbstract* terrain = NULL;

    if (this->_type == TerrainBuilder::TypeMesh) {
        terrain = new TerrainMesh();
    }

    if (this->_type == TerrainBuilder::TypeVoxel) {
        terrain = new TerrainVoxel();
    }

    if (terrain != NULL)
    {
        HeightMap* map = this->_transformer->generateHeightMap();

        if (map != NULL)
        {
            this->_applyHeightMapToTerrain(map, terrain);

            delete map;
            map = NULL;
        }
    }*/

    TerrainAbstract* terrain = NULL;
    HeightMap* map = this->_transformer->generateHeightMap();

    if (map != NULL)
    {
        if (this->_type == TerrainBuilder::TypeMesh) {
            terrain = new TerrainMesh(map->getWidth(), 20, map->getHeight());
        }
        else if (this->_type == TerrainBuilder::TypeVoxel) {
            terrain = new TerrainVoxel(map->getWidth(), 20, map->getHeight());
        }

        if (terrain != NULL) {
            this->_applyHeightMapToTerrain(map, terrain);
        }
        
        delete map;
        map = NULL;
    }

    return terrain;
}

void TerrainBuilder::_applyHeightMapToTerrain(const HeightMap* map, TerrainAbstract* terrain)
{
    unsigned int width  = map->getWidth();
    unsigned int height = map->getHeight();
    
    for (unsigned int x=0; x < width; ++x)
    {
        for (unsigned int z=0; z < height; ++z) {
            terrain->setGridNode(x, map->getHeight(), z);
        }
    }
}