/**
 * @version		1.3.1 18-Dec-14
 * @copyright	Copyright (c) 2014 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
 
#include <SimpleLib/Application.h>
#include <SFML/OpenGL.hpp>

#ifdef _DEBUG
	#include <iostream>
#endif

namespace SimpleLib
{
	Application::Application(void)
	{
	}
	
	Application::~Application(void)
	{
	}
			
	void Application::_updateViewport(const sf::Window& window)
	{
#ifdef _DEBUG
		std::cout << "update resized window" << std::endl;
#endif
		glViewport(0, 0, window.getSize().x, window.getSize().y);
	
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
	
		float ratio = (float)window.getSize().x / (float)window.getSize().y;
	
		glFrustum(-ratio, ratio, -1.0f, 1.0f, 1.0f, 100000.0f);
	
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}		
			
	void Application::run(IOpenGLScene* scene)
    {
    	ConfigParameter config;
        
        config.screenWidth 	= 1024;
        config.screenHeight	= 768;
        config.isWindowMode = true;
    
        _run(scene, config);
    }
    
    void Application::run(IOpenGLScene* scene, const ConfigParameter& config)
    {
        _run(scene, config);
    }
    
    void Application::_run(IOpenGLScene* scene, const ConfigParameter& config) 
	{
		sf::ContextSettings settings;
		
		settings.depthBits = 32;
		
		sf::Window window(sf::VideoMode(config.screenWidth, config.screenHeight), scene->getTitle(), (config.isWindowMode) ? sf::Style::Titlebar : sf::Style::Fullscreen, settings);

		window.setFramerateLimit(60);

#ifdef _DEBUG	
		settings = window.getSettings();
		
		std::cout << "depth bits: " << settings.depthBits << std::endl;
		std::cout << "stencil bits: " << settings.stencilBits << std::endl;
		std::cout << "antialiasing level: " << settings.antialiasingLevel << std::endl;
		std::cout << "major version: " << settings.majorVersion << std::endl;
		std::cout << "minor version: " << settings.minorVersion << std::endl;
#endif		
		_updateViewport(window);
	
		glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
	
		scene->init();
	
		sf::Clock clockHnd;
	
		while(window.isOpen())
		{
			sf::Event currEvent;
		
			while(window.pollEvent(currEvent))
			{
				if(currEvent.type == sf::Event::Closed || (currEvent.type == sf::Event::KeyPressed && currEvent.key.code == sf::Keyboard::Escape)) {
					window.close();
				}
				else if(currEvent.type == sf::Event::Resized) {
					_updateViewport(window);
				}
			}
		
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
			scene->update(clockHnd.getElapsedTime().asSeconds());
			scene->render(window);
		
			window.display();
		}
		
		scene->release();
	}		
} 