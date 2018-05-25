#pragma once
#include <QTextCodec> 
#include <QtWidgets/QMainWindow>
#include<QLabel.h>
#include <QTimer>
#include <QTime>
#include <QInputDialog>  
#include <QGridLayout>  
#include <QPushButton>
#include "Background.h"
#include "arrow.h"
#include"address.h"
#include"Elepoint.h"
#include<QMessageBox.h>
#include "Read.h"
#include "Subway.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(char *arg, QWidget *parent = 0);
	~MainWindow();
	QPixmap * bufferPixmap;
//	QPixmap *station;
	void paintEvent(QPaintEvent *);
	char *commond;

private:
	void drawaddress();
	void drawmap();
	arrow * Arrow;
	Background * background;
	QPushButton *startButton;
	QLabel *address_in;
	QLabel *address_out;
	QLabel *address_in_in;
	QLabel *address_out_in;
	address *address_aim;
	QTimer timer; // Main timer, refresh the interface.
	Elepoint *point;
	QLineEdit *echoLineEdit;
	Read *Findway;
	int order = 0;
	int *WAY;
	int point_color;
	int way[500];
	Point loc;
	QMessageBox  *erro;

public slots:
	void startmap(); // The button clicked , game began.
	
};
