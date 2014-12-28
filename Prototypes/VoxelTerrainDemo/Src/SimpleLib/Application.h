/**
 * @version             1.2.0 30-Nov-14
 * @copyright   Copyright (c) 2014 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
 
#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include <SFML/Window.hpp>
#include <SimpleLib/IOpenGLScene.h>
#include <SimpleLib/SimpleLib.h>

namespace SimpleLib
{
        class Application
        {
                public:
                        static void run(IOpenGLScene* scene);
                        static void run(IOpenGLScene* scene, const ConfigParameter& config);
                        
                private:
                        Application(void);
                        ~Application(void);
                        
                        static void _updateViewport(const sf::Window& window);
                        static void _run(IOpenGLScene* scene, const ConfigParameter& config);
        };
}

#endif