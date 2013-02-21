#ifndef INITIALIZE_HPP
#define INITIALIZE_HPP
#include<QString>
#include<QFile>
#include<QDir>
#include"version.hpp"
#include"Environments.hpp"

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
        if(!Environments::installNewEnvironment(QString("InitialEnv"),minecraft_dir)) return false;//error
        /*
          tmp1をもとに生成したxmlをtmp2で生成し直す
        */
        QFile::remove(mcswitch_dir_env + fsp + "InitialEnv" + fsp + eachEnvDataXmlName);
        if(!QFile::copy(tmp_xml2,mcswitch_dir_env + fsp + "InitialEnv" + fsp + eachEnvDataXmlName)) return false;
        QFile::setPermissions(mcswitch_dir_env + "/InitialEnv/" + eachEnvDataXmlName,
                              QFile::ReadOwner  |
                              QFile::WriteOwner |
                              QFile::ReadUser   |
                              QFile::WriteUser
                              );
        if(!QFile::copy(mcswitch_dir_env + fsp + "InitialEnv" + fsp + eachEnvDataXmlName ,minecraft_dir + fsp + eachEnvDataXmlName)) return false;
    }
	return true;
}

#endif
