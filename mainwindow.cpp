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
            SIGNAL(triggered(bool)),
            this,
            SLOT(put_box()));
    connect(ui->actionColocar_Voxel,
            SIGNAL(triggered(bool)),
            this,
            SLOT(put_voxel()));
    connect(ui->actionColocar_elipse,
            SIGNAL(triggered(bool)),
            this,
            SLOT(put_elipse()));
    connect(ui->actionColocar_esfera,
            SIGNAL(triggered(bool)),
            this,
            SLOT(put_esfera()));
    connect(ui->actionTirar_Caixa,
            SIGNAL(triggered(bool)),
            this,
            SLOT(cut_box()));
    connect(ui->actionTirar_Voxel,
            SIGNAL(triggered(bool)),
            this,
            SLOT(cut_voxel()));
    connect(ui->actionTirar_Elipse,
            SIGNAL(triggered(bool)),
            this,
            SLOT(cut_elipse()));
    connect(ui->actionTirar_esfera,
            SIGNAL(triggered(bool)),
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
    connect(ui->horizontalSliderz,
            SIGNAL(valueChanged(int)),
            this,
            SLOT(mudandoZ(int)));
    connect(ui->actionCor,
            SIGNAL(triggered(bool)),
            this,
            SLOT(coloca_cor()));

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
    ui->widget->plot_PutVoxel();
    repaint();
}

void MainWindow::put_box()
{
    ui->widget->Novo_PutBox(getBoxX(),getBoxY(),getBoxZ());
    ui->widget->plot_PutBox();
    repaint();
}

void MainWindow::put_elipse()
{
    ui->widget->Novo_PutEllipsoid(getRaioElipseX(),getRaioElipseY(),getRaioElipseZ());
    ui->widget->plot_PutEllipsoid();
    repaint();
}

void MainWindow::put_esfera()
{
    ui->widget->Novo_PutSphere(getRaioSphere());
    ui->widget->plot_PutSphere();
    repaint();
}

void MainWindow::cut_voxel()
{
    ui->widget->plot_CutVoxel();
    repaint();
}

void MainWindow::cut_box()
{
    ui->widget->Novo_PutBox(getBoxX(),getBoxY(),getBoxZ());
    ui->widget->plot_CutBox();
    repaint();
}

void MainWindow::cut_elipse()
{
    ui->widget->Novo_PutEllipsoid(getRaioElipseX(),getRaioElipseY(),getRaioElipseZ());
    ui->widget->plot_CutEllipsoid();
    repaint();
}

void MainWindow::cut_esfera()
{
    ui->widget->Novo_PutSphere(getRaioSphere());
    ui->widget->plot_CutSphere();
    repaint();
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
   return ui->horizontalBX->value();
}

int MainWindow::getBoxY()
{
   return ui->horizontalBY->value();
}

int MainWindow::getBoxZ()
{
   return ui->horizontalBZ->value();
}
<<<<<<< HEAD
=======
float MainWindow:: getCorR()
{
    return ui->horizontalSliderVermelho->value();
}
float MainWindow:: getCorG()
{
    return ui->horizontalSliderVerde->value();
}
float MainWindow:: getCorB()
{
    return ui->horizontalSliderAzul->value();
}
>>>>>>> 770d4fcf0a9dff4f762adb8cb421e96a1ee24404
int MainWindow::getRaioElipseX()
{
    return ui->horizontalSliderRaiox->value();
}

int MainWindow::getRaioElipseY()
{
    return ui->horizontalSliderRaioy->value();
}

int MainWindow::getRaioElipseZ()
{
    return ui->horizontalSliderRaioz->value();
}
int MainWindow::getRaioSphere()
{
    return ui->horizontalSliderEsfera->value();
}
void MainWindow::coloca_cor()
{
    if(dialog_pc.exec()==QDialog::Accepted){
        if(dialog_pc.getColorR()>=0 && dialog_pc.getColorR()<=255 && dialog_pc.getColorG()>=0 && dialog_pc.getColorG()<=255 && dialog_pc.getColorB()>=0 && dialog_pc.getColorB()<=255){
            ui->widget->Novo_Colors(dialog_pc.getColorR(),dialog_pc.getColorG(),dialog_pc.getColorB());
        }else{
            QMessageBox::information(this, tr("Erro"),tr("\nvalores inválidos, tente outra vez!\n"));
        }
    }
}
