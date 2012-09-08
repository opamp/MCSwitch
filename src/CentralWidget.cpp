#include"CentralWidget.hpp"

CentralWidget::CentralWidget(QWidget* parent):
    QWidget(parent){
    this->initEnvironments();
}

void CentralWidget::initEnvironments(){
    Environments::installNewEnvironment(QString("InitialEnv"),minecraft_dir);
    mcenvs = new Environments();
}

