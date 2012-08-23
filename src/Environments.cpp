#include"Environments.hpp"
#include"version.hpp"

Environments::Environments(){

}



bool Environments::createNewEnvironemnt(const QString name){
    if(name.isEmpty()) return false;
    QDir envsdir(mcswitch_dir_env);
    QStringList envs = envsdir.entryList();

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
    QStringList envs = envsdir.entryList();
}

bool Environments::removeEnvironment(const QString name){
    if(name.isEmpty()) return false;
    QDir envsdir(mcswitch_dir_env);
    QStringList envs = envsdir.entryList();

}
