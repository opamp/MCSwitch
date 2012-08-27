#include"CentralWidget.hpp"

CentralWidget::CentralWidget(QWidget* parent):
    QWidget(parent){
    this->initEnvironments();
}

void CentralWidget::initEnvironments(){
    mcenvs = new Environments();
}

