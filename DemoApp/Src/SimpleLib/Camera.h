/**
 * SimpleLib - Camera Model.
 *
 * @author      Andy Liebke\<coding@andysmiles4games.com\>
 * @file        SimpleLib/Camera.h
 * @version     1.1.0 23-Dec-14
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
            virtual ~Camera(void);
            
            void moveLeft(const float speed);
            void moveRight(const float speed);
            void moveForward(const float speed);
            void moveBackward(const float speed);
            
            void update(void);
            
        public:
            inline void setPosition(const glm::vec3 position);
            inline glm::vec3 getPosition(void) const;
            
        private:
            glm::vec3 _position;
    };
}

#include <SimpleLib/Detail/CameraDetail.h>

#endif