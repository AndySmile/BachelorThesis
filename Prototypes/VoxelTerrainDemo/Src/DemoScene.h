/**
 * @version		1.3.0 04-Dec-14
 * @copyright	Copyright (c) 2014 by Andy Liebke. All rights reserved. 
 */
#ifndef __DEMO_SCENE_H__
#define __DEMO_SCENE_H__

#include <SimpleLib/IOpenGLScene.h>
#include <VoxelChunk.h>

class DemoScene : public SimpleLib::IOpenGLScene
{
	public:
		DemoScene(void);
		virtual ~DemoScene(void);
		
		void init(void);
		void update(const float currTime);
		void render(sf::Window& window);
		void release(void);
		
		std::string getTitle(void);
		
	private:
		void _createFromHeightMap(void);
		void _createPyramid(void);	
		
	private:
		VoxelChunk* _voxelChunk;
};

#endif