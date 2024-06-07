#include "simulate_v.h"

int main() {

    Boltzmann_Verteilung verteilung{};

    for (size_t i{}; i < 100; i++) {
        verteilung.update();
    }

    return 0;
}