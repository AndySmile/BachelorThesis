/**
 * @version     1.1.0 23-Dec-14
 * @copyright   Copyright (c) 2014-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
 
void ImageTransformer::setImageFilePath(const std::string imageFilePath)
{
    this->_imageFilePath = imageFilePath;
}

std::string ImageTransformer::getImageFilePath(void) const
{
    return this->_imageFilePath;
}