/**
 * @version		1.0.0 14-Dec-14
 * @copyright	Copyright (c) 2014 by Andy Liebke. All rights reserved.
 */
#ifndef __DEMO_APP_SCENE_H__
#define __DEMO_APP_SCENE_H__

#include <SimpleLib/IOpenGLScene.h>
#include <Terrain.h>

class DemoAppScene : public SimpleLib::IOpenGLScene
{
	public:
    	DemoAppScene(void);
    	DemoAppScene(const DemoAppScene& src);
    	virtual ~DemoAppScene(void);
    
    	DemoAppScene& operator = (const DemoAppScene& src);
    
        void init(void);
        void update(const float currTime);
        void render(sf::Window& window);
        void release(void);
        
        std::string getTitle(void) const;
    
    public:
    	void setImagePath(const std::string path)
        {
           this->_imagePath = path;
        }
    
    	void setConfigFilePath(const std::string path)
    	{
        	this->_configFilePath = path;
        }
    
    private:
    	std::string _imagePath;
    	std::string _configFilePath;
    	Terrain* _terrain;
};

#endif