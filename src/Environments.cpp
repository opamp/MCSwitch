#include<iostream>
#include"Environments.hpp"
#include"version.hpp"
#include"fileutils.hpp"

Environments::Environments(const QString path){
    if(QFile::exists(path)){
        this->path = path;
    }else{
        return;
    }
    QDir dir(path);
    QStringList envList = dir.entryList();
    MCEnv *p;
    for(int i = 0;i < envList.size();++i){
        if(envList.at(i) == QString(".") || envList.at(i) == QString("..")){
            continue;
        }
        p = new MCEnv(path + "/" + envList.at(i));
        if(!p->open()){
            std::cerr<<"IGNORE::Failed to read "<<(path + "/" +envList.at(i)).toStdString()<<std::endl;
            continue;
        }
        envsVector.push_back(p);
    }
}

int Environments::getNumberOfEnvironments(){
    return envsVector.size();
}

MCEnv* Environments::getMCEnv(int n){
    if(n < 0 || n >= this->getNumberOfEnvironments()){
        return NULL;
    }else{
        return envsVector[n];
    }
}

bool Environments::createNewEnvironemnt(const QString name){
    if(!MCEnv::initEnv(name,mcswitch_dir_env))return false; // create new environment.
    return true;
}

bool Environments::installNewEnvironment(const QString name,const QString path){
    if(path.isEmpty() or !QDir().exists(path)) return false;
    QStringList envs = QDir(mcswitch_dir_env).entryList();
    QStringListIterator i(envs);
    while(i.hasNext()){
        if(i.next() == name){
            return false; // あったらfalseを返して終了
        }
    }

    if(!fileutils::cp_R(path, mcswitch_dir_env + "/" + name)) return false;



    /*以下のifの中でeachEnvDataXmlNameに入っている文字列で設定ファイルを生成*/
    if(QFile::exists(path + "/" + eachEnvDataXmlName)){
        QFile::remove(mcswitch_dir_env + "/" + name + "/" + eachEnvDataXmlName);
        QFile::copy(path + "/" + eachEnvDataXmlName,mcswitch_dir_env + "/" + name + "/" + eachEnvDataXmlName);
        QFile::setPermissions(mcswitch_dir_env + "/" + name + "/" + eachEnvDataXmlName,
                                  QFile::ReadOwner  |
                                  QFile::WriteOwner |
                                  QFile::ReadUser   |
                                  QFile::WriteUser
                                  );


    }else{
        if(!QFile::copy(tmp_xml1,mcswitch_dir_env + "/" + name + "/" + eachEnvDataXmlName)) return false;
        QFile::setPermissions(mcswitch_dir_env + "/" + name + "/" + eachEnvDataXmlName,
                              QFile::ReadOwner  |
                              QFile::WriteOwner |
                              QFile::ReadUser   |
                              QFile::WriteUser
                              );
    }
    return true;
}

bool Environments::removeEnvironment(const QString name){
    if(name.isEmpty()) return false;
    if(QDir().remove(mcswitch_dir_env + "/" + name)) return true;
    return false;
}
