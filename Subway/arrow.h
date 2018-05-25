#ifndef ARROW_H
#define ARROW_H

#include "MAPElement.h"
class arrow :
	public MAPElement
{
	Q_OBJECT
public:

	explicit arrow(QObject *parent = 0);
	void init();
	void draw(QPainter *);
	void logic();

private:
	int currentFrame;
	void loadFrame();

};

#endif 