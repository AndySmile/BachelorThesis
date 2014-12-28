/**
 * @version     1.0.0 21-Dec-14
 * @copyright   Copyright (c) 2014 by Andy Liebke. All rights reserved. 
 */
#ifndef __DEMO_SCENE_H__
#define __DEMO_SCENE_H__

#include <SimpleLib/IOpenGLScene.h>
#include <vector>
#include <glm/vec3.hpp>

typedef std::vector<glm::vec3> ListVertices;
typedef ListVertices::iterator ListVerticesIterator;

class DemoScene : public SimpleLib::IOpenGLScene
{
    public:
        DemoScene(void);
        virtual ~DemoScene(void);
        
        void init(void);
        void update(const float currTime);
        void render(sf::Window& window);
        void release(void);
        
        std::string getTitle(void) const;
    
    private:
        void _createFromHeightMap(void);
        void _printError(void);
    
    private:
        ListVertices _listVertices;
        unsigned int _meshId;
};

#endif