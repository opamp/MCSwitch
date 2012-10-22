#include "AddNewEnvDialog.hpp"


AddNewEnvDialog::AddNewEnvDialog(QWidget* parent):
	QWidget(parent)
{
	OKButton = new QPushButton("OK");
	CancelButton = new QPushButton("Cancel");
	nameEditor = new QLineEdit();

	QHBoxLayout* buttonsLayout = new QHBoxLayout();
	buttonsLayout->addWidget(OKButton);
	buttonsLayout->addWidget(CancelButton);

	QVBoxLayout* mainLayout = new QVBoxLayout();
	mainLayout->addWidget(nameEditor);
	mainLayout->addLayout(buttonsLayout);

    setLayout(mainLayout);
}
