#ifndef ADD_NEW_ENV_DIALOG
#define ADD_NEW_ENV_DIALOG
#include<QtGui>
#include<QTextEdit>
#include<QSpinBox>
#include<QLineEdit>
#include<QCheckBox>
#include<QLabel>
#include<QPushButton>

struct AddNewEnvDialogData{
    QString env_name;
    int version[3];//[0]->major,[1]->minor,[2]->patch
    QString comment;
    bool mod;
};typedef struct AddNewEnvDialogData AddNewEnvDialog_d;

class AddNewEnvDialog : public QWidget{
	Q_OBJECT
public:
    AddNewEnvDialog(QWidget* parent = 0);

protected:
    AddNewEnvDialog_d* getDatas();

private slots:
    void clickedOKButton();
    void clickedCancelButton();
    void changeCheckBox(int);

signals:
    void OKButtonIsPushed(AddNewEnvDialog_d*);
    void CancelButtonIsPushed();

private:
    AddNewEnvDialog_d data;
    QLineEdit* nameEditor;
    QTextEdit* commentEdit;
    QSpinBox* majorVersion;
    QSpinBox* minorVersion;
    QSpinBox* patchVersion;
    QCheckBox* usemodsBox;
	QPushButton* OKButton;
    QPushButton* CancelButton;

    QLabel* nameLabel;
    QLabel* commentLabel;
    QLabel* versionLabel;
    QLabel* modLabel;
};
#endif
