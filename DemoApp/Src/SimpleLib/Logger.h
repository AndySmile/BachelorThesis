/**
 * @version		1.1.0 28-Dec-14
 * @copyright	Copyright (c) 2014 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#ifndef __SIMPLE_LIB_LOGGER_H__
#define __SIMPLE_LIB_LOGGER_H__

#include <string>

namespace SimpleLib
{
    class Logger
    {
    	public:
        	enum LogType
        	{
            	Console = 1
			};
        
    	public:
        	static void init(const LogType type=Logger::Console);
        	static bool isInitilized(void);
        	static void write(const std::string message);
        	static void writeFailure(const std::string message, ...);
        	static void writeDebug(const std::string message, ...);
        	static void writeWarning(const std::string message, ...);
        
        private:
        	static bool _isInitilized;
        	static LogType _type;
    };
}

#endif