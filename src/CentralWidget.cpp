#include"CentralWidget.hpp"

CentralWidget::CentralWidget(QWidget* parent):
    QWidget(parent){
    this->initEnvironments();
    this->initComboBox(this->mcenvs);
    this->initButtons();
    this->setupUI();
}

void CentralWidget::initEnvironments(){
    mcenvs = new Environments();
}

void CentralWidget::initButtons(){
    OKButton = new QPushButton("OK");
    //connect();
    ExitButton = new QPushButton("EXIT");
    //connect();
}

void CentralWidget::initComboBox(Environments* e_obj){
    selectEnvBox = new ComboBox();
    int numOfEnvs = e_obj->getNumberOfEnvironments();
    for(int i = 0;i < numOfEnvs;i++){
        selectEnvBox->addItem((e_obj->getMCEnv(n))->getName());
    }
}

void CentralWidget::setupUI(){
    QHBoxLayout* buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(OKButton);
    buttonLayout->addWidget(ExitButton);
    QVBoxLayout* mainLayout = new QVBoxLayout();
    mainLayout->addWidget(selectEnvBox);
    mainLayout->addLayout(buttonLayout);

    setLayout(mainLayout);
}
