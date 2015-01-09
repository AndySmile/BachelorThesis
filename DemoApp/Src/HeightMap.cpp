/**
 * @version     1.1.0 09-Jan-15
 * @copyright   Copyright (c) 2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#include <HeightMap.h>
#include <cstddef>

#ifdef _DEBUG
    #include <SimpleLib/Logger.h>
#endif

HeightMap::HeightMap(const unsigned int width, const unsigned int height) :
    _data(NULL),
    _width(width),
    _height(height)
{
    this->_initMap();
}

HeightMap::HeightMap(void) :
    _data(NULL),
    _width(0),
    _height(0)
{

}

HeightMap::HeightMap(const HeightMap& src) :
    _data(NULL),
    _width(src._width),
    _height(src._height)
{
#ifdef _DEBUG
    SimpleLib::Logger::writeDebug("HeightMap: call copy constructor!");
#endif

    if (src._data != NULL) {
        memcpy(this->_data, src._data, this->_width * this->_height * sizeof(float));
    }
}

HeightMap::~HeightMap(void)
{
    this->_width    = 0;
    this->_height   = 0;
}

HeightMap& HeightMap::operator = (const HeightMap& src)
{
#ifdef _DEBUG
    SimpleLib::Logger::writeDebug("HeightMap: call assignment operator!");
#endif

    this->_width    = src._width;
    this->_height   = src._height;

    if (src._data != NULL) {
        memcpy(this->_data, src._data, this->_width * this->_height * sizeof(float));
    }
    else {
        this->_data = NULL;
    }
    
    return *this;
}

void HeightMap::resize(const unsigned int width, const unsigned int height)
{
#ifdef _DEBUG
    SimpleLib::Logger::writeDebug("resize map from [%d, %d] to [%d, %d]", this->_width, this->_height, width, height);
#endif
    this->_width    = width;
    this->_height   = height;

    if (!this->_initMap())
    {
#ifdef _DEBUG
        SimpleLib::Logger::writeDebug("copy data to new map [%d, %d]", this->_width, this->_height);
#endif
        float* newMap = new float[this->_width * this->_height];

        memcpy(newMap, this->_data, this->_width * this->_height * sizeof(float));

        delete[] this->_data;
        
        this->_data = newMap;
    }
}

void HeightMap::setHeight(const float height, const unsigned int x, const unsigned int y)
{
    if (this->_data != NULL && x < this->_width && y < this->_height) {
        this->_data[(this->_width * y) + x] = height;
    }
}

float HeightMap::getHeight(const unsigned int x, const unsigned int y) const
{
    return (this->_data != NULL && x < this->_width && y < this->_height) ? this->_data[(this->_width * y) + x] : 0.0f;
}

void HeightMap::release(void)
{
    if (this->_data != NULL)
    {
        delete[] this->_data;
        this->_data = NULL;
    }
}

bool HeightMap::_initMap(void)
{
    if (this->_data == NULL)
    {
#ifdef _DEBUG
        SimpleLib::Logger::writeDebug("Initialize height map with size of %d, %d", this->_width, this->_height);
#endif
        this->_data = new float[this->_width * this->_height];

        memset(this->_data, 0, this->_width * this->_height * sizeof(float));

        return true;
    }

    return false;
}