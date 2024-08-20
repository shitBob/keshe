#ifndef ADD_PASSENGER_H
#define ADD_PASSENGER_H

#include <QWidget>

namespace Ui {
class add_passenger;
}

class add_passenger : public QWidget
{
    Q_OBJECT

public:
    explicit add_passenger(QWidget *parent = nullptr);
    ~add_passenger();

private slots:
    void on_pushButton_clicked();

    void on_add_passenger_destroyed();

    void on_pushButton_2_clicked();

signals:
    void bWindowClosed(); // 定义一个信号


private:
    Ui::add_passenger *ui;
};

#endif // ADD_PASSENGER_H
