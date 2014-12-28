/**
 * @version				1.1.0 04-Dec-14
 * @copyright	Copyright (c) 2014 by Andy Liebke. All rights reserved.
 */
#ifndef __VOXEL_CHUNK_H__
#define __VOXEL_CHUNK_H__

class VoxelChunk
{
		public:
				VoxelChunk(const unsigned short width, const unsigned short height, const unsigned short depth);
				virtual ~VoxelChunk(void);
				
				void render(void);
				void release(void);
				
				void setVoxelState(const char state, const unsigned short x, const unsigned short y, const unsigned short z);
				
		private:
				void _renderVoxel(void);		
				
		private:
				unsigned char*** _chunk;
				unsigned short _width;
				unsigned short _height;
				unsigned short _depth;
				unsigned short _voxelMeshId;
};

#endif