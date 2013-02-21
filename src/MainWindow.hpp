#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP
#include<QMainWindow>
#include<QString>
#include"CentralWidget.hpp"
#include"AboutWidget.hpp"

class MainWindow : public QMainWindow{
Q_OBJECT
public:
    MainWindow();

private:
    CentralWidget* cwidget;
    AboutWidget* about;

    QMenu* aboutBar;
    QAction* aboutAction;

private slots:
    void showAboutWidget();
};

#endif
