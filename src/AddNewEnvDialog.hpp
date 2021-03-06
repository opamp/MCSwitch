#ifndef ADD_NEW_ENV_DIALOG
#define ADD_NEW_ENV_DIALOG
#include <QtGui>
#include <QTextEdit>
#include <QSpinBox>
#include <QLineEdit>
#include <QCheckBox>
#include <QComboBox>
#include <QLabel>
#include <QPushButton>

#define COPYFROM_SELECT_NOTHING "NOTHING"

struct AddNewEnvDialogData{
    QString env_name;
    QString copyFrom;
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
    void setZero();
private slots:
    void clickedOKButton();
    void clickedCancelButton();
    void changeCheckBox(int);

signals:
    void OKButtonIsPushed(AddNewEnvDialog_d*);
    void CancelButtonIsPushed();

private:
    void initCopyFromBox();

    AddNewEnvDialog_d data;
    QLineEdit* nameEditor;
    QTextEdit* commentEdit;
    QSpinBox* majorVersion;
    QSpinBox* minorVersion;
    QSpinBox* patchVersion;
    QCheckBox* usemodsBox;
    QPushButton* OKButton;
    QPushButton* CancelButton;
    QComboBox* copyFromBox;

    QLabel* nameLabel;
    QLabel* commentLabel;
    QLabel* versionLabel;
    QLabel* modLabel;
    QLabel* comboBoxLabel;
};
#endif
