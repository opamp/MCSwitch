#ifndef ENVIRONMENT_HPP
#define ENVIRONMENT_HPP
#include <QObject>
#include <QString>
#include <QStringList>
#include <QDir>
#include <QFile>
#include <QVector>

#include"MCEnv.hpp"

class Environments : public QObject{
Q_OBJECT
public:
    Environments(const QString path = mcswitch_dir_env);

    /*
    引数には新しく作る環境の名前を渡す
    第一引数 -> name
    第二引数 -> version配列
    第三引数 -> comment
    第四引数 -> use mod
    */
    static bool createNewEnvironemnt(const QString,int*,const QString,bool);
    /*nameには新しく作る環境の名前を、pathにはinstallするminecraftフォルダのPATHを渡す*/
    static bool installNewEnvironment(const QString name, const QString path);

    /*Environmentの内容(.mcswitch.xmlを除く)をfromからtoへコピーする。fromもtoも存在するenvironment名である必要がある*/
    bool copyEnvContents(const QString,const QString);
    /*envsVectorを読み込み直す*/
    int updateEnvData();
    /*環境の数を返す*/
    int getNumberOfEnvironments();
    /*n番目の環境のMCEnvデータへのポインタを返す*/
    MCEnv* getMCEnv(int n);
    /*現在有効になっている環境を返す*/
    MCEnv* getCurrentEnv();
    /*QStringで指定された名前の環境に変更する*/
    bool changeEnv(QString);

private:
    bool copyDirectoryAndFiles(const QString,const QString);
    QString path;
    QVector<MCEnv*> envsVector;
};
#endif
