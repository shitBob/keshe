#include "itemorder.h"
#include "ui_itemorder.h"

itemorder::itemorder(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::itemorder)
{
    ui->setupUi(this);
}

itemorder::~itemorder()
{
    delete ui;
}

void itemorder::setTrainInfo(QString passenger, QString no, QString type, QString time, QString start, QString end, int price)
{
    ui->name->setText(passenger);
    ui->no->setText(no);
    ui->time->setText(time);
    ui->s->setText(start);
    ui->e->setText(end);
    ui->t->setText(type);
    ui->p->setText(QString::number(price));
}
