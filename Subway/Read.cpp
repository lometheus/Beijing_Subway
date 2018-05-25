#include "Read.h"

#include<stdio.h>
#include<fstream>
#include <string.h>
using namespace std;
#pragma warning(disable:4996);

Read::Read(char *path)
{
	FILE *in;
	char buffer[500];
	char *part;
	Line *linetmp;
	Station *tmp;
	int id;
	int vnum, vid, lastno, firstno;
	int tag;
	int x, y;
	char name[30];
	init();
	if ((in = fopen(path, "r")) == NULL) {
		useful = 0;
		return;
	}
	//处理表，存入stas数组
	while (fgets(buffer, 500, in) != NULL) {
		if (!strcmp(buffer, "\n")) {
			break;
		}
		part = strtok(buffer, " ");
		id = atoi(part);
		part = strtok(NULL, " ");
		//part[strlen(part) - 1] = '\0';
		strncpy(name, part, strlen(part) + 1);
		part = strtok(NULL, " ");
		x = atoi(part);
		part = strtok(NULL, " ");
		y = atoi(part);
		tmp = new Station(name, id, x, y);
		stas[++stanum] = tmp;

	}
	for (int i = 0; i < Max_Sta; i++) {
		for (int j = 0; j < Max_Sta; j++) {
			vlink[i][j] = Max;
			vlink_c[i][j] = Max;
		}
	}
	vnum = 0;
	while ((fgets(buffer, 500, in) != NULL)) {
		tag = 0;
		lastno = -1;
		//读入线名
		for (int i = strlen(buffer) - 1; i >= 0; i--) {
			if (buffer[i] == ' ' || buffer[i] == '\n') {
				buffer[i] = '\0';
			}
			else {
				break;
			}
		}
		linetmp = new Line(buffer);
		if (fgets(buffer, 500, in) == NULL) {
			break;
		}
		//站名
		for (int i = strlen(buffer) - 1; i >= 0; i--) {
			if (buffer[i] == ' ' || buffer[i] == '\n') {
				buffer[i] = '\0';
			}
			else {
				break;
			}
		}
		part = strtok(buffer, " ");
		//若为单向就只将一个方向的值设为1
		if (!strcmp(part, "单向")) {
			part = strtok(NULL, " ");
			while (part != NULL) {
				id = atoi(part);
				//若站名在此线出现过，不再设新的虚id
				if (linetmp->idexist(id)) {
					vid = stas[id]->getvid(stas[id]->getvnum() - 1);
					vlink[lastno][vid] = 1;
					vlink_c[lastno][vid] = 1;
					lastno = vid;
					part = strtok(NULL, " ");
					continue;
				}
				stas[id]->addvid(vnum);
				v2pandl[vnum][0] = id;
				v2pandl[vnum][1] = linenum;
				for (int i = 0; i < stas[id]->getvnum() - 1; i++) {
					vlink[stas[id]->getvid(i)][vnum] = 0;
					vlink[vnum][stas[id]->getvid(i)] = 0;
					vlink_c[stas[id]->getvid(i)][vnum] = Max / 10;
					vlink_c[vnum][stas[id]->getvid(i)] = Max / 10;
				}
				linetmp->addsta(stas[id]);
				if (lastno != -1) {
					vlink[lastno][vnum] = 1;
					vlink_c[lastno][vnum] = 1;
				}
				lastno = vnum;
				vnum++;
				part = strtok(NULL, " ");
			}
			lines[linenum++] = linetmp;
			continue;
		}
		else if (!strcmp(part, "环线")) {
			tag = 1;
			firstno = -1;
			part = strtok(NULL, " ");
		}
		while (part != NULL) {
			id = atoi(part);
			stas[id]->addvid(vnum);
			v2pandl[vnum][0] = id;
			v2pandl[vnum][1] = linenum;
			for (int i = 0; i < stas[id]->getvnum() - 1; i++) {
				vlink[stas[id]->getvid(i)][vnum] = 0;
				vlink[vnum][stas[id]->getvid(i)] = 0;
				vlink_c[stas[id]->getvid(i)][vnum] = Max / 10;
				vlink_c[vnum][stas[id]->getvid(i)] = Max / 10;
			}
			linetmp->addsta(stas[id]);
			if (lastno != -1) {
				vlink[lastno][vnum] = 1;
				vlink[vnum][lastno] = 1;
				vlink_c[lastno][vnum] = 1;
				vlink_c[vnum][lastno] = 1;
			}
			lastno = vnum;
			if (tag == 1 && firstno == -1) {
				firstno = vnum;
			}
			vnum++;
			part = strtok(NULL, " ");
		}
		//若为环线，将收尾间接
		if (tag == 1) {
			vlink[lastno][firstno] = 1;
			vlink[firstno][lastno] = 1;
			vlink_c[lastno][firstno] = 1;
			vlink_c[firstno][lastno] = 1;
		}
		lines[linenum++] = linetmp;
	}
	vstanum = vnum;
	cout << endl << vnum << endl << linenum << endl;
	fflush(in);

	cout << path << endl;
}
void Read::init()
{
	v2pandl = (int**)malloc(sizeof(int*)*Max_Sta);
	for (int i = 0; i<Max_Sta; i++)
		v2pandl[i] = (int*)malloc(sizeof(int) * 2);

	vlink = (int**)malloc(sizeof(int*)*Max_Sta);
	for (int i = 0; i<Max_Sta; i++)
		vlink[i] = (int*)malloc(sizeof(int) * Max_Sta);

	vlink_c = (int**)malloc(sizeof(int*)*Max_Sta);
	for (int i = 0; i<Max_Sta; i++)
		vlink_c[i] = (int*)malloc(sizeof(int) * Max_Sta);

}

