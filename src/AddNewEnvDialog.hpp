#ifndef ADD_NEW_ENV_DIALOG
#define ADD_NEW_ENV_DIALOG
#include<QtGui>

struct AddNewEnvDialogData{
    QString env_name;
};typedef struct AddNewEnvDialogData AddNewEnvDialog_d;

class AddNewEnvDialog : public QWidget{
	Q_OBJECT
public:
    AddNewEnvDialog(QWidget* parent = 0);
    AddNewEnvDialog_d* getDatas();

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
