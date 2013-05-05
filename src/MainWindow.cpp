#include "MainWindow.hpp"
#include <QAction>
#include <QMenuBar>
#include <QFile>
#include <QMessageBox>

#include "version.hpp"


MainWindow::MainWindow(){
    cwidget = new CentralWidget();
    this->initMenuBar();//init menu bar.

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

    deleter = new DeleteEnvDialog();
    deleteEnvDialogAction = new QAction(QString("Delete Environemnt"),this);
    connect(deleteEnvDialogAction,SIGNAL(triggered()),this,SLOT(showDeleteEnvDialog()));
    connect(deleter,SIGNAL(finished()),cwidget,SLOT(update()));
    utilityBar->addAction(deleteEnvDialogAction);
}

void MainWindow::showDeleteEnvDialog(){
    deleter->updateSelector();
    deleter->show();
}

void MainWindow::calledRemakeSymlink(){
	bool b = true;
	if(!QFile::exists(mcswitch_dir_env_link)){
		if(QFile().link(mcswitch_dir_env,mcswitch_dir_env_link))
			b = true;
		else
			b = false;
	}
	if(b)
		QMessageBox::information(this,"SUCCESS","Remade symlink to directory of environments.");
	else
		QMessageBox::information(this,"Failure","Failed to remake symlink to directory of environments.");
}


void MainWindow::showAboutWidget(){
    about->show();
}
