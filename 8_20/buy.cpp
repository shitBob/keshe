#include "buy.h"
#include "ui_buy.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QPushButton>
#include <QHeaderView>
#include<QListWidgetItem>
#include<QDebug>
#include"itembuy.h"
#include"globalusermanager.h"

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

void buy::initialize(QString no)
{
    QString noo = no;
    QString userphone = GlobalDataManager::getInstance()->getUserDataBase();
    QSqlQuery querypa;
    querypa.prepare("SELECT * FROM passenger WHERE user_phone_num = (:value2)");
    querypa.bindValue(":value2", userphone);
    if (querypa.exec()){
        qDebug()<<"success buy";
        if(querypa.next()){
            QString id = querypa.value("passenger_id_num").toString();
            QString name = querypa.value("passenger_real_name").toString();
            itembuy * buyitem = new itembuy;
            buyitem->setbuy(name,noo,id,userphone);
            QListWidgetItem * item = new QListWidgetItem;
            item->setSizeHint(QSize(243,80));
            ui->listWidget->addItem(item);
            ui->listWidget->setItemWidget(item,buyitem);
        }
    }
    else{
        qDebug() << "Error buy query:" << querypa.lastError();
    }
}

