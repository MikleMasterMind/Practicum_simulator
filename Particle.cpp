#include "Particle.hpp"

MyNamespace::Particle::Particle(double r, double x, double y, double vx, double vy) : 
    coordinates(x, y), radius(r), velocity(vx, vy) {}

MyNamespace::Particle::Particle(double r, MyNamespace::Math_vector c, MyNamespace::Math_vector v) : 
    coordinates(c), radius(r), velocity(v){}

bool MyNamespace::Particle::collision(const MyNamespace::Particle &other) const {
    double sq_rad= (this->radius + other.radius) * (this->radius + other.radius);
    return sq_rad < this->coordinates.squared_distance(other.coordinates);
}

void MyNamespace::Particle::resolve_collision(MyNamespace::Particle &other) {
    Math_vector relative_velocity = other.velocity - this->velocity;

    Math_vector normal = Math_vector(other.coordinates.x - this->coordinates.x, other.coordinates.y - this->coordinates.y); // collision vector (directed to other)
    normal = Math_vector(normal.x / normal.module(), normal.y / normal.module()); // normalize

    double velocity_along_normal = relative_velocity * normal;
    if (velocity_along_normal > 0) // particles do not crash
        return;
    
    double scalar_impulse = velocity_along_normal * -2 / (this->inv_mass + other.inv_mass);
    Math_vector impulse = normal * scalar_impulse;
    this->velocity = impulse * this->inv_mass;
    other.velocity = impulse * other.inv_mass;
}

MyNamespace::Circle MyNamespace::Particle::get_image() const {
    return Circle(coordinates.x, coordinates.y, radius);
}


