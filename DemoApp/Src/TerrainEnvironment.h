/**
 * DemoApp - Terrain Environment Descriptor Model Header.
 *
 * @author      Andy Liebke<coding@andysmiles4games.com>
 * @file        Src/TerrainEnvironmentDescriptor.h
 * @version     2.0.0 09-Jan-15
 * @copyright   Copyright (c) 2014-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 * @ingroup     demoapp
 */
#ifndef __TERRAIN_ENVIRONMENT_H__
#define __TERRAIN_ENVIRONMENT_H__

#include <TerrainAbstract.h>
#include <TerrainDescriptorInterface.h>
#include <vector>
#include <string>

class TerrainEnvironment
{
    public:
        typedef std::vector<TerrainDescriptorInterface*> ListTerrainDescriptors;
        typedef ListTerrainDescriptors::iterator ListTerrainDescriptorsIterator;
    
    public:
        TerrainEnvironment(const std::string pathInputImage);
        TerrainEnvironment(const TerrainEnvironment& src);
        virtual ~TerrainEnvironment(void);
    
        TerrainEnvironment& operator = (const TerrainEnvironment& src);
    
        unsigned int getCountDescriptors(void);
        void addDescriptor(TerrainDescriptorInterface* descriptor);
        void process(TerrainAbstract* terrain);
        void release(void);
    
    private:
        ListTerrainDescriptors _listDescriptors;
        std::string _pathInputImage;
};

#endif