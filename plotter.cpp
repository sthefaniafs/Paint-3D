#include "plotter.h"
#include <QPainter>
#include <QBrush>
#include <QPen>

Plotter::Plotter(QWidget *parent) : QWidget(parent)
{
    s = new Sculptor (10,10,10);
}

void Plotter::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QBrush brush;
    QPen pen;

    brush.setColor(QColor(255,255,255));
    brush.setStyle(Qt::SolidPattern);

    pen.setColor(QColor(0,0,0));
    pen.setWidth(1);
    pen.setStyle(Qt::SolidLine);

    painter.setPen(pen);
    painter.setBrush(brush);

    int largura_tela = width() - width()%nx;
    int altura_tela = height() - height()%ny;

    int inicio_x=0,inicio_y=0;
        for (int i=1;i<=ny;i++) {
            inicio_x=0;
            for (int j=1;j<=nx;j++) {
                painter.drawRect(inicio_x,inicio_y,width()/nx,height()/ny);
                inicio_x+=(float)(width()/nx);
            }
            inicio_y+=(float)(height()/ny);
        }

        for(int i=0;i<nx;i++)
        {
            for(int j=0;j<ny;j++)
            {
                if(s->getis0n(i,j,dimz))
                {
                    brush.setColor(QColor(s->getR(i,j,dimz)*255,s->getG(i,j,dimz)*255,s->getB(i,j,dimz)*255));
                    painter.setBrush(brush);
                    painter.drawRect(i*(largura_tela/nx),j*(altura_tela/ny),largura_tela/nx,altura_tela/ny);
                }
            }
        }

}

void Plotter:: mudaplano(int _dimz)
{
    dimz=_dimz;
    repaint();
}

void Plotter::mouseMoveEvent(QMouseEvent *event)
{
    dimx=event->x();
    dimy=event->y();
    int linha=width()/nx;
    int coluna=height()/ny;
    dimx=(dimx/linha);
    dimy=(dimy/coluna);

    if(putvoxel){
        s->setColor(r,g,b,1);
        s->putVoxel(dimx,dimy,dimz);
    }
    if(cutvoxel){
        s->cutVoxel(dimx,dimy,dimz);
    }
    if(putbox){
        s->setColor(r,g,b,1);
        s->putBox(dimx,dimx+x1-1,dimy,dimy+y1-1,dimz,dimz+z1-1);
    }
    if(cutbox){
        s->cutBox(dimx,dimx+x1,dimy,dimy+y1,dimz,dimz+z1);
    }
    if(putsphere){
        s->setColor(r,g,b,1);
        s->putSphere(dimx,dimy,dimz,RaioS);
    }
    if(cutsphere){
        s->cutSphere(dimx,dimy,dimz,RaioS);
    }
    if(putellipsoid){
        s->setColor(r,g,b,1);
        s->putEllipsoid(dimx,dimy,dimz,xr,yr,zr);
    }
    if(cutellipsoid){
        s->cutEllipsoid(dimx,dimy,dimz,xr,yr,zr);
    }
    repaint();
}

void Plotter::mousePressEvent(QMouseEvent *event)
{

    dimx=event->x();
    dimy=event->y();
    int linha=width()/nx;
    int coluna=height()/ny;
    dimx=(dimx/linha);
    dimy=(dimy/coluna);

    if(putvoxel){
        s->setColor(r,g,b,1);
        s->putVoxel(dimx,dimy,dimz);
    }
    if(cutvoxel){
        s->cutVoxel(dimx,dimy,dimz);
    }
    if(putbox){
        s->setColor(r,g,b,1);
        s->putBox(dimx,dimx+x1-1,dimy,dimy+y1-1,dimz,dimz+z1-1);
    }
    if(cutbox){
        s->cutBox(dimx,dimx+x1,dimy,dimy+y1,dimz,dimz+z1);
    }
    if(putsphere){
        s->setColor(r,g,b,1);
        s->putSphere(dimx,dimy,dimz,RaioS);
    }
    if(cutsphere){
        s->cutSphere(dimx,dimy,dimz,RaioS);
    }
    if(putellipsoid){
        s->setColor(r,g,b,1);
        s->putEllipsoid(dimx,dimy,dimz,xr,yr,zr);
    }
    if(cutellipsoid){
        s->cutEllipsoid(dimx,dimy,dimz,xr,yr,zr);
    }
    repaint();
}
