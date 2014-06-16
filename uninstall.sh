#!/bin/zsh

UNAME=`uname`
if test ${UNAME} = "Darwin";then #DARWIN
    if [ -L $HOME/Library/Application\ Support/minecraft ];then
        rm -fr $HOME/Library/Application\ Support/minecraft
        mv $HOME/.MCSwitch/loadingenv $HOME/Library/Application\ Support/minecraft
        mv $HOME/.MCSwitch/env $HOME/Desktop/MCSwitchEnvs
        rm -f $HOME/Library/Application\ Support/minecraft/.mcswitch.xml
        rm -fr $HOME/.MCSwitch
        rm -f $HOME/MCSwitchEnvironments
        echo "FINISHED"
    else
        echo "ERROR"
    fi
elif test ${UNAME} = "Linux";then #LINUX
    if [ -L $HOME/.minecraft ];then
        rm -fr $HOME/.minecraft
        mv $HOME/.MCSwitch/loadingenv $HOME/.minecraft
        mv $HOME/.MCSwitch/env $HOME/MCSwitchEnvsBackup
        rm -f $HOME/.minecraft/.mcswitch.xml
        rm -fr $HOME/.MCSwitch
        rm -f $HOME/MCSwitchEnvironments
        echo "FINISHED"
    else
        echo "ERROR"
    fi
else
    echo "not supported"
fi
