#include"MCEnv.hpp"

MCEnv::MCEnv(){

}

bool MCEnv::initEnv(const QString name, const QString dir_path){
    if(name.isEmpty() or path.isEmpty()) return false;
    if(!QDir(path).exists()) return false;
    QDir envsdir(mcswitch_dir_env);
    QStringList envs = envsdir.entryList();

    /*同名のenvがないかチェック*/
    QStringListIterator i(envs);
    while(i.hasNext()){
        if(i.next() == name){
            return false; // あったらfalseを返して終了
        }
    }

    if(!QDir.mkdir(dir_path + "/" + name)) return false;
}
