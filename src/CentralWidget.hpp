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

private slots:
	void addNewEnvironment();

private:
    void initEnvironments();
    void initComboBox(Environments*);
    void initButtons();
    void setupUI();

    QComboBox* selectEnvBox;
    QPushButton* OKButton;
	QPushButton* AddButton;
    QPushButton* ExitButton;

    Environments* mcenvs;
};
#endif
