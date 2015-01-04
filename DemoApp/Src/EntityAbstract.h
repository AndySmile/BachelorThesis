/**
 * @version     1.0.0 04-Jan-15
 * @copyright   Copyright (c) 2014-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#ifndef __ENTITY_ABSTRACT_H__
#define __ENTITY_ABSTRACT_H__

#include <glm/vec3.hpp>

class EntityAbstract
{
    public:
        EntityAbstract(void);
        virtual ~EntityAbstract(void);
    
    public:
        virtual void render(void) = 0;
        virtual void release(void) = 0;
    
    public:
        inline void setPosition(const glm::vec3& position);
        inline glm::vec3 getPosition(void) const;
    
    protected:
        glm::vec3 _position;
};

#include <Detail/EntityAbstractDetail.h>

#endif