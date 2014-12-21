/**
 * @version		1.0.0 03-Aug-14
 * @copyright	Copyright (c) 2014 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */

#include <SimpleLib/Camera.h>
#include <SFML/OpenGL.hpp>

namespace SimpleLib
{
	Camera::Camera(void) :
		_position(glm::vec3(0.0f, 0.0f, 0.0f))
	{
	}

	Camera::~Camera(void)
	{
	}

	void Camera::moveLeft(const float speed)
	{
		this->_position.x -= speed;
	}

	void Camera::moveRight(const float speed)
	{
		this->_position.x += speed;
	}
	
	void Camera::moveBackward(const float speed)
	{
		this->_position.z -= speed;
	}
	
	void Camera::moveForward(const float speed)
	{
		this->_position.z += speed;
	}

	void Camera::update(void)
	{
		gluLookAt(this->_position.x, this->_position.y, this->_position.z, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	}
}