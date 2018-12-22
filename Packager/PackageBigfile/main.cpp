#include "PackageBigfile.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	PackageBigfile w;
	w.show();
	return a.exec();
}
