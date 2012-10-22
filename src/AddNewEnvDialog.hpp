#ifndef ADD_NEW_ENV_DIALOG
#define ADD_NEW_ENV_DIALOG
#include<QtGui>

class AddNewEnvDialog : public QWidget{
	Q_OBJECT
public:
	AddNewEnvDialog(QWidget* parent = 0);
private:
	QLineEdit* nameEditor;
	QPushButton* OKButton;
	QPushButton* CancelButton;
};
#endif
