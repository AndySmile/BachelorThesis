/**
 * @version		1.0.0 26-Dec-14
 * @copyright	Copyright (c) by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#include <AppConfig.h>

#ifdef _DEBUG
	#include <iostream>
#endif

AppConfig::AppConfig(void)
{
    
}

AppConfig::~AppConfig(void)
{
    
}

void AppConfig::assignScreenValues(SimpleLib::ConfigParameter* config)
{
	DataMap::iterator groupIterator = this->_data.find("scene");

	if (groupIterator != this->_data.end())
    {
    	for (DataMapItem::iterator it=groupIterator->second.begin(); it != groupIterator->second.end(); ++it) {
        	if (it->first.compare("screen_width") == 0) {
                config->screenWidth = it->second;
            }
            else if (it->first.compare("screen_height") == 0) {
                config->screenHeight = it->second;
            }
            else if (it->first.compare("fullscreen") == 0) {
                config->screenHeight = it->second;
            }
#ifdef _DEBUG
			else {
            	std::cout << "[DEBUG] skipped configuration item '" << it->first << "'!" << std::endl;
            }
#endif
        }
    }
}

void AppConfig::assignProcessors(ImageTransformer* transformer)
{
    
}

ImageTransformer::TerrainType AppConfig::getTerrainType(void)
{
    return ImageTransformer::MeshTerrain;
}