/**
 * DemoApp - Demo Application Scene.
 *
 * @author      Andy Liebke\<coding@andysmiles4games.com\>
 * @file        Src/DemoAppScene.cpp
 * @version     1.5.1 02-Jan-15
 * @copyright   Copyright (c) 2014-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 * @ingroup     demoapp
 */
 
#include <SimpleLib/SimpleLib.h>
#include <DemoAppScene.h>
#include <ImageTransformer.h>
#include <ImageProcessorHeightMap.h>
#include <ImageProcessorHistogramHeightMap.h>
#include <SFML/OpenGL.hpp>

#ifdef _DEBUG
    #include <SimpleLib/Logger.h>
    #include <assert.h>
#endif

DemoAppScene::DemoAppScene(void) :
    _isLightEnabled(false),
    _imagePath(""),
    _configFilePath(""),
    _terrain(NULL),
    _config(NULL),
    _sceneConfig()
{

}

DemoAppScene::DemoAppScene(const DemoAppScene& src) :
    _isLightEnabled(src._isLightEnabled),
    _imagePath(src._imagePath),
    _configFilePath(src._configFilePath),
    _terrain(NULL),
    _config(NULL),
    _sceneConfig()
{
#ifdef _DEBUG
    SimpleLib::Logger::writeDebug("call copy constructor!");
#endif
}

DemoAppScene::~DemoAppScene(void)
{
#ifdef _DEBUG
    SimpleLib::Logger::writeDebug("DemoAppScene Notice: call destructor!");
#endif
}

DemoAppScene& DemoAppScene::operator = (const DemoAppScene& src)
{
    this->_imagePath        = src._imagePath;
    this->_configFilePath   = src._configFilePath;
    this->_isLightEnabled   = src._isLightEnabled;
    this->_terrain          = NULL;
    
#ifdef _DEBUG
    SimpleLib::Logger::writeDebug("call assignment operator!");
#endif

    return *this;
}

void DemoAppScene::init(void)
{
    ImageTransformer* transformer               = new ImageTransformer(this->_imagePath);
    ImageTransformer::TerrainType terrainType   = ImageTransformer::MeshTerrain;
    
    if (this->_config != NULL)
    {
        this->_config->assignProcessors(transformer);
        this->_config->assignSceneConfig(&this->_sceneConfig);
        
        terrainType = this->_config->getTerrainType();
    }
    else
    {
#ifdef _DEBUG
        SimpleLib::Logger::writeDebug("DemoAppScene::init: No app config object defined! using default values instead!");
#endif
        transformer->addProcessor(new ImageProcessorHistogramHeightMap());
        //transformer->addProcessor(new ImageProcessorHeightMap());
        
        this->_sceneConfig.isLightEnabled = false;
    }
    
    this->_terrain = transformer->generateTerrain(terrainType);
    
    transformer->release();
    
    delete transformer;
    transformer = NULL;
    
    if (this->_isLightEnabled || this->_sceneConfig.isLightEnabled)
    {
        float lightPosition[] = {10.0f, this->_terrain->getHeight() * 2.0f, 0.0f, 0.0f};
        
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);
        glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    }
    
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
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
        gluLookAt(0.0f, 50.0f, -80.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
        
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