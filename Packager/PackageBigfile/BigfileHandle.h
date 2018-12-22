#pragma once

#include <QObject>
#include <qfile.h>
class BigfileHandle : public QObject
{
	Q_OBJECT
public:
	QString FileName;
	QString BFName;
	unsigned int StartPos;
	unsigned int Lenth;
public:
	BigfileHandle(QObject *parent);
	~BigfileHandle();

	void SaveHandle(QFile & file);
	void SaveData(QFile & file, const QString & baseDir);
	static BigfileHandle * ParseFile(const QString & baseDir, const QString & file, const QString BFName, unsigned int start_pos, QObject * parent);
};
