#ifndef PLOTTER_H
#define PLOTTER_H

#include <QWidget>
#include <QAction>
#include "sculptor.h"
#include <QMouseEvent>

class Plotter : public QWidget
{
    Q_OBJECT
public:
    explicit Plotter(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void mudaplano (int _dimz);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mudaSculptor(int s_x,int s_y, int s_z);
    Sculptor *s;
        int dimx=0, dimy=0, dimz=0;
        float r=0,g=0,b=0;
        int nx=10,ny=10,nz=10;
        int x1=0,y1=0,z1=0;
        int RaioS=0;
        int xr=0,yr=0,zr=0;
        bool putvoxel=false;
        bool cutvoxel=false;
        bool putbox=false;
        bool cutbox=false;
        bool putsphere=false;
        bool cutsphere=false;
        bool putellipsoid=false;
        bool cutellipsoid= false;
signals:

};

#endif // PLOTTER_H
