#include "BigFile.h"

BigFile::BigFile(QObject *parent)
	: QObject(parent)
{
}

BigFile::~BigFile()
{
}

void BigFile::Save(const QString & baseDir, const QString & dstDir)
{
	QString idx = dstDir + "/" + BigfileName + ".idx";
	QFile fileIdx(idx);
	assert(fileIdx.open(QIODevice::WriteOnly));

	QString dat = dstDir + "/" + BigfileName + ".dat";
	QFile fileDat(dat);
	assert(fileDat.open(QIODevice::WriteOnly));

	int total = Handles.size();
	for (int i = 0; i < total; ++i) {
		auto handle = Handles.at(i);
		handle->SaveHandle(fileIdx);
		handle->SaveData(fileDat, baseDir);
	}
	fileIdx.close();
	fileDat.close();
}

void BigFile::AddHandle(const QString & baseDir, const QString file)
{
	auto handle = BigfileHandle::ParseFile(baseDir, file, BigfileName, CurrentPos, this);
	this->CurrentPos += handle->Lenth;
	Handles.append(handle);
}
