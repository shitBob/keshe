#include "add_passenger.h"
#include "ui_add_passenger.h"

add_passenger::add_passenger(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::add_passenger)
{
    ui->setupUi(this);

}

add_passenger::~add_passenger()
{
    delete ui;
}
