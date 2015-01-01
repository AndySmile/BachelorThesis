/**
 * @defgroup demoapp DemoApp
 *
 * @author      Andy Liebke\<coding@andysmiles4games.com\>
 * @file        Src/DemoAppMain.cpp
 * @version     1.2.0 27-Dec-14
 * @copyright   Copyright (c) 2014-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#include <SimpleLib/Application.h>
#include <DemoAppScene.h>
#include <stdlib.h>
#include <iostream>

#ifdef _DEBUG
    #include <SimpleLib/Logger.h>
#endif

int main(const int argc, char** argv)
{
    if (argc <= 1) {
        std::cerr << "\x1b[37;41m[ERROR]: you have to enter the path to the input image!\x1b[0m" << std::endl;
    }
    else
    {
        DemoAppScene* scene = new DemoAppScene();
        
        scene->setImagePath(argv[1]);
        
        SimpleLib::ConfigParameter config;
        bool usingDefaultValues = (argc < 3);
        AppConfig* appConfig    = NULL;
        
        if (argc >= 3)
        {
            appConfig = new AppConfig();
            
            SimpleLib::DataCollection::ErrorCode errorCode = appConfig->loadFromFile(argv[2]);
            
            if (errorCode != SimpleLib::DataCollection::None)
            {
#ifdef _DEBUG
                SimpleLib::Logger::writeDebug("couldn't load configuration file! Using default values instead!");
#endif
                usingDefaultValues = true;
            }
            else
            {
                appConfig->assignWindowConfig(&config);
                scene->setAppConfig(appConfig);
            }
        }
        
        if (usingDefaultValues)
        {
            config.screenWidth  = 1024;
            config.screenHeight = 900;
            config.isWindowMode = true;
        }
        
        SimpleLib::Application::run(scene, config);
        
        if (appConfig != NULL)
        {
#ifdef _DEBUG
            SimpleLib::Logger::writeDebug("Releasing app config object!");
#endif
            delete appConfig;
            appConfig = NULL;
        }
        
        delete scene;
        scene = NULL;
    }
    
    return EXIT_SUCCESS;
}