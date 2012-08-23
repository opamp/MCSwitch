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

    static bool createNewEnvironemnt(const QString);
    static bool installNewEnvironment(const QString);
    static bool removeEnvironment(const QString);

private:
    QVector* envsVector;
};
#endif
