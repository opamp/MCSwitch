#include"CentralWidget.hpp"
#include<iostream>
using std::cout;
using std::endl;

CentralWidget::CentralWidget(QWidget* parent):
    QWidget(parent){
    this->initEnvironments();
}

void CentralWidget::initEnvironments(){
    Environments::installNewEnvironment(QString("InitialEnv"),minecraft_dir);
    mcenvs = new Environments();
}

