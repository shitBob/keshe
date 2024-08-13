#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include"QDebug"
#include"QSqlDatabase"
#include"QSqlError"
#include <QSqlQuery>
#include "menu.h"
#include<QPushButton>
#include"globalusermanager.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    ,ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->page2 = new Menu;
    connect(this->page2,&Menu::back,[=](){
        this->page2->hide();
        this->show();
    });
    qDebug()<<QSqlDatabase::drivers();
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("db"); // 数据库名
    db.setUserName("root"); // 数据库用户名
    db.setPassword("123456"); // 数据库密码
    if(!db.open())
    {
        qDebug() <<"Failed to open db"<<db.lastError();
    }else
    {
        qDebug() <<"open success";
    }
    // QString sql = "INSERT INTO user (user_phone_num, user_id_num,user_password, user_email, user_real_name, user_type, user_gender, user_address) "
    //               "VALUES (:user_phone_num,:user_id_num, :user_password, :user_email, :user_real_name, :user_type, :user_gender, :user_address)";

    // // 准备查询
    // QSqlQuery query;
    // if (query.prepare(sql)) {
    //     // 绑定参数
    //     query.bindValue(":user_phone_num", "12345678901");
    //     query.bindValue(":user_id_num", "123");
    //     query.bindValue(":user_password", "password123");
    //     query.bindValue(":user_email", "user@example.com");
    //     query.bindValue(":user_real_name", "张三");
    //     query.bindValue(":user_type", 1);
    //     query.bindValue(":user_gender", 1); // 假设1表示男性
    //     query.bindValue(":user_address", "北京市朝阳区");

    //     // 执行查询
    //     if (query.exec()) {
    //         qDebug() << "数据插入成功";
    //     } else {
    //         qDebug() << "数据插入失败:" << query.lastError().text();
    //     }
    // } else {
    //     qDebug() << "查询准备失败:" << query.lastError().text();
    // }
}

MainWindow::~MainWindow()
{

}

void MainWindow::on_login_clicked()
{
    QString user_id_num = ui->user_id_numLineEdit->text();
    QString password = ui->passwordLineEdit->text();

    QSqlQuery query;
    query.prepare("SELECT * FROM user WHERE user_id_num = :user_id_num");

    query.bindValue(":user_id_num", user_id_num);
    if (query.exec()) {
        if (query.next()) {
            QString storedPassword = query.value("user_password").toString();
            // 这里应该使用密码散列比较
            if (storedPassword == password) { // 实际上应该使用密码验证函数
                // 登录成功
                // 可能需要保存用户ID或用户名到应用程序中
                GlobalDataManager* manager = GlobalDataManager::getInstance();
                manager->setUserDataBase(user_id_num,password);
                // QString data=GlobalDataManager::getInstance()->getUserDataBase();
                // qDebug()<<data;
                this->hide();
                this->page2->show();
                qDebug()<<"success";
            } else {
                qDebug() << "Password does not match.";
            }
        } else {
            qDebug() << "User not found.";
        }
    } else {
        qDebug() << "Query execution failed.";
    }
}

