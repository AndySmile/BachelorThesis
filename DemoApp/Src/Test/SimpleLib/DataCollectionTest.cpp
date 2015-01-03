/**
 * @version     1.0.1 03-Jan-15
 * @copyright   Copyright (c) 2014-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#include <Test/SimpleLib/DataCollectionTest.h>
#include <SimpleLib/DataCollection.h>

/**
 * DemoApp UnitTest Namespace.
 *
 * This namespace includes all test cases.
 */
namespace DemoAppTest
{
    void DataCollectionTest::loadDataFromFileTest(void)
    {
        SimpleLib::DataCollection data;
        
        // first we test if it behaves in the right way if no valid parameter was given!
        SimpleLib::DataCollection::ErrorCode result = data.loadFromFile("");
        
        CPPUNIT_ASSERT(result == SimpleLib::DataCollection::InvalidParameter);
        
        // second we test if it fails in the right way!
        result = data.loadFromFile("FileNotExits.cfg");
        
        CPPUNIT_ASSERT(result == SimpleLib::DataCollection::FileIsNotReadable);
        
        // third we test if it finally loads a real data file!
        result = data.loadFromFile("LoadingTest.cfg");
        
        CPPUNIT_ASSERT(result == SimpleLib::DataCollection::None);
    }

    void DataCollectionTest::accessDataTest(void)
    {
        SimpleLib::DataCollection data;
        
        // no data were loaded yet, so the result have to be 0
        int screenWidth = data.getValue("window", "screen_width");
        
        CPPUNIT_ASSERT(screenWidth == 0);
        
        SimpleLib::DataCollection::ErrorCode result = data.loadFromFile("LoadingTest.cfg");
        
        CPPUNIT_ASSERT(result == SimpleLib::DataCollection::None);
        
        screenWidth = data.getValue("window", "screen_width");
        
        CPPUNIT_ASSERT(screenWidth != 0);
        CPPUNIT_ASSERT(screenWidth == 1024);
    }
}