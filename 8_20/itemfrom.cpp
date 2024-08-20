#include "itemfrom.h"
#include "ui_itemfrom.h"
#include <QMessageBox>
#include <QApplication>
#include <QPushButton>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

itemFrom::itemFrom(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::itemFrom)
{
    ui->setupUi(this);
}

itemFrom::~itemFrom()
{
    delete ui;
}

void itemFrom::setTrainInfo(QString no, QString type, QString time, QString start, QString end,int price, int carriage)
{
    ui->no->setText(no);
    ui->time->setText(time);
    ui->s->setText(start);
    ui->e->setText(end);
    ui->ca->setText(QString::number(carriage));
    ui->t->setText(type);
    ui->p->setText(QString::number(price));
}

void itemFrom::on_buy_clicked()
{
    QWidget window;
    //跳转选择乘客界面

    int ret = QMessageBox::question(&window,
                                    "询问",
                                    "您确定要购买该火车票吗？",
                                    QMessageBox::Yes | QMessageBox::No,
                                    QMessageBox::No);

    if (ret == QMessageBox::Yes) {
        // 用户点击了"是"
        QString noo = ui->no->text();
        QString caa = ui->ca->text();
        // 构建更新语句
        if(caa!="0"){
            QString query = QString("UPDATE train_info SET train_carriages = train_carriages - 1 WHERE train_no = '%1'")
                .arg(noo);
            QSqlQuery sql;
            if (sql.exec(query)) {
                qDebug() << "更新成功";
            } else {
                qDebug() << "更新失败";
            }
        }
        else{
            QMessageBox::information(this, "购票失败", "票已售空");
        }
        qDebug() << "用户购买";
    } else {
        // 用户点击了"否"
        qDebug() << "用户取消";
    }
}

