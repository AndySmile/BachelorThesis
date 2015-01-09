/**
 * DemoApp - UnitTest Main.
 *
 * @author      Andy Liebke<coding@andysmiles4games.com>
 * @version     1.5.0 09-Jan-15
 * @copyright   Copyright (c) 2014-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#include <cppunit/ui/text/TestRunner.h> 
#include <Test/ImageTransformerTest.h>
#include <Test/SimpleLib/DataCollectionTest.h>
#include <Test/TerrainBuilderTest.h>
#include <Test/TerrainEnvironmentTest.h>
#include <Test/TerrainDescriptorWaterTest.h>
#include <Test/EntityAbstractTest.h>
#include <Test/HeightMapTest.h>
#include <SimpleLib/Logger.h>
#include <cstdlib>

int main(void)
{
    // initilizes logger otherwise no message will appear
    SimpleLib::Logger::init(SimpleLib::Logger::Console);

    CppUnit::TextTestRunner runner;
    
    runner.addTest(DemoAppTest::ImageTransformerTest::suite());
    runner.addTest(DemoAppTest::DataCollectionTest::suite());
    runner.addTest(DemoAppTest::TerrainEnvironmentTest::suite());
    runner.addTest(DemoAppTest::TerrainBuilderTest::suite());
    runner.addTest(DemoAppTest::TerrainDescriptorWaterTest::suite());
    runner.addTest(DemoAppTest::EntityAbstractTest::suite());
    runner.addTest(DemoAppTest::HeightMapTest::suite());
    
    return (runner.run()) ? EXIT_SUCCESS : EXIT_FAILURE;
}