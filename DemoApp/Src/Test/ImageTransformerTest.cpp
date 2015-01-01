/**
 * @version     1.0.0 23-Dec-14
 * @copyright   Copyright (c) 2014-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#include <Test/ImageTransformerTest.h>
#include <ImageTransformer.h>

/**
 * DemoApp UnitTest Namespace.
 *
 * This namespace includes all test cases.
 */
namespace DemoAppTest
{
    /**
     * Tests setter and getter for image file path.
     */
    void ImageTransformerTest::setImageFilePathTest(void)
    {
        ImageTransformer transformer;
        
        std::string path = transformer.getImageFilePath();
        
        CPPUNIT_ASSERT(path.empty());
        
        transformer.setImageFilePath("test/path/to/image.png");
        
        path = transformer.getImageFilePath();
        
        CPPUNIT_ASSERT(!path.empty());
        CPPUNIT_ASSERT(path.compare("test/path/to/image.png") == 0);
    }
}