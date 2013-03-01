#ifndef CHANGE_ENV_DATA_DIALOG_HPP
#define CHANGE_ENV_DATA_DIALOG_HPP
#include <QtGui>
#include <QWidget>
#include "MCEnv.hpp"

#include "ui_ChangeEnvDataDialog.h"

class ChangeEnvDataDialog : public QWidget{
Q_OBJECT
public:
    ChangeEnvDataDialog(QWidget* parent = 0);
    bool setupDialog();
    void setTarget(MCEnv*);

signals:
    void changedData();
private slots:
    void pushedOKButton();
    void pushedCancelButton();
    void cb_stateChanged(int);
private:
    void saveNewDatas();

    bool cb_state;
    Ui::ChangeEnvDataDialogUI ui;
    MCEnv* env;
};
#endif
