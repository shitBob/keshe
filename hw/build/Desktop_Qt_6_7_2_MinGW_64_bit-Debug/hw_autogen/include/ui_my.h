/********************************************************************************
** Form generated from reading UI file 'my.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MY_H
#define UI_MY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_My
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *look;
    QPushButton *query;
    QPushButton *modify;
    QLabel *label_5;
    QLabel *label_6;
    QTableView *tableView;
    QPushButton *back2;
    QLabel *label_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *My)
    {
        if (My->objectName().isEmpty())
            My->setObjectName("My");
        My->resize(580, 373);
        centralwidget = new QWidget(My);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 10, 51, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\256\213\344\275\223")});
        font.setPointSize(15);
        font.setBold(true);
        label->setFont(font);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 40, 71, 31));
        label_2->setFont(font);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 70, 71, 31));
        label_3->setFont(font);
        look = new QPushButton(centralwidget);
        look->setObjectName("look");
        look->setGeometry(QRect(60, 160, 80, 18));
        query = new QPushButton(centralwidget);
        query->setObjectName("query");
        query->setGeometry(QRect(60, 190, 80, 18));
        modify = new QPushButton(centralwidget);
        modify->setObjectName("modify");
        modify->setGeometry(QRect(60, 220, 80, 18));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(100, 50, 40, 16));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(100, 80, 40, 16));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(200, 10, 331, 301));
        back2 = new QPushButton(centralwidget);
        back2->setObjectName("back2");
        back2->setGeometry(QRect(60, 250, 80, 18));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(100, 20, 71, 21));
        My->setCentralWidget(centralwidget);
        menubar = new QMenuBar(My);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 580, 17));
        My->setMenuBar(menubar);
        statusbar = new QStatusBar(My);
        statusbar->setObjectName("statusbar");
        My->setStatusBar(statusbar);

        retranslateUi(My);

        QMetaObject::connectSlotsByName(My);
    } // setupUi

    void retranslateUi(QMainWindow *My)
    {
        My->setWindowTitle(QCoreApplication::translate("My", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("My", "\347\224\250\346\210\267\345\220\215", nullptr));
        label_2->setText(QCoreApplication::translate("My", "\347\224\265\350\257\235\345\217\267\347\240\201", nullptr));
        label_3->setText(QCoreApplication::translate("My", "\347\224\250\346\210\267\347\261\273\345\236\213", nullptr));
        look->setText(QCoreApplication::translate("My", "\344\271\230\345\256\242\347\256\241\347\220\206", nullptr));
        query->setText(QCoreApplication::translate("My", "\350\256\242\345\215\225\346\237\245\350\257\242", nullptr));
        modify->setText(QCoreApplication::translate("My", "\347\224\250\346\210\267\344\277\241\346\201\257\344\277\256\346\224\271", nullptr));
        label_5->setText(QCoreApplication::translate("My", "TextLabel", nullptr));
        label_6->setText(QCoreApplication::translate("My", "TextLabel", nullptr));
        back2->setText(QCoreApplication::translate("My", "\350\277\224\345\233\236", nullptr));
        label_4->setText(QCoreApplication::translate("My", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class My: public Ui_My {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MY_H
