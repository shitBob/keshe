#include "manage_passenger.h"
#include "ui_manage_passenger.h"

manage_passenger::manage_passenger(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::manage_passenger)
{
    ui->setupUi(this);
}

manage_passenger::~manage_passenger()
{
    delete ui;
}
