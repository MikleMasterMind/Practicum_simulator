#include "Small_particle.hpp"

Box_with_balls::Small_particle::Small_particle(double x, double y, double vx, double vy) : Particle(x, y, vx, vy)
{}

double Box_with_balls::Small_particle::get_radius() const {
    return SMALL_RADIUS;
}

double Box_with_balls::Small_particle::get_inv_mass() const {
    return 1 / SMALL_MASS;
}

void Box_with_balls::Small_particle::bound_collision(int up, int down, int left, int rigth) {
    Math_vector coordinates = get_coordinates();
    Math_vector velocity = get_velocity();
    double radius = get_radius();
    if (coordinates.x - radius < left) {
        velocity.x = -velocity.x;
        coordinates.x = left + radius;
    }
    if (coordinates.x + radius > rigth) {
        velocity.x = -velocity.x;
        coordinates.x = rigth - radius;
    }
    if (coordinates.y - radius < up) {
        velocity.y = -velocity.y;
        coordinates.y = up + radius;
    }
    if (coordinates.y + radius > down) {
        velocity.y = -velocity.y;
        coordinates.y = down - radius;
    }
    set_coordinates(coordinates);
    set_velocity(velocity);
    return;
}

bool Box_with_balls::Small_particle::collision(const Box_with_balls::Particle *other) const {
    if (this == other) 
        return false;
    double sq_rad= (this->get_radius() + other->get_radius()) * (this->get_radius() + other->get_radius()); // (r_a + r_b)^2
    return sq_rad > this->get_coordinates().squared_distance(other->get_coordinates()); // (r_a + r_b)^2 > (a-b)^2
}

void Box_with_balls::Small_particle::resolve_collision(Box_with_balls::Particle *other) {
    Math_vector relative_velocity = other->get_velocity() - this->get_velocity();

    Math_vector normal = other->get_coordinates() - this->get_coordinates();
    normal = Math_vector(normal.x / normal.module(), normal.y / normal.module()); // normalize

    double velocity_along_normal = relative_velocity * normal;
    if (velocity_along_normal > 0) // particles do not crash
        return;
    
    double scalar_impulse = (velocity_along_normal * -2) / (this->get_inv_mass() + other->get_inv_mass()); // total impulse
    Math_vector impulse = normal * scalar_impulse; // total impulse vector
    this->set_velocity(this->get_velocity() - impulse * this->get_inv_mass());
    other->set_velocity(other->get_velocity() + impulse * other->get_inv_mass());
}
