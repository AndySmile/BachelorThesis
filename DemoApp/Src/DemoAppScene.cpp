/**
 * @version		1.3.0 26-Dec-14
 * @copyright	Copyright (c) 2014 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#include <SimpleLib/SimpleLib.h>
#include <DemoAppScene.h>
#include <ImageTransformer.h>
#include <ImageProcessorHeightMap.h>
#include <SFML/OpenGL.hpp>

#ifdef _DEBUG
	#include <iostream>
    #include <assert.h>
#endif

DemoAppScene::DemoAppScene(void) :
	_isLightEnabled(false),
	_imagePath(""),
	_configFilePath(""),
	_terrain(NULL),
	_config(NULL)
{

}

DemoAppScene::DemoAppScene(const DemoAppScene& src) :
	_isLightEnabled(src._isLightEnabled),
	_imagePath(src._imagePath),
	_configFilePath(src._configFilePath),
    _terrain(NULL),
    _config(NULL)
{
#ifdef _DEBUG
    std::cout << "call copy constructor!" << std::endl;
#endif
}

DemoAppScene::~DemoAppScene(void)
{
#ifdef _DEBUG
	std::cout << "DemoAppScene Notice: call destructor!" << std::endl;
#endif
}

DemoAppScene& DemoAppScene::operator = (const DemoAppScene& src)
{
	this->_imagePath 		= src._imagePath;
    this->_configFilePath 	= src._configFilePath;
    this->_isLightEnabled	= src._isLightEnabled;
    this->_terrain 			= NULL;
    
#ifdef _DEBUG
	std::cout << "call assignment operator!" << std::endl;
#endif

    return *this;
}

void DemoAppScene::init(void)
{
	if (this->_isLightEnabled)
    {
        float lightPosition[] = {10.0f, 5.0f, 0.0f, 0.0f};
        
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);
        glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    }
    
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    ImageTransformer* transformer = new ImageTransformer(this->_imagePath);
    ImageTransformer::TerrainType terrainType = ImageTransformer::MeshTerrain;
    
    if (this->_config != NULL)
    {
        this->_config->assignProcessors(transformer);
        
        terrainType = this->_config->getTerrainType();
    }
    else
    {
#ifdef _DEBUG
		std::cout << "[DEBUG]  DemoAppScene::init: No app config object defined! using default values instead!" << std::endl;
#endif
    	ImageProcessorHeightMap* heightMapProcessor = new ImageProcessorHeightMap();
        
    	transformer->addProcessor(heightMapProcessor);
    }
    
    this->_terrain = transformer->generateTerrain(terrainType);
    
    transformer->release();
    
    delete transformer;
    transformer = NULL;
}

void DemoAppScene::update(const float currTime)
{
    
}

void DemoAppScene::render(sf::Window& window)
{
    if (this->_terrain != NULL)
    {
    	static float rotationAngle = 0.0f;
        
        rotationAngle += 0.5f;
        
        glLoadIdentity();
        gluLookAt(0.0f, 30.0f, -20.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
        
        glPushMatrix();
			glRotatef(rotationAngle, 0.0f, 1.0f, 0.0f);
        
        	this->_terrain->render();
        glPopMatrix();
    }
}

void DemoAppScene::release(void)
{
    if (this->_terrain != NULL)
    {
        this->_terrain->release();
        
        delete this->_terrain;
        this->_terrain = NULL;
    }
}

std::string DemoAppScene::getTitle(void) const
{
    return "Image Transformer - Demo " __DATE__ " " __TIME__ " - Powered by ";
}