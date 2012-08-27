#ifndef XML_HPP
#define XML_HPP
#include<QString>
#include<QFile>
#include<QDir>
#include<QDomDocument>
#include<QDomElement>
#include<QDomText>
#include<QDomNode>

class Xml{
public:
    Xml();

    bool open(const QString); // file path.
    bool save();
private:
    QString filename;
};
#endif
