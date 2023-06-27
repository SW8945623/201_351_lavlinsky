#include "promocodes.h"
#include "ui_promocodes.h"

Promocodes::Promocodes(QString key, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Promocodes)
{
    ui->setupUi(this);
}

Promocodes::~Promocodes()
{
    delete ui;
}
