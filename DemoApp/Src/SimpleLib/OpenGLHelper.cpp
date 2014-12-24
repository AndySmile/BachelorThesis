/**
 * @version 	1.0.0 23-Dec-14
 * @copyright	Copyright (c) 2014 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#include <SimpleLib/OpenGLHelper.h>
#include <SFML/OpenGL.hpp>
#include <string>

namespace SimpleLib
{
	void OpenGLHelper::printError(void)
    {
        GLenum errorCode = glGetError();
        
        if (errorCode != GL_NO_ERROR) {
            printf("OPENGL FAILURE: %s", gluErrorString(errorCode));
        }
    }
}