/**
 * @version		2.0.0 23-Dec-14
 * @copyright	Copyright (c) 2014 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */

#ifndef __OPENGL_SCENE_INTERFACE_H__
#define __OPENGL_SCENE_INTERFACE_H__

#include <SFML/Window.hpp>
#include <string>

namespace SimpleLib
{
	class OpenGLSceneInterface
	{
		public:
			virtual ~OpenGLSceneInterface(void)
			{
			}
			
			virtual void init(void) = 0;
			virtual void update(const float currTime) = 0;
			virtual void render(sf::Window& window) = 0;
			virtual void release(void) = 0;
			
			virtual std::string getTitle(void) const = 0;
	};
}

#endif