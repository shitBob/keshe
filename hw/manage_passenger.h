#ifndef MANAGE_PASSENGER_H
#define MANAGE_PASSENGER_H

#include <QWidget>

namespace Ui {
class manage_passenger;
}

class manage_passenger : public QWidget
{
    Q_OBJECT

public:
    explicit manage_passenger(QWidget *parent = nullptr);
    ~manage_passenger();

private:
    Ui::manage_passenger *ui;
};

#endif // MANAGE_PASSENGER_H
