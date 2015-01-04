/**
 * DemoApp - Terrain Builder Model Header.
 *
 * @author      Andy Liebke<coding@andysmiles4games.com>
 * @file        Src/TerrainBuilder.h
 * @version     1.1.0 04-Jan-15
 * @copyright   Copyright (c) 2014-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 * @ingroup     demoapp
 */
#ifndef __TERRAIN_BUILDER_H__
#define __TERRAIN_BUILDER_H__

#include <ImageTransformer.h>
#include <TerrainEnvironmentDescriptor.h>
#include <TerrainDecorator.h>
#include <TerrainAbstract.h>

class TerrainBuilder
{
    public:
        enum TerrainType
        {
            TypeNone    = 0,
            TypeMesh    = 1,
            TypeVoxel   = 2
        };
    
    public:
        TerrainBuilder(const TerrainBuilder::TerrainType type, ImageTransformer* transformer);
        TerrainBuilder(const TerrainBuilder& src);
        virtual ~TerrainBuilder(void);

        TerrainBuilder& operator = (const TerrainBuilder& src);

        void release(void);
        TerrainEnvironmentDescriptor* getTerrainEnvironmentDescriptor(void);

    public:
        inline void setTerrainType(const TerrainBuilder::TerrainType type);
        inline TerrainBuilder::TerrainType getTerrainType(void) const;
        inline ImageTransformer* getImageTransformer(void) const;
        inline void setTerrainEnvironmentDescriptor(TerrainEnvironmentDescriptor* descriptor);
        inline void setTerrainDecorator(TerrainDecorator* decorator);
        inline TerrainDecorator* getTerrainDecorator(void) const;

    private:
        void _initTerrain(void);

    private:
        TerrainType _type;
        TerrainAbstract* _terrain;
        ImageTransformer* _transformer;
        TerrainEnvironmentDescriptor* _descriptor;
        TerrainDecorator* _decorator;
};

#include <Detail/TerrainBuilderDetail.h>

#endif