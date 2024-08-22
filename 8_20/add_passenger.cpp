#include "add_passenger.h"
#include "ui_add_passenger.h"
#include <qstring.h>
#include <QCoreApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include "globalusermanager.h"
add_passenger::add_passenger(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::add_passenger)
{
    ui->setupUi(this);
    ui->lineEdit->setPlaceholderText("请输入11位乘客电话号码(必填)");
    ui->lineEdit_2->setPlaceholderText("请输入乘客名字（必填）");
    ui->lineEdit_3->setPlaceholderText("请输入18位乘客身份证号码（必填）");
    ui->lineEdit_4->setPlaceholderText("请输入乘客地址（选填）");

}

add_passenger::~add_passenger()
{
    delete ui;
}

void add_passenger::on_pushButton_clicked()
{
    QString userphone = GlobalDataManager::getInstance()->getUserDataBase();
    QString username = GlobalDataManager::getInstance()->getUserDataBase2();
    QString phone;
    QString name;
    QString id;
    QString address;

    phone=ui->lineEdit->text();
    name=ui->lineEdit_2->text();
    id  = ui->lineEdit_3->text();
    address = ui->lineEdit_4 ->text();

    QSqlQuery query;
    query.prepare("INSERT INTO passenger VALUES (:phone, :name, :id,:address,:user_phone)");

    // 绑定参数
    query.bindValue(":phone", phone);
    query.bindValue(":name", name);
    query.bindValue(":id", id);
    query.bindValue(":address", address);
    query.bindValue(":user_phone", userphone);

    // 执行插入操作
    if (!query.exec()) {
        qDebug() << "Insert error:" << query.lastError().text();
    } else {
        qDebug() << "Data inserted successfully!";

    }




}


void add_passenger::on_add_passenger_destroyed()
{
    emit bWindowClosed(); // 发射信号
    qDebug()<<"关闭！";
}


void add_passenger::on_pushButton_2_clicked()
{
    emit bWindowClosed();
    this->close();
}

