#include "definircor.h"
#include "ui_definircor.h"

DefinirCor::DefinirCor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DefinirCor)
{
    ui->setupUi(this);
}

DefinirCor::~DefinirCor()
{
    delete ui;
}

int DefinirCor::getColorR()
{
    ui->spinBoxCorR->value();
}

int DefinirCor::getColorG()
{
    ui->spinBoxCorV->value();
}

int DefinirCor::getColorB()
{
    ui->spinBoxCorA->value();
}
