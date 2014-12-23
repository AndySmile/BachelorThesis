/**
 * @version		2.0.0 23-Dec-14
 * @copyright	Copyright (c) 2014 by Andy Liebke. All rights reserved.
 */
#ifndef __TERRAIN_VOXEL_H__
#define __TERRAIN_VOXEL_H__

#include <TerrainAbstract.h>

class TerrainVoxel : public TerrainAbstract
{
	public:
    	TerrainVoxel(const unsigned short width, const unsigned short height, const unsigned short depth);
    	TerrainVoxel(const TerrainVoxel& src);
        virtual ~TerrainVoxel(void);
    
    	TerrainVoxel& operator = (const TerrainVoxel& src);
    
    	void setVoxelState(const char state, const unsigned short x, const unsigned short y, const unsigned short z);
    	void setGridNode(const unsigned short x, const unsigned short y, const unsigned short z);
    	void render(void);
    	void release(void);
    
	private:
    	void _renderVoxel(void) const;
    
    private:
    	unsigned char*** _chunk;
};

#endif