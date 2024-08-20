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
        // 构建删除语句
        QSqlQuery query;
        QString delet = QString("DELETE FROM order_list WHERE order_id = '%1'")
                            .arg(id);
        if (query.exec(delet)) {
            qDebug() << "删除成功";
        } else {
            QMessageBox::critical(this, "删除失败", "删除出错: " + query.lastError().text());
        }
    } else {
        // 用户点击了"否"
        qDebug() << "用户取消";
    }
}

