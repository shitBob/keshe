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
    this->a= new Admin;
    connect(this->a,&Admin::back,[=](){
        this->a->hide();
        this->show();
    });
    this->r = new RegisterWindow;
    connect(this->r,&RegisterWindow::back,[=](){
        this->r->hide();
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
    // QString sql = "INSERT INTO user (user_phone_num, user_name,user_password, user_type) "
    //               "VALUES (:user_phone_num,:user_name, :user_password, :user_type)";

    // // 准备查询
    // QSqlQuery query;
    // if (query.prepare(sql)) {
    //     // 绑定参数
    //     query.bindValue(":user_phone_num", "123456");
    //     query.bindValue(":user_name", "123");
    //     query.bindValue(":user_password", "123456");
    //     query.bindValue(":user_type", "0");


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
    QString user_phone_num = ui->user_id_numLineEdit->text();
    QString password = ui->passwordLineEdit->text();
    QSqlQuery query;
    query.prepare("SELECT * FROM user WHERE user_phone_num = :user_phone_num");

    query.bindValue(":user_phone_num", user_phone_num);
    if (query.exec()) {
        if (query.next()) {
            QString storedPassword = query.value("user_password").toString();
            QString user_name = query.value("user_name").toString();
            QString type =  query.value("user_type").toString();
            // 这里应该使用密码散列比较
            if (storedPassword == password) { // 实际上应该使用密码验证函数
                // 登录成功
                // 可能需要保存用户ID或用户名到应用程序中
                qDebug()<<type;
                if(type=="0"){
                    GlobalDataManager* manager = GlobalDataManager::getInstance();
                    manager->setUserDataBase(user_phone_num,user_name,password);
                    // QString data=GlobalDataManager::getInstance()->getUserDataBase();
                    // qDebug()<<data;
                    this->hide();
                    this->page2->show();
                    qDebug()<<"success";
                }
                else {
                    this->hide();
                    this->a->show();
                }
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


void MainWindow::on_pushButton_clicked()
{

    this->hide();
    this->r->show();
}

