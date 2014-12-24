/**
 * @version		1.3.0 23-Dec-14
 * @copyright	Copyright (c) 2014 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
 
#ifndef __SIMPLE_LIB_APPLICATION_H__
#define __SIMPLE_LIB_APPLICATION_H__

#include <SFML/Window.hpp>
#include <SimpleLib/OpenGLSceneInterface.h>
#include <SimpleLib/SimpleLib.h>

namespace SimpleLib
{
	class Application
	{
		public:
			static void run(OpenGLSceneInterface* scene);
			static void run(OpenGLSceneInterface* scene, const ConfigParameter& config);
            
		private:
			Application(void);
			virtual ~Application(void);
			
			static void _updateViewport(const sf::Window& window);
            static void _run(OpenGLSceneInterface* scene, const ConfigParameter& config);
	};
}

#endif