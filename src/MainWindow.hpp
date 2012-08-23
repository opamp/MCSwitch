#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP
#include<QMainWindow>
#include<QString>
#include"CentralWidget.hpp"

class MainWindow : public QMainWindow{
Q_OBJECT
public:
    MainWindow();

private:
    CentralWidget* cwidget;
};

#endif
