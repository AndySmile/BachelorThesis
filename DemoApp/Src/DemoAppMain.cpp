/**
 * @version		1.0.0 14-Dec-14
 * @copyright	Copyright (c) 2014 by Andy Liebke. All rights reserved.
 */
#include <SimpleLib/Application.h>
#include <DemoAppScene.h>
#include <stdlib.h>
#include <iostream>

int main(const int argc, char** argv)
{
	if (argc <= 1) {
        std::cout << "Error: you have to entere the path to the input image!" << std::endl;
    }
	else
    {
        DemoAppScene* scene = new DemoAppScene();
        
        scene->setImagePath(argv[1]);
        
        if (argc >= 3) {
            scene->setConfigFilePath(argv[2]);
        }
        
        SimpleLib::ConfigParameter config;
        config.screenWidth 	= 1024;
        config.screenHeight = 900;
        config.isWindowMode	= true;
        
        SimpleLib::Application::run(scene);
        
        delete scene;
        scene = NULL;
    }
    
	return EXIT_SUCCESS;
}