#include "arrow.h"

arrow::arrow(QObject *parent) :
	MAPElement(parent)
{
	this->init();
}

void arrow::init()
{

	this->loadFrame();
	this->currentFrame = 0;
	this->bindRect.setRect(30, 13, 60, 40);
	this->enabledDraw = true;
}

void arrow::logic()
{
	if (!this->enabledLogic)
		return;
}

void arrow::draw(QPainter *painter)
{
	if (!this->enabledDraw)
		return;

	painter->drawPixmap(this->bindRect.x(), this->bindRect.y(),
		this->bindRect.width(), this->bindRect.height(),
		this->pixmapList[this->currentFrame]);
}
void arrow::loadFrame()
{
	this->clearAllFrame();
	this->addFrame(QPixmap(":/images/arrow"));

}
