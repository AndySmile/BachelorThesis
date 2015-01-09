/**
 * @version     2.4.0 09-Jan-15
 * @copyright   Copyright (c) 2014-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#ifndef __TERRAIN_MESH_H__
#define __TERRAIN_MESH_H__

#include <TerrainAbstract.h>

class TerrainMesh : public TerrainAbstract
{
    public:
        TerrainMesh(void);
        TerrainMesh(const unsigned short width, const unsigned short height, const unsigned short depth, const float unitLength=2.0f);
        TerrainMesh(const TerrainMesh& src);
        virtual ~TerrainMesh(void);
    
        TerrainMesh& operator = (const TerrainMesh& src);
    
        void setGridNode(const unsigned short x, const float y, const unsigned short z);
        void setSize(const unsigned short width, const unsigned short height, const unsigned short depth);
        void render(void);
        void release(void);
    
    private:
        void _resetGrid(void);
    
    private:
        float** _grid;
        unsigned int _meshId;
};

#endif