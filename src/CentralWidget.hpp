#ifndef CENTRALWIDGET_HPP
#define CENTRALWIDGET_HPP
#include<QtGui>
#include"Environments.hpp"

class CentralWidget : public QWidget {
Q_OBJECT
public:
    CentralWidget(QWidget* parent = 0);

private:
    void initEnvironments();

    QSpinBox* selectEnvBox;
    QPushButton* OKButton;
    QPushButton* ExitButton;

    Environments* mcenvs;
};
#endif
