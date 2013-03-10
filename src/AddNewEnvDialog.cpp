#include "AddNewEnvDialog.hpp"
#include "Environments.hpp"
#include <QHBoxLayout>
#include <QVBoxLayout>


AddNewEnvDialog::AddNewEnvDialog(QWidget* parent):
	QWidget(parent)
{
    this->initCopyFromBox();

    data.mod = false;
    /*labels*/
    commentLabel = new QLabel("Comment:");
    nameLabel = new QLabel("Name:");
    versionLabel = new QLabel("Version:");

    /*CheckBox*/
    usemodsBox = new QCheckBox("Use mods");
    connect(usemodsBox,SIGNAL(stateChanged(int)),this,SLOT(changeCheckBox(int)));

    /*buttons*/
	OKButton = new QPushButton("OK");
    CancelButton = new QPushButton("Cancel");
    connect(OKButton,SIGNAL(clicked()),this,SLOT(clickedOKButton()));
    connect(CancelButton,SIGNAL(clicked()),this,SLOT(clickedCancelButton()));

    /*lineEditor*/
    nameEditor = new QLineEdit();

    /*spinboxes*/
    majorVersion = new QSpinBox();
    minorVersion = new QSpinBox();
    patchVersion = new QSpinBox();

    majorVersion->setMinimum(0);
    minorVersion->setMinimum(0);
    patchVersion->setMinimum(0);

    /*textedit*/
    commentEdit = new QTextEdit();


    /*Layouts*/
    QHBoxLayout* copyFromLayout = new QHBoxLayout();
    copyFromLayout->addWidget(comboBoxLabel);
    copyFromLayout->addWidget(copyFromBox);

    QHBoxLayout* nameLayout = new QHBoxLayout();
    nameLayout->addWidget(nameLabel);
    nameLayout->addWidget(nameEditor);

    QHBoxLayout* versionLayout = new QHBoxLayout();
    versionLayout->addWidget(majorVersion);
    versionLayout->addWidget(minorVersion);
    versionLayout->addWidget(patchVersion);
    QVBoxLayout* versionMainLayout = new QVBoxLayout();
    versionMainLayout->addWidget(versionLabel);
    versionMainLayout->addLayout(versionLayout);

    QVBoxLayout* commentLayout = new QVBoxLayout();
    commentLayout->addWidget(commentLabel);
    commentLayout->addWidget(commentEdit);

    QHBoxLayout* buttonsLayout = new QHBoxLayout();
	buttonsLayout->addWidget(OKButton);
	buttonsLayout->addWidget(CancelButton);

    QVBoxLayout* mainLayout = new QVBoxLayout();
    mainLayout->addLayout(nameLayout);
    mainLayout->addLayout(copyFromLayout);
    mainLayout->addLayout(versionMainLayout);
    mainLayout->addLayout(commentLayout);
    mainLayout->addWidget(usemodsBox);
    mainLayout->addLayout(buttonsLayout);

    setLayout(mainLayout);
}

void AddNewEnvDialog::initCopyFromBox(){
    comboBoxLabel = new QLabel("Copy from ");
    copyFromBox = new QComboBox();
    copyFromBox->addItem(COPYFROM_SELECT_NOTHING);

    Environments* evs = new Environments();
    for(int n = 0;n < evs->getNumberOfEnvironments();n++){
        copyFromBox->addItem(evs->getMCEnv(n)->getName());
    }
}

AddNewEnvDialog_d* AddNewEnvDialog::getDatas(){
    data.env_name = nameEditor->text();
    data.version[0] = majorVersion->value();
    data.version[1] = minorVersion->value();
    data.version[2] = patchVersion->value();
    data.comment = commentEdit->toPlainText();
    data.copyFrom = copyFromBox->itemText(copyFromBox->currentIndex());
    return &data;
}

void AddNewEnvDialog::clickedOKButton(){
    emit OKButtonIsPushed(this->getDatas());
    this->setZero();
    this->setVisible(false);
}

void AddNewEnvDialog::clickedCancelButton(){
    emit CancelButtonIsPushed();
    this->setZero();
    this->setVisible(false);
}

void AddNewEnvDialog::changeCheckBox(int state){
    if(state == Qt::Checked){
        data.mod = true;
    }else{
        data.mod = false;
    }
}

void AddNewEnvDialog::setZero(){
    nameEditor->clear();
    commentEdit->clear();
    majorVersion->setValue(0);
    minorVersion->setValue(0);
    patchVersion->setValue(0);
    usemodsBox->setCheckState(Qt::Unchecked);
    copyFromBox->setCurrentIndex(0);
}
