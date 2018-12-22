#include "PackageBigfile.h"
#include "../../../Bigfile.h"

PackageBigfile::PackageBigfile(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

void PackageBigfile::OnChooseBaseDirClick()
{
}
#include "Database.h"
#include <qmessagebox.h>
void PackageBigfile::OnStartPackage()
{
	ui.StartPackage->setEnabled(false);

	Database * db = new Database(nullptr);
	db->PackageDir(ui.dir->text());

	db->Save(ui.dst->text());
	delete db;
	ui.StartPackage->setEnabled(true);
	QMessageBox::information(this, QString::fromLocal8Bit("打包完成"), QString::fromLocal8Bit("打包完成"));
}
