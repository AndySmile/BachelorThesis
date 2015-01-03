/**
 * @version     1.0.0 03-Jan-15
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

ImageTransformer* TerrainBuilder::getImageTransformer(void) const
{
    return this->_transformer;
}

void TerrainBuilder::setTerrainEnvironmentDescriptor(TerrainEnvironmentDescriptor* descriptor)
{
    this->_descriptor = descriptor;
}

void TerrainBuilder::setTerrainDecorator(TerrainDecorator* decorator)
{
    this->_decorator = decorator;
}

TerrainDecorator* TerrainBuilder::getTerrainDecorator(void) const
{
    return this->_decorator;
}