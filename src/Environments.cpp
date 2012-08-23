#include"Environments.hpp"
#include"version.hpp"

Environments::Environments(){

}



bool Environments::createNewEnvironemnt(const QString name){
    if(!MCEnv::initEnv(name,mcswitch_dir_env))return false; // create new environment.

    /*
    QFile::remove(mcswitch_dir_env + "/" + name + "/" + eachEnvDataXmlName);
    if(!QFile::copy(tmp_xml2,mcswitch_dir_env + "/" + name + "/" + eachEnvDataXmlName)) return false;
    QFile::setPermissions(mcswitch_dir_env + "/" + name + "/" + eachEnvDataXmlName,
                          QFile::ReadOwner  |
                          QFile::WriteOwner |
                          QFile::ReadUser   |
                          QFile::WriteUser
                          );
    */
    return true;
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
