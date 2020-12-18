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
    connect(ui->actionSalvar,
            SIGNAL(triggered(bool)),
            this,
            SLOT(salvarOFF()));
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
    ui->widget->Novo_PutBox(getBoxX(),getBoxY(),getBoxZ());
    ui->widget->plot_PutBox();
    repaint();
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
               QMessageBox::information(this, tr("Vixi, deu errado"),tr("\nAs dimensões precisam ser maiores que 0, tente outra vez!\n"));
           }
    }
}

void MainWindow::salvarOFF()
{
    QString file=QFileDialog::getSaveFileName();
    file=file+".off";
    ui->widget->s->writeOFF(file.toStdString().c_str());

}

void MainWindow::mudandoZ(int _dimz){

    ui->widget->mudaplano(_dimz);

}

int MainWindow::getBoxX()
{
<<<<<<< HEAD
   return ui->horizontalBX->value();
=======
    return ui->horizontalBX->value();
>>>>>>> 714ad3309cfb12bff570d95b7b2692a692170591
}

int MainWindow::getBoxY()
{
<<<<<<< HEAD
   return ui->horizontalBY->value();
=======
    return ui->horizontalBY->value();
>>>>>>> 714ad3309cfb12bff570d95b7b2692a692170591
}

int MainWindow::getBoxZ()
{
<<<<<<< HEAD
   return ui->horizontalBZ->value();
}
int MainWindow:: getCorR()
{
    return ui->horizontalSliderVermelho->value();
}
int MainWindow:: getCorG()
{
    return ui->horizontalSliderVerde->value();
}
int MainWindow:: getCorB()
{
    return ui->horizontalSliderAzul->value();
=======
    return ui->horizontalBZ->value();
}
int MainWindow::getRaioElipseX()
{
    return ui->horizontalSliderRaiox->value();
>>>>>>> 714ad3309cfb12bff570d95b7b2692a692170591
}

int MainWindow::getRaioElipseY()
{
    return ui->horizontalSliderRaioy->value();
}

int MainWindow::getRaioElipseZ()
{
    return ui->horizontalSliderRaioz->value();
}

