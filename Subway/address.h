#ifndef ADDRESS_H
#define ADDRESS_H
#include <QLabel>
#include <QPainter>

//class QLabel;
class address : public QLabel
{
	Q_OBJECT
public:
	explicit address(QLabel *parent = 0);
	 void aimprint(QLabel *);
	 void arrprint(QLabel *);
	 void inputaim_print(QLabel *, const QString &);
	 void inputarr_print(QLabel *, const QString &);
};

#endif