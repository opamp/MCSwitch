#include "ChangeEnvDataDialog.hpp"

ChangeEnvDataDialog::ChangeEnvDataDialog(QWidget* parent):
	QWidget(parent)
{
    ui.setupUi(this);
}

void ChangeEnvDataDialog::setTarget(MCEnv* e){
    env = e;
}

void ChangeEnvDataDialog::setupDialog(){

}

void ChangeEnvDataDialog::pushedOKButton(){
    emit changedData();
    setVisible(false);
}
void ChangeEnvDataDialog::pushedCancelButton(){
    setVisible(false);
}
