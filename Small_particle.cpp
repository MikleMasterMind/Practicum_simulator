#include "Small_particle.hpp"

Box_with_balls::Small_particle::Small_particle(double x, double y, double vx, double vy) : Particle(SMALL_RADIUS, x, y, vx, vy, SMALL_MASS) {}

Box_with_balls::Small_particle::Small_particle(double x, double y, double vx, double vy, double r, double m) : Small_particle(x, y, vx, vy) {}
