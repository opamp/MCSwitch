#include "AboutWidget.hpp"
#include "version.hpp"

#include <QTextStream>
#include <QVBoxLayout>

AboutWidget::AboutWidget(QWidget* parent):
    QWidget(parent){
    appNameLabel = new QLabel(QString("<h1>")+app_name+QString(" -for Switching Minecraft version- </h1>"));
    versionLabel = new QLabel(app_ver);
    urlLabel = new QLabel(QString("https://github.com/opamp/MCSwitch"));
    licenseViewer = new QTextEdit();
    QFile  licenseFile(":/texts/resources/text/LICENSE.txt");
    if(!licenseFile.open(QFile::Text | QFile::ReadOnly)){
        licenseViewer->setPlainText("Fail to read license text. Please see LICENSE.txt");
    }else{
        QTextStream op(&licenseFile);
        licenseViewer->setPlainText(op.readAll());
        licenseFile.close();
    }
    licenseViewer->setReadOnly(true);

    OKButton = new QPushButton("OK");
    connect(OKButton,SIGNAL(clicked()),this,SLOT(clickedOKButton()));

    QVBoxLayout *mainlayout = new QVBoxLayout();
    mainlayout->addWidget(appNameLabel);
    mainlayout->addWidget(versionLabel);
    mainlayout->addWidget(urlLabel);
    mainlayout->addWidget(licenseViewer);
    mainlayout->addWidget(OKButton);
    setLayout(mainlayout);

    setWindowTitle(QString("About ")+app_name);
    setWindowIcon(QIcon(":/Pictures/resources/icons/IconCandidate.png"));
}

void AboutWidget::clickedOKButton(){
    this->close();
}
