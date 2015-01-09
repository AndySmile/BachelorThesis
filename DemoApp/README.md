#DemoApp

This is the main application of my Bachelor Thesis. It transforms a 2D image to a 3D terrain. 

![Screenshot of the DemoApp render window](http://andysmiles4games.com/GitHub/Images/DemoApp-Screenshot-Terrain.png "Screenshot of a generated terrain rendered with OpenGL")

##Build Project

This application will be created with a makefile in the terminal. There're several options to build your application.
A detail description how to do that is available here: [CppProjectTools](https://github.com/AndySmile/CppProjectTools#options)
To have a quick start is here a quick guide how to compile your project:

1. Make sure that depencencies are installed and working on your machine
2. Go to [YOUR_INSTALL_DIRECTORY]/BachelorThesis/DemoApp/
3. Enter `make` inside your terminal
4. If no error occurred you're able to start the application with `./DemoApp [PATH-TO-YOUR-INPUT-IMAGE]`

##Control Schema

You can control the view camera by your keyboard. That's the keyboard schema for that:

* A - Moving in the left direction
* D - Moving in the right direction
* W - Moving forward
* S - Moving backward
* Q - Moving up
* E - Moving down
* Left Arrow Key - Moving view direction to the left
* Right Arrow Key - Moving view direction to the right

##Unit Testing

This project includes test suites which will be compiled and executed with CppUnit. To do so just go to the
project directory within your terminal and enter:

	make test

That'll create a separated executable for unit testing and it'll start right after it was build. To be able to
run those tests it's necessary that you have CppUnit v.1.12.x installed.

You can find it here: [http://sourceforge.net/projects/cppunit/](http://sourceforge.net/projects/cppunit/)