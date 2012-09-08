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
    bool save();

	QString getPath(){return path;};
    QString getName(){return envName;};
    QString getVersion(){return mcVersion;};
    QString getComment(){return comment;};
    bool getMods(){return mods;};


    bool setName(const QString);
    bool setVersion(const QString);
    bool setComment(const QString);
    bool setMods(bool);


    static bool initEnv(const QString name,const QString dir_path = mcswitch_dir_env);
private:
	QString path;
    QString envName;
	QString mcVersion;
	QString comment;
    bool mods;

    Xml *xmlReader;
};
#endif
