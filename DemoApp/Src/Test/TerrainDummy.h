/**
 * @version     1.0.0 04-Jan-15
 * @copyright   Copyright (c) 2014-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#ifndef __TERRAIN_DUMMY_H__
#define __TERRAIN_DUMMY_H__

#include <TerrainAbstract.h>

namespace DemoAppTest
{
    class TerrainDummy : public TerrainAbstract
    {
        public:
            TerrainDummy(void);
            virtual ~TerrainDummy(void);
            
            void setGridNode(const unsigned short x, const float y, const unsigned short z);
    };
}

#endif