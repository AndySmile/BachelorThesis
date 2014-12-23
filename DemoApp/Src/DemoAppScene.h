/**
 * @version		1.2.0 23-Dec-14
 * @copyright	Copyright (c) 2014 by Andy Liebke. All rights reserved.
 */
#ifndef __DEMO_APP_SCENE_H__
#define __DEMO_APP_SCENE_H__

#include <SimpleLib/OpenGLSceneInterface.h>
#include <TerrainAbstract.h>

class DemoAppScene : public SimpleLib::OpenGLSceneInterface
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
    	inline void setImagePath(const std::string path);
    	inline void setConfigFilePath(const std::string path);
    
    private:
    	std::string _imagePath;
    	std::string _configFilePath;
    	TerrainAbstract* _terrain;
};

#include <Detail/DemoAppSceneDetail.h>

#endif