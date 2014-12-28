/**
 * @version             1.0.0 03-Aug-14
 * @copyright   Copyright (c) 2014 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#ifndef __CAMERA_H__
#define __CAMERA_H__

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
                        
                        void setPosition(const glm::vec3 position)
                        {
                                this->_position = position;
                        }
                        
                        glm::vec3 getPosition(void) const
                        {
                                return this->_position;
                        }
                        
                private:
                        glm::vec3 _position;
        };
}

#endif