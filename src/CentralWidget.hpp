#ifndef CENTRALWIDGET_HPP
#define CENTRALWIDGET_HPP
#include <QtGui>
#include <QString>
#include <QComboBox>
#include <QHBoxLayout>
#include "Environments.hpp"
#include "addNewEnvDialog.hpp"
#include "ChangeEnvDataDialog.hpp"


class CentralWidget : public QWidget {
Q_OBJECT
public:
    CentralWidget(QWidget* parent = 0);

signals:
    void exitSignal();
    void requestToVisible();
    void requestToInvisible();
protected slots:
    void update();

public slots:
    void setVisibleTrue(){emit requestToVisible();};

private slots:
    void addNewEnvironment();
    void AddNewEnvDialogIsSet(AddNewEnvDialog_d*);
    void ExitButtonPushed();
    void OKButtonPushed();
    void callChangeEnvDataDialog();
    void selectEnvBoxChanged(const QString&);

private:
    void initEnvironments();
    void initComboBox(Environments*);
    void initButtons();
    void initInformationViewer();
    void setupUI();

    QComboBox* selectEnvBox;
    QPushButton* OKButton;
    QPushButton* AddButton;
    QPushButton* ChangeDataButton;
    QPushButton* ExitButton;

    QLabel* mViewer;
    QLabel* versionViewer;
    QTextEdit* commentViewer;

    QLabel* currentEnvLabel;
    QLineEdit* currentEnvView;

	AddNewEnvDialog* addEnvdlg;
	ChangeEnvDataDialog* changeDataDialog;

    Environments* mcenvs;
};
#endif
