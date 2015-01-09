/**
 * 
 * @version     2.2.0 09-Jan-15
 * @copyright   Copyright (c) 2014-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */

unsigned short TerrainAbstract::getWidth(void) const
{
    return this->_width;
}

unsigned short TerrainAbstract::getHeight(void) const
{
    return this->_height;
}

unsigned short TerrainAbstract::getDepth(void) const
{
    return this->_depth;
}

void TerrainAbstract::setUnitLength(const float unitLength)
{
    this->_unitLength = unitLength;
}

float TerrainAbstract::getUnitLength(void) const
{
    return this->_unitLength;
}

void TerrainAbstract::setSize(unsigned short width, unsigned short height, unsigned short depth)
{
    this->_width    = width;
    this->_height   = height;
    this->_depth    = depth;
}