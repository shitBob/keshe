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
        QString o_id = query.value("order_id").toString();
        QString id = query.value("passenger_id_num").toString();
        QString phone = query.value("user_phone_num").toString();
        QString userphone = GlobalDataManager::getInstance()->getUserDataBase();
        if(userphone == phone){
            QSqlQuery querytrain;
            querytrain.prepare("SELECT * FROM train_info WHERE train_no = (:value1)");
            querytrain.bindValue(":value1", no);
            QSqlQuery querypa;
            querypa.prepare("SELECT * FROM passenger WHERE passenger_id_num = (:value2)");
            querypa.bindValue(":value2", id);
            if (querytrain.exec() && querypa.exec()){
                qDebug()<<"success query";
            }
            else{
                qDebug() << "Error executing train_info query:" << querytrain.lastError();
            }
            if(querytrain.next() && querypa.next()){
                QString type = querytrain.value("train_type").toString();
                QString start = querytrain.value("train_start_station").toString();
                QString end = querytrain.value("train_end_station").toString();
                int price = querytrain.value("train_price").toInt();
                QString time = querytrain.value("train_start_time").toString();
                qDebug()<<"success next";
                QString name = querypa.value("passenger_real_name").toString();
                itemorder * orderitem = new itemorder;
                orderitem->setTrainInfo(name,no,type,time,start,end,price,o_id);
                QListWidgetItem * item = new QListWidgetItem;
                item->setSizeHint(QSize(850,75));
                ui->listWidget->addItem(item);
                ui->listWidget->setItemWidget(item,orderitem);
            }
        }
    }
}

void Query::initialize(){
    ui->listWidget->clear();
    QSqlQuery query;

    QString sqlCreateTable = QString ("select * from order_list;");
    if(!query.exec(sqlCreateTable)){
        qDebug()<<"create table";
    }
    while(query.next()){
        QString no = query.value("train_no").toString();
        QString o_id = query.value("order_id").toString();
        QString id = query.value("passenger_id_num").toString();
        QString phone = query.value("user_phone_num").toString();
        QString userphone = GlobalDataManager::getInstance()->getUserDataBase();
        if(userphone == phone){
            QSqlQuery querytrain;
            querytrain.prepare("SELECT * FROM train_info WHERE train_no = (:value1)");
            querytrain.bindValue(":value1", no);
            QSqlQuery querypa;
            querypa.prepare("SELECT * FROM passenger WHERE passenger_id_num = (:value2)");
            querypa.bindValue(":value2", id);
            if (querytrain.exec() && querypa.exec()){
                qDebug()<<"success query";
            }
            else{
                qDebug() << "Error executing train_info query:" << querytrain.lastError();
            }
            if(querytrain.next() && querypa.next()){
                QString type = querytrain.value("train_type").toString();
                QString start = querytrain.value("train_start_station").toString();
                QString end = querytrain.value("train_end_station").toString();
                int price = querytrain.value("train_price").toInt();
                QString time = querytrain.value("train_start_time").toString();
                qDebug()<<"success next";
                QString name = querypa.value("passenger_real_name").toString();
                itemorder * orderitem = new itemorder;
                orderitem->setTrainInfo(name,no,type,time,start,end,price,o_id);
                QListWidgetItem * item = new QListWidgetItem;
                item->setSizeHint(QSize(850,75));
                ui->listWidget->addItem(item);
                ui->listWidget->setItemWidget(item,orderitem);
            }
        }
    }
}

