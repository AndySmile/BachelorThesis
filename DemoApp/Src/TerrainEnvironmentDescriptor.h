/**
 * @version     1.0.0 03-Jan-15
 * @copyright   Copyright (c) 2014-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#ifndef __TERRAIN_ENVIRONMENT_DESCRIPTOR_H__
#define __TERRAIN_ENVIRONMENT_DESCRIPTOR_H__

#include <TerrainAbstract.h>
#include <TerrainDescriptorInterface.h>
#include <vector>

class TerrainEnvironmentDescriptor
{
    public:
        typedef std::vector<TerrainDescriptorInterface*> ListTerrainDescriptors;
    
    public:
        TerrainEnvironmentDescriptor(TerrainAbstract* terrain);
        virtual ~TerrainEnvironmentDescriptor(void);
    
        unsigned int getCountDescriptors(void);
        void addDescriptor(TerrainDescriptorInterface* descriptor);
        void process(void);
        void release(void);
    
    private:
        TerrainAbstract* _terrain;
        ListTerrainDescriptors _listDescriptors;
};

#endif