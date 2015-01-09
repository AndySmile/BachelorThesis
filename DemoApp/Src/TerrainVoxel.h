/**
 * DemoApp - Voxel Terrain Model Header.
 *
 * @author      Andy Liebke<coding@andysmiles4games.com>
 * @file        Src/TerrainVoxel.h
 * @version     2.3.0 09-Jan-15
 * @copyright   Copyright (c) 2014-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 * @ingroup     demoapp
 */
#ifndef __TERRAIN_VOXEL_H__
#define __TERRAIN_VOXEL_H__

#include <TerrainAbstract.h>

class TerrainVoxel : public TerrainAbstract
{
    public:
        TerrainVoxel(void);
        TerrainVoxel(const unsigned short width, const unsigned short height, const unsigned short depth, const float unitLength=1.0f);
        TerrainVoxel(const TerrainVoxel& src);
        virtual ~TerrainVoxel(void);
    
        TerrainVoxel& operator = (const TerrainVoxel& src);
    
        void setSize(const unsigned short width, const unsigned short height, const unsigned short depth);
        void setVoxelState(const char state, const unsigned short x, const unsigned short y, const unsigned short z);
        void setGridNode(const unsigned short x, const float y, const unsigned short z);
        void render(void);
        void release(void);
    
    private:
        void _renderVoxel(void) const;
        void _resetChunk(void);
    
    private:
        unsigned char*** _chunk;
};

#endif