#include"xml.hpp"

Xml::Xml(){

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
        return false;
    }
    QDomElement root = doc.documentElement();
    if(root.tagName().toStdString() != rootTagName){
        return false;
    }

    QDomNode node = root.firstChild();
    while(!node.isNull()){
        if(node.toElement().tagName().toStdString() == "name"){

        }
        else if(node.toElement().tagName().toStdString() == "version"){

        }
        else if(node.toElement().tagName().toStdString() == "mods"){

        }
        else if(node.toElement().tagName().toStdString() == "comment"){

        }
        else{

        }
    }

    return true;
}

bool Xml::save(){
    return true;
}
