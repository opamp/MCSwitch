MCSwitch   
========

## Qt5  
開発環境をQt5に移行中です。開発環境が十分に構築できるまでしばらく完全に更新がストップすると思います。  
Qt5はインストール済みですが、CMakeのほうがちょっとまだよくわかってない状況です。  
まあ、元々そんないいペースで進んでなかったけど...   
   
## About   
MCSwitch provides you with environment to play plural minecraft versions. But,Now It supports a mac only.  
I'm considering also about other platform support.  


## Note  
##### version 0.0.1  

	*First release.  
	*MCSwitch is released under a MIT License.   
	*There are many bugs.  
	*This is in development.

## Dependencies   
   
[Qt](http://qt.nokia.com/)  
License is [LGPLv2](http://www.gnu.org/licenses/lgpl-2.1.html)  

If you will build this application from source,you have to install [CMake](http://www.cmake.org/).  


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


## License  
MCSwitch is released under a MIT License.   
See also LICENSE.txt   
