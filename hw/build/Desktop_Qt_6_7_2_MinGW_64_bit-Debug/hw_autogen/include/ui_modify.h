/********************************************************************************
** Form generated from reading UI file 'modify.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFY_H
#define UI_MODIFY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Modify
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Modify)
    {
        if (Modify->objectName().isEmpty())
            Modify->setObjectName("Modify");
        Modify->resize(326, 300);
        centralwidget = new QWidget(Modify);
        centralwidget->setObjectName("centralwidget");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(120, 200, 80, 18));
        Modify->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Modify);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 326, 17));
        Modify->setMenuBar(menubar);
        statusbar = new QStatusBar(Modify);
        statusbar->setObjectName("statusbar");
        Modify->setStatusBar(statusbar);

        retranslateUi(Modify);

        QMetaObject::connectSlotsByName(Modify);
    } // setupUi

    void retranslateUi(QMainWindow *Modify)
    {
        Modify->setWindowTitle(QCoreApplication::translate("Modify", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("Modify", "\350\277\224\345\233\236/\345\256\214\346\210\220", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Modify: public Ui_Modify {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFY_H
