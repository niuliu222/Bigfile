#pragma once

#include <QtWidgets/QWidget>
#include "ui_PackageBigfile.h"

class PackageBigfile : public QWidget
{
	Q_OBJECT

public:
	PackageBigfile(QWidget *parent = Q_NULLPTR);
public slots:
	void OnChooseBaseDirClick();
	void OnStartPackage();
private:
	//QString GetChooseDir();

	Ui::PackageBigfileClass ui;
};
