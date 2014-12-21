/**
 * @version		1.0.0 21-Dec-14
 * @copyright	Copyright (c) 2014 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#include <SimpleLib/SimpleLib.h>
#include <SimpleLib/Application.h>
#include <DemoScene.h>
#include <stdlib.h>

int main(void)
{
	DemoScene* scene = new DemoScene();
	
    SimpleLib::ConfigParameter config;
    config.screenWidth 	= 1024;
    config.screenHeight = 900;
    config.isWindowMode	= true;
    
	SimpleLib::Application::run(scene);
	
	delete scene;
	scene = NULL;

    return EXIT_SUCCESS;
}