/**
 * DemoApp - Terrain Builder Model Header.
 *
 * @author      Andy Liebke<coding@andysmiles4games.com>
 * @file        Src/TerrainBuilder.h
 * @version     1.2.0 08-Jan-15
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
        TerrainBuilder(const TerrainBuilder::TerrainType type, const std::string pathInputImage);
        TerrainBuilder(const TerrainBuilder& src);
        virtual ~TerrainBuilder(void);

        TerrainBuilder& operator = (const TerrainBuilder& src);

        TerrainAbstract* build(void);
        TerrainEnvironmentDescriptor* getTerrainEnvironmentDescriptor(void);
        ImageTransformer* getImageTransformer(void);
        TerrainDecorator* getTerrainDecorator(void);
        void release(void);
    
    public:
        inline void setTerrainType(const TerrainBuilder::TerrainType type);
        inline TerrainBuilder::TerrainType getTerrainType(void) const;

    private:
        void _initTerrain(void);

    private:
        TerrainType _type;
        TerrainAbstract* _terrain;
        ImageTransformer* _transformer;
        TerrainEnvironmentDescriptor* _descriptor;
        TerrainDecorator* _decorator;
        std::string _pathInputImage;
};

#include <Detail/TerrainBuilderDetail.h>

#endif