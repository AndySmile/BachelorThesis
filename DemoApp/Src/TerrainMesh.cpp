/**
 * DemoApp - Terrain Mesh Model.
 *
 * @author      Andy Liebke\<coding@andysmiles4games.com\>
 * @file        Src/TerrainMesh.cpp
 * @version     2.5.0 07-Jan-15
 * @copyright   Copyright (c) 2014-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 * @ingroup     demoapp
 */
#include <TerrainMesh.h>
#include <SimpleLib/OpenGLHelper.h>
#include <SFML/OpenGL.hpp>

#ifdef _DEBUG
    #include <SimpleLib/Logger.h>
    #include <cassert>
#endif

TerrainMesh::TerrainMesh(void) :
    TerrainAbstract(0, 0, 0),
    _grid(NULL),
    _meshId(0)
{
    
}

TerrainMesh::TerrainMesh(const unsigned short width, const unsigned short height, const unsigned short depth) :
    TerrainAbstract(width, height, depth),
    _grid(NULL),
    _meshId(0)
{
#ifdef _DEBUG
    SimpleLib::Logger::writeDebug("Mesh Terrain Width: %d", this->_width);
    SimpleLib::Logger::writeDebug("Mesh Terrain Height: %d", this->_height);
    SimpleLib::Logger::writeDebug("Mesh Terrain Depth: %d", this->_depth);
#endif

    this->_resetGrid();
}

TerrainMesh::TerrainMesh(const TerrainMesh& src) :
    TerrainAbstract(src),
    _grid(NULL),
    _meshId(0)
{
#ifdef _DEBUG
    SimpleLib::Logger::writeDebug("Performing TerrainMesh copy constructor!");
#endif

    this->_grid = new float*[this->_width];
    
    for (unsigned short x = 0; x < this->_width; ++x)
    {
        this->_grid[x] = new float[this->_depth];
        
        for (unsigned short z = 0; z < this->_depth; ++z) {
            this->_grid[x][z] = (src._grid != NULL) ? src._grid[x][z] : 0.0f;
        }
    }
}

TerrainMesh::~TerrainMesh(void)
{
    this->_grid     = NULL;
    this->_meshId   = 0;
}

TerrainMesh& TerrainMesh::operator = (const TerrainMesh& src)
{
    TerrainAbstract::operator = (src);
    
    this->_grid = new float*[this->_width];
    
    for (unsigned short x = 0; x < this->_width; ++x)
    {
        this->_grid[x] = new float[this->_depth];
        
        for (unsigned short z = 0; z < this->_depth; ++z) {
            this->_grid[x][z] = (src._grid != NULL) ? src._grid[x][z] : 0.0f;
        }
    }
    
    return *this;
}

void TerrainMesh::setSize(const unsigned short width, const unsigned short height, const unsigned short depth)
{
#ifdef _DEBUG
    SimpleLib::Logger::writeDebug("TerrainMesh: Resize grid from [%d, %d, %d] to [%d, %d, %d]", this->_width, this->_height, this->_depth, width, height, depth);
#endif
    this->_width    = width;
    this->_height   = height;
    this->_depth    = depth;

    this->_resetGrid();
}

void TerrainMesh::_resetGrid(void)
{
#ifdef _DEBUG
    SimpleLib::Logger::writeDebug("Reseting mesh grid!");
#endif

    // if grid already exists release memory
    if (this->_grid != NULL)
    {
        for (unsigned int x=0; x < this->_width; ++x) {
            delete this->_grid[x];
        }
        
        delete this->_grid;
        this->_grid = NULL;
    }
    
    // create a new grid
    this->_grid = new float*[this->_width];
    
    for (unsigned short x = 0; x < this->_width; ++x)
    {
        this->_grid[x] = new float[this->_depth];
        
        for (unsigned short z = 0; z < this->_depth; ++z) {
            this->_grid[x][z] = 0.0f;
        }
    }
}

void TerrainMesh::setGridNode(const unsigned short x, const float y, const unsigned short z)
{
#ifdef _DEBUG
    assert(x < this->_width);
    assert(z < this->_depth);
#endif

    this->_grid[x][z] = y;
}

void TerrainMesh::render(void)
{
    if (this->_meshId == 0)
    {
        // create an offset to center the terrain
        float offsetX = -(this->_width / 2.0f);
        float offsetZ = -(this->_depth / 2.0f);
        this->_meshId = glGenLists(1);
        
#ifdef _DEBUG
        SimpleLib::Logger::writeDebug("Mesh ID: %d", this->_meshId);
        SimpleLib::Logger::writeDebug("offsetX: %f", offsetX);
        SimpleLib::Logger::writeDebug("offsetZ: %f", offsetZ);
#endif
        SimpleLib::OpenGLHelper::printError();
        
        glNewList(this->_meshId, GL_COMPILE);
        
            SimpleLib::OpenGLHelper::printError();
        
            for (unsigned short z=0; z < this->_depth - 1; ++z)
            {
                glBegin(GL_TRIANGLE_STRIP);
                
                    for (unsigned int x=0; x < this->_width; ++x)
                    {
                        float currHeight = this->_grid[x][z];
                        float nextHeight = (z + 1 < this->_depth) ? this->_grid[x][z + 1] : currHeight;
                        
                        glVertex3f((x * 2.0f), nextHeight, offsetZ + ((z + 1) * 2.0f));
                        glVertex3f((x * 2.0f), currHeight, offsetZ + (z * 2.0f));
                    }
                
                glEnd();
            }
        
        glEndList();
        
        SimpleLib::OpenGLHelper::printError();
    }
    
    glCallList(this->_meshId);
}

void TerrainMesh::release(void)
{
    TerrainAbstract::release();
    
    if (this->_grid != NULL)
    {
        for (unsigned int x=0; x < this->_width; ++x) {
            delete this->_grid[x];
        }
        
        delete this->_grid;
        this->_grid = NULL;
    }
}