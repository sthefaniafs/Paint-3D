#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QDialog>
#include "sculptor.h"
#include <cstdlib>
#include "plotter.h"
#include "definircor.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void fecha();
    void put_voxel();
    void put_box();
    void put_elipse();
    void put_esfera();
    void cut_voxel();
    void cut_box();
    void cut_elipse();
    void cut_esfera();
    void abreMatriz(void);
    void salvarOFF();
    void mudandoZ(int z);
    int getBoxX();
    int getBoxY();
    int getBoxZ();
    int getRaioElipseX();
    int getRaioElipseY();
    int getRaioElipseZ();
    int getRaioSphere();
    void coloca_cor();

private:
    Ui::MainWindow *ui;
    DefinirCor dialog_pc;
};
#endif // MAINWINDOW_H
