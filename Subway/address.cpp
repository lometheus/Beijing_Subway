#include "address.h"

address::address(QLabel *parent) :
	QLabel(parent)
{
	
}


void address::aimprint(QLabel *print)
{
	QFont font;
	font.setFamily("Microsoft YaHei");
	font.setPointSize(28);
	print->setFont(font);
	print->setGeometry(QRect(365, 23, 180, 40)); //设置大小和位置  
	print->setText(QString::fromLocal8Bit("目的地"));

}

void address::arrprint(QLabel *print)
{
	QFont font;
	font.setFamily("Microsoft YaHei");
	font.setPointSize(28);
	print->setFont(font);
	print->setGeometry(QRect(17, 23, 160, 40)); //设置大小和位置  
	print->setText(QString::fromLocal8Bit("出发地"));
}

void address::inputaim_print(QLabel *print, const QString &text)
{
	QFont font;
	font.setFamily("Microsoft YaHei");
	font.setPointSize(15);
	print->setFont(font);
	print->setGeometry(QRect(27, 57, 150, 40)); //设置大小和位置  
	print->setText(QString::fromLocal8Bit("%1").arg(text));

}

void address::inputarr_print(QLabel *print, const QString &text)
{
	QFont font;
	font.setFamily("Microsoft YaHei");
	font.setPointSize(15);
	print->setFont(font);
	print->setGeometry(QRect(375, 57, 150, 40)); //设置大小和位置  
	print->setText(QString::fromLocal8Bit("%1").arg(text));

}