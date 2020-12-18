#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dimensao.h"
#include <QtDebug>
#include <QtWidgets>
#include <QAction>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButtonQuit,
            SIGNAL(clicked(bool)),
            this,
            SLOT(fecha()));
    connect(ui->actionColocar_Caixa,
            SIGNAL(clicked(bool)),
            this,
            SLOT(put_box()));
    connect(ui->actionColocar_Voxel,
            SIGNAL(clicked(bool)),
            this,
            SLOT(put_voxel()));
    connect(ui->actionColocar_elipse,
            SIGNAL(clicked(bool)),
            this,
            SLOT(put_elipse()));
    connect(ui->actionColocar_esfera,
            SIGNAL(clicked(bool)),
            this,
            SLOT(put_esfera()));
    connect(ui->actionTirar_Caixa,
            SIGNAL(clicked(bool)),
            this,
            SLOT(cut_box()));
    connect(ui->actionTirar_Voxel,
            SIGNAL(clicked(bool)),
            this,
            SLOT(cut_voxel()));
    connect(ui->actionTirar_Elipse,
            SIGNAL(clicked(bool)),
            this,
            SLOT(cut_elipsoide()));
    connect(ui->actionTirar_esfera,
            SIGNAL(clicked(bool)),
            this,
            SLOT(cut_esfera()));
    connect(ui->actionAlterar_Tamanho_da_Matriz,
            SIGNAL(triggered(bool)),
            this,
            SLOT(abreMatriz()));
    connect(ui->horizontalSliderz,
                SIGNAL(valueChanged(int)),
                this,
                SLOT(mudandoZ(int)));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::fecha()
{
    exit(0);
}

void MainWindow::put_voxel()
{

}

void MainWindow::put_box()
{

}

void MainWindow::put_elipse()
{

}

void MainWindow::put_esfera()
{

}

void MainWindow::cut_voxel()
{

}

void MainWindow::cut_box()
{

}

void MainWindow::cut_elipse()
{

}

void MainWindow::cut_esfera()
{

}

void MainWindow::abreMatriz()
{
    Dimensao d;
    if(d.exec()==QDialog::Accepted){
           if(d.getX()!=0 && d.getY()!=0 && d.getZ()!=0){
               ui->widget->mudaSculptor(d.getX(),d.getY(),d.getZ());
               ui->horizontalSliderz->setMaximum(d.getZ());
               repaint();
           }else{
               QMessageBox::information(this, tr("Vixi deu errado"),tr("\nAs dimensões precisam ser maiores que 0, tente outra vez!\n"));
           }
    }
}

void MainWindow::mudandoZ(int _dimz){

    ui->widget->mudaplano(_dimz);

}

int MainWindow::getBoxX()
{
    ui->spinBoxBoxX->value();
}

int MainWindow::getBoxY()
{
    ui->spinBoxBoxY->value();
}

int MainWindow::getBoxZ()
{
    ui->spinBoxBoxZ->value();
}
