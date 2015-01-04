/**
 * @version     1.0.0 04-Jan-15
 * @copyright   Copyright (c) 2014-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#ifndef __ENTITY_WATER_H__
#define __ENTITY_WATER_H__

#include <EntityAbstract.h>

class EntityWater : public EntityAbstract
{
    public:
        EntityWater(void);
        EntityWater(const glm::vec3 position);
        virtual ~EntityWater(void);
    
        void render(void);
        void release(void);
};

#endif