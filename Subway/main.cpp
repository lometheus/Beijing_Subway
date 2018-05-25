#include "Subway.h"
#include <QtWidgets/QApplication>
using namespace std;
int main(int argc, char *argv[])
{
	char *arg;
	cout << argv[1] << endl;
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
	QApplication a(argc, argv);
	MainWindow w(arg);

	w.show();
	return a.exec();
}
