/**
 * @version		1.1.0 28-Dec-14
 * @copyright	Copyright (c) 2014 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#include <SimpleLib/Logger.h>
#include <stdarg.h>
#include <iostream>

namespace SimpleLib
{
	bool Logger::_isInitilized = false;
    Logger::LogType Logger::_type = Logger::Console;

    void Logger::init(const LogType type)
    {
        _type 			= type;
        _isInitilized	= true;
    }

    void Logger::write(const std::string message)
    {
    	if (_isInitilized) {
        	std::cout << message << std::endl;
        }
    }

    void Logger::writeFailure(const std::string message, ...)
    {
    	char messageBuffer[256];
        
        va_list args;
        va_start(args, message.c_str());
        vsprintf(messageBuffer, message.c_str(), args);
        va_end(args);
        
        write("\x1b[37;41m[FAILURE]: " + std::string(messageBuffer) + "\x1b[0m");
    }

    void Logger::writeDebug(const std::string message, ...)
    {
#ifdef _DEBUG  
		char messageBuffer[256];
        
        va_list args;
        va_start(args, message.c_str());
        vsprintf(messageBuffer, message.c_str(), args);
        va_end(args);
        
		// only print out debug information if this application was compiled in debug mode
        write("\x1b[34;41m[DEBUG]: " + std::string(messageBuffer) + "\x1b[0m");
#endif
    }

    void Logger::writeWarning(const std::string message, ...)
    {
    	char messageBuffer[256];
        
        va_list args;
        va_start(args, message.c_str());
        vsprintf(messageBuffer, message.c_str(), args);
        va_end(args);
    
        write("\x1b[33;41m[WARNING]: " + std::string(messageBuffer) + "\x1b[0m");
    }
    
    bool Logger::isInitilized(void)
    {
        return _isInitilized;
    }
}