#BachelorThesis

This project is part of my Bachelor Thesis. The subject is to transform a 2D Image into a 3D terrain.
It was build and tested on Mac OS X 10.7. But it might be easy to get it running on other platforms like Linux or Windows as well.

##Branches

* **master** 
	* stores latest stable version
* **Dev**
	* stores latest development state but it's probably not stable nor those features're ready yet

I'm currently working only in the **Dev** branch because this project is still work in progress.
Not all features are implemented and neither it's a stable version. After each feature is right in place
and stable, it'll move to the **master** branch. So, the latest stable version will be always in the **master**
branch and all the latest features, bugfixes and so on will be in the **Dev** branch. 

**BE CAREFUL USING THE VERSION WITHIN DEV BRANCH!**

##File Structure
- *DempApp*
	- Stores main demo application that includes all final features.
- *Lib*
	- Stores libraries/frameworks the DemoApp and all prototype depending on.
- *Prototypes*
	- Stores all prototype applications.

##Dependencies

This project is based on some frameworks and libraries. To get the source code compiled you have to install
those first. 

* *SFML Framework v2.1.x*
	* [http://www.sfml-dev.org/](http://www.sfml-dev.org/)
* *GLM Library v0.9.6.x* 
	* [http://glm.g-truc.net/](http://glm.g-truc.net/)
* OpenCV v2.0.x
	* [http://opencv.org/](http://opencv.org/)