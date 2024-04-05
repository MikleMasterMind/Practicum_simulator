#include <iostream>
#include <unistd.h>
#include <random>
#include "Math_vector.hpp"
#include "Painter.hpp"
#include "System.hpp"
#include "Simulator.hpp"

int main() {
    Box_wiht_balls::Simulator* sim = new Box_wiht_balls::Simulator;
    int seed = 1;
    int amount = 10;
    sim->generate_particles(seed, amount);
    sim->show();
    return Fl::run();
}
