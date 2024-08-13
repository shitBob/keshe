#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "menu.h"//主菜单
#include <QMainWindow>
#include<QSqlDatabase>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Menu *page2=NULL;
private slots:
    void on_login_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
};
#endif // MAINWINDOW_H
