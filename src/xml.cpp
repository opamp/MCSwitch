#include <QTextStream>
#include "xml.hpp"

Xml::Xml(const QString &f){
    data.mods = false;
    filename = f;
}

bool Xml::open(){
    if(!QFile::exists(filename)) return false;
    QDomDocument doc;
    QString error;int errorline;int errorColmun;
    QFile f(this->filename);

    if(!f.open(QIODevice::ReadOnly)){
        //fail to open file.
        return false;
    }

    if(!doc.setContent(&f,true,&error,&errorline,&errorColmun)){
        //fail to set content.
        f.close();
        return false;
    }
    QDomElement root = doc.documentElement();
    if(root.tagName() != rootTagName){
        return false;
    }

    QDomNode node = root.firstChild();
    while(!node.isNull()){
        if(node.toElement().tagName().toStdString() == "name"){
            data.name = node.toElement().text();
        }
        else if(node.toElement().tagName().toStdString() == "version"){
            data.version = node.toElement().text();
        }
        else if(node.toElement().tagName().toStdString() == "mods"){
            if(node.toElement().attribute("enable","false").toStdString() == "true"){
                data.mods = true;
            }else{
                data.mods = false;
            }
        }
        else if(node.toElement().tagName().toStdString() == "comment"){
            data.comment = node.toElement().text();
        }
        else{
            //else
        }
        node = node.nextSibling();
    }

    f.close();
    return true;
}

void Xml::getXmlData(xml_d* d){
    *d = data;
}

void Xml::setXmlData(xml_d* d){
    data = *d;
}

bool Xml::save(){
    if(data.name.isEmpty()) return false;
    if(data.version.isEmpty()) return false;

    QDomDocument doc;
    QDomElement newroot = doc.createElement(rootTagName);
    doc.appendChild(newroot);

    QDomElement E_name = doc.createElement("name");
    QDomElement E_version = doc.createElement("version");
    QDomElement E_mods = doc.createElement("mods");
    QDomElement E_comment = doc.createElement("comment");


    QDomText name_text = doc.createTextNode(data.name);
    QDomText version_text = doc.createTextNode(data.version);
    QDomText comment_test = doc.createTextNode(data.comment);
    E_name.appendChild(name_text);
    E_version.appendChild(version_text);
    E_comment.appendChild(comment_test);

    if(data.mods == true)
        E_mods.setAttribute(QString("enable"),QString("true"));
    else
        E_mods.setAttribute(QString("enable"),QString("false"));

    newroot.appendChild(E_name);
    newroot.appendChild(E_version);
    newroot.appendChild(E_mods);
    newroot.appendChild(E_comment);

    QFile file(filename);file.open(QIODevice::WriteOnly);
    QTextStream out(&file);
    doc.save(out,xml_indent);

    file.close();
    return true;
}
