/**
 * @version		1.0.0 21-Dec-14
 * @copyright	Copyright (c) 2014 by Andy Liebke. All rights reserved. 
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
}

void DemoScene::_createFromHeightMap(void)
{
	sf::Image heightMap;
	
	heightMap.loadFromFile("Resource/HeightMap.jpg");
	
	sf::Vector2u dimension = heightMap.getSize();
	
	
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
	glPopMatrix();
}

void DemoScene::release(void)
{
}


std::string DemoScene::getTitle(void) const
{
	return "Demo Mesh Terrain";
}
