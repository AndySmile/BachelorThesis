/**
 * @version		1.2.0 23-Dec-14
 * @copyright	Copyright (c) 2014 by Andy Liebke. All rights reserved.
 */
#ifndef __IMAGE_TRANSFORMER_H__
#define __IMAGE_TRANSFORMER_H__

#include <ImageProcessorInterface.h>
#include <TerrainAbstract.h>
#include <vector>
#include <string>

class ImageTransformer
{
    public:
    	ImageTransformer(const std::string imageFilePath);
    	ImageTransformer(void);
    	virtual ~ImageTransformer(void);
    
    public:
    	enum TerrainType
        {
        	VoxelTerrain = 1,
            MeshTerrain = 2
        };
    
    public:
        void addProcessor(ImageProcessorInterface* processor);
        TerrainAbstract* generateTerrain(TerrainType type);
        void release(void);
    
    public:
    	inline void setImageFilePath(const std::string imageFilePath);
    	inline std::string getImageFilePath(void) const;
    
    private:
    	typedef std::vector<ImageProcessorInterface*> ListImageProcessors;
    	typedef ListImageProcessors::iterator ImageProcessorsIterator;
    
	private:
		ListImageProcessors _listProcessors;
    	std::string _imageFilePath;
};

#include <Detail/ImageTransformerDetail.h>

#endif