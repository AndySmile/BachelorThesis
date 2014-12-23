/**
 * @version		1.0.0 23-Dec-14
 * @copyright	Copyright (c) 2014 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#ifndef __IMAGE_TRANSFORMER_TEST_H__
#define __IMAGE_TRANSFORMER_TEST_H__

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/TestCase.h>

/**
 * DemoApp UnitTest Namespace.
 *
 * This namespace includes all test cases.
 */
namespace DemoAppTest
{
	class ImageTransformerTest : public CppUnit::TestFixture
    {
        public:
            CPPUNIT_TEST_SUITE(ImageTransformerTest);
            CPPUNIT_TEST(setImageFilePathTest);
            CPPUNIT_TEST_SUITE_END();
        
        public:
            /**
             * Tests setter and getter for image file path.
             */
        	void setImageFilePathTest(void);
    };
}
#endif