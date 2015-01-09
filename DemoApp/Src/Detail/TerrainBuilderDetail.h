/**
 * @version     1.1.0 08-Jan-15
 * @copyright   Copyright (c) 2014-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */

void TerrainBuilder::setTerrainType(const TerrainBuilder::TerrainType type)
{
    this->_type = type;
}

TerrainBuilder::TerrainType TerrainBuilder::getTerrainType(void) const
{
    return this->_type;
}
