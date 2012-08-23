#ifndef ENVIRONMENT_HPP
#define ENVIRONMENT_HPP
#include<QObject>

class Environment{
public:
    Environment();

    static bool createNewEnvironemnt();
    static bool installNewEnvironment();
    static bool removeEnvironment();
};
#endif
