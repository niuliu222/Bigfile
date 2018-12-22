#pragma once

#include <QObject>
#include <qvector.h>
#include "BigfileHandle.h"
class BigFile : public QObject
{
	Q_OBJECT
public:
	QVector<BigfileHandle*> Handles;
	QString BigfileName;
	unsigned int CurrentPos = 0;
public:
	BigFile(QObject *parent);
	~BigFile();

	void Save(const QString & baseDir, const QString & dstDir);
	void AddHandle(const QString & baseDir, const QString file);
};