Read::~Read()
{
}


void Read::addline(Line *line) {
	lines[linenum++] = line;
}

void Read::setvlink(int a, int b)
{
	vlink[a][b] = 1;
}


void Read::setvlink_c(int a, int b)
{
	vlink_c[a][b] = 1;
}

int Read::str2id(char *s)
{
	for (int i = 1; i <= stanum; i++) {
		if (!strcmp(s, stas[i]->getname())) {
			return i;
		}
	}
	return -1;
}




//判断两站是否连接
int Read::linked(char *s1, char *s2)
{
	int id1, id2;
	id1 = str2id(s1);
	id2 = str2id(s2);
	for (int i = 0; i < stas[id1]->getvnum(); i++) {
		for (int j = 0; j < stas[id2]->getvnum(); j++) {
			if (vlink[stas[id1]->getvid(i)][stas[id2]->getvid(j)] == 1) {
				return 1;
			}
		}
	}
	return 0;
}
int Read::connected(int id1, int id2)
{
	for (int i = 0; i < stas[id1]->getvnum(); i++) {
		for (int j = 0; j < stas[id2]->getvnum(); j++) {
			if (vlink[stas[id1]->getvid(i)][stas[id2]->getvid(j)] == 1) {
				return 1;
			}
		}
	}
	return 0;
}
//根据type选择最短路或者最少换乘，用的Dijkstra
int *Read::findway(char *s1, char *s2, int type)
{
	int id1, id2, vid1, vid2;
	int tag, m, n;
	int tot = 1, tmp;
	int dist[Max_Sta], distbest = -1;
	int prev[Max_Sta], prevbest[Max_Sta];
	int que[Max_Sta];
	int way[Max_Sta];
	id1 = str2id(s1);
	id2 = str2id(s2);
	for (int i = 0; i < stas[id1]->getvnum(); i++) {
		if (type == 1) {
			Dijkstra(vstanum, stas[id1]->getvid(i), dist, prev);
		}
		else if (type == 2) {
			Dijkstra(vstanum, stas[id1]->getvid(i), dist, prev);
		}
		tag = 1;
		for (int j = 0; j < stas[id2]->getvnum(); j++) {
			if (distbest < 0 || distbest > dist[stas[id2]->getvid(j)]) {
				distbest = dist[stas[id2]->getvid(j)];
				vid1 = stas[id1]->getvid(i);
				vid2 = stas[id2]->getvid(j);
				if (tag == 1) {
					for (int m = 0; m < vstanum; m++) {
						prevbest[m] = prev[m];
					}
					tag = 0;
				}
			}
		}
	}
	tmp = prevbest[vid2];
	que[tot] = vid2;
	tot++;
	while (tmp != vid1)
	{
		que[tot] = tmp;
		tot++;
		tmp = prevbest[tmp];
	}
	que[tot] = vid1;
	n = 0;
	for (n = tot; n > 0; n--) {
		if (v2pandl[que[n - 1]][0] != id1) {
			break;
		}
	}
	m = 0;
	for (int i = n; i > 0; i--) {
		if (i > 0 && v2pandl[que[i]][0] == way[m - 1]) {
			way[m] = -v2pandl[que[i]][1];
			m++;
			continue;
		}
		way[m] = v2pandl[que[i]][0];
		m++;
		if (v2pandl[que[i]][0] == id2) {
			break;
		}
	}
	way[m] = 0;
	return way;
}

