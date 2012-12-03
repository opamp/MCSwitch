#include "AddNewEnvDialog.hpp"


AddNewEnvDialog::AddNewEnvDialog(QWidget* parent):
	QWidget(parent)
{
    /*labels*/
    commentLabel = new QLabel("Comment:");
    nameLabel = new QLabel("Name:");
    versionLabel = new QLabel("Version:");

    /*CheckBox*/
    usemodsBox = new QCheckBox("Use mods");


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
    mainLayout->addLayout(versionMainLayout);
    mainLayout->addLayout(commentLayout);
    mainLayout->addWidget(usemodsBox);
    mainLayout->addLayout(buttonsLayout);

    setLayout(mainLayout);
}

AddNewEnvDialog_d* AddNewEnvDialog::getDatas(){
    data.env_name = nameEditor->text();
    return &data;
}

void AddNewEnvDialog::clickedOKButton(){
    emit OKButtonIsPushed(this->getDatas());
    this->setVisible(false);
}

void AddNewEnvDialog::clickedCancelButton(){
    emit CancelButtonIsPushed();
    this->setVisible(false);
}
