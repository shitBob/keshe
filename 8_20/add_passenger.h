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

private:
    Ui::add_passenger *ui;
};

#endif // ADD_PASSENGER_H
