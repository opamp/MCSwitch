#ifndef ABOUT_WIDGET_HPP
#define ABOUT_WIDGET_HPP
#include <QWidget>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>

class AboutWidget : public QWidget{
    Q_OBJECT
public:
    AboutWidget(QWidget* parent = 0);

private slots:
    void clickedOKButton();
private:
    QLabel* appNameLabel;
    QLabel* versionLabel;
    QLabel* urlLabel;
    QTextEdit* licenseViewer;
    QPushButton* OKButton;
};

#endif
