#include "menu.h"
#include "ui_menu.h"
#include "booking.h"
#include "my.h"

Menu::Menu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Menu)
{
    ui->setupUi(this);
    this->booking = new Booking;
    this->my = new My;
    connect(ui->booking,&QPushButton::clicked,[=](){
        this->hide();
        this->booking->show();
    });
    connect(ui->my,&QPushButton::clicked,[=](){
        this->hide();
        this->my->show();
    });
    connect(this->booking,&Booking::back,[=](){
        this->booking->hide();
        this->show();
    });
    connect(this->my,&My::back,[=](){
        this->my->hide();
        this->show();
    });
}

Menu::~Menu()
{
    delete ui;
}


void Menu::on_back1_clicked()
{
    emit this->back();
}

