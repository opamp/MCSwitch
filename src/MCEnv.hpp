#ifndef MCENV_HPP
#define MCENV_HPP
#include<QObject>
#include<QDir>
#include<QFile>
#include<QString>
#include"xml.hpp"
#include"version.hpp"

class MCEnv : public QObject{
Q_OBJECT
public:
    MCEnv(const QString); // path to env dir.

	bool open();

	QString getPath(){return path;};
    QString name(){return envName;};


    static bool initEnv(const QString name,const QString dir_path = mcswitch_dir_env);
private:
	QString path;
    QString envName;
	QString mcVersion;
	QString comment;
	bool mods;
};
#endif
