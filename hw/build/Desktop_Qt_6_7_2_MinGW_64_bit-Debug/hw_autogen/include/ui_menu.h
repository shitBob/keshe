/********************************************************************************
** Form generated from reading UI file 'menu.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Menu
{
public:
    QWidget *centralwidget;
    QPushButton *my;
    QPushButton *booking;
    QPushButton *back1;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Menu)
    {
        if (Menu->objectName().isEmpty())
            Menu->setObjectName("Menu");
        Menu->resize(800, 600);
        centralwidget = new QWidget(Menu);
        centralwidget->setObjectName("centralwidget");
        my = new QPushButton(centralwidget);
        my->setObjectName("my");
        my->setGeometry(QRect(230, 70, 91, 31));
        booking = new QPushButton(centralwidget);
        booking->setObjectName("booking");
        booking->setGeometry(QRect(230, 120, 91, 31));
        back1 = new QPushButton(centralwidget);
        back1->setObjectName("back1");
        back1->setGeometry(QRect(350, 210, 80, 18));
        Menu->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Menu);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 17));
        Menu->setMenuBar(menubar);
        statusbar = new QStatusBar(Menu);
        statusbar->setObjectName("statusbar");
        Menu->setStatusBar(statusbar);

        retranslateUi(Menu);

        QMetaObject::connectSlotsByName(Menu);
    } // setupUi

    void retranslateUi(QMainWindow *Menu)
    {
        Menu->setWindowTitle(QCoreApplication::translate("Menu", "MainWindow", nullptr));
        my->setText(QCoreApplication::translate("Menu", "\344\270\252\344\272\272\344\270\255\345\277\203", nullptr));
        booking->setText(QCoreApplication::translate("Menu", "\350\264\255\347\245\250\344\270\255\345\277\203", nullptr));
        back1->setText(QCoreApplication::translate("Menu", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Menu: public Ui_Menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
