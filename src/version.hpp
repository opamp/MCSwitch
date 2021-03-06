#ifndef VERSION_HPP
#define VERSION_HPP
#include <QString>
#include <QDir>
#include <config.hpp>

#define LOADING_DIR_NAME "loadingenv"
#define DEFAULT_ENV_NAME "Main"

const QString fsp = QDir::separator();

const QString app_name = "MCSwitch"; // Application Full Name.
const QString app_ver = "0.4.1"; // Application Version.
const QString app_license = "MIT"; // Application License.

const QString mcswitch_dir = QDir::homePath() + fsp + ".MCSwitch"; //Application data dir.
const QString mcswitch_dir_common = mcswitch_dir + fsp + "common";
const QString mcswitch_dir_env = mcswitch_dir + fsp + "env";

const QString mcswitch_dir_env_link = QDir::homePath() + fsp + "MCSwitchEnvironments";

#ifdef P_OSX
const QString minecraft_dir = QDir::homePath() + "/Library/Application Support/minecraft"; //MacOSX
#endif
#ifdef P_LINUX
const QString minecraft_dir = QDir::homePath() + fsp + ".minecraft"; // linux(unix)
#endif

const QString eachEnvDataXmlName = ".mcswitch.xml";
/*resource*/
const QString license_text = ":/texts/resources/texts/LICENSE.txt";
const QString tmp_xml1 = ":/xmls/resources/xmls/tmp1.xml";
const QString tmp_xml2 = ":/xmls/resources/xmls/tmp2.xml";
#endif
