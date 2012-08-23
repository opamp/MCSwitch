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
		if(QFile::exists(to) or to.isEmpty()) return false;
		if(!QDir().mkdir(to)) return false;

		QDir dir(from);
		QStringList list = dir.entryList();
		QStringListIterator i(list);
		while(i.hasNext()){
			if(FileInfo(i.next()).isDir()){
				cp_R(i.next(),to + "/" + i.next());
			}else{
				QFile::copy(i.next(),to + "/" + i.next());
			}
		}
		return true;
	}
}
#endif
