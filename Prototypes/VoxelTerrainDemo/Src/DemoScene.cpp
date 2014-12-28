/**
 * @version     1.5.0 09-Dec-14
 * @copyright   Copyright (c) 2014 by Andy Liebke. All rights reserved. 
 */
#include <DemoScene.h>
#include <SFML/OpenGL.hpp>
#include <SFML/Graphics/Image.hpp>

#ifdef _DEBUG
    #include <iostream>
#endif

DemoScene::DemoScene(void)
{
}

DemoScene::~DemoScene(void)
{
}

void DemoScene::init(void)
{
    float lightPosition[] = {10.0f, 5.0f, 0.0f, 0.0f};

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    
    // setup landscape
    // this->_createFromHeightMap();
    this->_createPyramid();
}

void DemoScene::_createFromHeightMap(void)
{
    sf::Image heightMap;
    
    heightMap.loadFromFile("Resource/HeightMap.jpg");
    
    sf::Vector2u dimension = heightMap.getSize();
    
    this->_voxelChunk = new VoxelChunk(dimension.x, 20, dimension.y);
    
    for (unsigned short x = 0; x < dimension.x; ++x)
    {
        for (unsigned short z = 0; z < dimension.y; ++z)
        {
            sf::Color currColor = heightMap.getPixel(x, z);
            
            //unsigned int currAvgColor = (currColor.r + currColor.g + currColor.b) * 0.3333f;
        
            unsigned int currAvgColor = (currColor.r + currColor.g + currColor.b) / 3;
        
            currAvgColor /= 20;
        
            for (unsigned short y = 0; y < currAvgColor; ++y) {
                this->_voxelChunk->setVoxelState(1, x, y, z);
            }
        }
    }
}

void DemoScene::_createPyramid(void)
{
    unsigned short dimension = 100;
    
    this->_voxelChunk = new VoxelChunk(dimension, dimension, dimension);
    
    for (unsigned short y = 0; y < dimension; ++y)
    {
        for (unsigned short x = y; x < dimension - y; ++x)
        {
            for (unsigned short z = y; z < dimension - y; ++z) {
                this->_voxelChunk->setVoxelState(1, x, y, z);
            }
        }
    }
}

void DemoScene::update(const float currTime)
{
    
}

void DemoScene::render(sf::Window& window)
{
    static float rotationAngle = 0.0f;

    rotationAngle += 0.5f;

    glLoadIdentity();
    gluLookAt(0.0f, 28.0f, 5.0f, 10.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    
    glPushMatrix();
        glRotatef(rotationAngle, 0.0f, 1.0f, 0.0f);
        
        this->_voxelChunk->render();
    glPopMatrix();
}

void DemoScene::release(void)
{
    if (this->_voxelChunk != NULL)
    {
        this->_voxelChunk->release();
        
        delete this->_voxelChunk;
        this->_voxelChunk = NULL;
    }
}


std::string DemoScene::getTitle(void)
{
    return "Demo Voxel Terrain";
}
