/*
Copyright (c) 2012 opamp

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <QApplication>
#include <QMessageBox>
#include <iostream>
#include "MainWindow.hpp"
#include "initialize.hpp"


int main(int argc,char** argv){
    QApplication mcswitch(argc,argv);

	mcswitch.setApplicationName(app_name);
    mcswitch.setApplicationVersion(app_ver);

    MainWindow* window = new MainWindow();

    if(!init()){ //Initialize if MCSwitch data dir is not initialized yet.
       std::cerr<<"ERROR::MCSwitch failed in initialization."<<std::endl;
       QMessageBox::critical(window, "ERROR", "Failed to initialize. You should delete all MCSwitch's data files and directory.");
       return 1;//error exit.
    }
    window->show();

	return mcswitch.exec();
}
