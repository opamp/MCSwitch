#ifndef XML_HPP
#define XML_HPP
#include<QString>
#include<QFile>
#include<QDir>
#include<QDomDocument>
#include<QDomElement>
#include<QDomText>
#include<QDomNode>

struct xml_data{
   QString name;
   QString version;
   QString comment;
   bool mods;
};typedef struct xml_data xml_d;


class Xml{
public:
    Xml();

    bool open(const QString); // file path.
    bool save();
private:
    QString filename;
    xml_d data;
};
#endif
