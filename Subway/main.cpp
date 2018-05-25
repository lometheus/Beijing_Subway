#include "Subway.h"
#include <QtWidgets/QApplication>
int main(int argc, char *argv[])
{
	char *arg;
	if (argv[1])
	{
		if (!strcmp(argv[1], "/b"))
		{
			strcpy(arg, argv[2]);
			strcat(arg, "-");
			strcat(arg, argv[3]);
		}
		else if (!strcmp(argv[1], "/g"))
		{
			arg = argv[2];
		}
	}
	else
		arg = NULL;
	QApplication a(argc, argv);

	MainWindow w(arg);

	w.show();
	return a.exec();
}
