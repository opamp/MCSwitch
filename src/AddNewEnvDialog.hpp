#ifndef ADD_NEW_ENV_DIALOG
#define ADD_NEW_ENV_DIALOG
#include<QtGui>

class AddNewEnvDialog : public QWidget{
	Q_OBJECT
public:
    AddNewEnvDialog(QWidget* parent = 0);

private slots:
    void clickedOKButton();
signals:
    void OKButtonIsPushed();
private:
	QLineEdit* nameEditor;
	QPushButton* OKButton;
	QPushButton* CancelButton;
};
#endif
