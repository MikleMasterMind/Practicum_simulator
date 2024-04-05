#include <iostream>
#include <unistd.h>
#include <random>
#include "Simulator.hpp"

int main() {
    Box_with_balls::Simulator sim;
    int seed = 1;
    int amounts = 1;
    int amountb = 1;
    sim.generate_particles(seed, amounts, amountb);
    sim.end();
    sim.show();
    return Fl::run();
}
