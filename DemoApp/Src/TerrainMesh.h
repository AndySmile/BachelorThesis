/**
 * @version		2.0.0 23-Dec-14
 * @copyright	Copyright (c) 2014 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#ifndef __TERRAIN_MESH_H__
#define __TERRAIN_MESH_H__

#include <TerrainAbstract.h>

class TerrainMesh : public TerrainAbstract
{
    public:
    	TerrainMesh(const unsigned short width, const unsigned short height, const unsigned short depth);
    	virtual ~TerrainMesh(void);
    
    	void setGridNode(const unsigned short x, const unsigned short y, const unsigned short z);
    	void render(void);
    	void release(void);
    
    private:
    	float** _grid;
    	unsigned int _meshId;
};

#endif