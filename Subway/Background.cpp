#include "Background.h"

Background::Background(QObject *parent):
	MAPElement(parent)
{
	this->init();
}

void Background::init()
{
	
	this->loadFrame();
	this->currentFrame = 0;
	this->bindRect.setRect(0, 0, 288, 512);
	this->enabledDraw = true;
}

void Background::logic()
{
	if (!this->enabledLogic)
		return;
}

void Background::draw(QPainter *painter)
{
	if (!this->enabledDraw)
		return;

	painter->drawPixmap(this->bindRect.x(), this->bindRect.y(),
		this->bindRect.width(), this->bindRect.height(),
		this->pixmapList[this->currentFrame]);
}
void Background::loadFrame()
{
	this->clearAllFrame();
	this->addFrame(QPixmap(":/images/bg"));

}