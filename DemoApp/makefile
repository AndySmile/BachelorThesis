##
# C++ Project Makefile.
#
# LICENSE FOR THIS MAKEFILE:
#
#	The MIT License (MIT)
#
#	Copyright (c) 2013-2015 by Andy Liebke. All rights reserved.
#
#	Permission is hereby granted, free of charge, to any person obtaining a copy
#	of this software and associated documentation files (the "Software"), to deal
#	in the Software without restriction, including without limitation the rights
#	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
#	copies of the Software, and to permit persons to whom the Software is
#	furnished to do so, subject to the following conditions:
#
#	The above copyright notice and this permission notice shall be included in
#	all copies or substantial portions of the Software.
#
#	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
#	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
#	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
#	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
#	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
#	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
#	THE SOFTWARE.
#
# @author		Andy Liebke<coding@andysmiles4games.com>
# @version		1.6.0 03-Jan-15
# @copyright	Copyright (c) 2013-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
#

APP_TITLE = DemoApp
LIST_OBJECTS_COMMON =	Tmp/DemoAppScene.o \
						Tmp/TerrainAbstract.o \
						Tmp/TerrainVoxel.o \
						Tmp/TerrainMesh.o \
                        Tmp/TerrainBuilder.o \
                        Tmp/TerrainEnvironmentDescriptor.o \
                        Tmp/TerrainDecorator.o \
                        Tmp/TerrainDescriptorWater.o \
						Tmp/ImageProcessorHeightMap.o \
						Tmp/ImageProcessorWater.o \
                        Tmp/ImageProcessorHistogramHeightMap.o \
						Tmp/ImageTransformer.o \
						Tmp/AppConfig.o \
						Tmp/SimpleLib/Application.o \
						Tmp/SimpleLib/Camera.o \
						Tmp/SimpleLib/OpenGLHelper.o \
						Tmp/SimpleLib/DataCollection.o \
						Tmp/SimpleLib/Logger.o 

LIST_OBJECTS_APP = Tmp/DemoAppMain.o
LIST_OBJECTS_TEST = Tmp/Test/TestMain.o \
					Tmp/Test/ImageTransformerTest.o \
                    Tmp/Test/TerrainBuilderTest.o \
                    Tmp/Test/TerrainEnvironmentDescriptorTest.o \
                    Tmp/Test/TerrainDescriptorWaterTest.o \
					Tmp/Test/SimpleLib/DataCollectionTest.o
						
DEBUG_SETTINGS =  -g -D_DEBUG
COMMON_SETTINGS = $(DEBUG_SETTINGS) -Weffc++ -Wall -I Src/ -I ../Lib/ -arch i386
COMMON_TEST_SETTINGS = -D_UNITTEST $(COMMON_SETTINGS)
LINKER_SETTINGS = -framework OpenCV -framework sfml-window -framework sfml-system -framework sfml-graphics -framework OpenGL
LINKER_TEST_SETTINGS = -lcppunit
		
.PHONY: build-executable
build-executable: $(LIST_OBJECTS_COMMON) $(LIST_OBJECTS_APP)
	g++ $(COMMON_SETTINGS) $(LINKER_SETTINGS) -o $(APP_TITLE) $^
	
Tmp/Test/%.o: Src/Test/%.cpp
	@mkdir -p $(dir $@)
	g++ $(COMMON_TEST_SETTINGS) -c $^ -o $@

Tmp/%.o: Src/%.cpp
	@mkdir -p $(dir $@)
	g++ $(COMMON_SETTINGS) -c $^ -o $@ 

.PHONY: test
test: $(LIST_OBJECTS_COMMON) $(LIST_OBJECTS_TEST) 
	@g++ $(COMMON_TEST_SETTINGS) $(LINKER_SETTINGS) $(LINKER_TEST_SETTINGS) -o $(APP_TITLE)Test $^
	@echo "Running test cases..."
	@./$(APP_TITLE)Test

.PHONY: start
start:
	@./$(APP_TITLE)

.PHONY: clean
clean:
	rm -rf Tmp/
	rm -f $(APP_TITLE)
	rm -f $(APP_TITLE)Test
	
.PHONY: leakcheck
leakcheck:
	rm -f *.log
	rm -rf *.dSYM
	valgrind --leak-check=full -v --track-origins=yes --log-file=$(APP_TITLE)-Mem.log --dsymutil=yes ./$(APP_TITLE)