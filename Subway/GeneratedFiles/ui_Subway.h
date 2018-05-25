/********************************************************************************
** Form generated from reading UI file 'Subway.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUBWAY_H
#define UI_SUBWAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SubwayClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SubwayClass)
    {
        if (SubwayClass->objectName().isEmpty())
            SubwayClass->setObjectName(QStringLiteral("SubwayClass"));
        SubwayClass->resize(600, 400);
        menuBar = new QMenuBar(SubwayClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        SubwayClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SubwayClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        SubwayClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(SubwayClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        SubwayClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(SubwayClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        SubwayClass->setStatusBar(statusBar);

        retranslateUi(SubwayClass);

        QMetaObject::connectSlotsByName(SubwayClass);
    } // setupUi

    void retranslateUi(QMainWindow *SubwayClass)
    {
        SubwayClass->setWindowTitle(QApplication::translate("SubwayClass", "Subway", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SubwayClass: public Ui_SubwayClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUBWAY_H
