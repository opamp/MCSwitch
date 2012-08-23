#include<iostream>
#include"Environments.hpp"
#include"version.hpp"
#include"fileutils.hpp"

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

bool Environments::installNewEnvironment(const QString name,const QString path){
    if(path.isEmpty() or !QDir().exists(path)) return false;
    if(!MCEnv::initEnv(name,mcswitch_dir_env)) return false;

    if(QFile::exists(path + "/" + eachEnvDataXmlName)){
        QFile::remove(mcswitch_dir_env + "/" + name + "/" + eachEnvDataXmlName);
        QFile::copy(path + "/" + eachEnvDataXmlName,mcswitch_dir_env + "/" + name + "/" + eachEnvDataXmlName);
        QFile::setPermissions(mcswitch_dir_env + "/" + name + "/" + eachEnvDataXmlName,
                                  QFile::ReadOwner  |
                                  QFile::WriteOwner |
                                  QFile::ReadUser   |
                                  QFile::WriteUser
                                  );


    }

    /*
    QStringList idir = QDir(path).entryList();
    QStringListIterator i(idir);
    while(i.hasNext()){
        if(i.next() == QString(".") or i.next() == QString("..")) continue;
        std::cout<<i.next().toStdString()<<std::endl;
        if(!QFile::copy(path + "/" + i.next(),mcswitch_dir_env + "/" + name + "/" + i.next())) return false;
    }*/

    if(!fileutils::cp_R(path,mcswitch_dir_env + "/" + name)) return false;

    return true;
}

bool Environments::removeEnvironment(const QString name){
    if(name.isEmpty()) return false;
    if(QDir().remove(mcswitch_dir_env + "/" + name)) return true;
    return false;
}
