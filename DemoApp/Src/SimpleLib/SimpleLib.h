/**
 * @defgroup simplelib SimpleLib
 *
 * SimpleLib - Common Header.
 *
 * @author      Andy Liebke\<coding@andymiles4games.com\>
 * @file        SimpleLib/SimpleLib.h
 * @version     1.2.0 08-Jan-15
 * @copyright   Copyright (c) 2014-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
 
#ifndef __SIMPLE_LIB_H__
#define __SIMPLE_LIB_H__

#define SIMPLELIB_VERSION_MAJOR 1
#define SIMPLELIB_VERSION_MINOR 4
#define SIMPLELIB_VERSION_PATCH 2
#define SIMPLELIB_VERSION_STRING "1.4.2"
#define SIMPLELIB_VERSION_BUILD_STRING "v" SIMPLELIB_VERSION_STRING " " __DATE__ " " __TIME__

namespace SimpleLib
{
    typedef struct _struct_config_params
    {
        bool isWindowMode;
        unsigned short screenWidth;
        unsigned short screenHeight;
    } ConfigParameter;
}

#endif