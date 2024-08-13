#include "modify.h"
#include "ui_modify.h"

Modify::Modify(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Modify)
{
    ui->setupUi(this);
}

Modify::~Modify()
{
    delete ui;
}

void Modify::on_pushButton_clicked()
{
    emit this->back();
}

