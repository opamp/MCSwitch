#pragma onece
#include<QString>
#include<QFile>
#include<QDir>
#include"version.hpp"

bool initMCSwitchDir(){//init data dir.
	if(QDir(mcswitch_dir).exists() and QDir(mcswitch_dir_common).exists() and QDir(mcswitch_dir_env).exists()) return true;
	if(!QDir().mkdir(mcswitch_dir)) return false;
	if(!QDir().mkdir(mcswitch_dir_common)) return false;
	if(!QDir().mkdir(mcswitch_dir_env)) return false;
	return true;
}

bool init(){ 
	if(!initMCSwitchDir()) return false;
	return true;
}

