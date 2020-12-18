#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <math.h>
#include "sculptor.h"

using namespace std;

//Cria o construtor da classe Sculptor
Sculptor::Sculptor(int _nx, int _ny, int _nz)
{
    nx=_nx, ny=_ny, nz=_nz;
    v= new Voxel **[nx];
    for(int i=0; i<nx; i++)
    {
        v[i]= new Voxel *[ny];
        for(int j=0; j<ny; j++)
            v[i][j]= new Voxel [nz];
    }
    for(int i=0; i<nx; i++)
    {
        for(int j=0; j<ny; j++)
        {
            for(int k=0; k<nz; k++)
            {
                v[i][j][k].isOn=false;
            }
        }
    }
}
//Cria o destrutor da classe Sculptor
Sculptor::~Sculptor()
{
    for(int i=0; i<nx; i++)
    {
        for(int j=0; j<ny; j++)
        {
            delete [] v[i][j];
        }
        delete [] v[i];
    }
    delete [] v;
    nx=ny=nz=0;
    r=g=b=a=0;
}
//Função membro que atribui cor ao desenho
void Sculptor::setColor(float r, float g, float b, float alpha)
{
    this->r=r;
    this->g=g;
    this->b=b;
    a=alpha;
}

//Função membro que ativa o voxel na posição (x,y,z)e atribui a cor atual do desenho a ele
void Sculptor::putVoxel(int x, int y, int z)
{
    v[x][y][z].isOn=true;
    v[x][y][z].r=r;
    v[x][y][z].g=g;
    v[x][y][z].b=b;
    v[x][y][z].a=a;
}
//Função membro que desativa o voxel na posição (x,y,z)
void Sculptor::cutVoxel(int x, int y, int z)
{
    v[x][y][z].isOn=false;
}
//Função membro que ativa todos os voxels no intervalo [x0,x1], [y0,y1], [z0,z1] criando um cubo com a cor atual do desenho
void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1)
{

    for(int i=x0; i<x1; i++)
    {
        for(int j=y0; j<y1; j++)
        {
            for(int k=z0; k<z1; k++)
            {
                putVoxel(i,j,k);
            }
        }
    }
}
//Função membro que desativa todos os voxels no intervalo [x0,x1], [y0,y1], [z0,z1].
void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
   for(int i=x0; i<x1; i++)
    {
        for(int j=y0; j<y1; j++)
        {
            for(int k=z0; k<z1; k++)
            {
                cutVoxel(i,j,k);
            }
        }
    }

}
// Função membro que ativa os voxels que satisfazem à equação da esfera e atribui a eles a cor atual do desenho
void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    int px=0,py=0,pz=0;
    for(int i=0; i<(xcenter+radius); i++)
    {
        for(int j=0; j<(ycenter+radius); j++)
        {
            for(int k=0; k<(zcenter+radius); k++)
            {
                px=i-xcenter;
                py=j-ycenter;
                pz=k-zcenter;
                if(pow(px,2)+pow(py,2)+pow(pz,2)<=pow(radius,2))
                    {
                        if(i<(xcenter+radius) && j<(ycenter+radius) && k<(zcenter+radius) && i>0 && j>0 && k>0)
                            putVoxel(i,j,k);
                    }
            }
        }
    }
}
// Função membro que desativa os voxels que satisfazem à equação da esfera
void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    /*Seguindo a mesma lógica do putSphere, a diferença entre as funções é que o cutSphere remove os voxels seguindo as
    mesmas duas condições. */

    int px=0,py=0,pz=0;
    for(int i=0; i<(xcenter+radius); i++)
    {
        for(int j=0; j<(ycenter+radius); j++)
        {
            for(int k=0; k<(zcenter+radius); k++)
            {
                px=i-xcenter;
                py=j-ycenter;
                pz=k-zcenter;
                if(pow(px,2)+pow(py,2)+pow(pz,2)<=pow(radius,2))
                    {
                        if(i<(xcenter+radius) && j<(ycenter+radius) && k<(zcenter+radius) && i>0 && j>0 && k>0)
                            cutVoxel(i,j,k);
                    }
            }
        }
    }
}
//Ativa todos os voxels que satisfazem à equação do elipsóide e atribui a eles a cor atual de desenho
void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
   int px=0,py=0,pz=0;
    for(int i=0; i<(xcenter+rx); i++)
    {
        for(int j=0; j<(ycenter+ry); j++)
        {
            for(int k=0; k<(zcenter+rz); k++)
            {
                px=i-xcenter;
                py=j-ycenter;
                pz=k-zcenter;
                if((pow(px,2)/pow(rx,2))+(pow(py,2)/pow(ry,2))+(pow(pz,2)/pow(rz,2))<=1)
                    {
                        if(i<(xcenter+rx) && j<(ycenter+ry) && k<(zcenter+rz) && i>0 && j>0 && k>0)
                            putVoxel(i,j,k);
                    }
            }
        }
    }
}
//Desativa todos os voxels que satisfazem à equação do elipsóide
void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
    /*Seguindo a mesma lógica do putEllipsoid, a diferença entre as funções é que o cutEllipsoid remove os voxels seguindo as
    mesmas duas condições. */
    int px=0,py=0,pz=0;
    for(int i=0; i<(xcenter+rx); i++)
    {
        for(int j=0; j<(ycenter+ry); j++)
        {
            for(int k=0; k<(zcenter+rz); k++)
            {
                px=i-xcenter;
                py=j-ycenter;
                pz=k-zcenter;
                if((pow(px,2)/pow(rx,2))+(pow(py,2)/pow(ry,2))+(pow(pz,2)/pow(rz,2))<=1)
                    {
                        if(i<(xcenter+rx) && j<(ycenter+ry) && k<(zcenter+rz) && i>0 && j>0 && k>0)
                            cutVoxel(i,j,k);
                    }
            }
        }
    }
}
// Função membro que grava a escultura no arquivo filename com formato OFF
void Sculptor::writeOFF(char* filename)
{
    ofstream fout;
    fout.open(filename);
    if (!fout.is_open())
    {
        exit(0);
    }

    int P0,P1,P2,P3,P4,P5,P6,P7,n=0,nv=0;
    P0=0;
    P1=1;
    P2=2;
    P3=3;
    P4=4;
    P5=5;
    P6=6;
    P7=7;

    for(int i=0; i<nx; i++)
    {
        for(int j=0; j<ny; j++)
        {
            for(int k=0; k<nz; k++)
            {
                if (v[i][j][k].isOn==true)
                    nv++;
            }
        }
    }

    fout << "OFF" << endl;
    fout << 8*nv << " " << 6*nv << " 0" <<endl;

    for(int i=0; i<nx; i++)
    {
        for(int j=0; j<ny; j++)
        {
            for(int k=0; k<nz; k++)
            {
                if (v[i][j][k].isOn==true)
                {
                    float xmin,xmax,ymin,ymax,zmin,zmax;
                    xmin=i-0.5;
                    xmax=i+0.5;
                    ymin=j-0.5;
                    ymax=j+0.5;
                    zmin=k-0.5;
                    zmax=k+0.5;

                    fout << xmin << " " << ymax << " " << zmin <<endl;
                    fout << xmin << " " << ymin << " " << zmin <<endl;
                    fout << xmax << " " << ymin << " " << zmin <<endl;
                    fout << xmax << " " << ymax << " " << zmin <<endl;
                    fout << xmin << " " << ymax << " " << zmax <<endl;
                    fout << xmin << " " << ymin << " " << zmax <<endl;
                    fout << xmax << " " << ymin << " " << zmax <<endl;
                    fout << xmax << " " << ymax << " " << zmax <<endl;
                }
            }
        }
    }

    for(int i=0; i<nx; i++)
    {
        for(int j=0; j<ny; j++)
        {
            for(int k=0; k<nz; k++)
            {
                if (v[i][j][k].isOn==true)
                {
                    fout.setf(std::ios::showpoint);
                    fout << 4 << " " << P0+n << " " << P3+n << " " << P2+n << " " << P1+n << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                    fout << 4 << " " << P4+n << " " << P5+n << " " << P6+n << " " << P7+n << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                    fout << 4 << " " << P0+n << " " << P1+n << " " << P5+n << " " << P4+n << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                    fout << 4 << " " << P0+n << " " << P4+n << " " << P7+n << " " << P3+n << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                    fout << 4 << " " << P7+n << " " << P6+n << " " << P2+n << " " << P3+n << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                    fout << 4 << " " << P1+n << " " << P2+n << " " << P6+n << " " << P5+n << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                    n+=8;

                }
            }
        }
    }

    fout.close();
}

bool Sculptor::getis0n(int x, int y, int z)
{
    return v[x][y][z].isOn;
}

float Sculptor::getR(int i, int j, int k)
{
    return v[i][j][k].r;
}

float Sculptor::getG(int i, int j, int k)
{
    return v[i][j][k].g;
}

float Sculptor::getB(int i, int j, int k)
{
    return v[i][j][k].b;
}
