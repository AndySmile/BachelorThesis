/**
 * SimpleLib - App Config Model.
 *
 * @author      Andy Liebke\<coding@andysmiles4games.com\>
 * @file        Src/AppConfig.cpp
 * @version     1.2.9 09-Jan-15
 * @copyright   Copyright (c) 2014-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 * @ingroup     simplelib
 */
#include <AppConfig.h>

#ifdef _DEBUG
    #include <SimpleLib/Logger.h>
#endif

AppConfig::AppConfig(void)
{
    
}

AppConfig::~AppConfig(void)
{
    
}

void AppConfig::assignSceneConfig(SceneConfigParameter* config)
{
    DataMap::iterator groupIterator = this->_data.find("scene");
    
    if (groupIterator != this->_data.end())
    {
        for (DataMapItem::iterator it=groupIterator->second.begin(); it != groupIterator->second.end(); ++it)
        {
            if (it->first.compare("enable_light") == 0) {
                config->isLightEnabled = (it->second == 1);
            }
#ifdef _DEBUG
            else {
                SimpleLib::Logger::writeDebug("Skipped configuration item '%s' in group 'scene'!", it->first.c_str());
            }
#endif
        }
    }
}

void AppConfig::assignProcessors(ImageTransformer* transformer)
{
    
}

TerrainBuilder::TerrainType AppConfig::getTerrainType(void) const
{
    return TerrainBuilder::TypeMesh;
}