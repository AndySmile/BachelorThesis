/**
 * @version     1.1.0 09-Jan-15
 * @copyright   Copyright (c) 2014-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */

#include <EntityWater.h>
#include <SimpleLib/OpenGLHelper.h>
#include <SFML/OpenGL.hpp>

EntityWater::EntityWater(void) :
    EntityAbstract(),
    _meshId(0),
    _width(0),
    _depth(0)
{
    
}

EntityWater::EntityWater(const glm::vec3 position, unsigned int width, unsigned int depth) :
    EntityAbstract(position),
    _meshId(0),
    _width(width),
    _depth(depth)
{
    
}

EntityWater::~EntityWater(void)
{
    
}

void EntityWater::render(void)
{
    if (this->_meshId == 0)
    {
        this->_meshId = glGenLists(1);

        glNewList(this->_meshId, GL_COMPILE);
            glBegin(GL_TRIANGLE_STRIP);
                glVertex3f(0.0f, this->_position.y, 0.0f);
                glVertex3f(0.0f, this->_position.y, this->_depth);
                glVertex3f(this->_width, this->_position.y, 0.0f);
                glVertex3f(this->_width, this->_position.y, this->_depth);
            glEnd();
        glEndList();

        SimpleLib::OpenGLHelper::printError();
    }

    glColor3f(0.0f, 0.0f, 1.0f);
    glCallList(this->_meshId);
}

void EntityWater::release(void)
{
    
}