int *Read::shortestway(char *s1, char *s2)
{
	return findway(s1, s2, 1);
}

int *Read::least_transfer(char *s1, char *s2)
{
	return findway(s1, s2, 2);
}

char *Read::id2str(int i)
{
	return stas[i]->getname();
}

char *Read::id2line(int i)
{
	return lines[i]->getname();
}

int Read::printline(char *s)
{
	for (int i = 0; i < linenum; i++) {
		if (!strcmp(s, lines[i]->getname())) {
			lines[i]->printline();
			return i;
		}
	}
	return -1;
}

int Read::getlinenum()
{
	return linenum;
}

int *Read::getline(int i)
{
	return lines[i]->getstas();
}

int Read::getstanum()
{
	return stanum;
}

Point Read::getloc(int i)
{
	return stas[i]->getloc();
}

//Line
Line::Line(char *n)
{
	strncpy(name, n, sizeof(name));
	name[sizeof(name) - 1] = '\0';
	stanum = 0;
}

void Line::addsta(Station *sta)
{
	stas[stanum++] = sta;
}

int Line::idexist(int id)
{
	for (int i = 0; i < stanum; i++) {
		if (id == stas[i]->getid())
		{
			return 1;
		}
	}
	return 0;
}

int Line::getstanum()
{
	return stanum;
}

char *Line::getname()
{
	return name;
}

void Line::printline()
{
	char s[30];
	for (int i = 0; i < stanum; i++) {
		strncpy(s, stas[i]->getname(), 30);
		cout << s << endl;
	}
}


int *Line::getstas()
{
	int i;
	int *stasid = new int[100];
	for (i = 0; i < stanum; i++) {
		stasid[i] = stas[i]->getid();
	}
	stasid[i] = -1;
	return stasid;
}






//Station
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


void  Read::Dijkstra(int n, int v, int *dist, int *prev)
{
	bool s[Max_Sta];
	//vlink[v][i] = 0;
	for (int i = 0; i < n; ++i)
	{
		dist[i] = vlink[v][i];
		s[i] = 0;
		if (dist[i] == Max)
			prev[i] = 0;
		else
			prev[i] = v;
	}
	dist[v] = 0;
	s[v] = 1;
	for (int i = 1; i < n; ++i)
	{
		int tmp = Max;
		int u = v;
		for (int j = 0; j < n; ++j) {
			if ((!s[j]) && dist[j] < tmp) {
				u = j;
				tmp = dist[j];
			}
		}
		s[u] = 1;
		for (int j = 0; j < n; ++j) {
			if ((!s[j]) && vlink[u][j] < Max) {
				int newdist = dist[u] + vlink[u][j];
				if (newdist < dist[j]) {
					dist[j] = newdist;
					prev[j] = u;
				}
			}
		}
	}
}



