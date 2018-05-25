#ifndef ELEGROUND_H
#define ELEGROUND_H

#include "MAPElement.h"
class Background :
	public MAPElement
{
	Q_OBJECT
public:

	explicit Background(QObject *parent = 0);
	void init();
	void draw(QPainter *);
	void logic();

private:
	int currentFrame;
	void loadFrame();

};

#endif 