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

class Line
{
public:
	Line(char *n);
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

class Read
{
public:
	Read(char *pathfile);
	void setvlink(int a, int b);
	void setvlink_c(int a, int b);
	void addline(Line *line);
	int str2id(char *s);
	char *id2str(int i);
	char *id2line(int i);
	int linked(char *s1, char *s2);
	int connected(int id1, int id2);
	int *findway(char *s1, char *s2, int type);
	int *shortestway(char *s1, char *s2);
	int *least_transfer(char *s1, char *s2);
	int printline(char *s);
	int getlinenum();
	int getstanum();
	int *getline(int i);
	Point getloc(int i);
	void Dijkstra(int n, int v, int *dist, int *prev);
	Station *stas[Max_Sta];
	Line *lines[50];
	void init();
	~Read();
private:
	int useful;
	char name[30];
	int stanum = 0;
	int linenum = 0;
	int vstanum = 0;
	int **v2pandl;
	int **vlink;
	int **vlink_c;

	
};

