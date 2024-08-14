#ifndef ADMIN_H
#define ADMIN_H

#include <QMainWindow>

namespace Ui {
class Admin;
}

class Admin : public QMainWindow
{
    Q_OBJECT

public:
    explicit Admin(QWidget *parent = nullptr);
    ~Admin();
signals:
    void back();
private slots:
    void on_pushButton_clicked();

private:
    Ui::Admin *ui;
};

#endif // ADMIN_H
