#include "MAPElement.h"

MAPElement::MAPElement(QObject *parent) :
	QObject(parent)
{
	this->clearAllFrame();
	this->bindRect.setRect(0, 0, 0, 0);
	this->enabledLogic = false;
	this->enabledDraw = false;
}

void MAPElement::addFrame(QPixmap pixmap)
{
	if (pixmap.isNull())
		return;
	this->pixmapList.append(pixmap);
	this->frameCount++;
}

void MAPElement::clearAllFrame()
{
	this->pixmapList.clear();
	this->frameCount = 0;
}

QRectF& MAPElement::getBindRect()
{
	return this->bindRect;
}
