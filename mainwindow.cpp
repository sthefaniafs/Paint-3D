#include "mainwindow.h"
#include "ui_mainwindow.h"

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

