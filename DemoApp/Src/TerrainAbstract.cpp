/**
 * DempApp - Abstract Grid Terrain Model.
 *
 * @author		Andy Liebke\<coding@andysmiles4games.com\>
 * @file		Src/AbstractTerrain.cpp
 * @version		1.0.0 23-Dec-14
 * @copyright	Copyright (c) 2014 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#include <TerrainAbstract.h>

TerrainAbstract::TerrainAbstract(const unsigned short width, const unsigned short height, const unsigned short depth) :
    _width(width),
    _height(height),
    _depth(depth)
{
	
}

TerrainAbstract::~TerrainAbstract(void)
{
    this->_width 	= 0;
    this->_height	= 0;
    this->_depth	= 0;
}