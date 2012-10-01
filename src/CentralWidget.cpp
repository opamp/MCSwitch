#include"CentralWidget.hpp"

CentralWidget::CentralWidget(QWidget* parent):
    QWidget(parent){
    this->initEnvironments();
    this->initSpinBox(this->mcenvs);
}

void CentralWidget::initEnvironments(){
    mcenvs = new Environments();
}


void CentralWidget::initSpinBox(Environments* e_obj){
}

