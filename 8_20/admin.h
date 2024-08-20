#ifndef ADMIN_H
#define ADMIN_H
#include <QTableWidget>
#include<QSqlDatabase>
#include<Qsql>
#include <QMainWindow>
#include "addtrain.h"

namespace Ui {
class Admin;
}

class Admin : public QMainWindow
{
    Q_OBJECT

public:
    explicit Admin(QWidget *parent = nullptr);
    ~Admin();
    Addtrain *add = NULL;
    void initialize();
signals:
    void back();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_add_clicked();

private:
    Ui::Admin *ui;
};

#endif // ADMIN_H
