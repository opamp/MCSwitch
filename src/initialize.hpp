#pragma onece
#include<QString>
#include<QFile>
#include<QDir>
#include"version.hpp"


bool init(){ 
	if(!initMCSwitchDir()) return false;
	return true;
}

bool initMCSwitchDir(){//init data dir.
	if(QDir(mcswitch_dir).exists()) return true;
	if(QDir().mkdir(mcswitch_dir)) return true;
	return false;
}
