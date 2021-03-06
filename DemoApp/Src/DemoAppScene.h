/**
 * DemoApp - Scene Model.
 *
 * @author      Andy Liebke\<coding@andysmiles4games.com\>
 * @file        Src/DemoAppScene.h
 * @version     1.5.0 02-Jan-15
 * @copyright   Copyright (c) 2014-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 * @ingroup     demoapp
 */
#ifndef __DEMO_APP_SCENE_H__
#define __DEMO_APP_SCENE_H__

#include <SimpleLib/OpenGLSceneInterface.h>
#include <SimpleLib/Camera.h>
#include <TerrainAbstract.h>
#include <AppConfig.h>

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
        inline void enableLight(const bool isEnabled=true);
        inline void setAppConfig(AppConfig* config);
    
    private:
        bool _isLightEnabled;
        std::string _imagePath;
        std::string _configFilePath;
        TerrainAbstract* _terrain;
        AppConfig* _config;
        SimpleLib::Camera* _camera;
        SceneConfigParameter _sceneConfig;
};

#include <Detail/DemoAppSceneDetail.h>

#endif