#include "BigfileHandle.h"

BigfileHandle::BigfileHandle(QObject *parent)
	: QObject(parent)
{
}

BigfileHandle::~BigfileHandle()
{
}

const char * HANDLE_SPLITTER = "*";
#include <qfileinfo.h>
void BigfileHandle::SaveHandle(QFile & file)
{
	file.write(this->FileName.toStdString().c_str());
	file.write(HANDLE_SPLITTER);
	//file.write(this->BFName.toStdString().c_str());
	//file.write(" ");
	
	file.write(QString::number(StartPos).toStdString().c_str());
	file.write(HANDLE_SPLITTER);
	file.write(QString::number(Lenth).toStdString().c_str());
	file.write("\n");
}

void BigfileHandle::SaveData(QFile & file, const QString & baseDir)
{
	QString path = baseDir + "/" + FileName;
	QFile curr_file(path);

	assert(curr_file.open(QIODevice::ReadOnly));
	auto byte = curr_file.readAll();

	file.write(byte);
}

BigfileHandle * BigfileHandle::ParseFile(const QString & baseDir, const QString & file, const QString BFName, unsigned int start_pos, QObject * parent)
{
	BigfileHandle* handle = new BigfileHandle(parent);
	QFileInfo info(baseDir + "/" + file);
	handle->Lenth = info.size();
	handle->FileName = file;
	handle->BFName = BFName;
	handle->StartPos = start_pos;
	return handle;
}
