#include "buy.h"
#include "ui_buy.h"

buy::buy(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::buy)
{
    ui->setupUi(this);
}

buy::~buy()
{
    delete ui;
}
