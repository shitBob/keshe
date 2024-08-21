#include "registerwindow.h"
#include "ui_registerwindow.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

RegisterWindow::RegisterWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}

void RegisterWindow::on_Register_clicked()
{
    QString username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();
    QString phone = ui->phoneLineEdit->text();
    // 数据验证...
    if (username.isEmpty() || password.isEmpty() || phone.isEmpty()) {
        QMessageBox::warning(this, "注册错误", "所有字段均为必填项");
        return;
    }

    QString sql = "INSERT INTO user (user_phone_num, user_name,user_password, user_type) "
                  "VALUES (:user_phone_num,:user_name, :user_password, :user_type)";

    // 准备查询
    QSqlQuery query;
    if (query.prepare(sql)) {
        // 绑定参数
        query.bindValue(":user_phone_num", phone);
        query.bindValue(":user_name", username);
        query.bindValue(":user_password", password);
        query.bindValue(":user_type", "0");

    if (query.exec()) {
        QMessageBox::information(this, "注册成功", "注册成功，请返回登录");
    } else {
        QMessageBox::critical(this, "注册失败", "注册失败：" + query.lastError().text());
    }
}
}

void RegisterWindow::on_back_clicked()
{
    emit this->back();
}

