/**
 * DemoApp - Terrain Environment Descriptor Model Header.
 *
 * @author      Andy Liebke<coding@andysmiles4games.com>
 * @file        Src/TerrainEnvironmentDescriptor.h
 * @version     1.2.0 09-Jan-15
 * @copyright   Copyright (c) 2014-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 * @ingroup     demoapp
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
        TerrainEnvironmentDescriptor(void);
        TerrainEnvironmentDescriptor(const TerrainEnvironmentDescriptor& src);
        virtual ~TerrainEnvironmentDescriptor(void);
    
        TerrainEnvironmentDescriptor& operator = (const TerrainEnvironmentDescriptor& src);
    
        unsigned int getCountDescriptors(void);
        void addDescriptor(TerrainDescriptorInterface* descriptor);
        void process(const cv::Mat& inputImage, TerrainAbstract* terrain);
        void release(void);
    
    private:
        ListTerrainDescriptors _listDescriptors;
};

#endif