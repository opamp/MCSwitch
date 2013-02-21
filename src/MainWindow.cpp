#include"MainWindow.hpp"
#include<QAction>
#include<QMenuBar>


MainWindow::MainWindow(){
    about = new AboutWidget();
    aboutBar = menuBar()->addMenu(app_name);
    aboutAction = new QAction(QString("&About"),this);
    connect(aboutAction,SIGNAL(triggered()),this,SLOT(showAboutWidget()));
    aboutBar->addAction(aboutAction);

    cwidget = new CentralWidget();
    connect(cwidget,SIGNAL(exitSignal()),this,SLOT(close()));
    connect(cwidget,SIGNAL(requestToVisible()),this,SLOT(show()));
    connect(cwidget,SIGNAL(requestToInvisible()),this,SLOT(hide()));
    setCentralWidget(cwidget);
    setWindowTitle(tr("MCSWitch"));
    setWindowIcon(QIcon(":/Pictures/resources/icons/IconCandidate.png"));
}


void MainWindow::showAboutWidget(){
    about->show();
}
