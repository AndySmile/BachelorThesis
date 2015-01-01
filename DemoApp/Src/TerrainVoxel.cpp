/**
 * @version     2.0.1 27-Dec-14
 * @copyright   Copyright (c) 2014-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#include <TerrainVoxel.h>
#include <SFML/OpenGL.hpp>
#include <stdlib.h>

#ifdef _DEBUG
    #include <assert.h>
#endif

TerrainVoxel::TerrainVoxel(const unsigned short width, const unsigned short height, const unsigned short depth) :
    TerrainAbstract(width, height, depth),
    _chunk(NULL)
{
    this->_chunk = new unsigned char**[this->_width];
    
    for (unsigned short x = 0; x < this->_width; ++x)
    {
        this->_chunk[x] = new unsigned char*[this->_height];
        
        for (unsigned short y = 0; y < this->_height; ++y)
        {
            this->_chunk[x][y] = new unsigned char[this->_depth];
            
            for (unsigned short z = 0; z < this->_depth; ++z) {
                this->_chunk[x][y][z] = 0;
            }
        }
    }
}

TerrainVoxel::TerrainVoxel(const TerrainVoxel& src) :
    TerrainAbstract(src),
    _chunk(NULL)
{
    this->_chunk = new unsigned char**[this->_width];
    
    for (unsigned short x = 0; x < this->_width; ++x)
    {
        this->_chunk[x] = new unsigned char*[this->_height];
        
        for (unsigned short y = 0; y < this->_height; ++y)
        {
            this->_chunk[x][y] = new unsigned char[this->_depth];
            
            for (unsigned short z = 0; z < this->_depth; ++z) {
                this->_chunk[x][y][z] = src._chunk[x][y][z];
            }
        }
    }
}

TerrainVoxel::~TerrainVoxel(void)
{
    
}

TerrainVoxel& TerrainVoxel::operator = (const TerrainVoxel& src)
{
    TerrainAbstract::operator = (src);
    
    this->_chunk = new unsigned char**[this->_width];
    
    for (unsigned short x = 0; x < this->_width; ++x)
    {
        this->_chunk[x] = new unsigned char*[this->_height];
        
        for (unsigned short y = 0; y < this->_height; ++y)
        {
            this->_chunk[x][y] = new unsigned char[this->_depth];
            
            for (unsigned short z = 0; z < this->_depth; ++z) {
                this->_chunk[x][y][z] = src._chunk[x][y][z];
            }
        }
    }
    
    return *this;
}

void TerrainVoxel::render(void)
{
    for (unsigned short x = 0; x < this->_width; ++x)
    {
        for (unsigned short y = 0; y < this->_height; ++y)
        {
            for (unsigned short z = 0; z < this->_depth; ++z)
            {
                if (this->_chunk[x][y][z] == 1)
                {
                    glPushMatrix();
                        glTranslatef(1.0f * x, 1.0f * y, 1.0f * z);
                    
                        this->_renderVoxel();
                    glPopMatrix();
                }
            }
        }
    }
}

void TerrainVoxel::release(void)
{
    if (this->_chunk != NULL)
    {
        for (unsigned short x = 0; x < this->_width; ++x)
        {
            for (unsigned short y = 0; y < this->_height; ++y) {
                delete[] this->_chunk[x][y];
            }
            
            delete[] this->_chunk[x];
        }
        
        delete[] this->_chunk;
    }
}

void TerrainVoxel::setGridNode(const unsigned short x, const unsigned short y, const unsigned short z)
{
    for (unsigned short currHeight = 0; currHeight < y; ++currHeight) {
        this->setVoxelState(1, x, currHeight, z);
    }
}

void TerrainVoxel::setVoxelState(const char state, const unsigned short x, const unsigned short y, const unsigned short z)
{
#ifdef _DEBUG
    assert(x < this->_width);
    assert(y < this->_height);
    assert(z < this->_depth);
#endif
    this->_chunk[x][y][z] = state;
}

void TerrainVoxel::_renderVoxel(void) const
{
    glBegin(GL_TRIANGLE_STRIP);
        glColor3f(0.0, 0.5f, 0.0f);
        
        // front
        glNormal3f(0.0f, 0.0f, 1.0f);
        glVertex3f(-0.5f, 0.0f, 0.0f);
        glVertex3f(-0.5f, 1.0f, 0.0f);
        glVertex3f(0.5f, 0.0f, 0.0f);
        glVertex3f(0.5f, 1.0f, 0.0f);
        
        // right side
        glNormal3f(1.0f, 0.0f, 0.0f);
        glVertex3f(0.5f, 1.0f, -1.0f);
        glVertex3f(0.5f, 0.0f, 0.0f);
        glVertex3f(0.5f, 0.0f, -1.0f);
        glVertex3f(0.5f, 1.0f, -1.0f);
        
        // back
        glNormal3f(0.0f, 0.0f, -1.0f);
        glVertex3f(0.5f, 0.0f, -1.0f);
        glVertex3f(-0.5f, 0.0f, -1.0f);
        glVertex3f(0.5f, 1.0f, -1.0f);
        glVertex3f(-0.5f, 1.0f, -1.0f);
        
        // top
        glNormal3f(0.0f, 1.0f, 0.0f);
        glVertex3f(0.5f, 1.0f, -1.0f);
        glVertex3f(0.5f, 1.0f, 0.0f);
        glVertex3f(-0.5f, 1.0f, -1.0f);
        glVertex3f(-0.5f, 1.0f, 0.0f);
        
        // left side
        glNormal3f(-1.0f, 0.0f, 0.0f);
        glVertex3f(-0.5f, 1.0f, -1.0f);
        glVertex3f(-0.5f, 1.0f, 0.0f);
        glVertex3f(-0.5f, 0.0f, -1.0f);
        glVertex3f(-0.5f, 0.0f, 0.0f);
        
        // bottom
        glNormal3f(0.0f, -1.0f, 0.0f);
        glVertex3f(-0.5f, 0.0f, 0.0f);
        glVertex3f(-0.5f, 0.0f, -1.0f);
        glVertex3f(0.5f, 0.0f, 0.0f);
        glVertex3f(0.5f, 0.0f, -1.0f);
    glEnd();
}