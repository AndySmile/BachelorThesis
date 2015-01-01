/**
 * @version     1.1.1 28-Dec-14
 * @copyright   Copyright (c) 2014-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#include <SimpleLib/OpenGLHelper.h>
#include <SimpleLib/Logger.h>
#include <SFML/OpenGL.hpp>
#include <string>

namespace SimpleLib
{
    void OpenGLHelper::printError(void)
    {
        GLenum errorCode = glGetError();
        
        if (errorCode != GL_NO_ERROR) {
            Logger::writeFailure("OpenGL Failure: %s", gluErrorString(errorCode));
        }
    }
}