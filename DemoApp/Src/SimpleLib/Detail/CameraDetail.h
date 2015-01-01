/**
 * SimpleLib - Camera Model Detail Implementation.
 *
 * @author      Andy Liebke\<coding@andysmiles4games.com\>
 * @file        SimpleLib/Detail/Camera.h
 * @version     1.0.0 23-Dec-14
 * @copyright   Copyright (c) 2014-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
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
}