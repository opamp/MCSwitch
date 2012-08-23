#include"Environments.hpp"

Environments::Environments(){

}



bool Environments::createNewEnvironemnt(const QString name){
    if(name.isEmpty()) return false;
    QDir envsdir(mcswitch_dir_env);
    QStringList envs = QDir.entryList();

    QStringListIterator i(envs);
    while(i.hasNext()){
        if(i.next() == name){
            return false;
        }
    }
}

bool Environments::installNewEnvironment(const QString name){
    if(name.isEmpty()) return false;
    QDir envsdir(mcswitch_dir_env);
    QStringList envs = QDir.entryList();
}

bool Environments::removeEnvironment(const QString name){
    if(name.isEmpty()) return false;
    QDir envsdir(mcswitch_dir_env);
    QStringList envs = QDir.entryList();

}
