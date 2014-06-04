#include "ChangeEnvDataDialog.hpp"
#include <iostream>

ChangeEnvDataDialog::ChangeEnvDataDialog(QWidget* parent):
    QWidget(parent)
{
    ui.setupUi(this);

    connect(ui.pushButton,SIGNAL(clicked()),this,SLOT(pushedOKButton()));
    connect(ui.pushButton_2,SIGNAL(clicked()),this,SLOT(pushedCancelButton()));
    connect(ui.useModCheckBox,SIGNAL(stateChanged(int)),this,SLOT(cb_stateChanged(int)));
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
        cb_state = true;
    }else{
        ui.useModCheckBox->setCheckState(Qt::Unchecked);
        cb_state = false;
    }
    QString ver_str = env->getVersion();
    QStringList ver_str_list = ver_str.split(".");
    ui.spinBox_major->setValue(ver_str_list[0].toInt());
    ui.spinBox_minor->setValue(ver_str_list[1].toInt());
    ui.spinBox_patch->setValue(ver_str_list[2].toInt());

    return true;
}

void ChangeEnvDataDialog::saveNewDatas(){
    env->setVersion(QString::number(ui.spinBox_major->value()) + "." + QString::number(ui.spinBox_minor->value()) + "." + QString::number(ui.spinBox_patch->value()));
    env->setComment(ui.commentEdit->toPlainText());
    env->setMods(cb_state);
    if(!env->save()){
        std::cerr<<"Fail to save datas."<<std::endl;
    }
}
void ChangeEnvDataDialog::pushedOKButton(){
    this->saveNewDatas();
    emit changedData();
    setVisible(false);
}
void ChangeEnvDataDialog::pushedCancelButton(){
    setVisible(false);
}

void ChangeEnvDataDialog::cb_stateChanged(int s){
    if(s == 0){
        cb_state = false;
    }else{
        cb_state =true;
    }
}
