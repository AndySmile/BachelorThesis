/**
 * DemoApp - Water Entity Model Header.
 *
 * @author      Andy Liebke<coding@andysmiles4games.com>
 * @file        Src/EntityWater.h
 * @version     1.1.0 09-Jan-15
 * @copyright   Copyright (c) 2014-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#ifndef __ENTITY_WATER_H__
#define __ENTITY_WATER_H__

#include <EntityAbstract.h>

class EntityWater : public EntityAbstract
{
    public:
        EntityWater(void);
        EntityWater(const glm::vec3 position, const unsigned int width, const unsigned int depth);
        virtual ~EntityWater(void);
    
        void render(void);
        void release(void);

    private:
        unsigned int _meshId;
        unsigned int _width;
        unsigned int _depth;
};

#endif