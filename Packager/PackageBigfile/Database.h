#pragma once

#include <QObject>
#include <qvector.h>
#include <BigFile.h>
class Database : public QObject
{
	Q_OBJECT
public:
	QVector<BigFile*> Bigfiles;
	QString BaseUrl;
	int BigfileIndex = 1;
	QString Prefix = "Bigfile";
	unsigned MaxFileSize = (1024 * 1024 * 1024 * 3);//3G
public:
	Database(QObject *parent);
	~Database();

	void PackageDir(QString dir);
	void Save(const QString & dstDir);
private:
	void FindFiles(QString baseDir, QString dir);
};
