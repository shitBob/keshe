#include "admin.h"
#include "ui_admin.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QPushButton>
#include <QHeaderView>
#include<QListWidgetItem>
#include<QDebug>
#include"itemadmin.h"

Admin::Admin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Admin)
{
    ui->setupUi(this);
    this->add = new Addtrain;
    connect(this->add,&Addtrain::back,[=](){
        this->add->hide();
        this->show();
    });

}

Admin::~Admin()
{
    delete ui;
}

void Admin::on_pushButton_clicked()
{
    emit this->back();
}


void Admin::on_pushButton_2_clicked()
{
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
        int price = query.value("train_price").toInt();
        int carriage = query.value("train_carriages").toInt();
        qDebug()<<no<<time<<start;
        itemAdmin * trainitem = new itemAdmin;
        trainitem->setTrainInfo(no,type,time,start,end,price,carriage);
        QListWidgetItem * item = new QListWidgetItem;
        item->setSizeHint(QSize(629,79));
        ui->listWidget->addItem(item);
        ui->listWidget->setItemWidget(item,trainitem);

    }
}


void Admin::on_add_clicked()
{
    this->hide();
    this->add->show();
}

