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
		QStringList list = dir.entryList();
		QStringListIterator i(list);
		QString b,bf;
		while(i.hasNext()){
			b = i.next();
			bf = from + "/" + b;
			if(bf == from + "/" + QString(".") or bf == from + "/" + QString("..")) continue;
			if(QFileInfo(bf).isDir()){
				cp_R(bf,to + "/" + b);
			}else{
				if(!QFile::copy(bf,to + "/" + b)) return false;
			}
		}
		return true;
    }

    bool rm_R(const QString dirName){
        if(!QFileInfo(dirName).isDir()) return false;

        QDir dir(dirName);
        QStringList list = dir.entryList();
        QStringListIterator i(list);
        QString b;

        while(i.hasNext()){
            b = i.next();
            if(b == QString(".") or b == QString("..")) continue;
            if(QFileInfo(b).isDir()){
                rm_R(b);
            }else{
                if(!QFile::remove(b)) return false;
            }
        }
        if((new QDir())->rmdir(dirName)) return true;
        return false;
    }
}
#endif
