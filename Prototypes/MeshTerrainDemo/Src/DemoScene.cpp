/**
 * @version     1.0.1 22-Dec-14
 * @copyright   Copyright (c) 2014 by Andy Liebke. All rights reserved. 
 */
#include <DemoScene.h>
#include <SFML/OpenGL.hpp>
#include <SFML/Graphics/Image.hpp>

#ifdef _DEBUG
    #include <iostream>
#endif

DemoScene::DemoScene(void) :
    _meshId(0)
{
}

DemoScene::~DemoScene(void)
{
}

void DemoScene::init(void)
{
    float lightPosition[] = {10.0f, 5.0f, 0.0f, 0.0f};

    glEnable(GL_DEPTH_TEST);
    //glEnable(GL_LIGHTING);
    //glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    
    glColor3f(1.0f, 1.0f, 1.0f);
}

void DemoScene::_createFromHeightMap(void)
{
    if (this->_meshId == 0)
    {
#ifdef _DEBUG
        std::cout << "generate terrain from height map" << std::endl;
#endif
        sf::Image heightMap;
        
        heightMap.loadFromFile("Resource/HeightMap_5.jpg");
        
        sf::Vector2u dimension = heightMap.getSize();
        
        // create an offset to center the terrain
        float offsetX = -(dimension.x / 2.0f);
        float offsetZ = -(dimension.y / 2.0f);
        this->_meshId = glGenLists(1);
        
#ifdef _DEBUG
        std::cout << "Mesh ID: " << (int)this->_meshId << std::endl;
        std::cout << "offsetX: " << (float)offsetX << std::endl;
        std::cout << "offsetZ: " << (float)offsetZ << std::endl;
#endif
        
        this->_printError();
        
        glNewList(this->_meshId, GL_COMPILE);
        
            this->_printError();
        
            for (unsigned int z=0; z < dimension.y - 1; ++z)
            {
                glBegin(GL_TRIANGLE_STRIP);
                
                    for (unsigned int x=0; x < dimension.x; ++x)
                    {
                        sf::Color currColor = heightMap.getPixel(x, z);
                        float secondAvgColor = 0.0f;
                        float currAvgColor  = (currColor.r + currColor.g + currColor.b) * 0.3333f;
                        currAvgColor        = (currAvgColor / 256.0f) * 10.0f;
                        
                        if (z + 1 < dimension.y)
                        {
                            sf::Color secondColor = heightMap.getPixel(x, z + 1);
                            secondAvgColor  = (secondColor.r + secondColor.g + secondColor.b) * 0.3333f;
                            secondAvgColor      = (secondAvgColor / 256.0f) * 10.0f;
                        }
                        else {
                            secondAvgColor = currAvgColor;
                        }
                        
                        glColor3ub(currColor.r, currColor.g, currColor.b);
                        glVertex3f(offsetX + (x * 2.0f), secondAvgColor, offsetZ + ((z + 1) * 2.0f));
                        
                        glColor3ub(currColor.r, currColor.g, currColor.b);
                        glVertex3f(offsetX + (x * 2.0f), currAvgColor, offsetZ + (z * 2.0f));
                    }
                glEnd();
            }
        glEndList();
        
        this->_printError();
    }
}

void DemoScene::_printError(void)
{
    GLenum errorCode = glGetError();
    
    if (errorCode != GL_NO_ERROR) {
        printf("FAILURE: %s", gluErrorString(errorCode));
    }
}

void DemoScene::update(const float currTime)
{
    
}

void DemoScene::render(sf::Window& window)
{
    static float rotationAngle = 0.0f;

    glLoadIdentity();
    gluLookAt(0.0f, 18.0f, 45.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    
    rotationAngle += 0.5f;

    glPushMatrix();
        glRotatef(rotationAngle, 0.0f, 1.0f, 0.0f);
    
        this->_createFromHeightMap();
        glCallList(this->_meshId);
    glPopMatrix();
}

void DemoScene::release(void)
{
}


std::string DemoScene::getTitle(void) const
{
    return "Demo Mesh Terrain";
}
