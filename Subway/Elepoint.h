#ifndef ELEPOINT_H
#define ELEPOINT_H
#include<QLabel.h>
#include<Qstring.h>
#include <QTextCodec> 
#include "MAPElement.h"

enum PipeType {
	above = 0,
	following = 1
};

class Elepoint :
	public MAPElement
{
	Q_OBJECT
private:
	int currentFrame;
	int startPosition;
	QRectF pipeRect[2];
	bool pipePassEmited;

	void loadFrame();
public:
	explicit Elepoint(QObject *parent = 0);
	void init();
	void draw(QPainter *painter, int x, int y, int tx, int ty, char *name, int colornum);
	//void draw_address(QLabel *,int i);
	void logic();
	QLabel *address;
	QRectF &getRect(PipeType);
signals:
	void pipePass();
};

#endif