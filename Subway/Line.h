#include "Station.h"
#include<stdio.h>
#include<fstream>
#include <string.h>

class STATIONLine
{
public:
	STATIONLine(char *n);
	void addsta(Station *sta);
	int getstanum();
	int idexist(int id);
	char *getname();
	void printline();
	int *getstas();
private:
	char name[30];
	Station *stas[50];
	int stanum;
};