/**
 * SimpleLib - Application Model Header.
 *
 * @author		Andy Liebke\<coding@andysmiles4games.com\>
 * @file		Src/SimpleLib/Application.h
 * @version		1.3.0 23-Dec-14
 * @copyright	Copyright (c) 2014 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 * @ingroup		simplelib
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