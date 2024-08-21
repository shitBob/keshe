#include "itemorder.h"
#include "ui_itemorder.h"
#include <QMessageBox>
#include <QApplication>
#include <QPushButton>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

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

void itemorder::setTrainInfo(QString passenger, QString no, QString type, QString time, QString start, QString end, int price, QString id)
{
    ui->name->setText(passenger);
    ui->no->setText(no);
    ui->time->setText(time);
    ui->s->setText(start);
    ui->e->setText(end);
    ui->t->setText(type);
    ui->p->setText(QString::number(price));
    ui->id->setText(id);
}

void itemorder::on_delet_clicked()
{
    QWidget window;
    int ret = QMessageBox::question(&window,
                                    "询问",
                                    "您确定要删除该订单吗？",
                                    QMessageBox::Yes | QMessageBox::No,
                                    QMessageBox::No);
    if (ret == QMessageBox::Yes) {
        // 用户点击了"是"
        QString id = ui->id->text();
        // 首先检查订单是否存在
        QSqlQuery queryCheck;
        QString checkSql = QString("SELECT COUNT(*) FROM order_list WHERE order_id = '%1'").arg(id);
        if (!queryCheck.exec(checkSql) || !queryCheck.next()) {
            QMessageBox::critical(this, "删除失败", "查询订单失败，请稍后重试。");
            return;
        }
        int orderCount = queryCheck.value(0).toInt();
        if (orderCount == 0) {
            // 订单号不存在
            QMessageBox::information(this, "删除失败", "找不到该订单号，请检查订单号是否正确。");
        } else {
            // 构建删除语句
            QSqlQuery query;
            QString delet = QString("DELETE FROM order_list WHERE order_id = '%1'")
                                .arg(id);
            if (query.exec(delet)) {
                qDebug() << "删除成功";
                QSqlQuery querytrain;
                querytrain.prepare("SELECT * FROM train_info WHERE train_no = (:value1)");
                QString no = ui->no->text();
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
                        QString query1 = QString("UPDATE train_info SET train_carriages = train_carriages + 1 WHERE train_no = '%1'")
                        .arg(no);
                        QSqlQuery sql;
                        if (sql.exec(query1)) {
                            qDebug() << "更新成功";
                        } else {
                            qDebug() << "更新失败";
                        }
                    }
                    else{
                        QMessageBox::information(this, "退订失败", "请检查原因");
                    }
                }
            } else {
                QMessageBox::critical(this, "退订失败", "退订出错，请检查是否重复退票: " + query.lastError().text());
            }
        }
    } else {
        // 用户点击了"否"
        qDebug() << "用户取消";
    }
}

