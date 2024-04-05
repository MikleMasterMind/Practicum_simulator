#include <iostream>
#include <unistd.h>
#include <random>
#include "Simulator.hpp"

int main() {
    Box_wiht_balls::Simulator* sim = new Box_wiht_balls::Simulator;
    int seed = 1;
    int amounts = 1;
    int amountb = 1;
    sim->generate_particles(seed, amounts, amountb);
    sim->end();
    sim->show();
    return Fl::run();
}
