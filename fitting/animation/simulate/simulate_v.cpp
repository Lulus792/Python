#include "simulate_v.h"

#include <random>
#include <fstream>

void write_velocity(Partical par_array[PARTICALS]) {
    std::ofstream file("data.csv");

    for (size_t i{}; i < PARTICALS; i++) {
       file << par_array[i].v << "\n"; 
    }

}

float velocity(Partical partical) {
    return sqrt(2 * partical.energie / partical.m);
}

bool checkPosition(Partical *par1, Partical *par2) {

    float min1_x = par1->pos.x - RADIUS_PARTICAL;
    float min2_x = par2->pos.x - RADIUS_PARTICAL;
    float min1_y = par1->pos.y - RADIUS_PARTICAL;
    float min2_y = par2->pos.y - RADIUS_PARTICAL;
    float min1_z = par1->pos.z - RADIUS_PARTICAL;
    float min2_z = par2->pos.z - RADIUS_PARTICAL;

    float max1_x = par1->pos.x + RADIUS_PARTICAL;
    float max2_x = par2->pos.x + RADIUS_PARTICAL;
    float max1_y = par1->pos.y + RADIUS_PARTICAL;
    float max2_y = par2->pos.y + RADIUS_PARTICAL;
    float max1_z = par1->pos.z + RADIUS_PARTICAL;
    float max2_z = par2->pos.z + RADIUS_PARTICAL;

    if ((min1_x < min2_x < max1_x) || (min1_x < max2_x < max1_x)) {
        return true;
    }
    else if ((min1_y < min2_y < max1_y) || (min1_y < max2_y < max1_y)) {
        return true;
    } 
    else if ((min1_z < min2_z < max1_z) || (min1_z < max2_z < max1_z)) {
        return true;
    }

    return false;
}

void inelastic_collision(Partical *par1, Partical *par2) {
    float v_tmp_1 = par1->v;
    float v_tmp_2 = par2->v;

    par1->v = 2 * (par1->m * v_tmp_1 + par2->m * v_tmp_2) 
            / (par1->m + par2->m) - v_tmp_1;
    par2->v = 2 * (par1->m * v_tmp_1 + par2->m * v_tmp_2) 
            / (par1->m + par2->m) - v_tmp_2;
}

Boltzmann_Verteilung::Boltzmann_Verteilung() {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(0,SIZE_OF_CUBE);
    for (Partical &partical : this->m_partical) {
        partical.energie = ENERGIE / PARTICALS;
        partical.m = MASS;
        partical.pos.x = dist(rng);
        partical.pos.y = dist(rng);
        partical.pos.z = dist(rng);
        partical.v = velocity(partical);
    } 
}

void Boltzmann_Verteilung::update() {

    for (size_t i{}; i < PARTICALS; i++) {
       for (size_t j{}; j < PARTICALS; j++) {
            if (i == j) continue;
            if (checkPosition(&m_partical[i], &m_partical[j])) {
                inelastic_collision(&m_partical[i], &m_partical[j]);
            }
       } 
    }
    write_velocity(m_partical);

}