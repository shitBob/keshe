#ifndef ITEMORDER_H
#define ITEMORDER_H

#include <QMainWindow>

namespace Ui {
class itemorder;
}

class itemorder : public QMainWindow
{
    Q_OBJECT

public:
    explicit itemorder(QWidget *parent = nullptr);
    ~itemorder();
    void setTrainInfo(QString passenger,QString no,QString type,QString time,QString start,QString end,int price);
private:
    Ui::itemorder *ui;
};

#endif // ITEMORDER_H
