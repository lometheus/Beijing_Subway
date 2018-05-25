#include "Subway.h"

MainWindow::MainWindow(char arg[],QWidget *parent)
	: QMainWindow(parent)
{
	this->bufferPixmap = new QPixmap(1100, 700);
	// Set size.
	//this->station = new QPixmap(990,990);
	this->resize(1100, 700);
	//for (int i = 0; i < 20; i++)
	//{
	//	station[i] = new QLabel(this);
	//}
	
	if (arg != NULL)
	{
		commond = arg;
	}
	else
		commond = NULL;
	address_in = new QLabel(this);
	address_out = new QLabel(this);
	address_in_in = new QLabel(this);
	address_out_in = new QLabel(this);
	point_color = 0;
	this->address_aim->aimprint(address_in);
	this->address_aim->arrprint(address_out);
	this->echoLineEdit = new QLineEdit(this);
	this->echoLineEdit->setGeometry(QRect(750, 20, 250, 50));
	this->echoLineEdit->setPlaceholderText(QString::fromLocal8Bit("请按“出发站-终点站”输入"));
	this->echoLineEdit->setEchoMode(QLineEdit::Normal);
	this->echoLineEdit->setReadOnly(false);

	this->startButton = new QPushButton(this);
	this->startButton->setGeometry(QRect(930,20,50,50));
	this->startButton->setStyleSheet("QPushButton{border-image:url(:/images/st);}"
		"QPushButton:pressed{margin: 2px 2px 2px 2px;}");
	connect(this->startButton, SIGNAL(clicked()), this, SLOT(startmap()));

	/* Init all the game elements. */
	this->background = new Background();
	this->Arrow = new arrow();
	this->point = new Elepoint();
	char path[25] = { "./beijing-subway.txt" };
	this->Findway = new Read(path);

	QTimer *timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(update()));
	timer->start(100);
	//this->address_in->aimprint();
	
}

MainWindow::~MainWindow()
{
	delete this->background;
	delete this->Arrow;
}

void MainWindow::paintEvent(QPaintEvent *)
{

	QPainter painter(this->bufferPixmap);
	//QPainter painter2(this->station);
	/* Draw all the elements. */
	//this->background->init();
	this->background->logic();
	this->background->draw(&painter);//L-F;D-T

	this->Arrow->logic();
	this->Arrow->draw(&painter);


	QPainter mainWindowPainter(this);
	mainWindowPainter.drawPixmap(QRect(0, 0, 4500, 1000), *this->bufferPixmap);
	//mainWindowPainter.drawPixmap(QRect(0, 0, this->width(), this->height()), *this->station);
	this->point->logic();
	if (this->point->enabledDraw)
	{
		point_color = 0;
		if (way[order] == 0)
			order--;
		for (int i = 0; i <= order; i++)
		{
			if (way[i] < 0)
			{
				point_color++;
				continue;
			}
			loc = this->Findway->getloc(way[i]);
			int x = loc.x;
			int y = loc.y;
			int tx = x - 15, ty = y - 30;
			Point loc1;
			if (i > 0)
			{
			if (way[i - 1] < 0)
				loc1 = this->Findway->getloc(way[i - 2]);
			else
				loc1 = this->Findway->getloc(way[i - 1]);
			if (loc1.x == x)
			{
				ty = y - 40;
				if (i % 2)
				{
					tx = x - 68;
				}
			}
			else if (loc1.y == y)
			{
				tx = x - 35;
				if (i % 2)
				{
					ty = y - 60;
				}
			}
			}
			char *stationname = this->Findway->id2str(way[i]);
			this->point->draw(&mainWindowPainter, x, y, tx, ty, stationname, point_color);
		}
		order++;
	}
	else if (commond != NULL)
	{
		startmap();
	}
}

void MainWindow::startmap()
{
	/* Init all the game elements. */
	this->background->init();
	this->Arrow->init();
	this->point->init();
	for (int m = 0; m < 500; m++)
	{
		way[m] = 0;
	}
	order = 0;
	this->drawmap();
	this->drawaddress();

}

void MainWindow::drawmap()
{
	this->background->enabledLogic = true;
	this->background->enabledDraw = true;

	this->point->enabledLogic = false;
	this->point->enabledDraw = true;


	this->Arrow->enabledLogic = true;
	this->Arrow->enabledDraw = true;



}
void MainWindow::drawaddress()
{
	QString strText;
	if (commond != NULL)
	{
		QTextCodec * a = QTextCodec::codecForName("GB18030");

		strText = a->toUnicode(commond);
		commond = NULL;
		//this->address_aim->inputaim_print(address_in_in, strText);

	}
	else
	{
		strText = echoLineEdit->text();
	}
	//QString strText = echoLineEdit->text();
	//QString strText = {"aa-篱笆"};
	QString aimplace;
	QString arrplace;
	aimplace = strText.section('-', 0, 0);
	arrplace = strText.section('-', 1, 1);
	echoLineEdit->clear();


	echoLineEdit->setFocus();

	QByteArray cpath = aimplace.toLocal8Bit();
	std::string str = aimplace.toStdString();
	char *aimplace_c = cpath.data();

	QByteArray apath = arrplace.toLocal8Bit();
	std::string str2 = arrplace.toStdString();
	char *arrplace_c = apath.data();
	int x = this->Findway->str2id(arrplace_c);
	//if (!strcmp(typeid(aimplace_c).name(), "char"))
	//{

	//}
	if (this->Findway->str2id(aimplace_c)<0 && this->Findway->str2id(arrplace_c) < 0&& this->Findway->printline(aimplace_c)<0)
	{
		
		erro->information(NULL, "Warning", QString::fromLocal8Bit("请按要求输入"), QMessageBox::Yes);
	}
	else if (this->Findway->printline(aimplace_c) >= 0)//输出线路
	{
		WAY=this->Findway->lines[this->Findway->printline(aimplace_c)]->getstas();
		int m = 0;
		for (m = 0; *WAY != 0; m++)
		{
			way[m] = *WAY;
			WAY++;
		}
		way[m] = 0;
	}
	else if (x < 0)
	{
		way[0] = this->Findway->str2id(aimplace_c);
		way[1] = 0;
	}
	else if (this->Findway->str2id(aimplace_c) < 0)
	{
		erro->information(NULL, "Warning", QString::fromLocal8Bit("请按要求输入"), QMessageBox::Yes);
	}
	//const char* aimplace_a = str.c_str();
	//const char* aimplace_a = str.c_str();
	//char* aimplace_c = new char[50];
	//strcpy(aimplace_c, aimplace_a);
	else if (this->Findway->str2id(aimplace_c)>0 && this->Findway->str2id(arrplace_c)>0)
	{
		this->address_aim->inputaim_print(address_in_in, aimplace);
		this->address_aim->inputarr_print(address_out_in, arrplace);
		WAY = this->Findway->shortestway(aimplace_c, arrplace_c);
		int m = 0;
		for (m = 0; *WAY != 0; m++)
		{
			way[m] = *WAY;
			WAY++;
		}
		way[m] = 0;
	}

}