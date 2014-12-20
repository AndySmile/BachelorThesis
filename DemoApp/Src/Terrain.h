/**
 * @version		1.0.0 14-Dec-14
 * @copyright	Copyright (c) 2014 by Andy Liebke. All rights reserved.
 */
#ifndef __TERRAIN_H__
#define __TERRAIN_H__

class Terrain
{
	public:
    	Terrain(const unsigned short width, const unsigned short height, const unsigned short depth);
    	Terrain(const Terrain& src);
        virtual ~Terrain(void);
    
    	Terrain& operator = (const Terrain& src);
    
    	void setVoxelState(const char state, const unsigned short x, const unsigned short y, const unsigned short z);
    
    	void render(void) const;
    	void release(void);
    
    public:
    	unsigned short getWidth(void) const
   		{
        	return this->_width;
    	}
    
        unsigned short getHeight(void) const
        {
            return this->_height;
        }
        
        unsigned short getDepth(void) const
        {
            return this->_depth;
        }
    
	private:
    	void _renderVoxel(void) const;
    
    private:
    	unsigned char*** _chunk;
    	unsigned short _width;
    	unsigned short _height;
    	unsigned short _depth;
};

#endif