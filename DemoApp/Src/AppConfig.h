/**
 * @version		1.0.0 26-Dec-14
 * @copyright	Copyright (c) by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#ifndef __APP_CONFIG_H__
#define __APP_CONFIG_H__

#include <SimpleLib/SimpleLib.h>
#include <SimpleLib/DataCollection.h>
#include <ImageTransformer.h>

class AppConfig : public SimpleLib::DataCollection
{
	public:
    	AppConfig(void);
    	virtual ~AppConfig(void);

		void assignScreenValues(SimpleLib::ConfigParameter* config);
    	void assignProcessors(ImageTransformer* transformer);
    	ImageTransformer::TerrainType getTerrainType(void);
};

#endif