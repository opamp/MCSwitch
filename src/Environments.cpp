#include"Environments.hpp"
#include"version.hpp"

Environments::Environments(){

}



bool Environments::createNewEnvironemnt(const QString name){

    MCEnv.initEnv(name); // create new environment.
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
