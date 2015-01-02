/**
 * SimpleLib - Camera Model.
 *
 * @author      Andy Liebke\<coding@andysmiles4games.com>
 * @file        SimpleLib/Camera.cpp
 * @version     1.1.0 02-Jan-15
 * @copyright   Copyright (c) 2014-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 * @ingroup     simplelib
 */

#include <SimpleLib/Camera.h>
#include <SFML/OpenGL.hpp>
#include <glm/glm.hpp>
#include <glm/gtx/rotate_vector.hpp>

namespace SimpleLib
{
    Camera::Camera(const float positionX, const float positionY, const float positionZ, const float movementSpeed) :
        _movementSpeed(movementSpeed),
        _position(glm::vec3(positionX, positionY, positionZ)),
        _direction(glm::vec3(0.0f, 0.0f, 1.0f))
    {
    }
    
    Camera::Camera(void) :
        _movementSpeed(0.0f),
        _position(glm::vec3(0.0f, 0.0f, 0.0f)),
        _direction(glm::vec3(0.0f, 0.0f, 1.0f))
    {
    }

    Camera::~Camera(void)
    {
    }

    void Camera::moveLeft(const float speed)
    {
        this->_position.x -= (speed > 0.0f) ? speed : this->_movementSpeed;
    }

    void Camera::moveRight(const float speed)
    {
        this->_position.x += (speed > 0.0f) ? speed : this->_movementSpeed;
    }
    
    void Camera::moveBackward(const float speed)
    {
        this->_position.z -= (speed > 0.0f) ? speed : this->_movementSpeed;
    }
    
    void Camera::moveForward(const float speed)
    {
        this->_position.z += (speed > 0.0f) ? speed : this->_movementSpeed;
    }
    
    void Camera::moveUp(const float speed)
    {
        this->_position.y += (speed > 0.0f) ? speed : this->_movementSpeed;
    }
    
    void Camera::moveDown(const float speed)
    {
        this->_position.y -= (speed > 0.0f) ? speed : this->_movementSpeed;
    }
    
    void Camera::lookLeft(const float speed)
    {
        this->_direction = glm::rotateY(this->_direction, glm::radians((speed > 0.0f) ? speed : this->_movementSpeed));
        this->_direction = glm::normalize(this->_direction);
    }
    
    void Camera::lookRight(const float speed)
    {
        this->_direction = glm::rotateY(this->_direction, -glm::radians((speed > 0.0f) ? speed : this->_movementSpeed));
        this->_direction = glm::normalize(this->_direction);
    }

    void Camera::update(void)
    {
        gluLookAt(this->_position.x, this->_position.y, this->_position.z, this->_position.x + this->_direction.x, this->_position.y + this->_direction.y, this->_position.z + this->_direction.z, 0.0f, 1.0f, 0.0f);
    }
}