#ifndef _Particle_H_
#define _Particle_H_

#include "Math_vector.hpp"
#include "Circle.hpp"

namespace Box_with_balls {

    enum bound_type {
        no_bound = 0,
        up_bound = 1,
        down_bound = 2,
        left_bound = 3,
        rigth_bound = 4
    };

    class Particle {

        Math_vector coordinates;
        Math_vector velocity;
        double radius;
        double inv_mass; // better store in this way

    public:

        Particle(double r = 0, double x = 0, double y = 0, double vx = 0, double vy = 0, double mass = 1);

        Particle(double r = 0, Math_vector c = Math_vector(0, 0), Math_vector v = Math_vector(0, 0) , double mass = 1);

        virtual void move(double dt);

        virtual bound_type check_bound_collision(int up, int down, int left, int rigth) const; 

        virtual void resolve_bound_collision(bound_type type);

        virtual bool collision(const Particle* other) const; // find collision with other

        virtual void resolve_collision(Particle* other); // chenge its velocity and other's 

        virtual Circle get_image() const; // for drawing

    };
}

#endif // ! _Particle_H_