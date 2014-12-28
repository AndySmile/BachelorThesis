/**
 * @version				1.2.0 09-Dec-14
 * @copyright	Copyright (c) 2014 by Andy Liebke. All rights reserved.
 */
#include <VoxelChunk.h>
#include <SFML/OpenGL.hpp>
#include <stdlib.h>

#ifdef _DEBUG
		#include <iostream>
#endif

VoxelChunk::VoxelChunk(const unsigned short width, const unsigned short height, const unsigned short depth) :
		_chunk(NULL),
		_width(width),
		_height(height),
		_depth(depth),
		_voxelMeshId(0)
{
		this->_chunk = new unsigned char**[width];
		
		for (unsigned short x = 0; x < width; ++x)
		{
				this->_chunk[x] = new unsigned char*[height];
				
				for (unsigned short y = 0; y < height; ++y) {
						this->_chunk[x][y] = new unsigned char[depth];
						
						for (unsigned short z = 0; z < depth; ++z) {
								this->_chunk[x][y][z] = 0;
						}
				}
		}
}

VoxelChunk::~VoxelChunk(void)
{
}

void VoxelChunk::release(void)
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
		
		if (this->_voxelMeshId == 1) 
		{
				glDeleteLists(this->_voxelMeshId, 1);
				
				this->_voxelMeshId = 0;
		}
}

void VoxelChunk::render(void)
{
		if (this->_voxelMeshId == 0)
		{
				std::cout << "create mesh" << std::endl;
		
				this->_voxelMeshId = 1;
				
				glNewList(this->_voxelMeshId, GL_COMPILE);
						for (unsigned short x = 0; x < this->_width; ++x)
						{
								for (unsigned short y = 0; y < this->_height; ++y) {
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
				glEndList();
		}
		
		glCallList(this->_voxelMeshId);
}

void VoxelChunk::setVoxelState(const char state, const unsigned short x, const unsigned short y, const unsigned short z)
{
		this->_chunk[x][y][z] = state;
}

void VoxelChunk::_renderVoxel(void)
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