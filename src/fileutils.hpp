#ifndef FILEUTILS_HPP
#define FILEUTILS_HPP
#include<QString>
#include<QStringList>
#include<QFile>
#include<QFileInfo>
#include<QDir>

namespace fileutils{
	/*Directoryのコピーを行う*/
    bool cp_R(const QString from,const QString to){
		if(!QFileInfo(from).isDir())return false;
		if(to.isEmpty()) return false;
		if(!QDir().mkdir(to)) return false;

		QDir dir(from);
		QSringList list = dir.entryList();
		QStringListIterator i(list);
		QString b,bf;
		while(i.hasNext()){
			b = i.next();
			bf = from + "/" + b;
			//std::cout<<"=="<<bf.toStdString()<<std::endl;
			if(bf == from + "/" + QString(".") or bf == from + "/" + QString("..")) continue;
			if(QFileInfo(bf).isDir()){
				cp_R(bf,to + "/" + b);
			}else{
				if(!QFile::copy(bf,to + "/" + b)) return false;
			}
		}
		return true;
	}
}
#endif
