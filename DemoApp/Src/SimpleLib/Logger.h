/**
 * SimpleLib - Logger Model Header.
 *
 * @author      Andy Liebke\<coding@andysmiles4games.com\>
 * @file        SimpleLib/Logger.h
 * @version     1.2.0 02-Jan-15
 * @copyright   Copyright (c) 2014-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 * @ingroup     simplelib
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
            static void writeFailure(const char* message, ...);
            static void writeDebug(const char* message, ...);
            static void writeWarning(const char* message, ...);
        
        private:
            static bool _isInitilized;
            static LogType _type;
    };
}

#endif