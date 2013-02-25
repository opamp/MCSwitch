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
	void initMenuBar();

    CentralWidget* cwidget;
    AboutWidget* about;

    QMenu* aboutBar;
	QMenu* utilityBar;
    QAction* aboutAction;
	QAction* remakeSymLink;

private slots:
    void showAboutWidget();
	void calledRemakeSymlink();
};

#endif
