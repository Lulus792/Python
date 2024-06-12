#include "simulate_v.h"

#include <cmath>
#include <random>
#include <fstream>

float abs_of_vector(v_Vector3 *speed_vector) {
  return std::sqrt(std::pow(speed_vector->v_x, 2) +
                   std::pow(speed_vector->v_y, 2) +
                   std::pow(speed_vector->v_z, 2));
}

void write_velocity(Partical par_array[PARTICALS]) {
  std::ofstream file("data.csv");

  for (size_t i{}; i < PARTICALS; i++) {
   file << abs_of_vector(&par_array[i].v) << "\n"; 
  }
}

v_Vector3 velocity(Partical partical) {
  float v_one_dimension = sqrt(2 * partical.energie / partical.m);
  v_Vector3 ret{};

  std::random_device dev;
  std::mt19937 rng(dev());

  std::uniform_int_distribution<std::mt19937::result_type> dist_x(0,v_one_dimension);
  ret.v_x = dist_x(rng);

  std::uniform_int_distribution<std::mt19937::result_type> dist_y(0,ret.v_x);
  ret.v_y = dist_y(rng);

  ret.v_z = v_one_dimension - ret.v_x - ret.v_y;

  return ret; 
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
  
  if ((min1_x < min2_x && min2_x < max1_x) || 
    (min1_x < max2_x && max2_x < max1_x)) {
    return true;
  }
  else if ((min1_y < min2_y && min2_y < max1_y) || 
    (min1_y < max2_y && max2_y < max1_y)) {
    return true;
  } 
  else if ((min1_z < min2_z && min2_z < max1_z) || 
    (min1_z < max2_z && max2_z < max1_z)) {
    return true;
  }

  return false;
}

void setNewPositionOfPartical(Partical *partical) {
  partical->pos.x += partical->v.v_x; 
  partical->pos.y += partical->v.v_y;
  partical->pos.z += partical->v.v_z;

  if (partical->pos.x > SIZE_OF_CUBE) {
    partical->v.v_x *= -1.0;
    partical->pos.x = SIZE_OF_CUBE;
  }
  else if (partical->pos.x < 0.0) {
    partical->v.v_x *= -1.0;
    partical->pos.x = 0.0;
  }

  if (partical->pos.y > SIZE_OF_CUBE) {
    partical->v.v_y *= -1.0;
    partical->pos.y = SIZE_OF_CUBE;
  }
  else if (partical->pos.y < 0.0) {
    partical->v.v_y *= -1.0;
    partical->pos.y = 0.0;
  }

  if (partical->pos.z > SIZE_OF_CUBE) {
    partical->v.v_z *= -1.0;
    partical->pos.z = SIZE_OF_CUBE;
  }
  else if (partical->pos.z < 0.0) {
    partical->v.v_z *= -1.0;
    partical->pos.z = 0.0;
  }
}

void inelastic_collision(Partical *par1, Partical *par2) {
  v_Vector3 v_tmp_1 = par1->v;
  v_Vector3 v_tmp_2 = par2->v;

  par1->v.v_x = 2 * (par1->m * v_tmp_1.v_x + par2->m * v_tmp_2.v_x) 
          / (par1->m + par2->m) - v_tmp_1.v_x;
  par2->v.v_x = 2 * (par1->m * v_tmp_1.v_x + par2->m * v_tmp_2.v_x) 
          / (par1->m + par2->m) - v_tmp_2.v_x;

  par1->v.v_y = 2 * (par1->m * v_tmp_1.v_y + par2->m * v_tmp_2.v_y) 
          / (par1->m + par2->m) - v_tmp_1.v_y;
  par2->v.v_y = 2 * (par1->m * v_tmp_1.v_y + par2->m * v_tmp_2.v_y) 
          / (par1->m + par2->m) - v_tmp_2.v_y;

  par1->v.v_z = 2 * (par1->m * v_tmp_1.v_z + par2->m * v_tmp_2.v_z) 
          / (par1->m + par2->m) - v_tmp_1.v_z;
  par2->v.v_z = 2 * (par1->m * v_tmp_1.v_z + par2->m * v_tmp_2.v_z) 
          / (par1->m + par2->m) - v_tmp_2.v_z;
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

  unsigned int start{ 0 };
  for (size_t i{}; i < PARTICALS; i++) {
    for (size_t j{ start }; j < PARTICALS; j++) {
      if (i == j) continue;
      if (checkPosition(&m_partical[i], &m_partical[j])) {
        inelastic_collision(&m_partical[i], &m_partical[j]);
      }
    } 
    setNewPositionOfPartical(&m_partical[i]); 
    start++;
  }
  write_velocity(m_partical);
}
