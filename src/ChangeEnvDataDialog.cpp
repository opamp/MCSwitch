#include "ChangeEnvDataDialog.hpp"

ChangeEnvDataDialog::ChangeEnvDataDialog(QWidget* parent):
	QWidget(parent)
{
    ui.setupUi(this);

    connect(ui.pushButton,SIGNAL(clicked()),this,SLOT(pushedOKButton()));
    connect(ui.pushButton_2,SIGNAL(clicked()),this,SLOT(pushedCancelButton()));
}

void ChangeEnvDataDialog::setTarget(MCEnv* e){
    env = e;
}

bool ChangeEnvDataDialog::setupDialog(){
    if(env == NULL) return false;
    ui.lineEdit->setText(env->getName());
    ui.commentEdit->setPlainText(env->getComment());
    if(env->getMods()){
        ui.useModCheckBox->setCheckState(Qt::Checked);
    }else{
        ui.useModCheckBox->setCheckState(Qt::Unchecked);
    }
    QString ver_str = env->getVersion();
    QStringList ver_str_list = ver_str.split(".");
    ui.spinBox_major->setValue(ver_str_list[0].toInt());
    ui.spinBox_minor->setValue(ver_str_list[1].toInt());
    ui.spinBox_patch->setValue(ver_str_list[2].toInt());

    return true;
}

void ChangeEnvDataDialog::pushedOKButton(){
    emit changedData();
    setVisible(false);
}
void ChangeEnvDataDialog::pushedCancelButton(){
    setVisible(false);
}
