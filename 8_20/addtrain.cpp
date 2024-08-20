#include "addtrain.h"
#include "ui_addtrain.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

Addtrain::Addtrain(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Addtrain)
{
    ui->setupUi(this);
}

Addtrain::~Addtrain()
{
    delete ui;
}

void Addtrain::on_pushButton_clicked()
{
    QString no = ui->no->text();
    QString time = ui->time->text();
    QString start = ui->start->text();
    QString end = ui->end->text();
    QString ca = ui->ca->text();
    QString pr = ui->p->text();
    QString ty = ui->t->text();
    // 数据验证...
    if (no.isEmpty() || time.isEmpty() || start.isEmpty() || end.isEmpty() || ca.isEmpty()|| pr.isEmpty()|| ty.isEmpty()) {
        QMessageBox::warning(this, "添加错误", "所有字段均为必填项");
        return;
    }

    QString insertSql = QString("INSERT INTO train_info "
                                "(train_no, train_type, train_start_time, train_start_station, train_end_station, train_price, train_carriages) "
                                "VALUES ('%1', '%2', '%3', '%4', '%5','%6','%7')")
                            .arg(no)
                            .arg(ty)
                            .arg(time)
                            .arg(start)
                            .arg(end)
                            .arg(pr)
                            .arg(ca);

    QSqlQuery query;
    if (query.exec(insertSql)) {
        QMessageBox::information(this, "提示", "您已添加列车成功");
    } else {
        QMessageBox::critical(this, "列车信息添加失败", "添加失败：" + query.lastError().text());
    }
    emit this->back();
}

