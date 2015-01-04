#BachelorThesis

This project is part of my Bachelor Thesis. It was build and tested on Mac OS X 10.7. But it might be
easy to get it running on other platforms like Linux or Windows as well. 

##Branches

* **master** 
	* stores latest stable version
* **Dev**
	* stores latest development state but it's probably not stable nor those features're ready yet

I'm currently working only in the Dev branch because this project is still work in progress.
Not all features are implemented and neither it's a stable version. After all features are right in place
and stable, it'll move to the master branch. So, the latest stable version will be always in the master
branch and all the latest features, bugfixes and so on will be in the Dev branch. 

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

##Build project

This application will be created with a makefile in the terminal. There're several options to build your application.
How to do that can you find here: [https://github.com/AndySmile/CppProjectTools#options](CppProjectTools)

##Unit Testing

This project includes test suites which will be compiled and executed with CppUnit. To do so just go to the
project directory within your terminal and enter:

	make test

That'll create a separated executable for unit testing and it'll start right after it was build. To be able to
run those tests it's necessary that you have CppUnit v.1.12.x installed.

You can find it here: [http://sourceforge.net/projects/cppunit/](http://sourceforge.net/projects/cppunit/)