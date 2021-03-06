/**
 * @version     1.2.0 09-Jan-15
 * @copyright   Copyright (c) 2014-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#ifndef __APP_CONFIG_H__
#define __APP_CONFIG_H__

#include <SimpleLib/SimpleLib.h>
#include <SimpleLib/DataCollection.h>
#include <TerrainBuilder.h>
#include <ImageTransformer.h>

typedef struct _scene_config_parameter
{
    bool isLightEnabled;
} SceneConfigParameter;

class AppConfig : public SimpleLib::DataCollection
{
    public:
        AppConfig(void);
        virtual ~AppConfig(void);

        void assignProcessors(ImageTransformer* transformer);
        TerrainBuilder::TerrainType getTerrainType(void) const;
        void assignSceneConfig(SceneConfigParameter* config);
};

#endif