#include"MainWindow.hpp"


MainWindow::MainWindow(){
    cwidget = new CentralWidget();
    connect(cwidget,SIGNAL(exitSignal()),this,SLOT(close()));
    connect(cwidget,SIGNAL(requestToVisible()),this,SLOT(show()));
    connect(cwidget,SIGNAL(requestToInvisible()),this,SLOT(hide()));
    setCentralWidget(cwidget);
    setWindowTitle(tr("MCSWitch"));
    setWindowIcon(QIcon(":/Pictures/resources/icons/IconCandidate.png"));
}


