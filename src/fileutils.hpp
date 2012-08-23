#ifndef FILEUTILS_HPP
#define FILEUTILS_HPP
#include<QString>
#include<QStringList>
#include<QFile>
#include<QFileInfo>
#include<QDir>

#include<iostream>

namespace fileutils{
	/*Directoryのコピーを行う*/
    bool cp_R(const QString from,const QString to){
        if(!QFileInfo(from).isDir())return false;
        if(to.isEmpty()) return false;
        if(!QDir().mkdir(to)) return false;

		QDir dir(from);
		QStringList list = dir.entryList();
        QStringListIterator i(list);
        QString b,bf;
        while(i.hasNext()){
            b = i.next();
            bf = from + "/" + b;
            std::cout<<"=="<<bf.toStdString()<<std::endl;
            if(bf == from + "/" + QString(".") or bf == from + "/" + QString("..")){
                std::cout<<"==SKIP"<<std::endl;
                continue;
            }
            if(QFileInfo(bf).isDir()){
                std::cout<<"qfileinfo id dir\n";
                cp_R(bf,to + "/" + b);
            }else{
                std::cout<<"qfileinfo id is not dir."<<std::endl;
                if(!QFile::copy(bf,to + "/" + b)) return false;
			}
		}
		return true;
	}
}
#endif
