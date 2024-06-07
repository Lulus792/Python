#ifndef _SIMULATE_V_
#define _SIMULATE_V_

#define MASS 1.0
#define ENERGIE 100
#define PARTICALS 100
#define SIZE_OF_CUBE 10
#define RADIUS_PARTICAL 0.1

// typedef unsigned int size_t;
#include <iostream>

typedef struct {
    float x;
    float y;
    float z;
} Vector3;

typedef struct {
    float m;
    float energie;
    Vector3 pos;
    float v;
} Partical;

class Boltzmann_Verteilung {
private:
    Partical m_partical[PARTICALS];

public:
    Boltzmann_Verteilung();
    void update();
};

#endif