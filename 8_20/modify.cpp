#include "modify.h"
#include "ui_modify.h"
#include"globalusermanager.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

Modify::Modify(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Modify)
{
    ui->setupUi(this);
}

Modify::~Modify()
{
    delete ui;
}

void Modify::on_pushButton_clicked()
{
    QString newPhoneNum = ui->PhoneLineEdit->text();
    QString newName = ui->userNameLineEdit->text();
    QString newPassword = ui->userPasswordLineEdit->text();
    QString user_phone = GlobalDataManager::getInstance()->getUserDataBase();

    // 构建更新语句
    QString updateSql = "UPDATE user SET ";
    QSqlQuery query;

    // 只有非空字段才会添加到更新语句中
    if (!newPhoneNum.isEmpty() && newPhoneNum != user_phone) {
        updateSql += "user_phone_num = :phoneNum, ";
    }
    if (!newName.isEmpty()) { // 确保新用户名与当前用户名不同
        updateSql += "user_name = :name, ";
    }
    if (!newPassword.isEmpty()) {
        updateSql += "user_password = :password, ";
    }
    // 移除最后一个逗号
    updateSql.truncate(updateSql.length() - 2);

    // 添加 WHERE 子句来根据用户名查找记录
    updateSql += " WHERE user_phone_num = :userPhone";

    // 准备查询
    query.prepare(updateSql);

    // 绑定参数
    if (!newPhoneNum.isEmpty() && newPhoneNum != user_phone) {
        query.bindValue(":phoneNum", newPhoneNum);
    }
    if (!newName.isEmpty()) {
        query.bindValue(":name", newName);
    }
    if (!newPassword.isEmpty()) {
        query.bindValue(":password", newPassword);
    }
    query.bindValue(":userPhone", user_phone);
    // 执行更新操作
    if (query.exec()) {
        QMessageBox::information(this, "修改成功", "用户信息已更新");
        GlobalDataManager* manager = GlobalDataManager::getInstance();
        manager->setUserDataBase(newPhoneNum,newName,newPassword);
    } else {
        QMessageBox::critical(this, "修改失败", "更新出错: " + query.lastError().text());
    }

    emit this->back();
}

