/**
 * DemoApp - Terrain Mesh Model.
 *
 * @author		Andy Liebke\<coding@andysmiles4games.com\>
 * @file		Src/TerrainMesh.cpp
 * @version		2.1.0 24-Dec-14
 * @copyright	Copyright (c) 2014 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 * @ingroup		demoapp
 */
#include <TerrainMesh.h>
#include <SimpleLib/OpenGLHelper.h>
#include <SFML/OpenGL.hpp>

#ifdef _DEBUG
	#include <iostream>
    #include <assert.h>
#endif

TerrainMesh::TerrainMesh(const unsigned short width, const unsigned short height, const unsigned short depth) :
	TerrainAbstract(width, height, depth),
	_grid(NULL),
	_meshId(0)
{
#ifdef _DEBUG
	std::cout << "Mesh Terrain Width: " << (int)this->_width << std::endl;
    std::cout << "Mesh Terrain Height: " << (int)this->_height << std::endl;
    std::cout << "Mesh Terrain Depth: " << (int)this->_depth << std::endl;
#endif

    this->_grid = new float*[this->_width];
	
	for (unsigned short x = 0; x < this->_width; ++x)
	{
		this->_grid[x] = new float[this->_depth];
		
		for (unsigned short z = 0; z < this->_depth; ++z) {
			this->_grid[x][z] = 0.0f;
		}
	}
}

TerrainMesh::TerrainMesh(const TerrainMesh& src) :
	TerrainAbstract(src),
	_grid(NULL),
	_meshId(0)
{
#ifdef _DEBUG
	std::cout << "[DEBUG] call TerrainMesh copy constructor!" << std::endl;
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
	this->_grid 	= NULL;
    this->_meshId	= 0;
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

void TerrainMesh::setGridNode(const unsigned short x, const unsigned short y, const unsigned short z)
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
        std::cout << "Mesh ID: " << (int)this->_meshId << std::endl;
        std::cout << "offsetX: " << (float)offsetX << std::endl;
        std::cout << "offsetZ: " << (float)offsetZ << std::endl;
#endif
        SimpleLib::OpenGLHelper::printError();
        
        glNewList(this->_meshId, GL_COMPILE);
        
            SimpleLib::OpenGLHelper::printError();
            
            for (unsigned short z=0; z < this->_depth - 1; ++z)
            {
                glBegin(GL_TRIANGLE_STRIP);
                
                for (unsigned short x=0; x < this->_width; ++x)
                {
                    float currHeight = this->_grid[x][z];
                    float nextHeight = (z + 1 < this->_height) ? this->_grid[x][z + 1] : currHeight;
                    
                    glVertex3f(offsetX + (x * 2.0f), nextHeight, offsetZ + ((z + 1) * 2.0f));
                    glVertex3f(offsetX + (x * 2.0f), currHeight, offsetZ + (z * 2.0f));
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
	if (this->_grid != NULL)
    {
        for (unsigned int x=0; x < this->_width; ++x) {
            delete this->_grid[x];
        }
        
        delete this->_grid;
        this->_grid = NULL;
    }
}