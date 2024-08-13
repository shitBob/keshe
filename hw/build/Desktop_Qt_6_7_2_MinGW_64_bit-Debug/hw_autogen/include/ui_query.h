/********************************************************************************
** Form generated from reading UI file 'query.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUERY_H
#define UI_QUERY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Query
{
public:
    QWidget *centralwidget;
    QTableView *tableView;
    QPushButton *back6;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Query)
    {
        if (Query->objectName().isEmpty())
            Query->setObjectName("Query");
        Query->resize(439, 369);
        centralwidget = new QWidget(Query);
        centralwidget->setObjectName("centralwidget");
        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(30, 20, 371, 251));
        back6 = new QPushButton(centralwidget);
        back6->setObjectName("back6");
        back6->setGeometry(QRect(320, 290, 80, 18));
        Query->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Query);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 439, 17));
        Query->setMenuBar(menubar);
        statusbar = new QStatusBar(Query);
        statusbar->setObjectName("statusbar");
        Query->setStatusBar(statusbar);

        retranslateUi(Query);

        QMetaObject::connectSlotsByName(Query);
    } // setupUi

    void retranslateUi(QMainWindow *Query)
    {
        Query->setWindowTitle(QCoreApplication::translate("Query", "MainWindow", nullptr));
        back6->setText(QCoreApplication::translate("Query", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Query: public Ui_Query {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUERY_H
