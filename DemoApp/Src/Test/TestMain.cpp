/**
 * @version		1.0.0 23-ec-14
 * @copyright	Copyright (c) 2014 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#include <cppunit/ui/text/TestRunner.h> 
#include <Test/ImageTransformerTest.h>
#include <stdlib.h>

int main(void)
{
	CppUnit::TextTestRunner runner;
	runner.addTest(DemoAppTest::ImageTransformerTest::suite());
	runner.run();
    
    return EXIT_SUCCESS;
}