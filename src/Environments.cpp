#include <iostream>
#include "Environments.hpp"
#include "version.hpp"
#include "fileutils.hpp"
#include "xml.hpp"


Environments::Environments(const QString path){
    if(QFile::exists(path)){
        this->path = path;
    }else{
        return;
    }
    QDir dir(this->path);
    QStringList envList = dir.entryList();
    this->updateEnvData();

	/*起動時にloadingenvにEnvironmentがあれば読みこんでvectorに追加 (無理矢理感しかない)*/
	if(QFile::exists(mcswitch_dir + fsp + LOADING_DIR_NAME)){
		MCEnv* e = new MCEnv(mcswitch_dir + fsp + LOADING_DIR_NAME);
		e->open();
		this->envsVector.push_back(e);
	}

}

int Environments::updateEnvData(){
    QDir dir(this->path);
    QStringList envList = dir.entryList(QDir::NoDotAndDotDot | QDir::AllDirs);
    MCEnv* p;
    for(int i = 0;i < envList.size();++i){
        bool dumpflg = false;
        //候補のディレクトリ直下にeachEnvDataXmlNameが存在しない場合はスキップする
        if(!QFile::exists(mcswitch_dir_env + fsp + envList.at(i) + fsp + eachEnvDataXmlName)) continue;
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
        p = new MCEnv(path + fsp + envList.at(i));
        if(!p->open()){
            std::cerr<<"IGNORE::Failed to read "<<(path + fsp +envList.at(i)).toStdString()<<std::endl;
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
    if(QFile::exists(mcswitch_dir + fsp + LOADING_DIR_NAME)){
        MCEnv* e = new MCEnv(mcswitch_dir + fsp + LOADING_DIR_NAME);
        return e;
    }else{
        return NULL;
    }
}

bool Environments::createNewEnvironemnt(const QString name,int* v,const QString comment,bool usemod_f){
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
        if(!QFile::copy(tmp_xml1,mcswitch_dir_env + fsp + name + fsp + eachEnvDataXmlName)) return false;
        QFile::setPermissions(mcswitch_dir_env + fsp + name + fsp + eachEnvDataXmlName,
                              QFile::ReadOwner  |
                              QFile::WriteOwner |
                              QFile::ReadUser   |
                              QFile::WriteUser
                              );
    }
    return true;
}

bool Environments::copyEnvContents(const QString from,const QString to){
    bool fromExist,toExist;
    for(int i = 0;i < envsVector.size();i++){
        if(envsVector[i]->getName() == from){
            fromExist = true;
        }
        if(envsVector[i]->getName() == to){
            toExist = true;
        }
    }
    if(fromExist == false || toExist == false) return false;
    QString hfrom,hto;
    if(getCurrentEnv()->getName() == from){
        hfrom =  mcswitch_dir + fsp + LOADING_DIR_NAME;
    }else{
        hfrom = mcswitch_dir_env + fsp + from;
    }

    if(getCurrentEnv()->getName() == to){
        hto = mcswitch_dir + fsp + LOADING_DIR_NAME;
    }else{
        hto = mcswitch_dir_env + fsp + to;
    }
    this->copyDirectoryAndFiles(hfrom,hto);
    return true;
}

bool Environments::changeEnv(QString env_name){
    for(int n = 0;n < envsVector.size();++n){
        if(envsVector[n]->getName() == env_name){
            if(QFile::exists(mcswitch_dir + fsp + LOADING_DIR_NAME)){
                MCEnv* e = new MCEnv(mcswitch_dir + fsp + LOADING_DIR_NAME);
                e->open();
                if(!QFile::rename(mcswitch_dir + fsp + LOADING_DIR_NAME,mcswitch_dir_env + fsp + e->getName())) return false;
                delete e;
            }
            if(!QFile::rename(mcswitch_dir_env + fsp + env_name,mcswitch_dir + fsp + LOADING_DIR_NAME)) return false;
        }
    }
    if(this->updateEnvData())
        return true;
    else
        return false;
}


bool Environments::copyDirectoryAndFiles(const QString from,const QString to){
    QDir dir(from);

    QDir toDir(to);
    if(!toDir.exists()){
        toDir.mkdir(to);
    }

    QStringList list = dir.entryList(QDir::NoDotAndDotDot | QDir::Hidden | QDir::AllEntries);
    QStringListIterator i(list);
    QString b,bf;
    while(i.hasNext()){
        b = i.next();
        if(b == eachEnvDataXmlName) continue;
        if(QFileInfo(from + fsp + b).isDir()){
            copyDirectoryAndFiles(from + fsp + b,to + fsp + b);
        }else{
            if(!QFile::copy(from + fsp + b,to + fsp + b)) return false;
        }
    }
    return true;
}
