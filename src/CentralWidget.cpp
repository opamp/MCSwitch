#include"CentralWidget.hpp"

CentralWidget::CentralWidget(QWidget* parent):
    QWidget(parent){
    addEnvdlg = new AddNewEnvDialog();
    connect(addEnvdlg,SIGNAL(OKButtonIsPushed(AddNewEnvDialog_d*)),this,SLOT(AddNewEnvDialogIsSet(AddNewEnvDialog_d*)));
    connect(addEnvdlg,SIGNAL(CancelButtonIsPushed()),this,SLOT(setEnabledTrue()));
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
    currentEnvView->setText(cenv->getName());
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
    this->setEnabled(true);
}

//When AddButton is clicked,this is called.
void CentralWidget::addNewEnvironment(){
    addEnvdlg->show();
    this->setEnabled(false);
}

