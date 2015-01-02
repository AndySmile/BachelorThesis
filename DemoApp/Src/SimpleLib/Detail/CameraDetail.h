/**
 * SimpleLib - Camera Model Detail Implementation.
 *
 * @author      Andy Liebke\<coding@andysmiles4games.com\>
 * @file        SimpleLib/Detail/Camera.h
 * @version     1.1.0 02-Jan-15
 * @copyright   Copyright (c) 2014-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 * @ingroup     simplelib
 */

namespace SimpleLib
{
    void Camera::setPosition(const glm::vec3 position)
    {
        this->_position = position;
    }

    glm::vec3 Camera::getPosition(void) const
    {
        return this->_position;
    }
    
    void Camera::setMovementSpeed(const float movementSpeed)
    {
        this->_movementSpeed = movementSpeed;
    }
    
    float Camera::getMovementSpeed(void) const
    {
        return this->_movementSpeed;
    }
    
    void Camera::setDirection(const glm::vec3 direction)
    {
        this->_direction = direction;
    }
    
    glm::vec3 Camera::getDirection(void) const
    {
        return this->_direction;
    }
}