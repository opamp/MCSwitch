#include <QHBoxLayout>
#include <QVBoxLayout>
#include "DeleteEnvDialog.hpp"
#include "version.hpp"

DeleteEnvDialog::DeleteEnvDialog(QWidget* parent):
    QWidget(parent)
{
    QDir dir(mcswitch_dir_env);
    msgLabel = new QLabel("Select environment you'd like to delete");
    dirList = dir.entryList(QDir::NoDotAndDotDot | QDir::AllDirs);
    selector = new QComboBox();

    this->updateSelector();

    okButton = new QPushButton("Delete");
    cancelButton = new QPushButton("Cancel");

    connect(selector,SIGNAL(currentIndexChanged(const QString&)),this,SLOT(targetChanged(const QString&)));
    connect(okButton,SIGNAL(clicked()),this,SLOT(pushedOKButton()));
    connect(cancelButton,SIGNAL(clicked()),this,SLOT(pushedCancelButton()));

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(okButton);
    buttonLayout->addWidget(cancelButton);

    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addWidget(msgLabel);
    mainLayout->addWidget(selector);
    mainLayout->addLayout(buttonLayout);
    setLayout(mainLayout);
}

void DeleteEnvDialog::updateSelector(){
    selector->clear();
    for(int i = 0;i < dirList.size();i++){
        if(!QFile::exists(mcswitch_dir_env + fsp + dirList.at(i) + fsp + eachEnvDataXmlName)) continue;
        selector->addItem(dirList.at(i));
    }
}

void DeleteEnvDialog::targetChanged(const QString & name){
    this->target = name;
}

void DeleteEnvDialog::pushedOKButton(){
    this->rm_R(mcswitch_dir_env + fsp + this->target);
    emit finished();
    this->hide();
}

void DeleteEnvDialog::pushedCancelButton(){
    this->hide();
}

bool DeleteEnvDialog::rm_R(const QString &dirName){
    if(!QFileInfo(dirName).isDir()) return false;

    QDir dir(dirName);
    QStringList list = dir.entryList(QDir::NoDotAndDotDot | QDir::Hidden | QDir::AllEntries);
    QStringListIterator i(list);
    QString b;

    while(i.hasNext()){
        b = dirName + fsp + i.next();
        if(QFileInfo(b).isDir()){
            if(!rm_R(b)) return false;
        }else{
             if(!QFile::remove(b)) return false;
        }
    }
    if((new QDir())->rmdir(dirName)) return true;
    return false;
}

