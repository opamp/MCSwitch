#include "CentralWidget.hpp"
#include <QMessageBox>

CentralWidget::CentralWidget(QWidget* parent):
    QWidget(parent){
    //sub dialogs
    addEnvdlg = new AddNewEnvDialog();
    changeDataDialog = new ChangeEnvDataDialog();

    connect(changeDataDialog,SIGNAL(changedData()),this,SLOT(update()));
    connect(addEnvdlg,SIGNAL(OKButtonIsPushed(AddNewEnvDialog_d*)),this,SLOT(AddNewEnvDialogIsSet(AddNewEnvDialog_d*)));
    connect(addEnvdlg,SIGNAL(CancelButtonIsPushed()),this,SLOT(setVisibleTrue()));
    currentEnvLabel = new QLabel("Current Environment ");
    currentEnvView = new QLineEdit();
    currentEnvView->setReadOnly(true);
    currentEnvView->setFrame(true);

    this->initEnvironments();
    this->initInformationViewer();
    this->initComboBox(this->mcenvs);
    this->initButtons();
    this->setupUI();
    this->update();
}

void CentralWidget::update(){
    mcenvs->updateEnvData();
    MCEnv* cenv = mcenvs->getCurrentEnv();
    if(cenv == NULL){
        QMessageBox::critical(this, "ERROR", "MCSwitch cannot load currnet environment.");
        exit(1);
    }
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
    ChangeDataButton = new QPushButton("Change Data");
    connect(ChangeDataButton,SIGNAL(clicked()),this,SLOT(callChangeEnvDataDialog()));
    ExitButton = new QPushButton("QUIT");
    connect(ExitButton,SIGNAL(clicked()),this,SLOT(ExitButtonPushed()));
}

void CentralWidget::initComboBox(Environments* e_obj){
    selectEnvBox = new QComboBox();
    connect(selectEnvBox,SIGNAL(currentIndexChanged(const QString&)),this,SLOT(selectEnvBoxChanged(const QString&)));
    MCEnv* e = mcenvs->getCurrentEnv();
    e->open();
    int b = 0;
    for(int i = 0;i < e_obj->getNumberOfEnvironments();i++){
        selectEnvBox->addItem(e_obj->getMCEnv(i)->getName());
        if(e_obj->getMCEnv(i)->getName() == e->getName()){
            b = i;
        }
    }
    delete e;
    selectEnvBox->setCurrentIndex(b);
}

void CentralWidget::initInformationViewer(){
    this->mViewer = new QLabel("");

    this->commentViewer = new QTextEdit();
    this->commentViewer->setReadOnly(true);

    this->versionViewer = new QLabel("VERSION ");
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
    mainLayout->addWidget(ChangeDataButton);
    mainLayout->addWidget(versionViewer);
    mainLayout->addWidget(mViewer);
    mainLayout->addWidget(commentViewer);
    mainLayout->addLayout(currentEnvLayout);
    mainLayout->addLayout(buttonLayout);

    setLayout(mainLayout);
}

void CentralWidget::AddNewEnvDialogIsSet(AddNewEnvDialog_d* data){
    if(!Environments::createNewEnvironemnt(data->env_name,data->version,data->comment,data->mod)){
        QMessageBox::critical(this, "ERROR", "MCSwitch cannnot create new environment.");
        emit requestToVisible();
        mcenvs->updateEnvData();
        this->update();
        return ;
    }else{
        mcenvs->updateEnvData();
    }
    if(data->copyFrom != COPYFROM_SELECT_NOTHING){
        if(!mcenvs->copyEnvContents(data->copyFrom,data->env_name)){
            QMessageBox::critical(this, "ERROR", "Failed to copy environment's contents.");
        }
    }
    emit requestToVisible();
    this->update();
}

void CentralWidget::ExitButtonPushed(){
    //If you want to excuse something before exit,you should write it here.
    emit exitSignal();
}

void CentralWidget::OKButtonPushed(){
    //When OKButton is pushed,this is called.
    if(!mcenvs->changeEnv(selectEnvBox->itemText(selectEnvBox->currentIndex()))){
        QMessageBox::critical(this, "ERROR", "Failed to change environment.");
    }
    this->update();
}

void CentralWidget::selectEnvBoxChanged(const QString& env_name){
    for(int n = 0;n < mcenvs->getNumberOfEnvironments();n++){
        if(mcenvs->getMCEnv(n)->getName() == env_name){
            MCEnv *e = mcenvs->getMCEnv(n);
            if(e->getMods())
                this->mViewer->setText("using Mods");
            else
                this->mViewer->setText("Vanilla");
            this->commentViewer->setPlainText(e->getComment());//set commnet viewer's text.
            this->versionViewer->setText("VERSION " + e->getVersion());//set version info.
        }
    }
}

//When AddButton is clicked,this is called.
void CentralWidget::addNewEnvironment(){
    disconnect(addEnvdlg,SIGNAL(OKButtonIsPushed(AddNewEnvDialog_d*)),this,SLOT(AddNewEnvDialogIsSet(AddNewEnvDialog_d*)));
    disconnect(addEnvdlg,SIGNAL(CancelButtonIsPushed()),this,SLOT(setVisibleTrue()));
    delete addEnvdlg;
    addEnvdlg = new AddNewEnvDialog();
    connect(addEnvdlg,SIGNAL(OKButtonIsPushed(AddNewEnvDialog_d*)),this,SLOT(AddNewEnvDialogIsSet(AddNewEnvDialog_d*)));
    connect(addEnvdlg,SIGNAL(CancelButtonIsPushed()),this,SLOT(setVisibleTrue()));
    addEnvdlg->show();
    emit requestToInvisible();
}

void CentralWidget::callChangeEnvDataDialog(){
    MCEnv *env;
    for(int n = 0;n < mcenvs->getNumberOfEnvironments();n++){
        if(mcenvs->getMCEnv(n)->getName() == selectEnvBox->itemText(selectEnvBox->currentIndex())){
            env = mcenvs->getMCEnv(n);
            break;
        }
    }
    changeDataDialog->setTarget(env);
    changeDataDialog->setupDialog();
    changeDataDialog->show();
}


