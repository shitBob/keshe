#include "query.h"
#include "ui_query.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QPushButton>
#include <QHeaderView>
#include<QListWidgetItem>
#include<QDebug>
#include"itemorder.h"
#include"globalusermanager.h"

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


void Query::on_pushButton_clicked()
{
    ui->listWidget->clear();
    QSqlQuery query;

    QString sqlCreateTable = QString ("select * from order_list;");
    if(!query.exec(sqlCreateTable)){
        qDebug()<<"create table";
    }
    while(query.next()){
        QString no = query.value("train_no").toString();
        QString id = query.value("order_id").toString();
        QString pid = query.value("passenger_id_num").toString();
        QString phone = query.value("user_phone_num").toString();
        QString userphone = GlobalDataManager::getInstance()->getUserDataBase();
        QString name = query.value("passenger_real_name").toString();
        QString type = query.value("train_type").toString();
        QString start = query.value("train_start_station").toString();
        QString end = query.value("train_end_station").toString();
        int price = query.value("train_price").toInt();
        QString time = query.value("train_start_time").toString();
        qDebug()<<userphone<<phone;
        if(userphone == phone){
            itemorder * orderitem = new itemorder;
            orderitem->setTrainInfo(name,no,type,time,start,end,price);
            QListWidgetItem * item = new QListWidgetItem;
            item->setSizeHint(QSize(631,75));
            ui->listWidget->addItem(item);
            ui->listWidget->setItemWidget(item,orderitem);
        }
    }
}

