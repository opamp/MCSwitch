#!/bin/zsh

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

