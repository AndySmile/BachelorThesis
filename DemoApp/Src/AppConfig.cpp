/**
 * @version		1.1.1 28-Dec-14
 * @copyright	Copyright (c) by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
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
                SimpleLib::Logger::writeDebug("Skipped configuration item '" + it->first + "' in group 'scene'!");
            }
#endif
        }
    }
}

void AppConfig::assignProcessors(ImageTransformer* transformer)
{
    
}

ImageTransformer::TerrainType AppConfig::getTerrainType(void) const
{
    return ImageTransformer::MeshTerrain;
}