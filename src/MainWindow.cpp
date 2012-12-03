#include"MainWindow.hpp"


MainWindow::MainWindow(){
    cwidget = new CentralWidget();
    connect(cwidget,SIGNAL(exitSignal()),this,SLOT(close()));
    setCentralWidget(cwidget);
    setWindowTitle(tr("MCSWitch"));
    setWindowIcon(QIcon(":/Pictures/resources/icons/IconCandidate.png"));
}
