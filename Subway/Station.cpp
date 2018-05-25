#include "Station.h"

Station::Station(char *n, int i, int x, int y)
{
	strncpy(name, n, sizeof(name));
	name[sizeof(name) - 1] = '\0';
	id = i;
	vnum = 0;
	loc.x = x;
	loc.y = y;
}

char *Station::getname()
{
	return name;
}

void Station::addvid(int vi)
{
	vid[vnum++] = vi;
}

int Station::getid()
{
	return id;
}


int Station::getvid(int i)
{
	return vid[i];
}

int Station::getvnum()
{
	return vnum;
}

Point Station::getloc()
{
	return loc;
}
