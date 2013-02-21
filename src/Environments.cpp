#include<iostream>
#include"Environments.hpp"
#include"version.hpp"
#include"fileutils.hpp"
#include"xml.hpp"

Environments::Environments(const QString path){
    if(QFile::exists(path)){
        this->path = path;
    }else{
        return;
    }
    QDir dir(this->path);
    QStringList envList = dir.entryList();
    MCEnv *p;

    this->updateEnvData();
}

int Environments::updateEnvData(){
    QDir dir(this->path);
    QStringList envList = dir.entryList();
    MCEnv* p;
    for(int i = 0;i < envList.size();++i){
        bool dumpflg = false;
        //"."と".."は省く
        if(envList.at(i) == QString(".") || envList.at(i) == QString("..")){
            continue;
        }
        //すでに同PATHを表すMCSWitchが登録されてるならスキップする
        for(int n = 0;n < this->getNumberOfEnvironments();++n){
            if(envsVector[n]->getName() == envList.at(i)){
                dumpflg = true;
            }
        }
        if(dumpflg == true){
            continue;
        }

        //上記２つに引っかからないものをMCSwitchの環境として認め登録
        p = new MCEnv(path + "/" + envList.at(i));
        if(!p->open()){
            std::cerr<<"IGNORE::Failed to read "<<(path + "/" +envList.at(i)).toStdString()<<std::endl;
            continue;
        }
        envsVector.push_back(p);

    }
    return getNumberOfEnvironments();
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

MCEnv* Environments::getCurrentEnv(){
    Xml reader(minecraft_dir + "/" +  eachEnvDataXmlName);
    if(reader.open() == false){
        return NULL;
    }
    xml_d data;
    reader.getXmlData(&data);
    for(int i = 0;i < this->getNumberOfEnvironments();++i){
        if(envsVector[i]->getName() == data.name){
            return envsVector[i];
        }
    }
    return NULL;
}

bool Environments::createNewEnvironemnt(const QString name,int* v,const QString comment,bool usemod_f){
    if(!fileutils::rm_R(QString("/Users/opamp/Desktop/testdir"))){
        std::cout<<"失敗"<<std::endl;
    }
    init_d data;
    data.name = name;
    data.version[0] = *v;
    data.version[1] = *(v + 1);
    data.version[2] = *(v + 2);
    data.comment = comment;
    data.usemod = usemod_f;
    if(!MCEnv::initEnv(&data,mcswitch_dir_env))return false; // create new environment.
    return true;
}

bool Environments::installNewEnvironment(const QString name,const QString path){
    if(path.isEmpty() or !QDir().exists(path)) return false;
    QStringList envs = QDir(mcswitch_dir_env).entryList();
    QStringListIterator i(envs);
    while(i.hasNext()){
        if(i.next() == name){
            return false; //同名のEnvironemntがないかチェック
        }
    }


    if(!fileutils::cp_R(path, mcswitch_dir_env + fsp + name)) return false; //copy.



    /*以下のifの中でeachEnvDataXmlNameに入っている文字列で設定ファイルを生成*/
    if(QFile::exists(path + fsp + eachEnvDataXmlName)){
        QFile::remove(mcswitch_dir_env + fsp + name + fsp + eachEnvDataXmlName);
        QFile::copy(path + fsp + eachEnvDataXmlName,mcswitch_dir_env + fsp + name + fsp + eachEnvDataXmlName);
        QFile::setPermissions(mcswitch_dir_env + fsp + name + fsp + eachEnvDataXmlName,
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

bool Environments::changeEnv(QString env_name){
    for(int n = 0;n < envsVector.size();++n){
        if(envsVector[n]->getName() == env_name){
            QFile::remove(minecraft_dir + "/" + eachEnvDataXmlName);
            QFile::copy(mcswitch_dir_env + "/" + env_name + "/" + eachEnvDataXmlName,minecraft_dir + "/" + eachEnvDataXmlName);
        }
    }
}
