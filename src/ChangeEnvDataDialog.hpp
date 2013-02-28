#ifndef CHANGE_ENV_DATA_DIALOG_HPP
#define CHANGE_ENV_DATA_DIALOG_HPP
#include <QtGui>
#include <QWidget>

#include "ui_ChangeEnvDataDialog.h"
/*
namespace Ui{
    class Ui_ChangeEnvDataDialogUI;
}*/

class ChangeEnvDataDialog : public QWidget{
Q_OBJECT
public:
    ChangeEnvDataDialog(QWidget* parent = 0);

private:
    Ui::ChangeEnvDataDialogUI ui;
};
#endif
