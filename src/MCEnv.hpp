#ifndef MCENV_HPP
#define MCENV_HPP
#include<QObject>
#include<QDir>
#include<QFile>
#include<QString>
#include"version.hpp"

class MCEnv : public QObject{
Q_OBJECT
public:
    MCEnv();
    QString name(){return envName;};


    static bool initEnv(const QString name,const QString dir_path = mcswitch_dir_env);
private:
    QString envName;
};
#endif
