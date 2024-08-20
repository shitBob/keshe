#include "itembuy.h"
#include "ui_itembuy.h"

itembuy::itembuy(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::itembuy)
{
    ui->setupUi(this);
}

itembuy::~itembuy()
{
    delete ui;
}
