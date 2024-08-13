/********************************************************************************
** Form generated from reading UI file 'booking.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKING_H
#define UI_BOOKING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Booking
{
public:
    QWidget *centralwidget;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton;
    QTableView *tableView;
    QPushButton *pushButton_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Booking)
    {
        if (Booking->objectName().isEmpty())
            Booking->setObjectName("Booking");
        Booking->resize(800, 600);
        centralwidget = new QWidget(Booking);
        centralwidget->setObjectName("centralwidget");
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(80, 10, 113, 20));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(220, 10, 113, 20));
        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(350, 10, 113, 20));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(480, 10, 51, 21));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(80, 50, 461, 261));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(460, 330, 80, 18));
        Booking->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Booking);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 17));
        Booking->setMenuBar(menubar);
        statusbar = new QStatusBar(Booking);
        statusbar->setObjectName("statusbar");
        Booking->setStatusBar(statusbar);

        retranslateUi(Booking);

        QMetaObject::connectSlotsByName(Booking);
    } // setupUi

    void retranslateUi(QMainWindow *Booking)
    {
        Booking->setWindowTitle(QCoreApplication::translate("Booking", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("Booking", "PushButton", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Booking", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Booking: public Ui_Booking {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKING_H
