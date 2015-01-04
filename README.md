#BachelorThesis

This project is part of my Bachelor Thesis. 

##Branches

* master - stores latest stable version
* Dev - stores latest development state but it's probably not stable nor those features're ready yet

I'm currently working only in the Dev branch because this project is still work in progress.
Not all features are implemented and neither it's a stable version. After all features are right in place
and stable, it'll move to the master branch. So, the latest stable version will be always in the master
branch and all the latest features, bugfixes and so on will be in the Dev branch. 

**BE CAREFUL USING THE VERSION WITHIN DEV BRANCH!**

##Build project

This application will be created with a makefile in the terminal. So, open your terminal open to the DemoApp
or to one of the available prototype directories and enter:

	make
    
That's it. Assuming that all libraries are in place, it'll compile the entire project and you'll receive 
an executable within the project directory. Most of those applications doesn't need paramter to get them
started. For those you can enter:

	make start
    
In case that the application needs parameter, you'll receive an error message and you have to start it
directly.

##Unit Testing

This project includes test suites which will be compiled and executed with CppUnit. To do so just go to the
project directory within your terminal and enter:

	make test

That'll create a separated executable for unit testing and it'll start right after it was build. To be able to
run those tests it's necessary that you have CppUnit v.1.12.x installed.

You can find it here: [http://sourceforge.net/projects/cppunit/](http://sourceforge.net/projects/cppunit/)