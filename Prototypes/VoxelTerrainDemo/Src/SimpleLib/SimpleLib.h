/**
 * @version		1.0.0 30-Nov-14
 * @copyright	Copyright (c) 2014 by Andy Liebke. All rights reserved.
 */
#ifndef __SIMPLE_LIB_H__
#define __SIMPLE_LIB_H__

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