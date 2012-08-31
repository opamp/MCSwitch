#include"xml.hpp"

Xml::Xml(){
    data.mods = false;
}

bool Xml::open(const QString filename){
    if(!QFile::exists(filename)) return false;
    this->filename = filename;
    QDomDocument doc;
    QString error;int errorline;int errorColmun;
    QString rootTagName = "MCSwitch_Env";
    QFile f(this->filename);

    if(f.open(QIODevice::ReadOnly)){
        //fail to open file.
        return false;
    }

    if(!doc.setContent(&f,true,&error,&errorline,&errorColmun)){
        //fail to set content.
        f.close();
        return false;
    }
    QDomElement root = doc.documentElement();
    if(root.tagName().toStdString() != rootTagName){
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

bool Xml::save(){
    return true;
}
