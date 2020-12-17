#ifndef VOXEL_H
#define VOXEL_H

struct Voxel {
  float r,g,b; // cores (vermelho, verde, azul)
  float a; // Transparência (1 opaco, 0 transparente)
  bool isOn; // Included or not
};

#endif // VOXEL_H

