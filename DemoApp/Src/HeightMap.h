/**
 * DemoApp - Height Map Model Header.
 *
 * Basically this is a class to manage a 1D array like a 2D array.
 * Within this project it'll be used to manage data of a height map.
 *
 * @author      Andy Liebke<coding@andysmiles4games.com>
 * @file        Src/HeightMap.h
 * @version     1.1.0 09-Jan-15
 * @copyright   Copyright (c) 2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#ifndef __HEIGHT_MAP_H__
#define __HEIGHT_MAP_H__

class HeightMap
{
    public:
        HeightMap(const unsigned int width, const unsigned int height);
        HeightMap(void);
        HeightMap(const HeightMap& src);
        virtual ~HeightMap(void);

        HeightMap& operator = (const HeightMap& src);

        void resize(const unsigned int width, const unsigned int height);
        void setHeight(const float height, const unsigned int x, const unsigned int y);
        float getHeight(const unsigned int x, const unsigned int y) const;
        void release(void);

    public:
        inline unsigned int getWidth(void) const;
        inline unsigned int getHeight(void) const;
        inline unsigned int getSize(void) const;

    private:
        bool _initMap(void);

    private:
        float* _data;
        unsigned int _width;
        unsigned int _height;
};

#include <Detail/HeightMapDetail.h>

#endif