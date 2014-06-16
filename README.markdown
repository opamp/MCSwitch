MCSwitch  
========
  
## About   
MCSwitch provides environment for you to play plural minecraft versions.   

	I think this application is not useful any longer.  
	Please run uninstall.sh script if you want to uninstall it.  
	However, you can use it even now.  


![alt text](https://dl.dropboxusercontent.com/u/23369413/pictures/MCSwitch/MCSwitch_sc.png)   

## How to use  
1.You have to start minecraft once before installing MCSwitch.  
2.Install MCSwtich and start it.  
3.Select your environment which you want play.  
3.Or, you can add new environment.  
4.Push OK button.  
5.Close MCSwtich and launch minecraft!  
   
## Note  
##### version 0.4.0 plan

	* Support both osx and linux.

##### version 0.3.1  

	* Fix critical bug  


## Dependencies   
   
[Qt5](http://qt.nokia.com/)  
License is [LGPLv2](http://www.gnu.org/licenses/lgpl-2.1.html)  
You can build it if you rewrite CMakeLists.txt for Qt4.

If you will build this application from source code,you have to install [CMake](http://www.cmake.org/).  


## Compiling from source code.

I think you might as well imitate general cmake way.   


##### Clone my source  
Run this command...

	$ git clone git://github.com/opamp/MCSwitch.git  

and go in cloned directory.   
Would you like to compile dev version?  
You can build from dev branch. Please switch to dev branch.

##### Run cmake   
First,make a directory for work.  

	$ mkdir build  

Second,run cmake command. Please also attach options to command if necesarry.  

	$ cmake ../  

※ CMake will generate a GNU Makefile.  
##### execute gnu make command  

	$ make  

## Uninstall it  
Run uninstall.sh from your terminal.  

    $ ./uninstall.sh

## License  
MCSwitch is released under a MIT License.   
See also LICENSE.txt   
