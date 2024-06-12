#ifndef _SIMULATE_V_
#define _SIMULATE_V_

#define MASS 1.0
#define ENERGIE 100.0
#define PARTICALS 100
#define SIZE_OF_CUBE 10.0
#define RADIUS_PARTICAL 0.1

// typedef unsigned int size_t;
#include <iostream>

typedef struct {
  float x;
  float y;
  float z;
} Vector3;

typedef struct {
  float v_x;
  float v_y;
  float v_z;
} v_Vector3;

typedef struct {
  float m;
  float energie;
  Vector3 pos;
  v_Vector3 v;
} Partical;

class Boltzmann_Verteilung {
private:
  Partical m_partical[PARTICALS];

public:
  Boltzmann_Verteilung();
  void update();
    
  // friend bool checkPosition(Partical *par1, Partical *par2); 
};

#endif
