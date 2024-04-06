#include <iostream>
#include <unistd.h>
#include <random>
#include "Simulator.hpp"

int main() {
    Box_with_balls::Simulator sim;
    int seed;
    int amount_small;
    int amount_big;
    std::cin >> seed >> amount_small >> amount_big;
    sim.generate_particles(seed, amount_small, amount_big);
    sim.end();
    sim.show();
    return Fl::run();
}
