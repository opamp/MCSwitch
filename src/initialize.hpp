#ifndef INITIALIZE_HPP
#define INITIALIZE_HPP
#include<QString>
#include<QFile>
#include<QDir>
#include"version.hpp"
#include"Environments.hpp"

bool initMCSwitchDir(){//init data dir.
	if(QDir(mcswitch_dir).exists() and QDir(mcswitch_dir_common).exists() and QDir(mcswitch_dir_env).exists()) return true;
	if(!QDir().mkdir(mcswitch_dir)) return false;
	if(!QDir().mkdir(mcswitch_dir_common)) return false;
	if(!QDir().mkdir(mcswitch_dir_env)) return false;
	return true;
}

bool init(){ 
	if(!initMCSwitchDir()) return false;
	if(!QFile::exists(minecraft_dir + "/" + eachEnvDataXmlName)){
        if(!Environments::installNewEnvironment(QString("InitialEnv"),minecraft_dir)) return false;//error
        /*
          tmp1をもとに生成したxmlをtmp2で生成し直す
        */
        QFile::remove(mcswitch_dir_env + "/InitialEnv/" + eachEnvDataXmlName);
        if(!QFile::copy(tmp_xml2,mcswitch_dir_env + "/InitialEnv/" + eachEnvDataXmlName)) return false;
        QFile::setPermissions(mcswitch_dir_env + "/InitialEnv/" + eachEnvDataXmlName,
                              QFile::ReadOwner  |
                              QFile::WriteOwner |
                              QFile::ReadUser   |
                              QFile::WriteUser
                              );
        if(!QFile::copy(mcswitch_dir_env + "/InitialEnv/" + eachEnvDataXmlName ,minecraft_dir + "/" + eachEnvDataXmlName)) return false;
    }
	return true;
}

#endif
