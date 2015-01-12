/**
 * SimpleLib - App Config Model.
 *
 * @author      Andy Liebke\<coding@andysmiles4games.com\>
 * @file        Src/AppConfig.cpp
 * @version     1.4.0 12-Jan-15
 * @copyright   Copyright (c) 2014-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 * @ingroup     simplelib
 */
#include <AppConfig.h>
#include <ImageProcessorHeightMap.h>
#include <ImageProcessorHistogramHeightMap.h>

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
            if (it->first.compare("enable_light") == 0)
            {
                config->isLightEnabled = (it->second == 1);
#ifdef _DEBUG
                SimpleLib::Logger::writeDebug("AppConfig: set light to %s", ((config->isLightEnabled) ? "ON" : "OFF"));
#endif
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
    float maxHeight = 0.0f;
    DataMap::iterator groupIterator = this->_data.find("image_processor_settings");

    if (groupIterator != this->_data.end())
    {
        for (DataMapItem::iterator it=groupIterator->second.begin(); it != groupIterator->second.end(); ++it)
        {
            if (it->first.compare("ImageProcessorHeightMap_MaxHeight") == 0)
            {
                maxHeight = (float)it->second;

#ifdef _DEBUG
                SimpleLib::Logger::writeDebug("AppConfig:: ImageProcessorHeightMap_MaxHeight set to %f", maxHeight);
#endif
            }
        }
    }

    groupIterator = this->_data.find("image_processor");

    if (groupIterator != this->_data.end())
    {
        for (DataMapItem::iterator it=groupIterator->second.begin(); it != groupIterator->second.end(); ++it)
        {
            if (it->first.compare("ImageProcessorHeightMap") == 0 && it->second == 1)
            {
#ifdef _DEBUG
                SimpleLib::Logger::writeDebug("AppConfig: Adding ImageProcessorHeightMap!");
#endif
                transformer->addProcessor(new ImageProcessorHeightMap(maxHeight));
            }
            else if (it->first.compare("ImageProcessorHeightMap") == 0 && it->second == 1)
            {
#ifdef _DEBUG
                SimpleLib::Logger::writeDebug("AppConfig: Adding ImageProcessorHistorgramHeightMap!");
#endif
                transformer->addProcessor(new ImageProcessorHistogramHeightMap());
            }
        }
    }
}

TerrainBuilder::TerrainType AppConfig::getTerrainType(void) const
{
    return TerrainBuilder::TypeMesh;
}