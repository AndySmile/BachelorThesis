/**
 * @version     1.0.0 04-Jan-15
 * @copyright   Copyright (c) 2014-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#ifndef __ENTITY_DUMMY_H__
#define __ENTITY_DUMMY_H__

#include <EntityAbstract.h>

namespace DemoAppTest
{
    class EntityDummy : public EntityAbstract
    {
        public:
            EntityDummy(void);
            virtual ~EntityDummy(void);
        
            void render(void);
            void release(void);
    };
}

#endif