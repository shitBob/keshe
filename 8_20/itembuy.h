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

private:
    Ui::itembuy *ui;
};

#endif // ITEMBUY_H
