#ifndef SCULPTOR_H
#define SCULPTOR_H
#include "Voxel.h"

class Sculptor
{protected:
    Voxel ***v; // matriz de 3 dimensões do tipo voxel
    int nx,ny,nz; // determina a dimensão da matriz
    float r,g,b,a; // determina a cor da matriz
  public:
    Sculptor(int _nx, int _ny, int _nz); // construtor
    ~Sculptor(); //destrutor
    //funções membro
    void setColor(float r, float g, float b, float alpha);
    void putVoxel(int x, int y, int z);
    void cutVoxel(int x, int y, int z);
    void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
    void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
    void putSphere(int xcenter, int ycenter, int zcenter, int radius);
    void cutSphere(int xcenter, int ycenter, int zcenter, int radius);
    void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    bool getis0n(int x, int y, int z);
    void writeOFF(char* filename);
    float getR (int i, int j, int k);
    float getG (int i, int j, int k);
    float getB (int i, int j, int k);
};

#endif // SCULPTOR_H
