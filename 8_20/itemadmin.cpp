#include "itemadmin.h"
#include "ui_itemadmin.h"
#include <QMessageBox>
#include <QApplication>
#include <QPushButton>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

itemAdmin::itemAdmin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::itemAdmin)
{
    ui->setupUi(this);
}
void itemAdmin::setTrainInfo(QString no, QString type, QString time, QString start, QString end,int price, int carriage)
{
    ui->no->setText(no);
    ui->time->setText(time);
    ui->s->setText(start);
    ui->e->setText(end);
    ui->ca->setText(QString::number(carriage));
    ui->t->setText(type);
    ui->p->setText(QString::number(price));
}
itemAdmin::~itemAdmin()
{
    delete ui;
}

void itemAdmin::on_delete_2_clicked()
{
    QWidget window;
    int ret = QMessageBox::question(&window,
                                    "询问",
                                    "您确定要删除该车次吗？",
                                    QMessageBox::Yes | QMessageBox::No,
                                    QMessageBox::No);

    if (ret == QMessageBox::Yes) {
        // 用户点击了"是"
        QString noo = ui->no->text();
        // 构建删除语句
        QSqlQuery query;
        QString delet = QString("DELETE FROM train_info WHERE train_no = '%1'")
                            .arg(noo);
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


void itemAdmin::on_modify_clicked()
{
    QWidget window;
    int ret = QMessageBox::question(&window,
                                    "询问",
                                    "您确定要更新该车次吗？",
                                    QMessageBox::Yes | QMessageBox::No,
                                    QMessageBox::No);

    if (ret == QMessageBox::Yes) {
        // 用户点击了"是"
        QString noo = ui->no->text();
        QString caa = ui->ca->text();
        QString tii = ui->time->text();
        QString ss = ui->s->text();
        QString ee = ui->e->text();
        QString pp = ui->p->text();
        QString tt = ui->t->text();
        // 构建更新语句
        QString updateSql = "UPDATE train_info SET ";
        QSqlQuery query;

        // 只有非空字段才会添加到更新语句中
        if (!noo.isEmpty() ) {
            updateSql += "train_no = :no, ";
        }
        if (!tt.isEmpty() ) {
            updateSql += "train_type = :type, ";
        }
        if (!tii.isEmpty() ) {
            updateSql += "train_start_time = :time, ";
        }
        if (!ss.isEmpty() ) {
            updateSql += "train_start_station = :start, ";
        }
        if (!ee.isEmpty() ) {
            updateSql += "train_end_station = :end, ";
        }
        if (!pp.isEmpty() ) {
            updateSql += "train_price = :price, ";
        }
        if (!ee.isEmpty() ) {
            updateSql += "train_carriages = :carriage, ";
        }
        // 移除最后一个逗号
        updateSql.truncate(updateSql.length() - 2);
        // 添加 WHERE 子句来根据用户名查找记录
        updateSql += " WHERE train_no = :no";
        // 准备查询
        query.prepare(updateSql);
        // 绑定参数
        if (!noo.isEmpty()) {
            query.bindValue(":no", noo);
        }
        if (!tt.isEmpty()) {
            query.bindValue(":type", tt);
        }
        if (!tii.isEmpty()) {
            query.bindValue(":time", tii);
        }
        if (!ss.isEmpty()) {
            query.bindValue(":start", ss);
        }
        if (!ee.isEmpty()) {
            query.bindValue(":end", ee);
        }
        if (!pp.isEmpty()) {
            query.bindValue(":price", pp);
        }
        if (!caa.isEmpty()) {
            query.bindValue(":carriage", caa);
        }
        // 执行更新操作
        if (query.exec()) {
            QMessageBox::information(this, "修改成功", "列车信息已更新");
        } else {
            QMessageBox::critical(this, "修改失败", "更新出错,请检查是否有空信息: " + query.lastError().text());
        }
    } else {
        // 用户点击了"否"
        qDebug() << "用户取消";
    }
}

