#ifndef ITEMFROM_H
#define ITEMFROM_H
#include"buy.h"
#include <QMainWindow>

namespace Ui {
class itemFrom;
}

class itemFrom : public QMainWindow
{
    Q_OBJECT

public:
    explicit itemFrom(QWidget *parent = nullptr);
    ~itemFrom();
    buy * b =NULL;
    void setTrainInfo(QString no,QString type,QString time,QString start,QString end,int price,int carriage);
private slots:
    void on_buy_clicked();

private:
    Ui::itemFrom *ui;
};

#endif // ITEMFROM_H
