#include"CentralWidget.hpp"

CentralWidget::CentralWidget(QWidget* parent):
    QWidget(parent){
    this->initEnvironments();
    this->initComboBox(this->mcenvs);
}

void CentralWidget::initEnvironments(){
    mcenvs = new Environments();
}


void CentralWidget::initComboBox(Environments* e_obj){
    int numOfEnvs = mcenvs->getNumberOfEnvironments();
}

