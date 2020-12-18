#ifndef PLOTTER_H
#define PLOTTER_H

#include <QWidget>
#include "sculptor.h"

class Plotter : public QWidget
{
    Q_OBJECT
public:
    explicit Plotter(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void mudaplano (int _dimz);

    Sculptor *s;
        int dimx=0, dimy=0, dimz=0;
        float r=0,g=0,b=0;
        int nx=10,ny=10,nz=10;
        int x1=0,y1=0,z1=0;
        int RaioS=0;
        int xraios=0,yraios=0,zraios=0;
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
