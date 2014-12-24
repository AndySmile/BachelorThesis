/**
 * @version		2.0.0 23-Dec-14
 * @copyright	Copyright (c) 2014 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
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

TerrainMesh::~TerrainMesh(void)
{
	this->_grid 	= NULL;
    this->_meshId	= 0;
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
        
        for (unsigned int z=0; z < this->_depth - 1; ++z)
        {
            glBegin(GL_TRIANGLE_STRIP);
            
            for (unsigned int x=0; x < this->_width; ++x)
            {
                /*sf::Color currColor = heightMap.getPixel(x, z);
                float secondAvgColor = 0.0f;
                float currAvgColor 	= (currColor.r + currColor.g + currColor.b) * 0.3333f;
                currAvgColor 		= (currAvgColor / 256.0f) * 10.0f;
                
                if (z + 1 < dimension.y)
                {
                    sf::Color secondColor = heightMap.getPixel(x, z + 1);
                    secondAvgColor 	= (secondColor.r + secondColor.g + secondColor.b) * 0.3333f;
                    secondAvgColor 		= (secondAvgColor / 256.0f) * 10.0f;
                }
                else {
                    secondAvgColor = currAvgColor;
                }*/
                
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