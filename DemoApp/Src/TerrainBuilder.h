/**
 * @version     1.0.0 03-Jan-15
 * @copyright   Copyright (c) 2014-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
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
        virtual ~TerrainBuilder(void);

        TerrainEnvironmentDescriptor* getTerrainEnvironmentDescriptor(void);

    public:
        inline void setTerrainType(const TerrainBuilder::TerrainType type);
        inline TerrainBuilder::TerrainType getTerrainType(void) const;
        inline ImageTransformer* getImageTransformer(void) const;
        inline void setTerrainEnvironmentDescriptor(TerrainEnvironmentDescriptor* descriptor);
        inline void setTerrainDecorator(TerrainDecorator* decorator);
        inline TerrainDecorator* getTerrainDecorator(void) const;

    private:
        TerrainType _type;
        TerrainAbstract* _terrain;
        ImageTransformer* _transformer;
        TerrainEnvironmentDescriptor* _descriptor;
        TerrainDecorator* _decorator;
};

#include <Detail/TerrainBuilderDetail.h>

#endif