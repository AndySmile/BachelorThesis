/**
 * DemoApp - Abstract Terrain Model Header.
 *
 * @author      Andy Liebke\<coding@andysmiles4games.com\>
 * @file        Src/TerrainAbstract.h
 * @version     1.3.0 04-Jan-15
 * @copyright   Copyright (c) 2014-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 * @ingroup     demoapp
 */
#ifndef __TERRAIN_ABSTRACT_H__
#define __TERRAIN_ABSTRACT_H__

#include <EntityAbstract.h>
#include <vector>

class TerrainAbstract
{
    public:
        TerrainAbstract(const unsigned short width, const unsigned short height, const unsigned short depth);
        virtual ~TerrainAbstract(void);
    
        void addEntity(EntityAbstract* entity);
        unsigned int getNumberOfEntities(void);
        void render(void);
        void release(void);
    
    public:
        virtual void setGridNode(const unsigned short x, const float y, const unsigned short z) = 0;
    
    public:
        inline unsigned short getWidth(void) const;
        inline unsigned short getHeight(void) const;
        inline unsigned short getDepth(void) const;
        inline void setSize(unsigned short width, unsigned short height, unsigned short depth);
    
    protected:
        void _renderEntities(void);
    
    protected:
        typedef std::vector<EntityAbstract*> ListEntities;
        typedef ListEntities::iterator ListEntitiesIterator;
    
    protected:
        unsigned short _width;
        unsigned short _height;
        unsigned short _depth;
        ListEntities _listEntities;
};

#include <Detail/TerrainAbstractDetail.h>

#endif