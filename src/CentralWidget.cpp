#include"CentralWidget.hpp"

CentralWidget::CentralWidget(QWidget* parent):
    QWidget(parent){
    addEnvdlg = new AddNewEnvDialog();
    connect(addEnvdlg,SIGNAL(OKButtonIsPushed(AddNewEnvDialog_d*)),this,SLOT(AddNewEnvDialogIsSet(AddNewEnvDialog_d*)));


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
	AddButton = new QPushButton("Add");
	connect(AddButton,SIGNAL(clicked()),this,SLOT(addNewEnvironment()));
    ExitButton = new QPushButton("EXIT");
    //connect();
}

void CentralWidget::initComboBox(Environments* e_obj){
    selectEnvBox = new QComboBox();
    int numOfEnvs = e_obj->getNumberOfEnvironments();
    for(int i = 0;i < numOfEnvs;i++){
        selectEnvBox->addItem(e_obj->getMCEnv(i)->getName());
    }
}

void CentralWidget::setupUI(){
    QHBoxLayout* buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(OKButton);
    buttonLayout->addWidget(ExitButton);

	QHBoxLayout* comboBoxLayout = new QHBoxLayout();
	comboBoxLayout->addWidget(selectEnvBox);
	comboBoxLayout->addWidget(AddButton);

    QVBoxLayout* mainLayout = new QVBoxLayout();
	mainLayout->addLayout(comboBoxLayout);
	mainLayout->addLayout(buttonLayout);

    setLayout(mainLayout);
}

void CentralWidget::AddNewEnvDialogIsSet(AddNewEnvDialog_d* data){
    this->setEnabled(true);
    //data->env_name
}

//When AddButton is clicked,this is called.
void CentralWidget::addNewEnvironment(){
    addEnvdlg->show();
    this->setEnabled(false);
}

