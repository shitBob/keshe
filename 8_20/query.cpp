#include "query.h"
#include "ui_query.h"

Query::Query(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Query)
{
    ui->setupUi(this);
}

Query::~Query()
{
    delete ui;
}

void Query::on_back6_clicked()
{
    emit this->back();
}

