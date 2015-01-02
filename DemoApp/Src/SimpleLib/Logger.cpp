/**
 * SimpleLib - Logger Model.
 *
 * @author      Andy Liebke\<coding@andysmiles4games.com\>
 * @file        SimpleLib/Logger.cpp
 * @version     1.1.1 02-Jan-15
 * @copyright   Copyright (c) 2014-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 * @ingroup     simplelib
 */
#include <SimpleLib/Logger.h>
#include <stdarg.h>
#include <iostream>

namespace SimpleLib
{
    bool Logger::_isInitilized      = false;
    Logger::LogType Logger::_type   = Logger::Console;

    void Logger::init(const LogType type)
    {
        _type           = type;
        _isInitilized   = true;
    }

    void Logger::write(const std::string message)
    {
        if (_isInitilized) {
            std::cout << message << std::endl;
        }
    }

    void Logger::writeFailure(const char* message, ...)
    {
        char messageBuffer[256];
        //const char* messageFormat = message.c_str();
        va_list args;
        
        va_start(args, message);
        vsprintf(messageBuffer, message, args);
        va_end(args);
        
        write("\x1b[37;41m[FAILURE]: " + std::string(messageBuffer) + "\x1b[0m");
    }

    void Logger::writeDebug(const char* message, ...)
    {
#ifdef _DEBUG  
        char messageBuffer[256];
       // const char* messageFormat = message.c_str();
        va_list args;
        
        va_start(args, message);
        vsprintf(messageBuffer, message, args);
        va_end(args);
        
        // only print out debug information if this application was compiled in debug mode
        write("\x1b[30;47m[DEBUG]: " + std::string(messageBuffer) + "\x1b[0m");
#endif
    }

    void Logger::writeWarning(const char* message, ...)
    {
        char messageBuffer[256];
        //const char* messageFormat = message.c_str();
        va_list args;
        
        va_start(args, message);
        vsprintf(messageBuffer, message, args);
        va_end(args);
    
        write("\x1b[33;41m[WARNING]: " + std::string(messageBuffer) + "\x1b[0m");
    }
    
    bool Logger::isInitilized(void)
    {
        return _isInitilized;
    }
}