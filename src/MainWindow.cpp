#include"MainWindow.hpp"
#include<QAction>
#include<QMenuBar>
#include<QFile>

#include"version.hpp"


MainWindow::MainWindow(){
/*
    about = new AboutWidget();
    aboutBar = menuBar()->addMenu(app_name);
    aboutAction = new QAction(QString("&About"),this);
    connect(aboutAction,SIGNAL(triggered()),this,SLOT(showAboutWidget()));
    aboutBar->addAction(aboutAction);
*/
	this->initMenuBar();	

    cwidget = new CentralWidget();
    connect(cwidget,SIGNAL(exitSignal()),this,SLOT(close()));
    connect(cwidget,SIGNAL(requestToVisible()),this,SLOT(show()));
    connect(cwidget,SIGNAL(requestToInvisible()),this,SLOT(hide()));
    setCentralWidget(cwidget);
    setWindowTitle(tr("MCSWitch"));
    setWindowIcon(QIcon(":/Pictures/resources/icons/IconCandidate.png"));
}

void MainWindow::initMenuBar(){
	/*About*/
	about = new AboutWidget();
    aboutBar = menuBar()->addMenu(app_name);
    aboutAction = new QAction(QString("&About"),this);
    connect(aboutAction,SIGNAL(triggered()),this,SLOT(showAboutWidget()));
    aboutBar->addAction(aboutAction);

	/*Utility*/
	utilityBar = menuBar()->addMenu("Utility");
	remakeSymLink = new QAction(QString("Remake Symlink"),this);
	connect(remakeSymLink,SIGNAL(triggered()),this,SLOT(calledRemakeSymlink()));
	utilityBar->addAction(remakeSymLink);

}

void MainWindow::calledRemakeSymlink(){
	QFile().link(mcswitch_dir_env,mcswitch_dir_env_link);
}


void MainWindow::showAboutWidget(){
    about->show();
}
