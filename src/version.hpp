#pragma onece
#include<QString>
#include<QDir>

const QString app_name = "MCSwitch"; // Application Full Name.
const QString app_ver = "0.0.1-dev"; // Application Version.
const QString app_license = "MIT"; // Application License.

const QString mcswitch_dir = QDir::homePath() + "/.MCSwitch"; //Application data dir.
const QString mcswitch_dir_common = mcswitch_dir + "/common";
const QString mcswitch_dir_env = mcswitch_dir + "/env";
