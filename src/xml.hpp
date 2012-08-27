#ifndef XML_HPP
#define XML_HPP
#include<QString>
#include<QFile>
#include<QDir>
#include<QtXml>

class Xml{
public:
    Xml();

    bool open(const QString); // file path.
    bool save();
private:
    QString filename;
};
#endif
