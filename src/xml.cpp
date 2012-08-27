#include"xml.hpp"

Xml::Xml(){

}

bool Xml::open(const QString filename){
    if(!QFile::exists(filename)) return false;
    this->filename = filename;
}

bool Xml::save(){

}
