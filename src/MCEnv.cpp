#include"MCEnv.hpp"

MCEnv::MCEnv(const QString path){
	if(QFile::exists(path))
		this->path = path;
	mods = false;
}

bool MCEnv::open(){
    xmlReader = new Xml(path + fsp +  eachEnvDataXmlName);
    if(!xmlReader->open()) return false;
    xml_d data;
    xmlReader->getXmlData(&data);
    envName = data.name;
	mcVersion = data.version;
	mods = data.mods;
    comment = data.comment;
    return true;
}

bool MCEnv::save(){
    xml_d data;
    data.name = envName;
    data.version = mcVersion;
    data.mods = mods;
    data.comment = comment;
    xmlReader->setXmlData(&data);
    return true;
}

bool MCEnv::initEnv(init_d *d, const QString dir_path){
    if(d->name.isEmpty() or dir_path.isEmpty()) return false;
    if(!QDir(dir_path).exists()) return false;
    QDir envsdir(mcswitch_dir_env);
    QStringList envs = envsdir.entryList();

    /*同名のenvがないかチェック*/
    QStringListIterator i(envs);
    while(i.hasNext()){
        if(i.next() == d->name){
            return false; // あったらfalseを返して終了
        }
    }

    if(!QDir().mkdir(dir_path + "/" + d->name)) return false;
    if(!QFile::copy(tmp_xml1,dir_path + "/" + d->name + "/" + eachEnvDataXmlName)) return false;
    QFile::setPermissions(dir_path + "/" + d->name + "/" + eachEnvDataXmlName,
                          QFile::ReadOwner  |
                          QFile::WriteOwner |
                          QFile::ReadUser   |
                          QFile::WriteUser
                          );

    Xml writer(dir_path + "/" + d->name + "/" + eachEnvDataXmlName);
    writer.open();
    xml_d data;
    data.name = d->name;
    data.version = QString::number(d->version[0]) + "." + QString::number(d->version[1]) + "." + QString::number(d->version[2]);
    data.mods = d->usemod;
    data.comment = d->comment;
    writer.setXmlData(&data);
    if(!writer.save()) return false;
    return true;
}


bool MCEnv::setName(const QString name){
    if(name.isEmpty()){
        return false;
    }else{
        this->envName = name;
        return true;
    }
}

bool MCEnv::setVersion(const QString version){
    if(version.isEmpty()){
        return false;
    }else{
        this->mcVersion = version;
        return true;
    }
}

bool MCEnv::setComment(const QString comment){
    this->comment = comment;
    return true;
}

bool MCEnv::setMods(bool f){
    this->mods = f;
    return true;
}
