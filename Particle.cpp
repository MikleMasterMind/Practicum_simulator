#include "Particle.hpp"

Box_wiht_balls::Particle::Particle(double r, double x, double y, double vx, double vy, double mass) : 
    coordinates(x, y), radius(r), velocity(vx, vy), inv_mass(1/mass) {}

Box_wiht_balls::Particle::Particle(double r, Box_wiht_balls::Math_vector c, Box_wiht_balls::Math_vector v, double mass) : 
    coordinates(c), radius(r), velocity(v), inv_mass(1/mass) {}

void Box_wiht_balls::Particle::move(double dt) {
    coordinates = coordinates + velocity * dt;
}

bool Box_wiht_balls::Particle::collision(const Box_wiht_balls::Particle* other) const {
    double sq_rad= (this->radius + other->radius) * (this->radius + other->radius); // (r_a + r_b)^2
    return sq_rad < this->coordinates.squared_distance(other->coordinates); // (r_a + r_b)^2 < (a-b)^2
}

void Box_wiht_balls::Particle::resolve_collision(Box_wiht_balls::Particle* other) {
    Math_vector relative_velocity = other->velocity - this->velocity;

    Math_vector normal = Math_vector(other->coordinates.x - this->coordinates.x, other->coordinates.y - this->coordinates.y); // collision vector (directed to other)
    normal = Math_vector(normal.x / normal.module(), normal.y / normal.module()); // normalize

    double velocity_along_normal = relative_velocity * normal;
    if (velocity_along_normal > 0) // particles do not crash
        return;
    
    double scalar_impulse = velocity_along_normal * -2 / (this->inv_mass + other->inv_mass); // total impulse
    Math_vector impulse = normal * scalar_impulse; // total impulse vector
    this->velocity = impulse * this->inv_mass;
    other->velocity = impulse * other->inv_mass;
}

Box_wiht_balls::Circle Box_wiht_balls::Particle::get_image() const {
    return Circle(coordinates.x, coordinates.y, radius);
}


