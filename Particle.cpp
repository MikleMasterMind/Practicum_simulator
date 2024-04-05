#include "Particle.hpp"

Box_with_balls::Particle::Particle(double r, double x, double y, double vx, double vy, double mass) : 
    coordinates(x, y), radius(r), velocity(vx, vy), inv_mass(1/mass) {}

Box_with_balls::Particle::Particle(double r, Box_with_balls::Math_vector c, Box_with_balls::Math_vector v, double mass) : 
    coordinates(c), radius(r), velocity(v), inv_mass(1/mass) {}

void Box_with_balls::Particle::move(double dt) {
    coordinates = coordinates + velocity * dt;
}

Box_with_balls::bound_type Box_with_balls::Particle::check_bound_collision(int up, int down, int left, int rigth) const {
    if (coordinates.y - radius < up)
        return up_bound;
    if (coordinates.y + radius > down)
        return down_bound;
    if (coordinates.x - radius < left)
        return left_bound;
    if (coordinates.x + radius > rigth)
        return rigth_bound;
    return no_bound;
}

void Box_with_balls::Particle::resolve_bound_collision(Box_with_balls::bound_type type) {
    if (type == up_bound || type == down_bound)
        velocity.y = -velocity.y;
    else if (type == left_bound || type == rigth_bound)
        velocity.x = -velocity.x;
    return;
}

bool Box_with_balls::Particle::collision(const Box_with_balls::Particle* other) const {
    if (this == other) 
        return false;
    double sq_rad= (this->radius + other->radius) * (this->radius + other->radius); // (r_a + r_b)^2
    return sq_rad > this->coordinates.squared_distance(other->coordinates); // (r_a + r_b)^2 < (a-b)^2
}

void Box_with_balls::Particle::resolve_collision(Box_with_balls::Particle* other) {

    Math_vector relative_velocity = other->velocity - this->velocity;

    Math_vector normal = other->coordinates - this->coordinates;
    normal = Math_vector(normal.x / normal.module(), normal.y / normal.module()); // normalize

    double velocity_along_normal = relative_velocity * normal;
    if (velocity_along_normal > 0) // particles do not crash
        return;
    
    double scalar_impulse = (velocity_along_normal * -2) / (this->inv_mass + other->inv_mass); // total impulse
    Math_vector impulse = normal * scalar_impulse; // total impulse vector
    this->velocity = this->velocity - impulse * this->inv_mass;
    other->velocity = other->velocity + impulse * other->inv_mass;
}

Box_with_balls::Circle Box_with_balls::Particle::get_image() const {
    return Circle(coordinates.x, coordinates.y, radius);
}


