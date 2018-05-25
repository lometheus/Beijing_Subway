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
	print->setGeometry(QRect(365, 23, 180, 40)); //���ô�С��λ��  
	print->setText(QString::fromLocal8Bit("Ŀ�ĵ�"));

}

void address::arrprint(QLabel *print)
{
	QFont font;
	font.setFamily("Microsoft YaHei");
	font.setPointSize(28);
	print->setFont(font);
	print->setGeometry(QRect(17, 23, 160, 40)); //���ô�С��λ��  
	print->setText(QString::fromLocal8Bit("������"));
}

void address::inputaim_print(QLabel *print, const QString &text)
{
	QFont font;
	font.setFamily("Microsoft YaHei");
	font.setPointSize(15);
	print->setFont(font);
	print->setGeometry(QRect(27, 57, 150, 40)); //���ô�С��λ��  
	print->setText(QString::fromLocal8Bit("%1").arg(text));

}

void address::inputarr_print(QLabel *print, const QString &text)
{
	QFont font;
	font.setFamily("Microsoft YaHei");
	font.setPointSize(15);
	print->setFont(font);
	print->setGeometry(QRect(375, 57, 150, 40)); //���ô�С��λ��  
	print->setText(QString::fromLocal8Bit("%1").arg(text));

}