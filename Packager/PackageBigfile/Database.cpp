#include "Database.h"

Database::Database(QObject *parent)
	: QObject(parent)
{
}

Database::~Database()
{
}

void Database::PackageDir( QString dir)
{
	BaseUrl = dir;
	FindFiles(dir, dir);
}
void Database::Save(const QString & dstDir)
{
	QFile file(dstDir + "/" + "Database");
	assert(file.open(QIODevice::WriteOnly));

	int total = Bigfiles.size();
	for (int i = 0; i < total; ++i) {
		QString str = Bigfiles.at(i)->BigfileName;
		file.write(str.toStdString().c_str());
		if (i < total - 1) {
			file.write("\n");
		}
		Bigfiles.at(i)->Save(BaseUrl, dstDir);
	}
	file.close();
}
#include <qdir.h>
#include "BigFile.h"
void Database::FindFiles(QString baseDir, QString dirpath)
{
	QDir dir(dirpath);
	if (!dir.exists()) {
		return;
	}
	dir.setFilter(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);
	dir.setSorting(QDir::DirsFirst);

	QFileInfoList list = dir.entryInfoList();
	if (list.size() < 1) {
		return;
	}
	int i = 0;

	do {
		QFileInfo fileInfo = list.at(i);
		bool bisDir = fileInfo.isDir();
		if (bisDir) {
			FindFiles(baseDir, fileInfo.filePath());
		}
		else {
			//qDebug() << fileInfo.filePath() << ":" << fileInfo.fileName();
			QString filepath = fileInfo.filePath();
			QString relPath = filepath.mid(baseDir.length() + 1);

			if (Bigfiles.size() == 0) {
				auto bf = new BigFile(this);
				Bigfiles.append(bf);
				bf->BigfileName = Prefix + "_" + QString::number(BigfileIndex);
				++BigfileIndex;
			}

			BigFile* bigfile = Bigfiles.at(Bigfiles.size() - 1);
			if (bigfile->CurrentPos > MaxFileSize) {
				Bigfiles.append(new BigFile(this));
				bigfile = Bigfiles.at(Bigfiles.size() - 1);
				bigfile->BigfileName = Prefix + "_" + QString::number(BigfileIndex);
				++BigfileIndex;
			}
			
			bigfile->AddHandle(baseDir, relPath);
			//this->Bigfiles.append(bigfile);
		}//end else
		i++;
	} while (i < list.size());
}
