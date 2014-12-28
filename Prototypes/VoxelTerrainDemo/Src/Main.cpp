/**
 * @version     1.2.0 30-Nov-14
 * @copyright   Copyright (c) Andy Liebke. All rights reserved.
 */

#include <SimpleLib/Application.h>
#include <DemoScene.h> 
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

#include <iostream> 
#include <stdlib.h>

int main(void)
{
    DemoScene* scene = new DemoScene();
    
    SimpleLib::ConfigParameter config;
    config.screenWidth  = 1024;
    config.screenHeight = 900;
    config.isWindowMode = true; 
    
    SimpleLib::Application::run(scene);
    
    delete scene;
    scene = NULL;
    
    return EXIT_SUCCESS;
}