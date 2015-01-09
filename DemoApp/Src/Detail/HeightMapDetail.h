/**
 * @version     1.0.0 08-Jan-15
 * @copyright   Copyright (c) 2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */

unsigned int HeightMap::getWidth(void) const
{
    return this->_width;
}

unsigned int HeightMap::getHeight(void) const
{
    return this->_height;
}

unsigned int HeightMap::getSize(void) const
{
    return this->_width * this->_height;
}