#include "Elepoint.h"



Elepoint::Elepoint( QObject *parent):
	MAPElement(parent)
{
	
	this->loadFrame();
	this->init();
}

void Elepoint::init()
{
	this->currentFrame = 0;
	this->pipePassEmited = false;
	this->pipeRect[above].setRect(75, 225, 10, 10);
	this->pipeRect[following].setRect(576 + this->startPosition*175.6, this->pipeRect[above].bottom() + 100.0, 52.0, 321.0);
}

void Elepoint::logic()
{
	if (!this->enabledLogic)
		return;//£¿£¿£¿£¿£¿£¿£¿£¿£¿£¿£¿£¿£¿£¿£¿
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	

	//if (this->pipeRect[above].right() < 0)
	//{
	//	this->pipeRect[above].moveTo(474.0, -271.0 + qrand() % 200);
	//	this->pipeRect[following].moveTo(474.0, this->pipeRect[above].bottom() + 100.0);
	//	this->pipePassEmited = false;
	//}

	//if (this->pipeRect[above].left() < 72 && this->pipePassEmited == false)
	//{
	//	//emit pipePass();
	//	this->pipePassEmited = true;
	//}
}

void Elepoint::draw(QPainter *painter,int x,int y,int tx,int ty,char *name,int colornum)
{
	if (!this->enabledDraw)
		return;

		QFont font;
		font.setFamily("Microsoft YaHei");
		font.setPointSize(10);
		painter->setFont(font);
		//QString str;
		//str = QString(QLatin1String(name));
		QTextCodec * a = QTextCodec::codecForName("GB18030");

		QString strText = a->toUnicode(name);
		painter->drawText(tx , ty,90,90, Qt::AlignCenter, strText);
		painter->drawPixmap(x,y,this->pipeRect[above].width(),
			this->pipeRect[above].height(),this->pixmapList[colornum]);


	painter->drawPixmap(this->pipeRect[following].x(),
		this->pipeRect[following].y(),
		this->pipeRect[following].width(),
		this->pipeRect[following].height(),
		this->pixmapList[1]);
}

void Elepoint::loadFrame()
{
	this->clearAllFrame();
	this->addFrame(QPixmap(":/images/point"));
	this->addFrame(QPixmap(":/images/point_red"));
	this->addFrame(QPixmap(":/images/point_yel"));
	this->addFrame(QPixmap(":/images/point_gre"));
	this->addFrame(QPixmap(":/images/point_wri"));
}

QRectF& Elepoint::getRect(PipeType type)
{
	return this->pipeRect[type];
}

