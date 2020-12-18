#include "dimensao.h"
#include "ui_dimensao.h"

Dimensao::Dimensao(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dimensao)
{
    ui->setupUi(this);
}

Dimensao::~Dimensao()
{
    delete ui;
}

int Dimensao::getX()
{
    return ui->spinBoxX->value();
}

int Dimensao::getY()
{
    return ui->spinBoxY->value();
}

int Dimensao::getZ()
{
    return ui->spinBoxZ->value();
}
