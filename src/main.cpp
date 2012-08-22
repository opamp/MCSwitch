#include<QApplication>
#include<version.hpp>

int main(int argc,char** argv){
	QApplication mcswitch(argc,argv);

	mcswitch.setApplicationName(app_name);
	mcswitch.setApllicationVersion(app_ver);


	return mcswitch.exec();
}
