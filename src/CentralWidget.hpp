#ifndef CENTRALWIDGET_HPP
#define CENTRALWIDGET_HPP
#include<QtGui>
#include"Environment.hpp"

class CentralWidget : public QWidget {
Q_OBJECT
public:
    CentralWidget(QWidget* parent = 0);

private:
    QSpinBox* selectEnvBox;
    QPushButton* OKButton;
    QPushButton* ExitButton;

    Environment* mcenv;
};
#endif
