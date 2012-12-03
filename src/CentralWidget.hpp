#ifndef CENTRALWIDGET_HPP
#define CENTRALWIDGET_HPP
#include<QtGui>
#include<QString>
#include<QComboBox>
#include"Environments.hpp"
#include"addNewEnvDialog.hpp"


class CentralWidget : public QWidget {
Q_OBJECT
public:
    CentralWidget(QWidget* parent = 0);

signals:
    void exitSignal();
protected:
    void update();

public slots:
    void setEnabledTrue(){this->setEnabled(true);};

private slots:
    void addNewEnvironment();
    void AddNewEnvDialogIsSet(AddNewEnvDialog_d*);
    void ExitButtonPushed();
    void OKButtonPushed();

private:
    void initEnvironments();
    void initComboBox(Environments*);
    void initButtons();
    void setupUI();

    QComboBox* selectEnvBox;
    QPushButton* OKButton;
	QPushButton* AddButton;
    QPushButton* ExitButton;

    QLabel* currentEnvLabel;
    QLineEdit* currentEnvView;

	AddNewEnvDialog* addEnvdlg;

    Environments* mcenvs;
};
#endif
