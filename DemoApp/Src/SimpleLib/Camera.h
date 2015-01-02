/**
 * SimpleLib - Camera Model Header.
 *
 * @author      Andy Liebke\<coding@andysmiles4games.com\>
 * @file        SimpleLib/Camera.h
 * @version     1.2.0 02-Jan-15
 * @copyright   Copyright (c) 2014-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 * @ingroup     simplelib
 */
#ifndef __SIMPLE_LIB_CAMERA_H__
#define __SIMPLE_LIB_CAMERA_H__

#include <glm/vec3.hpp>

namespace SimpleLib
{
    class Camera
    {
        public:
            Camera(void);
            Camera(const float positionX, const float positionY, const float positionZ, const float movementSpeed);
            virtual ~Camera(void);
            
            void moveLeft(const float speed=0.0f);
            void moveRight(const float speed=0.0f);
            void moveForward(const float speed=0.0f);
            void moveBackward(const float speed=0.0f);
            void moveUp(const float speed=0.0f);
            void moveDown(const float speed=0.0f);
        
            void update(void);
            
        public:
            inline void setPosition(const glm::vec3 position);
            inline glm::vec3 getPosition(void) const;
            inline void setMovementSpeed(const float movementSpeed);
            inline float getMovementSpeed(void) const;
            inline void setDirection(const glm::vec3 direction);
            inline glm::vec3 getDirection(void) const;
        
        private:
            float _movementSpeed;
            glm::vec3 _position;
            glm::vec3 _direction;
    };
}

#include <SimpleLib/Detail/CameraDetail.h>

#endif