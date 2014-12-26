/**
 * @version		1.1.0 26-Dec-14
 * @copyright	Copyright (c) 2014 by Andy Liebke. All rights reserved.
 */
#include <SimpleLib/Application.h>
#include <DemoAppScene.h>
#include <stdlib.h>
#include <iostream>

int main(const int argc, char** argv)
{
	if (argc <= 1) {
        std::cerr << "Error: you have to entere the path to the input image!" << std::endl;
    }
	else
    {
        DemoAppScene* scene = new DemoAppScene();
        
        scene->setImagePath(argv[1]);
        
        SimpleLib::ConfigParameter config;
        bool usingDefaultValues = (argc < 3);
        AppConfig* appConfig = NULL;
        
        if (argc >= 3)
        {
            appConfig = new AppConfig();
            
            SimpleLib::DataCollection::ErrorCode errorCode = appConfig->loadFromFile(argv[2]);
            
            if (errorCode != SimpleLib::DataCollection::None)
            {
#ifdef _DEBUG
				std::cout << "[WARNING]: couldn't load configuration file! Using default values instead!" << std::endl;
#endif
				usingDefaultValues = true;
            }
            else
            {
                appConfig->assignScreenValues(&config);
                scene->setAppConfig(appConfig);
            }
        }
        
        if (usingDefaultValues)
        {
            config.screenWidth 	= 1024;
            config.screenHeight = 900;
            config.isWindowMode	= true;
        }
        
        SimpleLib::Application::run(scene, config);
        
        if (appConfig != NULL)
        {
#ifdef _DEBUG
			std::cout << "[DEBUG] Releasing app config object!" << std::endl;
#endif
			delete appConfig;
            appConfig = NULL;
        }
        
        delete scene;
        scene = NULL;
    }
    
	return EXIT_SUCCESS;
}