#ifndef VERSION_HPP
#define VERSION_HPP
#include<QString>
#include<QDir>

const QString app_name = "MCSwitch"; // Application Full Name.
const QString app_ver = "0.0.1-dev"; // Application Version.
const QString app_license = "MIT"; // Application License.

const QString mcswitch_dir = QDir::homePath() + "/.MCSwitch"; //Application data dir.
const QString mcswitch_dir_common = mcswitch_dir + "/common";
const QString mcswitch_dir_env = mcswitch_dir + "/env";

const QString minecraft_dir = QDir::homePath() + "/Library/Application\ Support/minecraft";

const QString eachEnvDataXmlName = ".mcswitch.xml";
/*resource*/
const QString license_text = ":/texts/resources/texts/LICENSE.txt";
const QString tmp_xml1 = ":/xmls/resources/xmls/tmp1.xml";
const QString tmp_xml2 = ":/xmls/resources/xmls/tmp2.xml";
#endif
