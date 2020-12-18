#include "plotter.h"
#include <QPainter>
#include <QBrush>
#include <QPen>

Plotter::Plotter(QWidget *parent) : QWidget(parent)
{

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
            contx=0;
            for (int j=1;j<=nx;j++) {
                painter.drawRect(inicio_x,inicio_y,width()/nx,height()/ny);
                contx+=(float)(width()/nx);
            }
            conty+=(float)(height()/ny);
        }

        for(int i=0;i<nx;i++)
        {
            for(int j=0;j<ny;j++)
            {
                if(sculptor->getisOn(i,j,Dz))
                {
                    brush.setColor(QColor(sculptor->getR(i,j,Dz)*255,sculptor->getG(i,j,Dz)*255,sculptor->getB(i,j,Dz)*255));
                    painter.setBrush(brush);
                    painter.drawRect(i*(larg/nx),j*(alt/ny),larg/nx,alt/ny);
                }
            }
        }

}
