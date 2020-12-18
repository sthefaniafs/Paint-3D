#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


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
    void mudandoZ(int z);


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
