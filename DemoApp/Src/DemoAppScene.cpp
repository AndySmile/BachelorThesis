/**
 * DemoApp - Demo Application Scene.
 *
 * @author      Andy Liebke\<coding@andysmiles4games.com\>
 * @file        Src/DemoAppScene.cpp
 * @version     1.8.0 09-Jan-15
 * @copyright   Copyright (c) 2014-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 * @ingroup     demoapp
 */
 
#include <SimpleLib/SimpleLib.h>
#include <DemoAppScene.h>
#include <ImageTransformer.h>
#include <ImageProcessorHeightMap.h>
#include <ImageProcessorHistogramHeightMap.h>
#include <TerrainBuilder.h>
#include <TerrainDescriptorWater.h>
#include <SFML/OpenGL.hpp>

#ifdef _DEBUG
    #include <SimpleLib/Logger.h>
    #include <cassert>
#endif

DemoAppScene::DemoAppScene(void) :
    _isLightEnabled(false),
    _imagePath(""),
    _configFilePath(""),
    _terrain(NULL),
    _config(NULL),
    _camera(NULL),
    _sceneConfig()
{

}

DemoAppScene::DemoAppScene(const DemoAppScene& src) :
    _isLightEnabled(src._isLightEnabled),
    _imagePath(src._imagePath),
    _configFilePath(src._configFilePath),
    _terrain(NULL),
    _config(NULL),
    _camera(NULL),
    _sceneConfig()
{
#ifdef _DEBUG
    SimpleLib::Logger::writeDebug("DemoAppScene: call copy constructor!");
#endif
}

DemoAppScene::~DemoAppScene(void)
{
#ifdef _DEBUG
    SimpleLib::Logger::writeDebug("DemoAppScene: call destructor!");
#endif
}

DemoAppScene& DemoAppScene::operator = (const DemoAppScene& src)
{
    this->_imagePath        = src._imagePath;
    this->_configFilePath   = src._configFilePath;
    this->_isLightEnabled   = src._isLightEnabled;
    this->_terrain          = NULL;
    
#ifdef _DEBUG
    SimpleLib::Logger::writeDebug("DemoAppScene: call assignment operator!");
#endif

    return *this;
}

void DemoAppScene::init(void)
{
    // setup terrain
    TerrainBuilder* builder = NULL;

    if (this->_config != NULL)
    {
        this->_config->assignSceneConfig(&this->_sceneConfig);

        builder                         = new TerrainBuilder(this->_config->getTerrainType(), this->_imagePath);
        ImageTransformer* transformer   = builder->getImageTransformer();

        this->_config->assignProcessors(transformer);
    }
    else
    {
#ifdef _DEBUG
        SimpleLib::Logger::writeDebug("DemoAppScene::init: No app config object defined! using default values instead!");
#endif
        builder                         = new TerrainBuilder(TerrainBuilder::TypeMesh, this->_imagePath);
        ImageTransformer* transformer   = builder->getImageTransformer();
        TerrainEnvironment* environment = builder->getTerrainEnvironment();
        
        //transformer->addProcessor(new ImageProcessorHistogramHeightMap());
        transformer->addProcessor(new ImageProcessorHeightMap(300.0f));

        environment->addDescriptor(new TerrainDescriptorWater());

        this->_sceneConfig.isLightEnabled = false;
    }

    this->_terrain = builder->build();

    builder->release();
    
    delete builder;
    builder = NULL;

    // initialize camera
    this->_camera = new SimpleLib::Camera(0.0f, 50.0f, -80.0f, 3.0f);
    
    // if enabled setup light
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
    // camera control
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        this->_camera->moveRight();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        this->_camera->moveLeft();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        this->_camera->moveForward();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        this->_camera->moveBackward();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        this->_camera->moveUp();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
        this->_camera->moveDown();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        this->_camera->lookLeft();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        this->_camera->lookRight();
    }
}

void DemoAppScene::render(sf::Window& window)
{
    if (this->_terrain != NULL)
    {
        glLoadIdentity();
        
        this->_camera->update();
        
        glPushMatrix();
            this->_terrain->render();
        glPopMatrix();
    }
#ifdef _DEBUG
    else {
        SimpleLib::Logger::writeDebug("DemoAppScene: No terrain object available!");
    }
#endif
}

void DemoAppScene::release(void)
{
    if (this->_terrain != NULL)
    {
        this->_terrain->release();
        
        delete this->_terrain;
        this->_terrain = NULL;
    }
    
    if (this->_camera != NULL)
    {
        delete this->_camera;
        this->_camera = NULL;
    }
}

std::string DemoAppScene::getTitle(void) const
{
    return "Image Transformer - Demo " __DATE__ " " __TIME__ " - Powered by SimpleLib " SIMPLELIB_VERSION_BUILD_STRING;
}