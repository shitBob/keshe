#include "booking.h"
#include "ui_booking.h"

Booking::Booking(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Booking)
{
    ui->setupUi(this);
}

Booking::~Booking()
{
    delete ui;
}

void Booking::on_pushButton_2_clicked()
{
    emit this->back();
}

