/**
 * @version		1.1.0 21-Dec-14
 * @copyright	Copyright (c) 2014 by Andy Liebke. All rights reserved.
 */
#ifndef __TERRAIN_H__
#define __TERRAIN_H__

class Terrain
{
	public:
    	Terrain(const unsigned short width, const unsigned short height, const unsigned short depth);
    	Terrain(const Terrain& src);
        virtual ~Terrain(void);
    
    	Terrain& operator = (const Terrain& src);
    
    	void setVoxelState(const char state, const unsigned short x, const unsigned short y, const unsigned short z);
    
    	void render(void) const;
    	void release(void);
    
    public:
    	inline unsigned short getWidth(void) const;
        inline unsigned short getHeight(void) const;
        inline unsigned short getDepth(void) const;
    
	private:
    	void _renderVoxel(void) const;
    
    private:
    	unsigned char*** _chunk;
    	unsigned short _width;
    	unsigned short _height;
    	unsigned short _depth;
};

#include <Detail/TerrainDetail.h>

#endif