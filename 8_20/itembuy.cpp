#include "itembuy.h"
#include "ui_itembuy.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

itembuy::itembuy(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::itembuy)
{
    ui->setupUi(this);
}

itembuy::~itembuy()
{
    delete ui;
}

void itembuy::setbuy(QString name, QString no, QString id, QString phone)
{
    ui->name->setText(name);
    ui->no->setText(no);
    ui->phone->setText(phone);
    ui->id->setText(id);
}

void itembuy::on_pushButton_clicked()
{
    QString no = ui->no->text();
    QString id = ui->id->text();
    QString phone = ui->phone->text();
    // 数据验证...
    if (no.isEmpty() || phone.isEmpty() || id.isEmpty()) {
        QMessageBox::warning(this, "添加错误", "订单缺失信息");
        return;
    }
    QSqlQuery query;
    query.prepare("INSERT INTO order_list (user_phone_num, passenger_id_num, train_no) VALUES (:user_phone, :id,:no)");

    // 绑定参数
    query.bindValue(":id", id);
    query.bindValue(":no", no);
    query.bindValue(":user_phone", phone);
    // 构建更新语句
    QSqlQuery querytrain;
    querytrain.prepare("SELECT * FROM train_info WHERE train_no = (:value1)");
    querytrain.bindValue(":value1", no);
    if (querytrain.exec() ){
        qDebug()<<"success query";
    }
    else{
        qDebug() << "Error executing train_info query:" << querytrain.lastError();
    }
    if(querytrain.next()){
        QString caa = querytrain.value("train_carriages").toString();
        if(caa!="0"){
            QString query1 = QString("UPDATE train_info SET train_carriages = train_carriages - 1 WHERE train_no = '%1'")
            .arg(no);
            QSqlQuery sql;
            if (sql.exec(query1)) {
                qDebug() << "更新成功";
            } else {
                qDebug() << "更新失败";
            }
        }
        else{
            QMessageBox::information(this, "购票失败", "票已售空");
        }
    }
    // 执行插入操作
    if (query.exec()) {
        QMessageBox::information(this, "提示", "您已为该乘客购买成功");
    } else {
        QMessageBox::critical(this, "购买失败", "失败原因：" + query.lastError().text());
    }
}

