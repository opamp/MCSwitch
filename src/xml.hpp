#ifndef XML_HPP
#define XML_HPP
#include<QString>
#include<QFile>
#include<QDir>
#include<QDomDocument>
#include<QDomElement>
#include<QDomText>
#include<QDomNode>

const QString rootTagName = "MCSwitch_Env";
const int xml_indent = 4;

struct xml_data{
   QString name;
   QString version;
   QString comment;
   bool mods;
};typedef struct xml_data xml_d;


class Xml{
public:
    Xml(const QString);

    bool open(); // file path.
    void getXmlData(xml_d*);
    void setXmlData(xml_d*);
    bool save();
private:
    QString filename;
    xml_d data;
};
#endif
