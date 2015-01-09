/**
 * DemoApp - ImageTransformer Test Suite.
 *
 * @author      Andy Liebke<coding@andysmiles4games.com>
 * @version     1.1.0 09-Jan-15
 * @copyright   Copyright (c) 2014-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#include <Test/ImageTransformerTest.h>
#include <ImageTransformer.h>
#include <ImageProcessorHeightMap.h>

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

    void ImageTransformerTest::generateHeightMapTest(void)
    {
        ImageTransformer transformer("Resource/HeightMap_6.png");

        // no processor was assigned so no height map will be generated
        HeightMap* map = transformer.generateHeightMap();

        CPPUNIT_ASSERT(map == NULL);

        // after adding a processor a height map has to be generated
        transformer.addProcessor(new ImageProcessorHeightMap(20.0f));

        map = transformer.generateHeightMap();

        CPPUNIT_ASSERT(map != NULL);

        delete map;
        map = NULL;
    }
}