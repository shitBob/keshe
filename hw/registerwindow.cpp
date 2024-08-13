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
