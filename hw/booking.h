#ifndef BOOKING_H
#define BOOKING_H

#include <QMainWindow>

namespace Ui {
class Booking;
}

class Booking : public QMainWindow
{
    Q_OBJECT

public:
    explicit Booking(QWidget *parent = nullptr);
    ~Booking();
signals:
    void back();
private slots:
    void on_pushButton_2_clicked();

private:
    Ui::Booking *ui;
};

#endif // BOOKING_H
