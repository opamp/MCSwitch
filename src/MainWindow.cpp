#include"MainWindow.hpp"


MainWindow::MainWindow(){
    cwidget = new CentralWidget();
    setCentralWidget(cwidget);
    setWindowTitle(tr("MCSWitch"));
    setWindowIcon(QIcon(":/Pictures/resources/icons/IconCandidate.png"));
}
