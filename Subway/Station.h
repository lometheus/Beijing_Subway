#pragma once
#include <iostream>
#define Max 10000
#define Max_Sta 500
struct Point {
	int x;
	int y;
};
class Station
{
public:
	Station(char *n, int i, int x, int y);
	void addvid(int vi);
	char *getname();
	int getid();
	int getvid(int i);
	int getvnum();
	Point getloc();

private:
	char name[30];
	int id;
	int vid[10];
	int vnum;
	Point loc;
};
