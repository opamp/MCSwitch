#ifndef INITIALIZE_HPP
#define INITIALIZE_HPP
#include<QString>
#include<QStringList>
#include<QStringListIterator>
#include<QFile>
#include<QFileInfo>
#include<QDir>

#include"version.hpp"
#include"Environments.hpp"

#include<iostream>

bool rm_R(const QString dirName){
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
    if((new QDir())->rmdir(dirName)){
       return true;
    }
    return false;
}


bool initMCSwitchDir(){//init data dir.
	if(!QDir(mcswitch_dir).exists()){
		if(!QDir().mkdir(mcswitch_dir)) return false;
	}	
	if(!QDir(mcswitch_dir_env).exists()){
		if(!QDir().mkdir(mcswitch_dir_env)) return false;
	}
	if(!QDir(mcswitch_dir_common).exists()){
		if(!QDir().mkdir(mcswitch_dir_common)) return false;
	}
	if(!QFile().exists(mcswitch_dir_env_link)){
		if(!QFile().link(mcswitch_dir_env,mcswitch_dir_env_link)) return false;
	}
	return true;
}
bool init(){
	if(!initMCSwitchDir()) return false; //init data dirs.
	if(!QFile::exists(minecraft_dir + fsp + eachEnvDataXmlName)){
		//if(!Environments::installNewEnvironment(QString("InitialEnv"),minecraft_dir)) return false;//error
		if(!Environments::installNewEnvironment(QString(DEFAULT_ENV_NAME),minecraft_dir)) return false;//error
        /*
          tmp1をもとに生成したxmlをtmp2で生成し直す
        */

		/*
        QFile::remove(mcswitch_dir_env + fsp + "InitialEnv" + fsp + eachEnvDataXmlName);
        if(!QFile::copy(tmp_xml2,mcswitch_dir_env + fsp + "InitialEnv" + fsp + eachEnvDataXmlName)) return false;
        QFile::setPermissions(mcswitch_dir_env + "/InitialEnv/" + eachEnvDataXmlName,
                              QFile::ReadOwner  |
                              QFile::WriteOwner |
                              QFile::ReadUser   |
                              QFile::WriteUser
                              );
		if(!rm_R(minecraft_dir)) return false;
		QFile::rename(mcswitch_dir_env + fsp + "InitialEnv",mcswitch_dir + fsp + LOADING_DIR_NAME);
		if(!QFile::link(mcswitch_dir + fsp + LOADING_DIR_NAME,minecraft_dir)) return false;
    }*/
		QFile::remove(mcswitch_dir_env + fsp + DEFAULT_ENV_NAME + fsp + eachEnvDataXmlName);
        if(!QFile::copy(tmp_xml2,mcswitch_dir_env + fsp + DEFAULT_ENV_NAME + fsp + eachEnvDataXmlName)) return false;
        QFile::setPermissions(mcswitch_dir_env + fsp + DEFAULT_ENV_NAME +  fsp + eachEnvDataXmlName,
                              QFile::ReadOwner  |
                              QFile::WriteOwner |
                              QFile::ReadUser   |
                              QFile::WriteUser
                              );
		if(!rm_R(minecraft_dir)) return false;
		QFile::rename(mcswitch_dir_env + fsp + DEFAULT_ENV_NAME,mcswitch_dir + fsp + LOADING_DIR_NAME);
		if(!QFile::link(mcswitch_dir + fsp + LOADING_DIR_NAME,minecraft_dir)) return false;
    }
	return true;
}

#endif
