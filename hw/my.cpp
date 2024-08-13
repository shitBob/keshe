#include "my.h"
#include "ui_my.h"
#include "query.h"
#include "modify.h"
#include<QLabel>
#include"globalusermanager.h"
My::My(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::My)
{
    ui->setupUi(this);
    this->modify = new Modify;
    this->query = new Query;
    connect(ui->modify,&QPushButton::clicked,[=](){
        this->hide();
        this->modify->show();
    });
    connect(ui->query,&QPushButton::clicked,[=](){
        this->hide();
        this->query->show();
    });
    connect(this->modify,&Modify::back,[=](){
        this->modify->hide();
        this->show();
    });
    connect(this->query,&Query::back,[=](){
        this->query->hide();
        this->show();
    });
}

My::~My()
{
    delete ui;
}

void My::on_back2_clicked()
{
    emit this->back();

}



void My::on_modify_clicked()
{
    QString userData = GlobalDataManager::getInstance()->getUserDataBase();
    QString password = GlobalDataManager::getInstance()->getUserDataBase1();
    qDebug()<<userData;
    ui->label_4->setText(userData);
    ui->label_5->setText(password);
}

