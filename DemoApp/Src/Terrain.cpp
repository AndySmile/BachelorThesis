/**
 * @version		1.0.1 18-Dec-14
 * @copyright	Copyright (c) 2014 by Andy Liebke. All rights reserved.
 */
#include <Terrain.h>
#include <SFML/OpenGL.hpp>
#include <stdlib.h>
#include <assert.h>

Terrain::Terrain(const unsigned short width, const unsigned short height, const unsigned short depth) :
	_chunk(NULL),
	_width(width),
	_height(height),
	_depth(depth)
{
    this->_chunk = new unsigned char**[width];
	
	for (unsigned short x = 0; x < width; ++x)
	{
		this->_chunk[x] = new unsigned char*[height];
		
		for (unsigned short y = 0; y < height; ++y)
        {
			this->_chunk[x][y] = new unsigned char[depth];
			
			for (unsigned short z = 0; z < depth; ++z) {
				this->_chunk[x][y][z] = 0;
			}
		}
	}
}

Terrain::Terrain(const Terrain& src) :
    _chunk(NULL),
    _width(src._width),
    _height(src._height),
    _depth(src._depth)
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

Terrain::~Terrain(void)
{
    
}

Terrain& Terrain::operator = (const Terrain& src)
{
	this->_width = src._width;
    this->_height = src._height;
    this->_depth = src._depth;
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

void Terrain::render(void) const
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

void Terrain::release(void)
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

void Terrain::setVoxelState(const char state, const unsigned short x, const unsigned short y, const unsigned short z)
{
	assert(x < this->_width);
    assert(y < this->_height);
    assert(z < this->_depth);
    
	this->_chunk[x][y][z] = state;
}

void Terrain::_renderVoxel(void) const
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