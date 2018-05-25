#include "Line.h"

//using namespace std;

STATIONLine::STATIONLine(char *n)
{
	strncpy(name, n, sizeof(name));
	name[sizeof(name) - 1] = '\0';
	stanum = 0;
}

void STATIONLine::addsta(Station *sta)
{
	stas[stanum++] = sta;
}

int STATIONLine::idexist(int id)
{
	for (int i = 0; i < stanum; i++) {
		if (id == stas[i]->getid())
		{
			return 1;
		}
	}
	return 0;
}

int STATIONLine::getstanum()
{
	return stanum;
}

char *STATIONLine::getname()
{
	return name;
}

void STATIONLine::printline()
{
	char s[30];
	for (int i = 0; i < stanum; i++) {
		strncpy(s, stas[i]->getname(), 30);
		//cout << s << endl;
	}
}


int *STATIONLine::getstas()
{
	int i;
	int *stasid = new int[100];
	for (i = 0; i < stanum; i++) {
		stasid[i] = stas[i]->getid();
	}
	stasid[i] = -1;
	return stasid;
}

