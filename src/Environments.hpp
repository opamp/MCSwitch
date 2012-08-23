#ifndef ENVIRONMENT_HPP
#define ENVIRONMENT_HPP
#include<QObject>
#include<QString>
#include<QStringList>
#include<QDir>
#include<QFile>
#include<QVector>

#include"MCEnv.hpp"

class Environments : public QObject{
Q_OBJECT
public:
    Environments();

    /*引数には新しく作る環境の名前を渡す*/
    static bool createNewEnvironemnt(const QString);
    /*nameには新しく作る環境の名前を、pathにはinstallするminecraftフォルダのPATHを渡す*/
    static bool installNewEnvironment(const QString name, const QString path);
    /*指定した名前の環境を削除*/
    static bool removeEnvironment(const QString);

private:
    QVector<MCEnv> envsVector;
};
#endif
