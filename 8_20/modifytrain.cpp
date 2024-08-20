#include "modifytrain.h"
#include "ui_modifytrain.h"

Modifytrain::Modifytrain(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Modifytrain)
{
    ui->setupUi(this);
}

Modifytrain::~Modifytrain()
{
    delete ui;
}
