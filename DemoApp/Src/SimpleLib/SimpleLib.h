/**
 * SimpleLib - Common Header.
 *
 * @author		Andy Liebke\<coding@andymiles4games.com\>
 * @file		SimpleLib/SimpleLib.h
 * @version		1.1.0 21-Dec-14
 * @copyright	Copyright (c) 2014 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
 
#ifndef __SIMPLE_LIB_H__
#define __SIMPLE_LIB_H__

#define SIMPLELIB_VERSION_MAJOR 1
#define SIMPLELIB_VERSION_MINOR 2
#define SIMPLELIB_VERSION_PATCH 0
/*#define SIMPLELIB_VERSION SIMPLELIB_VERSION_MAJOR "." SIMPLELIB_VERSION_MINOR "." SIMPLELIB_VERSION_PATCH
#define SIMPLELIB_VERSION_STRING "v" SIMPLELIB_VERSION " " __DATE__ " " __TIME__*/

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