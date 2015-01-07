#BachelorThesis

This project is part of my Bachelor Thesis. The subject is to transform a 2D Image into a 3D terrain.
It was build and tested on Mac OS X 10.7. But it might be easy to get it running on other platforms like Linux or Windows as well.

![Screenshot of the DemoApp render window](http://andysmiles4games.com/GitHub/Images/DemoApp-Screenshot.png "Screenshot of a generated terrain rendered with OpenGL")

##Branches

* **master** 
	* stores latest stable version
* **Dev**
	* stores latest development state but it's probably not stable nor those features're ready yet

I'm currently working only in the Dev branch because this project is still work in progress.
Not all features are implemented and neither it's a stable version. After each feature is right in place
and stable, it'll move to the **master** branch. So, the latest stable version will be always in the **master**
branch and all the latest features, bugfixes and so on will be in the **Dev** branch. 

**BE CAREFUL USING THE VERSION WITHIN DEV BRANCH!**

##Dependencies

This project is based on some frameworks and libraries. To get the source code compiled you have to install
those first. 

* *SFML Framework v2.1.x*
	* [http://www.sfml-dev.org/](http://www.sfml-dev.org/)
* *GLM Library v0.9.6.x* 
	* [http://glm.g-truc.net/](http://glm.g-truc.net/)
* OpenCV v2.0.x
	* [http://opencv.org/](http://opencv.org/)

##Build Project

This application will be created with a makefile in the terminal. There're several options to build your application.
A detail description how to do that is available here: [CppProjectTools](https://github.com/AndySmile/CppProjectTools#options)
To have a quick start is here a quick guide how to compile your project:

* Make sure that depencencies are installed and working on your machine
* Go to [YOUR_INSTALL_DIRECTORY]/BachelorThesis/DemoApp/
* Enter `make` inside your terminal
* If no error occurred you're able to start the application with `./DemoApp [PATH-TO-YOUR-INPUT-IMAGE]`

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