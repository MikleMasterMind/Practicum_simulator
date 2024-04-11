#include "Particle.hpp"

Box_with_balls::Particle::Particle(double x, double y, double vx, double vy) : 
    coordinates(x, y), velocity(vx, vy) {}

Box_with_balls::Particle::Particle(Box_with_balls::Math_vector c, Box_with_balls::Math_vector v) : 
    coordinates(c), velocity(v) {}

Box_with_balls::Math_vector Box_with_balls::Particle::get_coordinates() const {
    return coordinates;
}

void Box_with_balls::Particle::set_coordinates(const Box_with_balls::Math_vector &x) {
    coordinates = x;
}

Box_with_balls::Math_vector Box_with_balls::Particle::get_velocity() const {
    return velocity;
}

void Box_with_balls::Particle::set_velocity(const Box_with_balls::Math_vector &v) {
    velocity = v;
}

void Box_with_balls::Particle::move(double dt) {
    coordinates = coordinates + velocity * dt;
}
