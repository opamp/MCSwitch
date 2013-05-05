#ifndef DELETE_ENV_DIALOG_HPP
#define DELETE_ENV_DIALOG_HPP
#include <QWidget>
#include <QStringList>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>

class DeleteEnvDialog : public QWidget{
    Q_OBJECT
public:
    DeleteEnvDialog(QWidget* parent = 0);
    void updateSelector();

private slots:
    void targetChanged(const QString&);
    void pushedOKButton();
    void pushedCancelButton();
signals:
    void finished();

private:
    bool rm_R(const QString&);
    QString target;
    QStringList dirList;
    QLabel* msgLabel;
    QComboBox* selector;
    QPushButton* okButton;
    QPushButton* cancelButton;
};
#endif
