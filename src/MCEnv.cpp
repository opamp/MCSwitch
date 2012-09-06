#include"MCEnv.hpp"

MCEnv::MCEnv(const QString path){
	if(QFile::exists(path))
		this->path = path;
	mods = false;
}

bool MCEnv::open(){
	Xml xmlReader(path);
	if(!xmlReader.open()) return false;
	xml_d data;
	xmlReader.getXmlData(&data);
	envName = data.name;
	mcVersion = data.version;
	mods = data.mods;
	comment = data.comment;
}

bool MCEnv::initEnv(const QString name, const QString dir_path){
    if(name.isEmpty() or dir_path.isEmpty()) return false;
    if(!QDir(dir_path).exists()) return false;
    QDir envsdir(mcswitch_dir_env);
    QStringList envs = envsdir.entryList();

    /*同名のenvがないかチェック*/
    QStringListIterator i(envs);
    while(i.hasNext()){
        if(i.next() == name){
            return false; // あったらfalseを返して終了
        }
    }

    if(!QDir().mkdir(dir_path + "/" + name)) return false;
    if(!QFile::copy(tmp_xml1,dir_path + "/" + name + "/" + eachEnvDataXmlName)) return false;
    QFile::setPermissions(dir_path + "/" + name + "/" + eachEnvDataXmlName,
                          QFile::ReadOwner  |
                          QFile::WriteOwner |
                          QFile::ReadUser   |
                          QFile::WriteUser
                          );

    return true;
}
