#ifndef CENTRALWIDGET_HPP
#define CENTRALWIDGET_HPP
#include<QtGui>
#include<QString>
#include<QComboBox>
#include"Environments.hpp"


class CentralWidget : public QWidget {
Q_OBJECT
public:
    CentralWidget(QWidget* parent = 0);

private:
    void initEnvironments();
    void initComboBox(Environments*);

    QComboBox* selectEnvBox;
    QPushButton* OKButton;
    QPushButton* ExitButton;

    Environments* mcenvs;
};
#endif
