/**
 * SimpleLib - Application Model.
 *
 * @author		Andy Liebke\<coding@andysmiles4games.com>
 * @file		Src/SimpleLib/Application.cpp
 * @version		1.5.0 27-Dec-14
 * @copyright	Copyright (c) 2014 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 * @ingroup		simplelib
 */
 
#include <SimpleLib/Application.h>
#include <SimpleLib/Logger.h>
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
		Logger::writeDebug("update resized window");
#endif
		glViewport(0, 0, window.getSize().x, window.getSize().y);
	
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
	
		float ratio = (float)window.getSize().x / (float)window.getSize().y;
	
		glFrustum(-ratio, ratio, -1.0f, 1.0f, 1.0f, 100000.0f);
	
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}		
			
	void Application::run(OpenGLSceneInterface* scene)
    {
    	ConfigParameter config;
        
        config.screenWidth 	= 1024;
        config.screenHeight	= 768;
        config.isWindowMode = true;
    
        _run(scene, config);
    }
    
    void Application::run(OpenGLSceneInterface* scene, const ConfigParameter& config)
    {
        _run(scene, config);
    }
    
    void Application::_run(OpenGLSceneInterface* scene, const ConfigParameter& config)
	{
    	if (!Logger::isInitilized()) {
            Logger::init();
        }
    
		sf::ContextSettings settings;
		
		settings.depthBits = 32;
		
		sf::Window window(sf::VideoMode(config.screenWidth, config.screenHeight), scene->getTitle(), (config.isWindowMode) ? sf::Style::Titlebar : sf::Style::Fullscreen, settings);

		window.setFramerateLimit(60);

#ifdef _DEBUG	
		settings = window.getSettings();
		
		Logger::writeDebug("depth bits: " + settings.depthBits);
		Logger::writeDebug("stencil bits: " + settings.stencilBits);
		Logger::writeDebug("antialiasing level: " + settings.antialiasingLevel);
		Logger::writeDebug("major version: " + settings.majorVersion);
		Logger::writeDebug("minor version: " + settings.minorVersion);
#endif		
		_updateViewport(window);
	
		glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
	
		scene->init();
	
		sf::Clock clockHnd;
	
		while (window.isOpen())
		{
			sf::Event currEvent;
		
			while (window.pollEvent(currEvent))
			{
				if (currEvent.type == sf::Event::Closed || (currEvent.type == sf::Event::KeyPressed && currEvent.key.code == sf::Keyboard::Escape)) {
					window.close();
				}
				else if (currEvent.type == sf::Event::Resized) {
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