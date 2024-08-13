#ifndef MENU_H
#define MENU_H
#include "booking.h"
#include "my.h"
#include <QMainWindow>

namespace Ui {
class Menu;
}

class Menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();
    My *my = NULL;
    Booking *booking = NULL;
signals:
    void back();
private slots:
    void on_back1_clicked();

private:
    Ui::Menu *ui;
};

#endif // MENU_H
