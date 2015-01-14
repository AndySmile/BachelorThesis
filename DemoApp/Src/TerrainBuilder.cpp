/**
 * DemoApp - Terrain Builder Model.
 *
 * @author      Andy Liebke<coding@andysmiles4games.com>
 * @file        Src/TerrainBuilder.cpp
 * @version     1.3.1 14-Jan-15
 * @copyright   Copyright (c) 2014-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 * @ingroup     demoapp
 */
#include <TerrainBuilder.h>
#include <TerrainMesh.h>
#include <TerrainVoxel.h>

#ifdef _DEBUG
    #include <SimpleLib/Logger.h>
#endif

TerrainBuilder::TerrainBuilder(const TerrainBuilder::TerrainType type, const std::string pathInputImage) :
    _type(type),
    _transformer(NULL),
    _environment(NULL),
    _decorator(NULL),
    _pathInputImage(pathInputImage)
{
    this->_transformer = new ImageTransformer(this->_pathInputImage);
    this->_environment = new TerrainEnvironment(this->_pathInputImage);
}

TerrainBuilder::TerrainBuilder(const TerrainBuilder& src) :
    _type(src._type),
    _transformer(NULL),
    _environment(NULL),
    _decorator(NULL),
    _pathInputImage(src._pathInputImage)
{
}

TerrainBuilder::~TerrainBuilder(void)
{
    
}

TerrainBuilder& TerrainBuilder::operator = (const TerrainBuilder& src)
{
    this->_type             = src._type;
    this->_pathInputImage   = src._pathInputImage;
    this->_transformer      = NULL;
    this->_environment      = NULL;
    this->_decorator        = NULL;
    
    return *this;
}

void TerrainBuilder::release(void)
{
    if (this->_transformer != NULL)
    {
        this->_transformer->release();
        
        delete this->_transformer;
        this->_transformer = NULL;
    }
    
    if (this->_environment != NULL)
    {
        this->_environment->release();
        
        delete this->_environment;
        this->_environment = NULL;
    }
    
    if (this->_decorator != NULL)
    {
        delete this->_decorator;
        this->_decorator = NULL;
    }
}

TerrainAbstract* TerrainBuilder::build(void)
{
    TerrainAbstract* terrain = NULL;
    HeightMap* map = this->_transformer->generateHeightMap();

    if (map != NULL)
    {
        if (this->_type == TerrainBuilder::TypeMesh) {
            terrain = new TerrainMesh(map->getWidth(), 0, map->getHeight());
        }
        else if (this->_type == TerrainBuilder::TypeVoxel) {
            terrain = new TerrainVoxel(map->getWidth(), 0, map->getHeight());
        }

        if (terrain != NULL)
        {
            this->_applyHeightMapToTerrain(map, terrain);
            this->_environment->process(terrain);
        }
        
        delete map;
        map = NULL;
    }

    return terrain;
}

void TerrainBuilder::_applyHeightMapToTerrain(const HeightMap* map, TerrainAbstract* terrain)
{
#ifdef _DEBUG
    SimpleLib::Logger::writeDebug("TerrainBuilder: apply height map to terrain");
#endif

    unsigned int width  = map->getWidth();
    unsigned int height = map->getHeight();

#ifdef _DEBUG
    SimpleLib::Logger::writeDebug("TerrainBuilder: apply heigh map with size [%d, %d]", width, height);
#endif

    for (unsigned int x=0; x < width; ++x)
    {
        for (unsigned int z=0; z < height; ++z) {
            terrain->setGridNode(x, map->getHeight(x, z), z);
        }
    }
}