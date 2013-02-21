#include"CentralWidget.hpp"
#include<iostream>

CentralWidget::CentralWidget(QWidget* parent):
    QWidget(parent){
    addEnvdlg = new AddNewEnvDialog();
    connect(addEnvdlg,SIGNAL(OKButtonIsPushed(AddNewEnvDialog_d*)),this,SLOT(AddNewEnvDialogIsSet(AddNewEnvDialog_d*)));
    connect(addEnvdlg,SIGNAL(CancelButtonIsPushed()),this,SLOT(setVisibleTrue()));
    currentEnvLabel = new QLabel("CurrentEnv ");
    currentEnvView = new QLineEdit();
    currentEnvView->setReadOnly(true);
    currentEnvView->setFrame(true);

    this->initEnvironments();
    this->initComboBox(this->mcenvs);
    this->initButtons();
    this->setupUI();
    this->update();
}

void CentralWidget::update(){
    MCEnv* cenv = mcenvs->getCurrentEnv();
    cenv->open();
    currentEnvView->setText(cenv->getName());
    QString c = selectEnvBox->currentText();
    int i = -1;
    selectEnvBox->clear();
    for(int n = 0;n < mcenvs->getNumberOfEnvironments();n++){
      selectEnvBox->addItem(mcenvs->getMCEnv(n)->getName());
      if(mcenvs->getMCEnv(n)->getName() == c){
          i = n;
      }
    }
    if(i != -1){
        selectEnvBox->setCurrentIndex(i);
    }
}

void CentralWidget::initEnvironments(){
    mcenvs = new Environments();
}

void CentralWidget::initButtons(){
    OKButton = new QPushButton("OK");
    connect(OKButton,SIGNAL(clicked()),this,SLOT(OKButtonPushed()));
	AddButton = new QPushButton("Add");
	connect(AddButton,SIGNAL(clicked()),this,SLOT(addNewEnvironment()));
    ExitButton = new QPushButton("EXIT");
    connect(ExitButton,SIGNAL(clicked()),this,SLOT(ExitButtonPushed()));
}

void CentralWidget::initComboBox(Environments* e_obj){
    selectEnvBox = new QComboBox();
    for(int i = 0;i < e_obj->getNumberOfEnvironments();i++){
        selectEnvBox->addItem(e_obj->getMCEnv(i)->getName());
    }
}

void CentralWidget::setupUI(){
    QHBoxLayout* currentEnvLayout = new QHBoxLayout();
    currentEnvLayout->addWidget(currentEnvLabel);
    currentEnvLayout->addWidget(currentEnvView);
    QHBoxLayout* buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(OKButton);
    buttonLayout->addWidget(ExitButton);

	QHBoxLayout* comboBoxLayout = new QHBoxLayout();
	comboBoxLayout->addWidget(selectEnvBox);
	comboBoxLayout->addWidget(AddButton);

    QVBoxLayout* mainLayout = new QVBoxLayout();
	mainLayout->addLayout(comboBoxLayout);
    mainLayout->addLayout(currentEnvLayout);
    mainLayout->addLayout(buttonLayout);

    setLayout(mainLayout);
}

void CentralWidget::AddNewEnvDialogIsSet(AddNewEnvDialog_d* data){
    Environments::createNewEnvironemnt(data->env_name,data->version,data->comment,data->mod);
    mcenvs->updateEnvData();
    emit requestToVisible();
    this->update();
}

void CentralWidget::ExitButtonPushed(){
    //If you want to excuse something before exit,you should write it here.
    emit exitSignal();
}

void CentralWidget::OKButtonPushed(){
    //When OKButton is pushed,this is called.
    mcenvs->changeEnv(selectEnvBox->itemText(selectEnvBox->currentIndex()));
    this->update();
}

//When AddButton is clicked,this is called.
void CentralWidget::addNewEnvironment(){
    addEnvdlg->show();
    emit requestToInvisible();
}


