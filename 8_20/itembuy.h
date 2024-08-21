#ifndef ITEMBUY_H
#define ITEMBUY_H

#include <QMainWindow>

namespace Ui {
class itembuy;
}

class itembuy : public QMainWindow
{
    Q_OBJECT

public:
    explicit itembuy(QWidget *parent = nullptr);
    ~itembuy();
    void setbuy(QString name,QString no,QString id,QString phone);
private slots:
    void on_pushButton_clicked();

private:
    Ui::itembuy *ui;
    QString noo = "fuck";
};

#endif // ITEMBUY_H
