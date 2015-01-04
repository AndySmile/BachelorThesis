#Third Party Libraries And Frameworks

This directory actually includes third party libraries/frameworks.
But to prevent trouble with those licenses of each library/frameworks, I've decided to not add them in
this repository. So, if you want to compile those applications, go to
those following websites and install all dependencies:

##Global Installation

Those libraries/frameworks have to be installed globally on your machine. Those haven't be installed
within this directory, otherwise you have to edit those makefiles that all include and library files
will be found.

* SFML Framework v2.1.x - [http://www.sfml-dev.org/](http://www.sfml-dev.org/)
* OpenCV v2.0.0 - [http://opencv.org/](http://opencv.org/)

##Local Installation

This library has to be installed within this directory otherwise the compiler isn't able to 
find all needed header and library files during creating the executable.

* GLM Library v0.9.6.1 - [http://glm.g-truc.net/](http://glm.g-truc.net/)