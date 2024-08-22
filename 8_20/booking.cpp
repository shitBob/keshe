#include "booking.h"
#include "ui_booking.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QPushButton>
#include <QHeaderView>
#include<QListWidgetItem>
#include<QDebug>
#include"itemfrom.h"

Booking::Booking(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Booking) {
    ui->setupUi(this);
    ui->no->setPlaceholderText("查询车次");
    ui->time->setPlaceholderText("查询出发时间");
    ui->start->setPlaceholderText("查询起始站");
    ui->end->setPlaceholderText("查询终点站");
}

Booking::~Booking() {
    delete ui;
}

void Booking::on_pushButton_2_clicked() {
    emit this->back();
}

void Booking::on_pushButton_clicked()
{
    QString noo = ui->no->text();
    QString timee = ui->time->text();
    QString startt = ui->start->text();
    QString endd = ui->end->text();
    ui->listWidget->clear();
    QSqlQuery query;

    QString sqlCreateTable = QString ("select * from train_info;");
    if(!query.exec(sqlCreateTable)){
        qDebug()<<"create table";
    }
    while(query.next()){
        QString no = query.value("train_no").toString();
        QString type = query.value("train_type").toString();
        QString time = query.value("train_start_time").toString();
        QString start = query.value("train_start_station").toString();
        QString end = query.value("train_end_station").toString();
        if(noo.isEmpty() || no.contains(noo)){
            if(timee.isEmpty() || time.contains(timee)){
                if(startt.isEmpty() || start.contains(startt)){
                    if(endd.isEmpty() || end.contains(endd)){
                        int price = query.value("train_price").toInt();
                        int carriage = query.value("train_carriages").toInt();
                        qDebug()<<no<<time<<start;
                        itemFrom * trainitem = new itemFrom;
                        trainitem->setTrainInfo(no,type,time,start,end,price,carriage);
                        QListWidgetItem * item = new QListWidgetItem;
                        item->setSizeHint(QSize(629,79));
                        ui->listWidget->addItem(item);
                        ui->listWidget->setItemWidget(item,trainitem);
                    }
                }
            }
        }
    }
}

