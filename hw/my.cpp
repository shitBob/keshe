#include "my.h"
#include "ui_my.h"
#include "query.h"
#include "modify.h"
#include<QLabel>
#include"globalusermanager.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "add_passenger.h"
#include <QStandardItemModel>
#include <QStandardItem>

My::My(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::My)
{
    ui->setupUi(this);
    this->modify = new Modify;
    this->query = new Query;
    this->ad  = new add_passenger;
    connect(ui->modify,&QPushButton::clicked,[=](){
        this->hide();
        this->modify->show();
    });
    connect(ui->query,&QPushButton::clicked,[=](){
        this->hide();
        this->query->show();
    });
    connect(this->modify,&Modify::back,[=](){
        this->modify->hide();
        this->show();
    });
    connect(this->query,&Query::back,[=](){
        this->query->hide();
        this->show();
    });
    connect(ad, &add_passenger::bWindowClosed, this, &My::updateOnBWindowClosed);

    QString username = GlobalDataManager::getInstance()->getUserDataBase();
    QString password = GlobalDataManager::getInstance()->getUserDataBase1();
    qDebug()<<username ;
    qDebug()<<"666" ;
   ui->label_4->setText(username);
   ui->label_5->setText(password);
    QSqlQueryModel *model = new QSqlQueryModel;
    QSqlQuery query;
    query.prepare("SELECT * FROM us_pa WHERE user_phone_num = (:value1)");
    query.bindValue(":value1", username);

    model->setQuery(query);

    // if (model->lastError().isValid()) {
    //     qDebug() << "Query Error: " << model->lastError().text();
    //     return -1;
    // }


    // 创建视图并设置模型

    // PassengerView->setModel(model);
    // tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    // tableView->verticalHeader()->setVisible(false);
    // tableView->show();

    initialize();
}

My::~My()
{
    delete ui;
}

void My::on_back2_clicked()
{
    emit this->back();

}

void My::initialize()
{
    QString userphone = GlobalDataManager::getInstance()->getUserDataBase();
    QString username = GlobalDataManager::getInstance()->getUserDataBase2();
    qDebug()<<userphone ;
    ui->label_4->setText(username);
    ui->label_5->setText(userphone);
    QSqlQueryModel *model = new QSqlQueryModel;
    QSqlQuery query;
    query.prepare("SELECT * FROM passenger WHERE user_phone_num = (:value1)");
    query.bindValue(":value1", userphone);
    query.exec();
    model->setQuery(query);


    ui->PassengerView->setModel(model);
    ui->PassengerView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->PassengerView->verticalHeader()->setVisible(false);
    ui->PassengerView->show();
}

void My::on_look_clicked()
{
    ad->show();
    QEventLoop loop;
    loop.exec();
}
 void My::updateOnBWindowClosed()
{
     My::initialize();
}

void My::on_pushButton_clicked()
{

    QAbstractItemModel *model = ui->PassengerView->model();
    QString data = model->data(model->index(delete_row, 2)).toString();

    QSqlQuery query;
    query.prepare("DELETE FROM passenger WHERE passenger_id_num  = (:value1);");
    query.bindValue(":value1",data);
    query.exec();
    initialize();
    qDebug()<<data;

}


void My::on_PassengerView_clicked(const QModelIndex &index)
{
    int row=index.row();//获得当前行索引
    this->delete_row=row;

}

